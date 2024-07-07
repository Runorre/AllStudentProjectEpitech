/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * Player
 */

using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

namespace Zappy {
    public class Player : MonoBehaviour {
        ControllerCamera controllerCamera;
        private SkinnedMeshRenderer render;
        private bool isSelected = false;
        private int timeUnit;
        public Animator PlayerAnimator;
        public Animator TeamAnimator;
        public Camera cam;
        public Color color;
        public Color highlightColor = Color.green;
        public Color[] originalColors;
        public GameObject playerInformation;
        public GameObject teamInformation;
        public List<Material> materials;
        public TMP_Text DeraumereText;
        public TMP_Text FoodText;
        public TMP_Text LevelText;
        public TMP_Text LinemateText;
        public TMP_Text MendianeText;
        public TMP_Text PhirasText;
        public TMP_Text PlayerText;
        public TMP_Text SiburText;
        public TMP_Text TeamText;
        public TMP_Text TeamsText;
        public TMP_Text ThystameText;
        public TMP_Text levelText;
        public Team team;
        public Transform head;
        public bool isIncanting = false;
        public bool isMoving = false;
        public int height;
        public int id;
        public int level = 1;
        public int orientation;
        public int width;
        public int x;
        public int y;
        public string playerName;

        public Dictionary<ResourceType, int> inventory = new() {
            {ResourceType.Food, 10},
            {ResourceType.Linemate, 0},
            {ResourceType.Deraumere, 0},
            {ResourceType.Sibur, 0},
            {ResourceType.Mendiane, 0},
            {ResourceType.Phiras, 0},
            {ResourceType.Thystame, 0}
        };

        public void Broadcast(string message)
        {
            SpeechBubbleManager.Instance.AddSpeechBubble(head, message);
        }

        private void UpdateNameTag()
        {
            levelText.text = "[" + team.name + "]\n" + playerName + "\nNiveau: " + level.ToString() + "\nNourriture: " + inventory[ResourceType.Food].ToString();
        }

        private string GetOrientation(int orientation)
        {
            if (orientation == 1) {
                return "NORD";
            } else if (orientation == 2) {
                return "EST";
            } else if (orientation == 3) {
                return "SUD";
            } else if (orientation == 4) {
                return "OUEST";
            }
            return "NORD";
        }

        private void Start()
        {
            if (PlayerPrefs.HasKey("TimeUnit")) {
                timeUnit = PlayerPrefs.GetInt("TimeUnit");
            }
            if (PlayerPrefs.HasKey("Width")) {
                width = PlayerPrefs.GetInt("Width");
            }
            if (PlayerPrefs.HasKey("Height")) {
                height = PlayerPrefs.GetInt("Height");
            }
            cam = Camera.main;
            playerInformation = GameObject.Find("PlayerInformation");
            teamInformation = GameObject.Find("TeamInformation");
            PlayerAnimator = playerInformation.GetComponent<Animator>();
            TeamAnimator = teamInformation.GetComponent<Animator>();
            PlayerText = GameObject.Find("PlayerText").GetComponent<TMP_Text>();
            FoodText = GameObject.Find("FoodText").GetComponent<TMP_Text>();
            LevelText = GameObject.Find("LevelText").GetComponent<TMP_Text>();
            LinemateText = GameObject.Find("LinemateText").GetComponent<TMP_Text>();
            DeraumereText = GameObject.Find("DeraumereText").GetComponent<TMP_Text>();
            SiburText = GameObject.Find("SiburText").GetComponent<TMP_Text>();
            MendianeText = GameObject.Find("MendianeText").GetComponent<TMP_Text>();
            PhirasText = GameObject.Find("PhirasText").GetComponent<TMP_Text>();
            ThystameText = GameObject.Find("ThystameText").GetComponent<TMP_Text>();
            TeamsText = GameObject.Find("TeamsText").GetComponent<TMP_Text>();
            TeamText = GameObject.Find("TeamText").GetComponent<TMP_Text>();
            controllerCamera = cam.GetComponent<ControllerCamera>();
            render = gameObject.GetComponentInChildren<SkinnedMeshRenderer>();
            originalColors = new Color[render.materials.Length];
            for (int i = 0; i < render.materials.Length; i++) {
                originalColors[i] = render.materials[i].color;
            }
            int randomColorIndex = UnityEngine.Random.Range(0, materials.Count);
            Material material = materials[randomColorIndex];
            TextAsset namesFile = Resources.Load<TextAsset>("Names");
            string[] names = namesFile.text.Split('\n');
            Dictionary<int, Color> colorMap = new() {
                {0, new Color(0.19f, 0.21f, 0.2f)},
                {1, new Color(0.27f, 0.49f, 0.44f)},
                {2, new Color(0.27f, 0.45f, 0.20f)},
                {3, new Color(0.55f, 0.33f, 0.18f)},
                {4, new Color(0.42f, 0.25f, 0.37f)},
                {5, new Color(0.40f, 0.13f, 0.14f)},
                {6, new Color(0.44f, 0.45f, 0.30f)},
                {7, new Color(0.63f, 0.63f, 0.31f)},
            };
            color = colorMap[randomColorIndex];
            gameObject.GetComponentInChildren<SkinnedMeshRenderer>().materials = new[] {material};
            playerName = names.Length > 0 ? names[UnityEngine.Random.Range(0, names.Length)] : "Joueur";
            UpdateNameTag();
            string message = $"{playerName}: connnecté à {{x: {x}, y: {y}, o: {GetOrientation(orientation)}}}";
            Log.Instance.AddLog(message, color);
        }

        private void OnMouseOver()
        {
            if (controllerCamera.IsFocused) {
                return;
            }
            foreach (Material material in render.materials) {
                material.color = highlightColor;
            }
        }
        
        private void OnMouseExit()
        {
            if (isSelected) {
                return;
            }
            for (int i = 0; i < render.materials.Length; i++) {
                render.materials[i].color = originalColors[i];
            }
        }

        private void Display()
        {
            PlayerText.text  = $"JOUEUR {playerName.ToUpper()}";
            LevelText.text = level.ToString();
            FoodText.text = inventory[ResourceType.Food].ToString();
            LinemateText.text = inventory[ResourceType.Linemate].ToString();
            DeraumereText.text = inventory[ResourceType.Deraumere].ToString();
            SiburText.text = inventory[ResourceType.Sibur].ToString();
            MendianeText.text = inventory[ResourceType.Mendiane].ToString();
            PhirasText.text = inventory[ResourceType.Phiras].ToString();
            ThystameText.text = inventory[ResourceType.Thystame].ToString();
            TeamText.text = $"ÉQUIPE {team.name.ToUpper()}";
            TeamsText.text = "";
            foreach (Player player in team.teamPlayers) {
                TeamsText.text += $"- {player.playerName.ToUpper()} (NIVEAU {player.level})\n";
            }
            PlayerAnimator.Play("Window In");
            TeamAnimator.Play("Window In");
        }

        private void Hide()
        {
            PlayerAnimator.Play("Window Out");
            TeamAnimator.Play("Window Out");
        }

        private void OnMouseDown()
        {
            if (controllerCamera.IsFocused) {
                return;
            }
            isSelected = !isSelected;
            if (isSelected) {
                Display();
            } else {
                Hide();
            }
        }

        private void Update()
        {
            if (isSelected && Input.GetKeyDown(KeyCode.Escape)) {
                isSelected = false;
                OnMouseExit();
                Hide();
            } else if (isSelected) {
                Display();
            }
        }

        public void SetPosition(int x, int y, GameObject tile, bool isFirstSpawn)
        {
            if (tile == null) {
                throw new ArgumentNullException(nameof(tile), "Parameter tile must not be null.");
            }
            if (this.x == x && this.y == y) {
                return;
            }
            this.x = x;
            this.y = y;
            Collider planetCollider = tile.GetComponent<Collider>();
            float latitude = UnityEngine.Random.Range(Mathf.PI / 4, Mathf.PI / 2);
            float longitude = UnityEngine.Random.Range(-Mathf.PI, Mathf.PI);
            float radius = tile.transform.localScale.x / 2;
            Vector3 position = new(
                radius * Mathf.Cos(latitude) * Mathf.Cos(longitude),
                radius * Mathf.Sin(latitude),
                radius * Mathf.Cos(latitude) * Mathf.Sin(longitude)
            );
            position += tile.transform.position;
            Ray ray = new(position + Vector3.up * 1000, Vector3.down);
            if (planetCollider.Raycast(ray, out RaycastHit hit, Mathf.Infinity)) {
                Vector3 closestPoint = hit.point;
                Vector3 upDirection = (closestPoint - tile.transform.position).normalized;
                if (isFirstSpawn || (closestPoint - transform.position).magnitude > 30f) {
                    transform.SetPositionAndRotation(closestPoint, Quaternion.FromToRotation(transform.up, upDirection) * transform.rotation);
                } else {
                    Quaternion newRotation = Quaternion.FromToRotation(transform.up, upDirection) * transform.rotation;
                    StartCoroutine(JumpToPosition(closestPoint, newRotation));
                }
            }
        }
        
        private IEnumerator JumpToPosition(Vector3 newPosition, Quaternion newRotation)
        {
            float duration = 7f / timeUnit;
            float elapsedTime = 0f;
        
            transform.GetPositionAndRotation(out Vector3 startPosition, out Quaternion startRotation);
            isMoving = true;
            while (elapsedTime < duration) {
                float t = elapsedTime / duration;
                transform.SetPositionAndRotation(
                    Vector3.Lerp(startPosition, newPosition, t),
                    Quaternion.Slerp(startRotation, newRotation, t)
                );
                elapsedTime += Time.deltaTime;
                yield return null;
            }
            transform.SetPositionAndRotation(newPosition, newRotation);
            isMoving = false;
        }

        public void SetOrientation(int orientation, bool isFirstSpawn)
        {
            this.orientation = orientation;
            if (orientation == 1) {
                orientation = 3;
            } else if (orientation == 2) {
                orientation = 4;
            } else if (orientation == 3) {
                orientation = 1;
            } else if (orientation == 4) {
                orientation = 2;
            }
            float targetAngle = (orientation + 1) * 90;
            float currentAngle = gameObject.transform.rotation.eulerAngles.y;
            float rotationAmountClockwise = (targetAngle - currentAngle + 360) % 360;
            float rotationAmountCounterClockwise = (currentAngle - targetAngle + 360) % 360;
            float rotationAmount = rotationAmountClockwise <= rotationAmountCounterClockwise ? rotationAmountClockwise : -rotationAmountCounterClockwise;
            if (isFirstSpawn) {
                gameObject.transform.RotateAround(gameObject.transform.position, gameObject.transform.up, rotationAmount);
            } else {
                StartCoroutine(RotateOverTime(rotationAmount));
            }
        }
        
        private IEnumerator RotateOverTime(float rotationAmount)
        {
            float duration = 7f / timeUnit;
            float elapsedTime = 0f;
            float rotationPerSecond = rotationAmount / duration;
        
            while (elapsedTime < duration) {
                float currentRotation = rotationPerSecond * Time.deltaTime;
                gameObject.transform.RotateAround(gameObject.transform.position, gameObject.transform.up, currentRotation);
                elapsedTime += Time.deltaTime;
                yield return null;
            }
        }

        public void UpdateInventory(Dictionary<ResourceType, int> inventory)
        {
            this.inventory = inventory ?? throw new ArgumentNullException(nameof(inventory), "Parameter inventory must not be null.");
            UpdateNameTag();
        }

        public void UpgradeLevel()
        {
            level++;
            UpdateNameTag();
        }
    }
}
