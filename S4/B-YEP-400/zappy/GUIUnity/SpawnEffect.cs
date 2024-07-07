/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * SpawnEffect
 */

using UnityEngine;

namespace Zappy {
    public class SpawnEffect : MonoBehaviour {
        private ParticleSystem ps;

        private void Start()
        {
            ps = GetComponentInChildren<ParticleSystem>();
            if (ps.isPlaying) {
                ps.Stop();
            }
        }

        public void StartParticles()
        {
            if (ps == null) {
                return;
            }
            if (ps.isPlaying) {
                ps.Stop();
            }
            ps.Play();
        }

        public void StopParticles()
        {
            if (ps == null) {
                return;
            }
            ps.Stop();
        }
    }
}
