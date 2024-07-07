/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * ToastNotification
 */

using TMPro;
using UnityEngine;

namespace Zappy {
    public class ToastNotification : MonoBehaviour {
        private readonly float _minimumMessageTime = 3;
        private static Transform messagePrefab;
        private static Transform toastNotification;
        public Transform _messagePrefab;
        public Vector2 _margin = new(20, 20);
        public static Vector2 margin;
        public static bool isCanvasGroup = false;
        public static bool isHiding = false;
        public static bool isStoped = false;
        public static float minimumMessageTime = 3;

        void Awake()
        {
            messagePrefab = _messagePrefab;
            toastNotification = transform;
            minimumMessageTime = _minimumMessageTime;
            margin = _margin;
            SetupToastNotificationObject();

            static void SetupToastNotificationObject()
            {
                if (toastNotification.GetComponent<CanvasGroup>()) {
                    isCanvasGroup = true;
                }
                toastNotification.GetComponent<RectTransform>().anchorMin = new Vector2(0, 0);
                toastNotification.GetComponent<RectTransform>().anchorMax = new Vector2(0, 0);
                toastNotification.GetComponent<RectTransform>().pivot = new Vector2(0, 0);
            }

        }

        private void FixedUpdate()
        {
            if (!isCanvasGroup) {
                return;
            }
            if (isHiding) {
                toastNotification.GetComponent<CanvasGroup>().alpha -= 0.08f;
                if (toastNotification.GetComponent<CanvasGroup>().alpha < 0.01f) {
                    Hide();
                    isHiding = false;
                }
            } else if (toastNotification.GetComponent<CanvasGroup>().alpha < 1) {
                toastNotification.GetComponent<CanvasGroup>().alpha += 0.05f;
            }
        }

        public static void Show(string messageText)
        {
            Show(messageText, "");
        }

        public static void Show(string messageText, string iconName)
        {
            Hide();
            Transform message = Instantiate(messagePrefab, toastNotification);
            message.gameObject.SetActive(true);
            message.name = "Message";
            if (isCanvasGroup) {
                toastNotification.GetComponent<CanvasGroup>().alpha = 0;
            }
            TextMeshProUGUI text = message.Find("Text").GetComponent<TextMeshProUGUI>();
            UnityEngine.UI.Image background = message.Find("Background").GetComponent<UnityEngine.UI.Image>();
            Transform icons = message.Find("Icons");
            UnityEngine.UI.Image selectedIcon;
            Vector2 backgroundSize = background.GetComponent<RectTransform>().sizeDelta;
            RectTransform parentRect = toastNotification.GetComponent<RectTransform>();
            SetText();
            SetMessageIcon();
            SetupInvokeMessage();
            ResetToastNoticationPosition();
            SetMessagePositionOnScreen();

            void SetText()
            {
                text.text = messageText;
                text.alignment = TextAlignmentOptions.MidlineLeft;
            }

            void SetMessageIcon()
            {
                if (iconName != "") {
                    selectedIcon = icons.Find(iconName).transform.GetComponent<UnityEngine.UI.Image>();
                    selectedIcon.enabled = true;
                } else {
                    float iconSize = icons.GetChild(0).GetComponent<RectTransform>().sizeDelta.x;
                    backgroundSize = new Vector2( backgroundSize.x - iconSize - iconSize / 2 , backgroundSize.y);
                    background.GetComponent<RectTransform>().sizeDelta = backgroundSize;
                    Vector2 newAnchor = background.GetComponent<RectTransform>().anchoredPosition;
                    newAnchor = new Vector2(newAnchor.x - iconSize, newAnchor.y);
                    toastNotification.GetComponent<RectTransform>().anchoredPosition = newAnchor;
                    text.GetComponent<RectTransform>().sizeDelta *= 0.90f ;
                    text.GetComponent<RectTransform>().anchoredPosition = Vector2.zero;
                }
            }

            void SetupInvokeMessage()
            {
                ToastNotificationMessage toastNotificationMessage = message.GetComponent<ToastNotificationMessage>();
                toastNotificationMessage.messageTime = minimumMessageTime;
            }

            void ResetToastNoticationPosition()
            {
                parentRect.anchoredPosition = Vector3.zero;
                message.GetComponent<RectTransform>().sizeDelta = backgroundSize;
                parentRect.sizeDelta = backgroundSize;
            }

            void SetMessagePositionOnScreen()
            {
                RectTransform parentRect = toastNotification.GetComponent<RectTransform>();
                Vector2 backgroundSize = background.GetComponent<RectTransform>().sizeDelta;
                parentRect.anchorMax = new Vector2(0.5f, 1);
                parentRect.anchorMin = new Vector2(0.5f, 1);
                parentRect.anchoredPosition = new Vector2(-backgroundSize.x / 2, -backgroundSize.y - margin.y);
            }

        }

        public static void Hide()
        {
            if (toastNotification.childCount <= 0) {
                return;
            }
            for (int i = 0; i < toastNotification.childCount; i++) {
                if (toastNotification.GetChild(i).gameObject.activeSelf) {
                    Destroy(toastNotification.GetChild(i).gameObject);
                }
            }
        }
    }
}
