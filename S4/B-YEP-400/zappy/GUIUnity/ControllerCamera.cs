/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * ControllerCamera
 */

using UnityEngine;

namespace Zappy {
    [RequireComponent(typeof(Camera))]
    public class ControllerCamera : MonoBehaviour {
        private readonly bool focusOnEnable = true;
        private readonly float acceleration = 200;
        private readonly float dampingCoefficient = 5;
        private readonly float lookSensitivity = 1;
        private readonly float verticalRotationLimit = 85f;

        Vector3 velocity;
        float verticalRotation = 0f;

        public bool IsFocused
        {
            get {
                return Cursor.lockState == CursorLockMode.Locked;
            }
            set {
                Cursor.lockState = value ? CursorLockMode.Locked : CursorLockMode.None;
                Cursor.visible = !value;
            }
        }

        void OnEnable()
        {
            if (focusOnEnable) {
                IsFocused = true;
            }
            verticalRotation = 89f;
            transform.localEulerAngles = new Vector3(verticalRotation, -90, 0);
        
        }

        void OnDisable()
        {
            IsFocused = false;
        }

        void Update()
        {
            if (IsFocused) {
                UpdateInput();
            } else if (Input.GetMouseButtonDown(0)) {
                IsFocused = true;
            }
            velocity = Vector3.Lerp(velocity, Vector3.zero, dampingCoefficient * Time.deltaTime);
            transform.position += velocity * Time.deltaTime;
        }

        void UpdateInput()
        {
            velocity += GetAccelerationVector() * Time.deltaTime;
            velocity.y += GetVerticalAccelerationVector().y * Time.deltaTime;
            Vector2 mouseDelta = lookSensitivity * new Vector2(Input.GetAxis("Mouse X"), -Input.GetAxis("Mouse Y"));
            transform.Rotate(Vector3.up, mouseDelta.x, Space.World);
            verticalRotation += mouseDelta.y;
            verticalRotation = Mathf.Clamp(verticalRotation, -verticalRotationLimit, verticalRotationLimit);
            transform.localEulerAngles = new Vector3(verticalRotation, transform.localEulerAngles.y, 0);
            if (Input.GetKeyDown(KeyCode.Escape)) {
                IsFocused = false;
            }
        }

        Vector3 GetAccelerationVector()
        {
            Vector3 moveInput = default;
        
            void AddMovement(KeyCode key, Vector3 dir) {
                if (Input.GetKey(key)) {
                    moveInput += dir;
                }
            }
            AddMovement(KeyCode.W, Vector3.forward);
            AddMovement(KeyCode.A, Vector3.left);
            AddMovement(KeyCode.S, Vector3.back);
            AddMovement(KeyCode.D, Vector3.right);
            Vector3 direction = transform.TransformVector(moveInput.normalized);
            direction.y = 0;
            float sprintFactor = Input.GetKey(KeyCode.LeftControl) ? 2f : 1f;
            return acceleration * sprintFactor * direction;
        }
        
        Vector3 GetVerticalAccelerationVector()
        {
            Vector3 moveInput = default;
        
            void AddMovement(KeyCode key, Vector3 dir) {
                if (Input.GetKey(key)) {
                    moveInput += dir;
                }
            }
            AddMovement(KeyCode.Space, Vector3.up);
            AddMovement(KeyCode.LeftShift, Vector3.down);
            return moveInput * acceleration;
        }
    }
}
