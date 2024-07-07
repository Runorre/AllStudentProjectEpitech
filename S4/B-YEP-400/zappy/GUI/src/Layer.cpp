/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Layer
*/

#include "../includes/Layer.hpp"
#include "../includes/Characters.hpp"

void Layer::displayInfo()
{
    int i = 0;
    const SDL_Color color = {255, 255, 255, 255};
    string text = "Food: " + to_string(mBackground.getNumberObjects()[0]);
    SDL_Surface *surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    SDL_Texture *texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    SDL_Rect rect;
    rect.x = 1500;
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Linemate: " + to_string(mBackground.getNumberObjects()[1]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Deraumere: " + to_string(mBackground.getNumberObjects()[2]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Sibur: " + to_string(mBackground.getNumberObjects()[3]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Mendiane: " + to_string(mBackground.getNumberObjects()[4]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Phiras: " + to_string(mBackground.getNumberObjects()[5]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Thystame: " + to_string(mBackground.getNumberObjects()[6]);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Player dead: " + to_string(nNbrPlayerDead);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    for (const auto &[teamName, players] : mPlayers) {
        string teamInfo = teamName + " (" + to_string(players.size()) + ") : ";
        bool done = false;
        size_t index = 0;
        while (!done) {
            done = true;
            int sum = 0;
            for (const auto &player : players) {
                vector<int> numbers = player.getInventory();
                if (index < numbers.size()) {
                    sum += numbers[index];
                    done = false;
                }
            }
            if (!done) {
                teamInfo += to_string(sum) + " ";
            }
            index++;
        }
        SDL_Surface *const surface2 = ::TTF_RenderText_Solid(mFont, teamInfo.c_str(), color);
        SDL_Texture *const texture2 = ::SDL_CreateTextureFromSurface(mRenderer, surface2);
        rect.x = 1500;
        rect.y = ((i++) * 24) + 72;
        rect.w = surface2->w;
        rect.h = surface2->h;
        ::SDL_RenderCopy(mRenderer, texture2, nullptr, &rect);
        ::SDL_FreeSurface(surface2);
        ::SDL_DestroyTexture(texture2);
    }
}

bool Layer::isPointInRect(const int x, const int y, const SDL_Rect &rect) const
{
    return (x >= rect.x) && (x <= (rect.x + rect.w)) && (y >= rect.y) && (y <= (rect.y + rect.h));
}

void Layer::handleClick(const int mouseX, const int mouseY)
{
    const size_t texturesSize = mBackground.getTextures().size();

    for (const auto &[playerKey, charactersList] : mPlayers) {
        for (const auto &characters : charactersList) {
            if (isPointInRect(mouseX, mouseY, characters.getTextRect()) && characters.getIsSelected()) {
                displayParcelInfo(mLastPos[0], mLastPos[1]);
                displayParcelInfo(characters);
                return;
            }
        }
    }
    for (size_t i = 0; i < texturesSize; i++) {
        const size_t innerTexturesSize = mBackground.getTextures()[i].size();
        for (size_t j = 0; j < innerTexturesSize; j++) {
            const SDL_Rect rect = mRectMap[i][j];
            if ((mouseX >= rect.x) && (mouseX <= (rect.x + rect.w)) &&
                (mouseY >= rect.y) && (mouseY <= (rect.y + rect.h))) {
                mLastPos = {static_cast<int>(i), static_cast<int>(j)};
                displayParcelInfo(static_cast<int>(i), static_cast<int>(j));
                return;
            }
        }
    }
}

void Layer::displayParcelInfo(const Characters &character)
{
    int i = 0;
    const SDL_Color color = {255, 255, 255, 255};
    const int posX = character.getX();
    const int posY = character.getY();
    const int level = character.getLevel();
    const string name = "Player" + to_string(character.getNumber());
    string text = name + " (" + to_string(posX) + ", " + to_string(posY) + ")";
    SDL_Surface* surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    SDL_Texture *texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    SDL_Rect rect;
    rect.x = 200;
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Level " + to_string(level);
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "Inventory: ";
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Food: " + to_string(character.getFood());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Linemate: " + to_string(character.getLinemate());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Deraumere: " + to_string(character.getDeraumere());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Sibur: " + to_string(character.getSibur());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Mendiane: " + to_string(character.getMendiane());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Phiras: " + to_string(character.getPhiras());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);
    text = "    Thystame: " + to_string(character.getThystame());
    surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
    texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    rect.y = (i++) * 24;
    rect.w = surface->w;
    rect.h = surface->h;
    ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
    ::SDL_FreeSurface(surface);
    ::SDL_DestroyTexture(texture);

}

void Layer::displayParcelInfo(const int x, const int y)
{
    int i = 0;
    const size_t objectSize = mBackground.getObject()[x][y].size();
    for (; i < static_cast<int>(objectSize); i++) {
        const SDL_Color color = {255, 255, 255, 255};
        const string text = mObjectName[i] + to_string(mBackground.getObject()[x][y][i]);
        SDL_Surface *const surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
        SDL_Texture *const texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
        SDL_Rect rect;
        rect.x = 0;
        rect.y = i * 24;
        rect.w = surface->w;
        rect.h = surface->h;
        ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
        ::SDL_FreeSurface(surface);
        ::SDL_DestroyTexture(texture);
    }
    if (mPlayers.empty()) {
        return;
    }
    for (auto &[playerKey, charactersList] : mPlayers) {
        const SDL_Color color = {255, 255, 255, 255};
        const string text = playerKey + ": ";
        SDL_Surface *const surface = ::TTF_RenderText_Solid(mFont, text.c_str(), color);
        SDL_Texture *const texture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
        SDL_Rect rect;
        rect.x = 0;
        rect.y = (i++) * 24;
        rect.w = surface->w;
        rect.h = surface->h;
        ::SDL_RenderCopy(mRenderer, texture, nullptr, &rect);
        ::SDL_FreeSurface(surface);
        ::SDL_DestroyTexture(texture);
        for (auto &characters : charactersList) {
            if ((characters.getX() == x) && (characters.getY() == y)) {
                const string text2 = "    " + string("Player") + to_string(characters.getNumber()) + " (" + to_string(characters.getX()) + ", " + to_string(characters.getY()) + ")";
                SDL_Surface *const surface2 = ::TTF_RenderText_Solid(mFont, text2.c_str(), color);
                SDL_Texture *const texture2 = ::SDL_CreateTextureFromSurface(mRenderer, surface2);
                rect.x = 0;
                rect.y = (i++) * 24;
                rect.w = surface2->w;
                rect.h = surface2->h;
                characters.setTextRect(rect);
                characters.setIsSelected(true);
                ::SDL_RenderCopy(mRenderer, texture2, nullptr, &rect);
                ::SDL_FreeSurface(surface2);
                ::SDL_DestroyTexture(texture2);
            } else {
                characters.setIsSelected(false);
            }
        }
    }
}

Layer::Layer(SDL_Renderer *const renderer) : mRenderer(renderer) , mBackground(renderer)
{
    SDL_Surface *const surface = ::IMG_Load("GUI/assets/Background1.png");
    mBack = ::SDL_CreateTextureFromSurface(renderer, surface);
    ::TTF_Init();
    mFont = ::TTF_OpenFont("GUI/assets/font.ttf", 24);
    ::SDL_FreeSurface(surface);
}

void Layer::printPlayer()
{
    if (mPlayers.empty()) {
        return;
    }
    for (auto &[playerKey, charactersList] : mPlayers) {
        const hash<string> strHash;
        const size_t hashedValue = strHash(playerKey);
        for (auto &characters : charactersList) {
            const auto x = static_cast<size_t>(characters.getX());
            const auto y = static_cast<size_t>(characters.getY());
            if ((x >= mRectMap.size()) || (y >= mRectMap[x].size())) {
                continue;
            }
            SDL_Rect posRect = mRectMap[x][y];
            posRect = {posRect.x + characters.getModifX(), posRect.y + characters.getModifY(), posRect.h, posRect.w};
            SDL_Texture *texture = characters.getTexture();
            if (texture == nullptr) {
                characters.setTexture(mRenderer);
                texture = characters.getTexture();
            }
            if (texture == nullptr) {
                continue;
            }
            ::SDL_SetTextureColorMod(
                texture,
                static_cast<Uint8>(hashedValue % 256),
                static_cast<Uint8>((hashedValue >> 8) % 256),
                static_cast<Uint8>((hashedValue >> 16) % 256)
            );
            SDL_Rect rect = characters.getRect();
            if (characters.getIncantation()) {
                characters.setIncantationX(characters.getIncantationX() + 65);
                if (characters.getIncantationX() >= 440) {
                    characters.setIncantationX(0);
                }
                rect.x = characters.getIncantationX();
            }
            ::SDL_RenderCopy(mRenderer, characters.getTexture(), &rect, &posRect);
        }
    }
}

void Layer::setObject(const int x, const int y)
{
    const int reduction = 70;

    if (mBackground.getObject().empty()) {
        return;
    }
    vector<vector<vector<int>>> objects = mBackground.getObject();
    const size_t objectSize = objects[x][y].size();
    for (size_t i = 0; i != objectSize; i++) {
        SDL_Rect posRect = mRectMap[x][y];
        posRect = {static_cast<int>(posRect.x + (10 * i)), static_cast<int>(posRect.y + (10 * i)), posRect.h - reduction , posRect.w - reduction};
        const SDL_Rect rect = mBackground.getRects()[i];
        ::SDL_RenderCopy(mRenderer, mBackground.getObjectTexture(objects[x][y][i]), &rect, &posRect);
    }
}

void Layer::printBackground()
{
    const size_t texturesSize = mBackground.getTextures().size();

    for (size_t i = 0; i < texturesSize; i++) {
        const size_t innerTexturesSize = mBackground.getTextures()[i].size();
        for (size_t j = 0; j < innerTexturesSize; j++) {
            const SDL_Rect rectSprite = mRectSprites[i][j];
            const SDL_Rect rect = mRectMap[i][j];
            ::SDL_RenderCopy(mRenderer, mBackground.getTextures()[i][j], &rectSprite, &rect);
            setObject(static_cast<int>(i), static_cast<int>(j));
        }
    }
}

void Layer::printAll()
{
    ::SDL_RenderClear(mRenderer);
    ::SDL_RenderCopy(mRenderer, mBack, nullptr, nullptr);
    printBackground();
    printPlayer();
    mChat.render(mRenderer);
    displayInfo();
    handleClick(0, 0);
}

map<string, vector<Characters>> Layer::getPlayers() const
{
    return mPlayers;
}

void Layer::setMap(const size_t sizeMapX, const size_t sizeMapY, SDL_Window *const window)
{
    mRectMap = vector<vector<SDL_Rect>>(sizeMapY, vector<SDL_Rect>(sizeMapX));
    mRectSprites = vector<vector<SDL_Rect>>(sizeMapY, vector<SDL_Rect>(sizeMapX));
    int width = 0;
    int height = 0;
    ::SDL_GetWindowSize(window, &width, &height);
    const size_t mapWidth = sizeMapX * 100;
    const size_t mapHeight = sizeMapY * 100;
    const SDL_Rect square1 = {0, 0, 28, 30};
    const SDL_Rect square2 = {31, 0, 28, 32};
    const SDL_Rect square3 = {63, 0, 28, 32};
    const SDL_Rect square4 = {95, 0, 28, 32};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0,3);

    for (size_t i = 0; i < sizeMapX; i++) {
        for (size_t j = 0; j < sizeMapY; j++) {
            mBackground.setBackground("GUI/assets/Object.png", mRenderer, i, j);
            const size_t x = ((i * 100) - (mapWidth / 2)) + (width / 2);
            size_t y = ((j * 100) - (mapHeight / 2)) + (height / 2);
            y -= 30;
            const SDL_Rect rect = {static_cast<int>(x), static_cast<int>(y), 100, 100};
            mRectMap[i][j] = rect;
            const int randomNumber = dis(gen);
            SDL_Rect selectedSquare;
            if (randomNumber == 0) {
                selectedSquare = square1;
            } else if (randomNumber == 1) {
                selectedSquare = square2;
            } else if (randomNumber == 2) {
                selectedSquare = square3;
            } else {
                selectedSquare = square4;
            }
            mRectSprites[i][j] = selectedSquare;
        }
    }
}

void Layer::getBackgroundObjects(const string &command)
{
    mBackground.getBackgroundObjects(command);
}

void Layer::addMessage(const int id, const string &message)
{
    const string name = "Player" + to_string(id);
    string team;
    for (const auto &[team2, charactersList] : mPlayers) {
        for (const auto &characters : charactersList) {
            if (characters.getNumber() == id) {
                team = team2;
            }
        }
    }
    const string fullMessage = name + " (" + team + "): " + message;
    mChat.addMessage(fullMessage);
}

void Layer::setCurrentMessage(const string &message)
{
    mChat.setCurrentMessage(message);
}

string Layer::getCurrentMessage() const
{
    return mChat.getCurrentMessage();
}

void Layer::setEggs(vector<Egg> const &eggs)
{
    mEggs = eggs;
}

void Layer::printEggs()
{
    for (const auto &egg : mEggs) {
        SDL_Rect posRect = mRectMap[egg.getX()][egg.getY()];
        posRect = {posRect.x + 30, posRect.y + 30, posRect.h - 50 , posRect.w - 50};
        const SDL_Rect rect = mBackground.getRects()[0];
        ::SDL_RenderCopy(mRenderer, egg.getTexture(), &rect, &posRect);
    }
}

vector<Egg> Layer::getEggs() const
{
    return mEggs;
}

SDL_Renderer *Layer::getRenderer()
{
    return mRenderer;
}

void Layer::addCharacter(const Characters &character, const string &team)
{
    mPlayers[team].push_back(character);
    std::ranges::sort(mPlayers[team], [](const Characters &a, const Characters &b) {
        return a.getModifY() < b.getModifY();
    });
}

void Layer::moveCharacter(const int id, const int x, const int y, const int orientation)
{
    for (auto &[playerKey, charactersList] : mPlayers) {
        for (auto &characters : charactersList) {
            if (characters.getNumber() == id) {
                characters.setX(x);
                characters.setY(y);
                characters.setOrientation(orientation);
            }
        }
    }
}

void Layer::updateInventory(const int id, const int food, const int linemate, const int deraumere, const int sibur, const int mendiane, const int phiras, const int thystame)
{
    for (auto &[playerKey, charactersList] : mPlayers) {
        for (auto &characters : charactersList) {
            if (characters.getNumber() == id) {
                characters.setFood(food);
                characters.setLinemate(linemate);
                characters.setDeraumere(deraumere);
                characters.setSibur(sibur);
                characters.setMendiane(mendiane);
                characters.setPhiras(phiras);
                characters.setThystame(thystame);
            }
        }
    }
}

void Layer::startIncantation(const int id)
{
    for (auto &[playerKey, charactersList] : mPlayers) {
        for (auto &characters : charactersList) {
            if (characters.getNumber() == id) {
                characters.setIncantation(true);
            }
        }
    }
}

void Layer::stopIncantation(const int x, const int y)
{
    for (auto &[playerKey, charactersList] : mPlayers) {
        for (auto &characters : charactersList) {
            if ((characters.getX() == x) && (characters.getY() == y)) {
                characters.setIncantation(false);
            }
        }
    }
}

void Layer::updateLevel(const int id, const int level)
{
    for (auto &[playerKey, charactersList] : mPlayers) {
        for (auto &characters : charactersList) {
            if (characters.getNumber() == id) {
                characters.setLevel(level);
            }
        }
    }
}

void Layer::deletePlayer(const int id)
{
    for (auto &[playerKey, characters] : mPlayers) {
        const auto it = std::remove_if(characters.begin(), characters.end(), [id](const Characters &character) {
            return character.getNumber() == id;
        });
        if (it != characters.end()) {
            nNbrPlayerDead++;
            characters.erase(it, characters.end());
        }
    }
}
