/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** engine
*/

#include "../includes/Engine.hpp"

void Engine::setNetwork(const Network &network)
{
    mNetwork = network;
}

void Engine::setProcess(const Process &process)
{
    mProcess = process;
}

vector<string> Engine::split(const string &s, const char delimiter) const
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Engine::getTeams(vector<string> &teams)
{
    mProcess.send_message("tna");
    const string command = mProcess.receive_message();
    const vector<string> lines = split(command, '\n');
    for (const auto &line : lines) {
        if (line.substr(0, 3) == "tna") {
            vector<string> words = split(line, ' ');
            teams.push_back(words[1]);
        }
    }
}

void Engine::getSpawPlayer(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    const int x = stoi(words[2]);
    const int y = stoi(words[3]);
    const int orientation = stoi(words[4]);
    const int level = stoi(words[5]);
    const string team = words[6];
    const Characters character(id, x, y, orientation, level);
    mLayer.addCharacter(character, team);
}

void Engine::updateInventory(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    const int food = stoi(words[4]);
    const int linemate = stoi(words[5]);
    const int deraumere = stoi(words[6]);
    const int sibur = stoi(words[7]);
    const int mendiane = stoi(words[8]);
    const int phiras = stoi(words[9]);
    const int thystame = stoi(words[10]);
    mLayer.updateInventory(id, food, linemate, deraumere, sibur, mendiane, phiras, thystame);
}

void Engine::moveCharacter(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    const int x = stoi(words[2]);
    const int y = stoi(words[3]);
    const int orientation = stoi(words[4]);
    mLayer.moveCharacter(id, x, y, orientation);
}

void Engine::startIncantation(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[4]);
    mLayer.startIncantation(id);
}

void Engine::stopIncantation(const string &command)
{
    vector<string> words = split(command, ' ');
    const int x = stoi(words[1]);
    const int y = stoi(words[2]);
    mLayer.stopIncantation(x, y);
}

void Engine::broadcast(const string &command)
{
    istringstream iss(command);
    string token;
    getline(iss, token, ' ');
    getline(iss, token, ' ');
    const int id = stoi(token);
    string message;
    getline(iss, message, ' ');
    mLayer.addMessage(id, message);
}

void Engine::endGame(const string &command)
{
    vector<string> words = split(command, ' ');
    const string team = words[1];
    const string message = "Team " + team + " won the game!";
    cout << message << endl;
    mWindow.destroyWindow();
}

void Engine::levelUp(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    const int level = stoi(words[2]);
    mLayer.updateLevel(id, level);
}

void Engine::deletePlayer(const string &command)
{
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    mLayer.deletePlayer(id);
}

void Engine::getSpawnEgg(const string &command)
{
    vector<Egg> eggs = mLayer.getEggs();
    vector<string> words = split(command, ' ');
    const int id = stoi(words[1]);
    const int x = stoi(words[2]);
    const int y = stoi(words[3]);
    const Egg egg(id, x, y);
    eggs.push_back(egg);
    mLayer.setEggs(eggs);
}

void Engine::selectionAction(const string &command)
{
    if (command.substr(0, 3) == "bct") {
        mLayer.getBackgroundObjects(command);
    } else if (command.substr(0, 3) == "pnw") {
        getSpawPlayer(command);
    } else if (command.substr(0, 3) == "ppo") {
        moveCharacter(command);
    } else if (command.substr(0, 3) == "pin") {
        updateInventory(command);
    } else if (command.substr(0, 3) == "pic") {
        startIncantation(command);
    } else if (command.substr(0, 3) == "pbc") {
        broadcast(command);
    } else if (command.substr(0, 3) == "pie") {
        stopIncantation(command);
    } else if (command.substr(0, 3) == "seg") {
        endGame(command);
    } else if (command.substr(0, 3) == "plv") {
        levelUp(command);
    } else if (command.substr(0, 3) == "pdi") {
        deletePlayer(command);
    } else if (command.substr(0, 3) == "enw") {
        getSpawnEgg(command);
    }
}

void Engine::processMessages()
{
    while (runningThread) {
        const std::scoped_lock lock(mMutex);
        if (mQueue.empty()) {
            continue;
        }
        string message = mQueue.front();
        mQueue.pop();
        message = message.substr(0, message.size() - 1);
        const vector<string> commands = split(message, '\n');
        for (const auto &command : commands) {
            selectionAction(command);
        }
    }
}

void Engine::handleMouseButtonDownEvent(const SDL_Event &event, int &mouseX, int &mouseY) const
{
    if (event.button.button == SDL_BUTTON_LEFT) {
        mouseX = event.button.x;
        mouseY = event.button.y;
    }
}

void Engine::handleKeyDownEvent(const SDL_Event &event, bool &running)
{
    if (event.key.keysym.sym == SDLK_ESCAPE) {
        running = false;
    }
    if (event.key.keysym.sym == SDLK_RETURN) {
        if (mLayer.getCurrentMessage() == "") {
            mLayer.setCurrentMessage(" ");
        }
        const string currentMessage = mLayer.getCurrentMessage();
        const regex pattern("^sst [0-9]+$", regex::icase);
        if (regex_match(currentMessage, pattern)) {
            mProcess.send_message(currentMessage);
        }
        mLayer.setCurrentMessage("ENTER789");
    }
    if (event.key.keysym.sym == SDLK_BACKSPACE) {
        mLayer.setCurrentMessage(mLayer.getCurrentMessage().substr(0, mLayer.getCurrentMessage().size() - 1));
    }
}

void Engine::handleTextInputEvent(const SDL_Event &event)
{
    if (mLayer.getCurrentMessage() == " ") {
        mLayer.setCurrentMessage(mLayer.getCurrentMessage().substr(0, mLayer.getCurrentMessage().size() - 1));
    }
    mLayer.setCurrentMessage(mLayer.getCurrentMessage() + event.text.text);
}

void Engine::runLoop(const size_t sizeMapX, const size_t sizeMapY)
{
    bool running = true;
    int mouseX = 0;
    int mouseY = 0;
    SDL_Event event = {0};
    mLayer.setMap(sizeMapX, sizeMapY, mWindow.getWindow());
    getTeams(mTeams);
    thread process(&Engine::processMessages, this);

    while (running) {
        while (::SDL_PollEvent(&event) == 1) {
            switch (event.type) {
                case SDL_QUIT:
                    ::exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    handleMouseButtonDownEvent(event, mouseX, mouseY);
                    break;
                case SDL_KEYDOWN:
                    handleKeyDownEvent(event, running);
                    break;
                case SDL_TEXTINPUT:
                    handleTextInputEvent(event);
                    break;
                default:
                    break;
            }
        }
        mLayer.printAll();
        if ((mouseX != 0) && (mouseY != 0)) {
            mLayer.handleClick(mouseX, mouseY);
        }
        ::SDL_RenderPresent(mWindow.getRenderer());
    }
    runningThread = false;
    process.join();
}

void Engine::addQueue(const string &command)
{
    mQueue.push(command);
}

mutex &Engine::getMutex()
{
    return mMutex;
}
