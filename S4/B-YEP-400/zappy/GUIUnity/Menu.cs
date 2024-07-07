/*
 * EPITECH PROJECT, 2024
 * Zappy
 * File description:
 * Menu
 */

using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System;
using TMPro;
using UnityEngine.SceneManagement;
using UnityEngine;


namespace Zappy {
    public class Menu : MonoBehaviour {
        public TMP_InputField host;
        public TMP_InputField port;
        private readonly int MIN_PORT = 1024;
        private readonly int MAX_PORT = 65535;
        private int portNumber;
        private readonly int BUFFER_SIZE = 2048;
        private Socket socket;
        private readonly string errorIconName = "Error";
        private bool isConnected = false;
        public int width;
        public int height;
        public int timeUnit;
        public Animator transition;
        public GameObject splashScreen;
        private Animator splashScreenAnimator;

        void OnEnable()
        {
            if (splashScreenAnimator == null && !splashScreen.TryGetComponent<Animator>(out splashScreenAnimator)) {
                return;
            }
            splashScreen.SetActive(true);
            splashScreenAnimator.SetTrigger("Connect");
        }

        private void Awake()
        {
            DontDestroyOnLoad(transform.gameObject);
        }

        private void Start()
        {
            if (PlayerPrefs.HasKey("Host") && PlayerPrefs.HasKey("Port")) {
                host.text = PlayerPrefs.GetString("Host");
                port.text = PlayerPrefs.GetInt("Port").ToString();
            }
        }

        public async void OnConnectButtonClick()
        {
            if (isConnected) {
                ToastNotification.Show("Already connected to the server", errorIconName);
                return;
            }
            if (!IsValidHost(host.text)) {
                ToastNotification.Show("Invalid port number. Please enter a number between 1024 and 65535.", errorIconName);
                return;
            }
            if (!IsValidPort(port.text)) {
                ToastNotification.Show("Invalid host. Please enter 'localhost' or a valid IP address or domain name.", errorIconName);
                return;
            }
            PlayerPrefs.SetString("Host", host.text);
            PlayerPrefs.SetInt("Port", portNumber);
            PlayerPrefs.Save();
            await ConnectAsync();
        }

        private bool IsValidHost(string host)
        {
            return host == "localhost" || Uri.CheckHostName(host) != UriHostNameType.Unknown;
        }

        private bool IsValidPort(string port)
        {
            return int.TryParse(port, out portNumber) && portNumber >= MIN_PORT && portNumber <= MAX_PORT;
        }

        public async Task ConnectAsync()
        {
            try {
                socket = new(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                await socket.ConnectAsync(host.text, portNumber);
                if (await ReceiveMessageAsync() != "WELCOME\n") {
                    throw new SocketException();
                }
                await SendMessageAsync("GRAPHIC");
                (width, height, timeUnit) = await ParseMessageAsync();
                PlayerPrefs.SetInt("Width", width);
                PlayerPrefs.SetInt("Height", height);
                PlayerPrefs.SetInt("TimeUnit", timeUnit);
                PlayerPrefs.Save();
                isConnected = true;
                transition.SetTrigger("Start");
                AsyncOperation asyncOperation = SceneManager.LoadSceneAsync("Game");
                asyncOperation.allowSceneActivation = false;
                float startTime = Time.realtimeSinceStartup;
                while (Time.realtimeSinceStartup - startTime < 1.5f && !asyncOperation.isDone) {
                    await Task.Delay(100);
                }
                asyncOperation.allowSceneActivation = true;
            } catch (SocketException) {
                ToastNotification.Show($"Échec de la connexion au serveur", errorIconName);
            }
        }

        public async Task<(int X, int Y, int T)> ParseMessageAsync()
        {
            string message = await ReceiveMessageAsync();
            string[] parts = message.Split(new[] {' ', '\n'}, StringSplitOptions.RemoveEmptyEntries);

            if (parts.Length < 5 || parts[0] != "msz" || parts[3] != "sgt") {
                throw new SocketException();
            }
            if (!int.TryParse(parts[1], out int X) || !int.TryParse(parts[2], out int Y) || !int.TryParse(parts[4], out int T)) {
                throw new SocketException();
            }
            return (X, Y, T);
        }

        public Task SendMessageAsync(string message)
        {
            try {
                byte[] msg = Encoding.UTF8.GetBytes(message + "\n");
                return socket.SendAsync(msg, SocketFlags.None);
            } catch (SocketException) {
                socket.Close();
                return Task.CompletedTask;
            }
        }
        
        public async Task<string> ReceiveMessageAsync()
        {
            MemoryStream memoryStream = new();
            byte[] buffer = new byte[BUFFER_SIZE];
        
            while (true) {
                try {
                    int bytesRead = await socket.ReceiveAsync(new ArraySegment<byte>(buffer), SocketFlags.None);
                    if (bytesRead == 0) {
                        throw new SocketException();
                    }
                    await memoryStream.WriteAsync(buffer, 0, bytesRead);
                    if (bytesRead < BUFFER_SIZE) {
                        break;
                    }
                } catch (SocketException ex) when (ex.SocketErrorCode == SocketError.WouldBlock) {
                    continue;
                }
            }
            return Encoding.UTF8.GetString(memoryStream.ToArray());
        }
    }
}
