/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * UIrotator
 */

using UnityEngine;

namespace Zappy {
    public class UIrotator : MonoBehaviour {
        private Transform trans;
        private Vector3 offset = new(0f, 180f, 0f);

        void Start()
        {
            trans = GameObject.Find("Main Camera").GetComponent<Transform>();
        }

        void Update()
        {
            transform.LookAt(trans);
            transform.Rotate(offset);
        }
    }
}
