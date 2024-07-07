/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Server
*/

#pragma once

#include "INetwork.hpp"
#include "IProcess.hpp"
#include <algorithm>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

using std::cerr;
using std::endl;
using std::string;
using std::vector;

class Network : public INetwork {
    public:
        Network() = default;
        Network(const string &machine, const int port) : machine(machine), port(port) {}
        ~Network() override;
        [[nodiscard]] int getSockFd() const;
        void connect() override;
    private:
        string machine;
        int port;
        int sockfd = -1;
        [[noreturn]] void close(const string &message) const;
};

class Process : public IProcess {
    public:
        Process() = default;
        explicit Process(const int sockfd) : sockfd(sockfd) {}
        void send_message(const string &message) override;
        string receive_message() const override;
    private:
        int sockfd = -1;
};
