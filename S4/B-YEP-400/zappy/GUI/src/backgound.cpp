/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** backgound
*/

#include "../includes/Background.hpp"

Background::Background(SDL_Renderer *const renderer)
{
    mObjectTexture = ::IMG_LoadTexture(renderer, "GUI/assets/ore.png");
    mFoodTexture = ::IMG_LoadTexture(renderer, "GUI/assets/food.png");
}

vector<string> Background::split(const string &s, const char delimiter) const
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Background::setBackground(const string &path, SDL_Renderer *const renderer, const size_t x, const size_t y)
{
    SDL_Surface *const surface = ::IMG_Load(path.c_str());
    if (surface == nullptr) {
        return;
    }
    SDL_Texture *const texture = ::SDL_CreateTextureFromSurface(renderer, surface);
    ::SDL_FreeSurface(surface);
    while (mTextures.size() <= y) {
        mTextures.emplace_back();
    }
    while (mTextures[y].size() <= x) {
        mTextures[y].push_back(nullptr);
    }
    mTextures[y][x] = texture;
}

vector<vector<SDL_Texture *>> Background::getTextures() const
{
    return mTextures;
}

void Background::getBackgroundObjects(const string &command)
{
    vector<string> words = split(command, ' ');
    try {
        const size_t x = std::stoul(words[1]);
        const size_t y = std::stoul(words[2]);
        vector<int> objects;
        for (size_t i = 3; i < 10; i++) {
            objects.push_back(stoi(words[i]));
        }
        mBackgroundObjects[x][y] = objects;
    } catch (const invalid_argument &ia) {
        cerr << "Invalid argument: " << ia.what() << '\n';
    } catch (const out_of_range &oor) {
        cerr << "Out of range: " << oor.what() << '\n';
    }
}

vector<vector<vector<int>>> Background::getObject() const
{
    return mBackgroundObjects;
}

vector<SDL_Rect> Background::getRects() const
{
    return mRects;
}

SDL_Texture *Background::getObjectTexture(const int i) const
{
    if (i == 0) {
        return mFoodTexture;
    }
    return mObjectTexture;
}

vector<int> Background::getNumberObjects()
{
    const auto numObjectsSize = mNumberObjects.size();

    for (size_t i = 0; i < numObjectsSize; i++) {
        mNumberObjects[i] = 0;
        for (const auto &bgObjects : mBackgroundObjects) {
            for (const auto &obj : bgObjects) {
                mNumberObjects[i] += obj[i];
            }
        }
    }
    return mNumberObjects;
}
