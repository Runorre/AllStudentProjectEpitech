/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * Log
 */

using TMPro;
using UnityEngine;
using UnityEngine.Assertions;
using System.Collections.Generic;

namespace Zappy {
    public class Log : MonoBehaviour {
        private bool isActive = false;
        private static Log instance;
        public Animator animator;
        public GameObject content;
        public GameObject log;
        public Transform logTextPrefab;
        private readonly Queue<Transform> logMessages = new();
        private const int maxLogCount = 10;

        public static Log Instance {
            get {
                Assert.IsNotNull(instance, "The static variable for Instance has not been set. Did you do this call before Awake()?");
                return instance;
            }
        }

        protected void Awake()
        {
            Assert.IsNull(instance, "Instance was not null. Do you maybe have several Log in your scene, all trying to be singletons?");
            instance = this;
        }

        private void Start()
        {
            animator = log.GetComponent<Animator>();
            log.SetActive(true);
            log.GetComponent<CanvasGroup>().alpha = 0;
        }

        public void AddLog(string message, Color color)
        {
            if (!isActive) {
                animator.Play("Window In");
                isActive = true;
            }
            if (logMessages.Count >= maxLogCount) {
                Transform oldestLog = logMessages.Dequeue();
                Destroy(oldestLog.gameObject);
            }
            Transform textObjectTransform = Instantiate(logTextPrefab, content.transform, false);
            TMP_Text newText = textObjectTransform.GetComponent<TMP_Text>();
            newText.text = message;
            newText.color = color;
            logMessages.Enqueue(textObjectTransform);
        }
    }
}
