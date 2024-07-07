/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Network
*/

#include "../includes/Server.hpp"

Network::~Network()
{
    if (sockfd != -1) {
        ::close(sockfd);
    }
}

void Network::connect()
{
    sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        ::perror("socket");
        ::exit(84);
    }

    sockaddr_in networkAddr;
    ::memset(&networkAddr, 0, sizeof(networkAddr));
    networkAddr.sin_family = AF_INET;

    networkAddr.sin_port = ::htons(static_cast<unsigned short>(port));

    if (::inet_pton(AF_INET, machine.c_str(), &networkAddr.sin_addr) <= 0) {
        ::perror("inet_pton");
        ::exit(84);
    }

    if (::connect(sockfd, reinterpret_cast<struct sockaddr*>(&networkAddr), sizeof(networkAddr)) == -1) {
        ::perror("connect");
        ::exit(84);
    }
}

[[noreturn]] void Network::close(const string &message) const
{
    cerr << message << endl;
    ::close(sockfd);
    ::exit(84);
}

int Network::getSockFd() const
{
    return sockfd;
}

void Process::send_message(const string &message)
{
    const string msg = message + "\n";

    if (::send(sockfd, msg.c_str(), msg.size(), 0) == -1) {
        ::close(sockfd);
    }
}

string Process::receive_message() const
{
    const int BUFFER_SIZE = 2048;
    std::string buffer(BUFFER_SIZE, '\0');
    std::string message;
    ssize_t bytesRead = 0;

    while (true) {
        bytesRead = ::recv(sockfd, &buffer[0], BUFFER_SIZE, 0);
        if (bytesRead <= 0) {
            break;
        }
        message.append(buffer, 0, bytesRead);
        if (bytesRead < BUFFER_SIZE) {
            break;
        }
    }
    return message;
}
