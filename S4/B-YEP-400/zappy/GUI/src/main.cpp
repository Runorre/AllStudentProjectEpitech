/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** main
*/

#include "../includes/Engine.hpp"
#include "../includes/Engine.hpp"
#include "../includes/Manager.hpp"
#include "../includes/Server.hpp"
#include "../includes/Server.hpp"
#include <fstream>
#include <map>
#include <regex>
#include <string>

using std::ifstream;
using std::regex;
using std::invalid_argument;
using std::out_of_range;

map<string, string> getIp()
{
    map<string, string> ips;
    ifstream file("/etc/hosts");
    string line;
    const regex ipRegex(
        "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
        "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
        "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
        "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\b");
    while (getline(file, line)) {
        smatch match;
        if (regex_search(line, match, ipRegex)) {
            const string ip = match.str();
            string hostname = line.substr(line.find(ip) + ip.size());
            hostname = regex_replace(hostname, regex("^\\s+|\\s+$"), "");
            hostname = hostname.substr(0, hostname.find_first_of(" \t"));
            ips[hostname] = ip;
        }
    }

    return ips;
}

int main(int ac, char **av)
{
    if (ac != 5) {
        cerr << "Usage: ./zappy_gui -p port -h machine\n";
        return 84;
    }
    map<string, string> argMap;
    for (int i = 1; i < ac; i += 2) {
        argMap[string(av[i])] = string(av[i+1]);
    }
    if ((argMap.find("-p") == argMap.end()) || (argMap.find("-h") == argMap.end())) {
        cerr << "Usage: ./zappy_gui -p port -h machine\n";
        return 84;
    }
    map<string, string> ipMap = ::getIp();
    int port = 0;
    try {
        port = stoi(argMap["-p"]);
    } catch (const invalid_argument &) {
        cerr << "Invalid argument: Port must be an integer\n";
        return 84;
    } catch (const out_of_range &) {
        cerr << "Out of range: Port number is too large\n";
        return 84;
    }
    string machine = argMap["-h"];
    if (ipMap.find(machine) != ipMap.end()) {
        machine = ipMap[machine];
    } else {
        regex ipRegex(
            "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
            "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
            "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\."
            "(\\b25[0-5]|\\b2[0-4][0-9]|\\b1[0-9]{2}|\\b[1-9]?[0-9]|\\b0)\\b");

        if (!regex_match(machine, ipRegex)) {
            cerr << "Invalid IP address\n";
            return 84;
        }
    }
    Network server(machine, port);
    server.connect();
    Process process(server.getSockFd());
    string message;
    regex rgx("msz (\\d+) (\\d+)");
    smatch matches;
    int val1 = 0;
    int val2 = 0;
    process.send_message("GRAPHIC");
    do {
        message = process.receive_message();
        if (regex_search(message, matches, rgx)) {
            val1 = stoi(matches[1].str());
            val2 = stoi(matches[2].str());
            break;
        }
    } while (true);
    Engine engine;
    Manager manager(process, engine);
    if ((val1 != 10) && (val2 != 10)) {
        cerr << "Invalid map size : must be 10x10\n";
        return 84;
    }
    manager.runLoop(val1, val2);
}
