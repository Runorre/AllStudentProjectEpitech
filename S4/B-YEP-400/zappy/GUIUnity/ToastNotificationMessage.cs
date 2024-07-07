/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * ToastNotificationMessage
 */

using UnityEngine;

namespace Zappy {
    public class ToastNotificationMessage : MonoBehaviour
    {
        public float messageTime;
        private float timeElapsed;

        void Start()
        {
            messageTime = messageTime <= -1 ? ToastNotification.minimumMessageTime : messageTime;
        }

        void FixedUpdate()
        {
            if (ToastNotification.isStoped) {
                return;
            }
            if (Mathf.Abs(messageTime) > Mathf.Epsilon) {
                if (timeElapsed > messageTime) {
                    if (ToastNotification.isCanvasGroup) {
                        ToastNotification.isHiding = true;
                    } else {
                        ToastNotification.Hide();
                    }
                }
                timeElapsed += Time.deltaTime;
            }
        }
    }
}
