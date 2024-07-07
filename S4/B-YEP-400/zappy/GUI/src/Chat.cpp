/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Chat
*/

#include "../includes/Chat.hpp"

Chat::Chat()
{
    ::TTF_Init();
    mFont = ::TTF_OpenFont("GUI/assets/font.ttf", 18);
}

void Chat::addMessage(const string &message)
{
    mMessages.push_back(message);
    if (mMessages.size() > 20) {
        mMessages.erase(mMessages.begin());
    }
}

void Chat::render(SDL_Renderer *const renderer)
{
    const size_t messageCount = mMessages.size();

    for (size_t i = 0; i < messageCount; i++) {
        SDL_Surface *const surfaceMessage = ::TTF_RenderText_Solid(mFont, mMessages[i].c_str(), mTextColor);
        SDL_Texture *const message = ::SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect messageRect;
        messageRect.x = mChatBox.x;
        messageRect.y = (mChatBox.y + mChatBox.h) - (((static_cast<int>(messageCount) - static_cast<int>(i)) + 1) * 24);
        messageRect.w = surfaceMessage->w;
        messageRect.h = surfaceMessage->h;
        ::SDL_RenderCopy(renderer, message, nullptr, &messageRect);
        ::SDL_FreeSurface(surfaceMessage);
        ::SDL_DestroyTexture(message);
    }
    if (mCurrentMessage == "ENTER789") {
        addMessage(mLastMessage);
        mCurrentMessage = " ";
        mLastMessage = " ";
    }
    if (!mCurrentMessage.empty()) {
        SDL_Surface *const surfaceMessage = ::TTF_RenderText_Solid(mFont, mCurrentMessage.c_str(), mTextColor);
        SDL_Texture *const message = ::SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect messageRect;
        messageRect.x = mChatBox.x;
        messageRect.y = (mChatBox.y + mChatBox.h) - 24;
        messageRect.w = surfaceMessage->w;
        messageRect.h = surfaceMessage->h;
        ::SDL_RenderCopy(renderer, message, nullptr, &messageRect);
        ::SDL_FreeSurface(surfaceMessage);
        ::SDL_DestroyTexture(message);
    }
}

void Chat::setCurrentMessage(const string &message)
{
    mLastMessage = mCurrentMessage;
    mCurrentMessage = message;
}

string Chat::getCurrentMessage() const
{
    return mCurrentMessage;
}
