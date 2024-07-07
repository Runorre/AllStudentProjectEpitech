/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * Core
 */

using System.Threading.Tasks;
using System;
using UnityEngine;
using System.Collections.Generic;
using TMPro;
using System.Linq;

namespace Zappy {
    public class Team {
        public string name;
        public List<Player> teamPlayers = new();
    }

    public class Core : MonoBehaviour {
        private bool isMapFilled = false;
        private readonly string errorMessage = "Error parsing";
        private readonly string errorMessagePlayerNotFound = "Player not found";
        public Animator transition;
        public GameObject cam;
        public GameObject[][] tiles;
        public List<GameObject> eggs = new();
        public List<GameObject> players = new();
        public List<Team> teamList = new();
        public List<Transform> tilesPrefab;
        public Menu menuComponent;
        public TMP_Text TeamsText;
        public TMP_Text TimeUnitText;
        public TMP_Text mapSizeText;
        public Transform eggPrefab;
        public Transform playerPrefab;
        public Transform portalPrefab;

        private async void Start()
        {
            GameObject menuGameObject = GameObject.Find("Menu");
            if (menuGameObject == null) {
                return;
            }
            if (!menuGameObject.TryGetComponent<Menu>(out menuComponent)) {
                Debug.LogError("Menu not found");
                return;
            }
            cam.transform.SetPositionAndRotation(
                new Vector3(
                    (float)Math.Ceiling(menuComponent.width * 5 / 2.0) - 2.5f,
                    Math.Max(menuComponent.width * 5, menuComponent.height * 5) / 2,
                    (float)Math.Ceiling(menuComponent.height * 5 / 2.0) - 2.5f),
                Quaternion.Euler(90, 0, 90)
            );
            mapSizeText.text = $"{menuComponent.width}x{menuComponent.height}";
            TimeUnitText.text = $"{menuComponent.timeUnit}";
            await menuComponent.SendMessageAsync("tna");
            await ParseTeamsAsync();
            GenerateMap();
            await ReceiveMessagesAsync();
        }

        private async Task ParseTeamsAsync()
        {
            string command = await menuComponent.ReceiveMessageAsync();
            string[] commands = command.Split("\n");
            foreach (string newCommand in commands.Where(c => c.StartsWith("tna", StringComparison.Ordinal))) {
                string[] teams = newCommand.Split(" ");
                TeamsText.text += $"- {teams[1]}\n";
            }
        }
        
        private async Task ReceiveMessagesAsync()
        {
            while (true) {
                string command = await menuComponent.ReceiveMessageAsync();
                command = command[..^1];
                string[] commands = command.Split("\n");
                foreach (string newCommand in commands) {
                    SelectionAction(newCommand);
                }
            }
        }

        private void SelectionAction(string command)
        {
            if (command.StartsWith("bct", StringComparison.Ordinal)) {
                FillTiles(command);
            } else if (command.StartsWith("pnw", StringComparison.Ordinal)) {
                SpawnPlayer(command);
            } else if (command.StartsWith("ppo", StringComparison.Ordinal)) {
                MovePlayer(command);
            } else if (command.StartsWith("pic", StringComparison.Ordinal)) {
                StartIncantation(command);
            } else if (command.StartsWith("pdi", StringComparison.Ordinal)) {
                KillPlayer(command);
            } else if (command.StartsWith("pbc", StringComparison.Ordinal)) {
                Broadcast(command);
            } else if (command.StartsWith("pie", StringComparison.Ordinal)) {
                StopIncantation(command);
            } else if (command.StartsWith("pin", StringComparison.Ordinal)) {
                UpdateInventory(command);
            } else if (command.StartsWith("seg", StringComparison.Ordinal)) {
                EndGame(command);
            } else {
                HandleEggCommands(command);
            }
        }

        private void HandleEggCommands(string command)
        {
            if (command.StartsWith("enw", StringComparison.Ordinal)) {
                SpawnEgg(command);
            } else if (command.StartsWith("ebo", StringComparison.Ordinal) || command.StartsWith("edi", StringComparison.Ordinal)) {
                KillEgg(command);
            }
        }

        private void GenerateMap()
        {
            int width = menuComponent.width;
            int height = menuComponent.height;

            tiles = new GameObject[width][];
            for (int x = 0; x < width; x++) {
                tiles[x] = new GameObject[height];
                for (int y = 0; y < height; y++) {
                    int index = UnityEngine.Random.Range(0, tilesPrefab.Count);
                    float angleX = UnityEngine.Random.Range(0, 360);
                    float angleY = UnityEngine.Random.Range(0, 360);
                    float angleZ = UnityEngine.Random.Range(0, 360);
                    GameObject prefab = Instantiate(tilesPrefab[index], new Vector3(x * 5, 0, y * 5), Quaternion.Euler(angleX, angleY, angleZ)).gameObject;
                    prefab.transform.localScale = new Vector3(4, 4, 4);
                    tiles[x][y] = prefab;
                }
            }
            for (int i = 0; i < (width * 5); i += 5) {
                Instantiate(portalPrefab, new Vector3(i, 2.5f, -2.5f), Quaternion.Euler(0f, 0f, 0f));
                Instantiate(portalPrefab, new Vector3(i, 2.5f, (height * 5) - 2.5f), Quaternion.Euler(0f, 0f, 0f));
            }
            for (int j = 0; j < (height * 5); j += 5) {
                Instantiate(portalPrefab, new Vector3(-2.5f, 2.5f, j), Quaternion.Euler(0f, 90f, 0f));
                Instantiate(portalPrefab, new Vector3((width * 5) - 2.5f, 2.5f, j), Quaternion.Euler(0f, 90f, 0f));
            }
        }

        private void FillTiles(string tilesContent)
        {
            string[] tileContentArray = tilesContent.Split(" ");

            if (!int.TryParse(tileContentArray[1], out int x) || !int.TryParse(tileContentArray[2], out int y)) {
                Debug.LogError("Error parsing coordinates");
                return;
            }
            Tile tile;
            try {
                tile = tiles[x][y].GetComponent<Tile>();
            } catch (MissingReferenceException) {
                return;
            }
            if (tile == null) {
                Debug.LogError("Tile not found");
                return;
            }
            tile.x = x;
            tile.y = y;
            for (int i = 0; i < Enum.GetValues(typeof(ResourceType)).Length; i++) {
                if (tileContentArray.Length <= i + 3 || !int.TryParse(tileContentArray[i + 3], out int quantity)) {
                    Debug.LogError($"Error parsing quantity: {tilesContent}");
                    continue;
                }
                tile.UpdateResource((ResourceType)i, quantity);
            }
            CheckMapFilled(x, y);
        }

        private void CheckMapFilled(int x, int y)
        {
            if (!isMapFilled && x == menuComponent.width - 1 && y == menuComponent.height - 1) {
                transition.SetTrigger("End");
                isMapFilled = true;
            }
        }

        private void SpawnPlayer(string playerContent)
        {
            string[] playerContentArray = playerContent.Split(" ");

            if (!int.TryParse(playerContentArray[1], out int playerNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[2], out int x)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[3], out int y)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[4], out int orientation)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[5], out int level)) {
                Debug.LogError(errorMessage);
                return;
            }
            string teamName = playerContentArray[6];
            Transform prefab = Instantiate(playerPrefab, new Vector3(0f, 0f, 0f), Quaternion.Euler(0, (orientation + 1) * 90, 0));
            Player player = prefab.GetComponent<Player>();
            player.SetPosition(x, y, tiles[x][y], true);
            player.SetOrientation(orientation, true);
            prefab.gameObject.name = $"Player {playerNumber}";
            player.id = playerNumber;
            player.x = x;
            player.y = y;
            player.level = level;
            player.orientation = orientation;
            players.Add(prefab.gameObject);
            tiles[x][y].GetComponent<Tile>().AddPlayer(prefab.gameObject);
            Team existingTeam = teamList.Find(team => team.name == teamName);
            if (existingTeam == null) {
                existingTeam = new Team { name = teamName, teamPlayers = new List<Player>() };
                teamList.Add(existingTeam);
            }
            existingTeam.teamPlayers.Add(player);
            player.team = existingTeam;
        }

        private void SpawnEgg(string eggContent)
        {
            string[] eggContentArray = eggContent.Split(" ");

            if (!int.TryParse(eggContentArray[1], out int eggNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(eggContentArray[3], out int x)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(eggContentArray[4], out int y)) {
                Debug.LogError(errorMessage);
                return;
            }
            GameObject egg = tiles[x][y].GetComponent<Tile>().SpawnEgg(eggNumber);
            if (egg != null) {
                eggs.Add(egg);
            }
        }

        private void MovePlayer(string playerContent)
        {
            string[] playerContentArray = playerContent.Split(" ");

            if (!int.TryParse(playerContentArray[1], out int playerNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[2], out int x)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[3], out int y)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(playerContentArray[4], out int orientation)) {
                Debug.LogError(errorMessage);
                return;
            }
            GameObject player;
            try {
                player = players.Find(p => p != null && p.name == $"Player {playerNumber}");
            } catch (MissingReferenceException) {
                return;
            }
            if (player == null) {
                Debug.LogError(errorMessagePlayerNotFound);
                return;
            }
            Player playerComponent = player.GetComponent<Player>();
            tiles[playerComponent.x][playerComponent.y].GetComponent<Tile>().RemovePlayer(player);
            tiles[x][y].GetComponent<Tile>().AddPlayer(player);
            playerComponent.SetPosition(x, y, tiles[x][y], false);
            playerComponent.SetOrientation(orientation, false);
        }

        private void StartIncantation(string incantationContent)
        {
            string[] incantationContentArray = incantationContent.Split(" ");

            if (!int.TryParse(incantationContentArray[1], out int x)) {
                Debug.LogError(errorMessage);
                return;
            }
            if (!int.TryParse(incantationContentArray[2], out int y)) {
                Debug.LogError(errorMessage);
                return;
            }
            StartCoroutine(tiles[x][y].GetComponent<Tile>().StartIncantation());
            for (int i = 4; i < incantationContentArray.Length; i++) {
                if (!int.TryParse(incantationContentArray[i], out int playerNumber)) {
                    Debug.LogError(errorMessage);
                    continue;
                }
                GameObject player = players.Find(p => p != null && p.name == $"Player {playerNumber}");
                if (player == null) {
                    Debug.LogError(errorMessagePlayerNotFound);
                    continue;
                }
                Player playerComponent = player.GetComponent<Player>();
                player.GetComponent<SpawnEffect>().StartParticles();
                playerComponent.isIncanting = true;
                if (playerComponent.playerName == "") {
                    return;
                }
                string message = $"{playerComponent.playerName}: commence l'incantation à {{x: {x}, y: {y}}}";
                Log.Instance.AddLog(message, playerComponent.color);
            }
        }

        private void StopIncantation(string incantationContent)
        {
            string[] incantationContentArray = incantationContent.Split(" ");
            bool hasWriteLog = false;

            if (!TryParseCoordinates(incantationContentArray, out int x, out int y, out int result)) {
                Debug.LogError("Invalid incantation content");
                return;
            }
            Tile tileComponent = tiles[x][y].GetComponent<Tile>();
            List<GameObject> playerOnTile = tileComponent.players;
            foreach (GameObject player in playerOnTile) {
                ProcessPlayer(player, result, ref hasWriteLog);
            }
            string message = $"SERVEUR: l'incantation à {{x: {x}, y: {y}}} s'est terminée";
            Log.Instance.AddLog(message, Color.white);
        }

        private bool TryParseCoordinates(string[] contentArray, out int x, out int y, out int result)
        {
            if (int.TryParse(contentArray[1], out x) && int.TryParse(contentArray[2], out y) && int.TryParse(contentArray[3], out result)) {
                return true;
            }
            x = y = result = 0;
            return false;
        }

        private void ProcessPlayer(GameObject player, int result, ref bool hasWriteLog)
        {
            if (player == null) {
                return;
            }
            Player playerComponent = player.GetComponent<Player>();
            if (playerComponent == null || !playerComponent.isIncanting) {
                return;
            }
            playerComponent.isIncanting = false;
            if (player.TryGetComponent<SpawnEffect>(out var spawnEffect)) {
                spawnEffect.StopParticles();
            }
            if (result == 1) {
                playerComponent.UpgradeLevel();
                if (!hasWriteLog) {
                    string message = $"SERVEUR: passage au niveau {playerComponent.level}";
                    Log.Instance.AddLog(message, Color.white);
                    hasWriteLog = true;
                }
            }
        }

        private void KillPlayer(string playerContent)
        {
            string[] playerContentArray = playerContent.Split(" ");

            if (!int.TryParse(playerContentArray[1], out int playerNumber)) {
                Debug.LogError("Invalid player number");
                return;
            }
            GameObject player = players.Find(p => p != null && p.name == $"Player {playerNumber}");
            if (player == null) {
                Debug.LogError("Player not found");
                return;
            }
            if (!player.TryGetComponent<Player>(out var playerComponent)) {
                Debug.LogError("Player component not found");
                return;
            }
            players.Remove(player);
            if (playerComponent.team != null && playerComponent.team.teamPlayers != null) {
                playerComponent.team.teamPlayers.Remove(playerComponent);
            }
            string message = playerComponent.playerName + ": est mort";
            Log.Instance.AddLog(message, playerComponent.color);
            Destroy(player);
        }

        private void KillEgg(string eggContent)
        {
            string[] eggContentArray = eggContent.Split(" ");

            if (!int.TryParse(eggContentArray[1], out int eggNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            GameObject egg = eggs.Find(egg => egg.name == $"Egg {eggNumber}");
            if (egg == null) {
                return;
            }
            eggs.Remove(egg);
            Destroy(egg);
        }

        private void Broadcast(string broadcastContent)
        {
            string[] broadcastContentArray = broadcastContent.Split(" ");

            if (!int.TryParse(broadcastContentArray[1], out int playerNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            GameObject playerObject = players.Find(p => p != null && p.name == $"Player {playerNumber}");
            if (playerObject == null) {
                Debug.LogError(errorMessagePlayerNotFound);
                return;
            }
            Player playerComponent = playerObject.GetComponent<Player>();
            playerComponent.Broadcast(broadcastContentArray[2]);
            string message = $"{playerComponent.playerName}: diffuse \"{broadcastContentArray[2]}\"";
            Log.Instance.AddLog(message, playerComponent.color);
        }

        private void UpdateInventory(string inventoryContent)
        {
            string[] inventoryContentArray = inventoryContent.Split(" ");
            GameObject player;

            int[] parsedValues = new int[10];
            for (int i = 0; i < parsedValues.Length; i++) {
                if (!int.TryParse(inventoryContentArray[i + 1], out parsedValues[i])) {
                    Debug.LogError(errorMessage);
                    return;
                }
            }
            try {
                player = players.Find(p => p != null && p.name == $"Player {parsedValues[0]}");
            } catch (MissingReferenceException) {
                return;
            }
            Dictionary<ResourceType, int> inventory = new() {
                {ResourceType.Food, parsedValues[3]},
                {ResourceType.Linemate, parsedValues[4]},
                {ResourceType.Deraumere, parsedValues[5]},
                {ResourceType.Sibur, parsedValues[6]},
                {ResourceType.Mendiane, parsedValues[7]},
                {ResourceType.Phiras, parsedValues[8]},
                {ResourceType.Thystame, parsedValues[9]}
            };
            player.GetComponent<Player>().UpdateInventory(inventory);
        }

        private void EndGame(string endGameContent)
        {
            string[] endGameContentArray = endGameContent.Split(" ");
            GameObject winnerPanel = GameObject.Find("Winner");
            GameObject InfoPanel = GameObject.Find("Informations");
            TMP_Text winnerText = GameObject.Find("WinnerTeamName").GetComponent<TMP_Text>();

            if (!int.TryParse(endGameContentArray[1], out int winnerPlayerNumber)) {
                Debug.LogError(errorMessage);
                return;
            }
            GameObject winnerPlayer = players.Find(p => p != null && p.name == $"Player {winnerPlayerNumber}");
            Team winnerTeam = winnerPlayer.GetComponent<Player>().team;
            InfoPanel.GetComponent<CanvasGroup>().alpha = 0;
            winnerText.text = $" {winnerTeam.name}";
            winnerPanel.GetComponent<CanvasGroup>().alpha = 1;
        }
    }
}
