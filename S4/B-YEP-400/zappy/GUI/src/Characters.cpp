/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Characters
*/

#include "../includes/Characters.hpp"

Characters::Characters(const int number, const int x, const int y, const int orientation, const int level)
    : mNumber(number), mX(x), mY(y), mOrientation(orientation), mLevel(level) {}

void Characters::setTexture(SDL_Renderer *const mRenderer)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution disY(-50,20);
    uniform_int_distribution disX(-30,30);
    SDL_Surface *const surface = ::IMG_Load("GUI/assets/characters.png");
    if (surface == nullptr) {
        return;
    }
    mModifX = disX(gen);
    mModifY = disY(gen);
    mTexture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    if (mTexture == nullptr) {
        return;
    }
    ::SDL_FreeSurface(surface);
}

SDL_Texture *Characters::getTexture() const
{
    return mTexture;
}

int Characters::getNumber() const
{
    return mNumber;
}

int Characters::getX() const
{
    return mX;
}

int Characters::getY() const
{
    return mY;
}

int Characters::getOrientation() const
{
    return mOrientation;
}

int Characters::getLevel() const
{
    return mLevel;
}

SDL_Rect Characters::getRect() const
{
    const auto orientation = static_cast<size_t>(mOrientation);
    if ((mRects.empty()) || (orientation < 1) || (orientation > mRects.size())) {
        return SDL_Rect();
    }
    SDL_Rect rect = mRects[orientation - 1];
    if ((rect.x < 0) || (rect.y < 0) || (rect.w < 0) || (rect.h < 0)) {
        return SDL_Rect();
    }
    return rect;
}

void Characters::setX(const int x)
{
    mX = x;
}

void Characters::setY(const int y)
{
    mY = y;
}

void Characters::setOrientation(const int orientation)
{
    assert(orientation >= 1 && static_cast<size_t>(orientation) <= mRects.size());
    mOrientation = orientation;
}

int Characters::getModifX() const
{
    return mModifX;
}

int Characters::getModifY() const
{
    return mModifY;
}

void Characters::setTextRect(const SDL_Rect textRect)
{
    mTextRect = textRect;
}

SDL_Rect Characters::getTextRect() const
{
    return mTextRect;
}

void Characters::setIsSelected(const bool isSelected)
{
    mIsSelected = isSelected;
}

bool Characters::getIsSelected() const
{
    return mIsSelected;
}

void Characters::setFood(const int food)
{
    mFood = food;
}

void Characters::setLinemate(const int linemate)
{
    mLinemate = linemate;
}

void Characters::setDeraumere(const int deraumere)
{
    mDeraumere = deraumere;
}

void Characters::setSibur(const int sibur)
{
    mSibur = sibur;
}

void Characters::setMendiane(const int mendiane)
{
    mMendiane = mendiane;
}

void Characters::setPhiras(const int phiras)
{
    mPhiras = phiras;
}

void Characters::setThystame(const int thystame)
{
    mThystame = thystame;
}

int Characters::getFood() const
{
    return mFood;
}

int Characters::getLinemate() const
{
    return mLinemate;
}

int Characters::getDeraumere() const
{
    return mDeraumere;
}

int Characters::getSibur() const
{
    return mSibur;
}

int Characters::getMendiane() const
{
    return mMendiane;
}

int Characters::getPhiras() const
{
    return mPhiras;
}

int Characters::getThystame() const
{
    return mThystame;
}

void Characters::setIncantation(const bool incantation)
{
    mIncantation = incantation;
}

bool Characters::getIncantation() const
{
    return mIncantation;
}

void Characters::setIncantationX(const int incantationX)
{
    mIncantationX = incantationX;
}

int Characters::getIncantationX() const
{
    return mIncantationX;
}

void Characters::setLevel(const int level)
{
    mLevel = level;
}

vector<int> Characters::getInventory() const
{
    return {mFood, mLinemate, mDeraumere, mSibur, mMendiane, mPhiras, mThystame};
}
