/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * Tile
 */

using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

namespace Zappy {
    public enum ResourceType {
        Food,
        Linemate,
        Deraumere,
        Sibur,
        Mendiane,
        Phiras,
        Thystame
    }

    public class ResourceInstance {
        public GameObject Instance { get; set; }
        public ResourceType Type { get; set; }
        
    }

    public class Tile : MonoBehaviour {
        ControllerCamera controllerCamera;
        private Renderer render;
        private Vector3 rotation;
        private bool isDown = false;
        private bool isIncanting = false;
        private bool isSelected = false;
        private bool isUp = false;
        private int timeUnit;
        public Animator animator;
        public Camera cam;
        public Color highlightColor = Color.green;
        public Color[] originalColors;
        public GameObject tileInformation;
        public List<GameObject> players = new();
        public List<ResourceInstance> ressources = new();
        public TMP_Text CoordinatesText;
        public TMP_Text DeraumereText;
        public TMP_Text FoodText;
        public TMP_Text LinemateText;
        public TMP_Text MendianeText;
        public TMP_Text PhirasText;
        public TMP_Text SiburText;
        public TMP_Text ThystameText;
        public Transform deraumerePrefab;
        public Transform eggPrefab;
        public Transform foodPrefab;
        public Transform linematePrefab;
        public Transform mendianePrefab;
        public Transform phirasPrefab;
        public Transform siburPrefab;
        public Transform thystamePrefab;
        public int x;
        public int y;
        
        private void Start()
        {
            if (PlayerPrefs.HasKey("TimeUnit")) {
                timeUnit = PlayerPrefs.GetInt("TimeUnit");
            }
            cam = Camera.main;
            tileInformation = GameObject.Find("TileInformation");
            animator = tileInformation.GetComponent<Animator>();
            CoordinatesText = GameObject.Find("CoordinatesText").GetComponent<TMP_Text>();
            FoodText = GameObject.Find("FoodText").GetComponent<TMP_Text>();
            LinemateText = GameObject.Find("LinemateText").GetComponent<TMP_Text>();
            DeraumereText = GameObject.Find("DeraumereText").GetComponent<TMP_Text>();
            SiburText = GameObject.Find("SiburText").GetComponent<TMP_Text>();
            MendianeText = GameObject.Find("MendianeText").GetComponent<TMP_Text>();
            PhirasText = GameObject.Find("PhirasText").GetComponent<TMP_Text>();
            ThystameText = GameObject.Find("ThystameText").GetComponent<TMP_Text>();
            controllerCamera = cam.GetComponent<ControllerCamera>();
            render = GetComponent<Renderer>();
            originalColors = new Color[render.materials.Length];
            for (int i = 0; i < render.materials.Length; i++) {
                originalColors[i] = render.materials[i].color;
            }
            rotation = new Vector3(UnityEngine.Random.Range(0f, 1f), UnityEngine.Random.Range(0f, 1f), UnityEngine.Random.Range(0f, 1f));
            animator.Play("Window Out");
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
            CoordinatesText.text = $"X: {x} | Y: {y}";
            FoodText.text = ressources.FindAll(r => r.Type == ResourceType.Food).Count.ToString();
            LinemateText.text = ressources.FindAll(r => r.Type == ResourceType.Linemate).Count.ToString();
            DeraumereText.text = ressources.FindAll(r => r.Type == ResourceType.Deraumere).Count.ToString();
            SiburText.text = ressources.FindAll(r => r.Type == ResourceType.Sibur).Count.ToString();
            MendianeText.text = ressources.FindAll(r => r.Type == ResourceType.Mendiane).Count.ToString();
            PhirasText.text = ressources.FindAll(r => r.Type == ResourceType.Phiras).Count.ToString();
            ThystameText.text = ressources.FindAll(r => r.Type == ResourceType.Thystame).Count.ToString();
            animator.Play("Window In");
        }

        private void Hide()
        {
            animator.Play("Window Out");
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
            if (isIncanting) {
                transform.Rotate(10 * Time.deltaTime * rotation);
            } else {
                transform.Rotate(rotation * Time.deltaTime);
            }
            if (isSelected && Input.GetKeyDown(KeyCode.Escape)) {
                isSelected = false;
                OnMouseExit();
                Hide();
            } else if (isSelected) {
                Display();
            }
        }

        private Transform GetPrefab(ResourceType type)
        {
            return type switch {
                ResourceType.Food => foodPrefab,
                ResourceType.Linemate => linematePrefab,
                ResourceType.Deraumere => deraumerePrefab,
                ResourceType.Sibur => siburPrefab,
                ResourceType.Mendiane => mendianePrefab,
                ResourceType.Phiras => phirasPrefab,
                ResourceType.Thystame => thystamePrefab,
                _ => null,
            };
        }

        public void AddPlayer(GameObject player)
        {
            if (player == null) {
                throw new ArgumentNullException(nameof(player));
            }
            players.Add(player);
            Player playerComponent = player.GetComponent<Player>();
            if (isIncanting) {
                Vector3 newPosition;
                if (isUp) {
                    float heightDifference = 2 - transform.position.y;
                    newPosition = player.transform.position + Vector3.up * heightDifference;
                    StartCoroutine(MoveToPositionPlayer(player.transform, newPosition, playerComponent));
                } else if (isDown) {
                    newPosition = player.transform.position + Vector3.down * transform.position.y;
                    StartCoroutine(MoveToPositionPlayer(player.transform, newPosition, playerComponent));
                }
            }
        }

        public void RemovePlayer(GameObject player)
        {
            if (player == null) {
                throw new ArgumentNullException(nameof(player));
            }
            players.Remove(player);
        }


        public IEnumerator StartIncantation()
        {
            if (isIncanting) {
                yield break;
            }
            isIncanting = true;
            Vector3 upPosition = new(transform.position.x, 2, transform.position.z);
            StartCoroutine(MoveToPositionPlanet(transform, upPosition, 1));
            foreach (GameObject player in players) {
                if (player != null) {
                    Player playerComponent = player.GetComponent<Player>();
                    if (playerComponent != null) {
                        StartCoroutine(MoveToPositionPlayer(player.transform, player.transform.position + Vector3.up * 2, playerComponent));
                    }
                }
            }
            yield return new WaitForSeconds(300f / timeUnit / 2f);
            Vector3 downPosition = new(transform.position.x, 0, transform.position.z);
            StartCoroutine(MoveToPositionPlanet(transform, downPosition, -1));
            foreach (GameObject player in players) {
                if (player != null) {
                    Player playerComponent = player.GetComponent<Player>();
                    if (playerComponent != null) {
                        StartCoroutine(MoveToPositionPlayer(player.transform, player.transform.position + Vector3.down * 2, playerComponent));
                    }
                }
            }
            yield return new WaitForSeconds(300f / timeUnit / 2f);
            isIncanting = false;
        }

        private IEnumerator MoveToPositionPlanet(Transform transform, Vector3 newPosition, int way)
        {
            if (way == 1) {
                isUp = true;
            } else {
                isDown = true;
            }
            Vector3 currentPosition = transform.position;
            float duration = 300f / timeUnit / 2f;
            float time = 0;
        
            while (time < duration) {
                transform.position = Vector3.Lerp(currentPosition, newPosition, time / duration);
                time += Time.deltaTime;
                yield return null;
            }
            transform.position = newPosition;
            if (way == 1) {
                isUp = false;
            } else {
                isDown = false;
            }
        }

        private IEnumerator MoveToPositionPlayer(Transform transform, Vector3 newPosition, Player player)
        {
            if (transform == null || player == null) {
                yield break;
            }
            Vector3 currentPosition = transform.position;
            float duration = 300f / timeUnit / 2f;
            float time = 0;

            while (time < duration) {
                if (player == null || transform == null || player.isMoving) {
                    yield break;
                }
                transform.position = Vector3.Lerp(currentPosition, newPosition, time / duration);
                time += Time.deltaTime;
                yield return null;
            }
            if (transform != null) {
                transform.position = newPosition;
            }
        }

        private void DisplayResource(ResourceType type, int quantity)
        {
            Transform prefab = GetPrefab(type);
            Collider planetCollider = GetComponent<Collider>();
            for (int i = 0; i < quantity; i++)  {
                float latitude = UnityEngine.Random.Range(Mathf.PI / 4, Mathf.PI / 2);
                float longitude = UnityEngine.Random.Range(-Mathf.PI, Mathf.PI);
                float radius = transform.localScale.x / 2;
                Vector3 position = new(
                    radius * Mathf.Cos(latitude) * Mathf.Cos(longitude),
                    radius * Mathf.Sin(latitude),
                    radius * Mathf.Cos(latitude) * Mathf.Sin(longitude)
                );
                position += transform.position;
                Ray ray = new(position + Vector3.up * 1000, Vector3.down);
                if (planetCollider.Raycast(ray, out RaycastHit hit, Mathf.Infinity)) {
                    Vector3 closestPoint = hit.point;
                    Vector3 upDirection = (closestPoint - transform.position).normalized;
                    GameObject instance = Instantiate(prefab, closestPoint, Quaternion.identity, transform).gameObject;
                    instance.transform.localScale /= 4;
                    instance.transform.SetPositionAndRotation(closestPoint, Quaternion.FromToRotation(instance.transform.up, upDirection) * instance.transform.rotation);
                    ressources.Add(new ResourceInstance { Instance = instance, Type = type });
                }
            }
        }

        public GameObject SpawnEgg(int id)
        {
            Collider planetCollider = GetComponent<Collider>();
            float latitude = UnityEngine.Random.Range(Mathf.PI / 4, Mathf.PI / 2);
            float longitude = UnityEngine.Random.Range(-Mathf.PI, Mathf.PI);
            float radius = transform.localScale.x / 2;
            Vector3 position = new(
                radius * Mathf.Cos(latitude) * Mathf.Cos(longitude),
                radius * Mathf.Sin(latitude),
                radius * Mathf.Cos(latitude) * Mathf.Sin(longitude)
            );
            position += transform.position;
            Ray ray = new(position + Vector3.up * 1000, Vector3.down);
            if (planetCollider.Raycast(ray, out RaycastHit hit, Mathf.Infinity)) {
                Vector3 closestPoint = hit.point;
                Vector3 upDirection = (closestPoint - transform.position).normalized;
                Transform instance = Instantiate(eggPrefab, closestPoint, Quaternion.identity, transform);
                instance.transform.localScale /= 4;
                instance.gameObject.name = $"Egg {id}";
                instance.SetPositionAndRotation(closestPoint, Quaternion.FromToRotation(instance.up, upDirection) * instance.rotation);
                return instance.gameObject;
            }
            return null;
        }

        private void RemoveResource(ResourceType type, int quantity)
        {
            for (int i = ressources.Count - 1; i >= 0 && quantity > 0; i--) {
                if (ressources[i].Type == type) {
                    GameObject instance = ressources[i].Instance;
                    ressources.RemoveAt(i);
                    Destroy(instance);
                    quantity--;
                }
            }
        }

        public void UpdateResource(ResourceType type, int newquantity) {
            int quantity = ressources.FindAll(r => r.Type == type).Count;
            if (quantity < newquantity) {
                DisplayResource(type, newquantity - quantity);
            } else if (quantity > newquantity) {
                RemoveResource(type, quantity - newquantity);
            }
        }
    }
}
