#include "../include/SDL.hpp"

void printOptions(SDL_Renderer* renderer, TTF_Font* font, const std::vector<std::string>& libgraphs, const std::vector<std::string>& libgames, const std::vector<std::vector<std::string>>& scores, int selectedOptionIndex) {
    SDL_Color textColor = {255, 255, 255, 255};

    // Afficher libgraphs dans le rectangle gauche
    for (size_t i = 0; i < libgraphs.size(); ++i) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, ("Choose a graphical library: " + libgraphs[i]).c_str(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect = {115, 450 + i * 40, surface->w, surface->h}; // Ajustez la position x et y pour le rectangle gauche
        SDL_RenderCopy(renderer, texture, NULL, &textRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    // Afficher libgames dans le rectangle droit
    for (size_t i = 0; i < libgames.size(); ++i) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, ("Choose a game library: " + libgames[i]).c_str(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect = {1425, 450 + i * 40, surface->w, surface->h}; // Ajustez la position x et y pour le rectangle droit
        SDL_RenderCopy(renderer, texture, NULL, &textRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    // Afficher scores dans le rectangle du bas
    for (size_t i = 0; i < scores.size(); ++i) {
        for (size_t j = 0; j < scores[i].size(); j += 2) {
            SDL_Surface* surface = TTF_RenderText_Solid(font, ("Score: " + scores[i][j] + " " + scores[i][j + 1]).c_str(), textColor);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect = {650, 750 + i * 40, surface->w, surface->h}; // Ajustez la position x et y pour le rectangle du bas
            SDL_RenderCopy(renderer, texture, NULL, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }
}

void createRectangles(SDL_Renderer* renderer) {
    SDL_Rect leftRect = {100, 400, 400, 400}; // Rectangle à gauche de la fenêtre
    SDL_Rect rightRect = {1400, 400, 400, 400}; // Rectangle à droite de la fenêtre
    SDL_Rect bottomRect = {580, 700, 750, 300}; // Rectangle en bas de la fenêtre

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Couleur blanche
    SDL_RenderDrawRect(renderer, &leftRect); // Dessiner le rectangle à gauche
    SDL_RenderDrawRect(renderer, &rightRect); // Dessiner le rectangle à droite
    SDL_RenderDrawRect(renderer, &bottomRect); // Dessiner le rectangle en bas
}

void SDL::determineSelectedLibraryAndGame(int x, int y, std::vector<std::string> libgraphs, std::vector<std::string> libgames) {
    int baseX = 113;
    int baseY = 450;

    for (size_t i = 0; i < libgraphs.size(); i++) {
        if (x >= baseX && x<= baseX + (84 * libgraphs[i].size()) && y >= baseY + (40 * i) && y <= baseY + (40 * (i + 1)))
            graphical = i;

    }
    baseX = 1400;
    baseY = 450;

    for (size_t i = 0; i < libgames.size(); i++) {
        if (x >= baseX && x<= baseX + (84 * libgames[i].size()) && y >= baseY + (40 * i) && y <= baseY + (40 * (i + 1)))
            game = i;
    }
    // if (x >= 1427 && x <= 1762 && y >= 455 && y <= 471) {
    //     selectedGame = "PACMAN";
    //     this->game = 0;
    // } else if (x >= 1429 && x <= 1763 && y >= 496 && y <= 511) {
    //     selectedGame = "SNAKE";    
    //     this->game = 1;
    // }
}

void SDL::handleEvents(SDL_Event &event, bool &running, bool &nameVisible, bool &typingText, std::string &userInput, SDL_Rect &rect,
                  std::vector<std::string> libgraphs, std::vector<std::string> libgames, bool &startAvailable) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = false;
        else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            int mouseX = event.button.x;
            int mouseY = event.button.y;
            std::cout << "Clicked at position: (" << mouseX << ", " << mouseY << ")" << std::endl;
        
            determineSelectedLibraryAndGame(mouseX, mouseY, libgraphs, libgames);

            if (startAvailable && mouseX >= 925 && mouseX <= 993 && mouseY >= 267 && mouseY <= 283) {
                running = false;
            }
        
            if (mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h) {
                nameVisible = false;
                typingText = true;
            }
        }
        else if (event.type == SDL_TEXTINPUT && typingText) {
            userInput += event.text.text;
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_RETURN) {
                typingText = false;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE && typingText && !userInput.empty()) {
                userInput.pop_back();
            }
        }
    }
    if (graphical != -1 && game != -1) {
        startAvailable = true;
    } else {
        startAvailable = false;
    }
}

void SDL::renderText(SDL_Renderer* renderer, TTF_Font* font, bool nameVisible, std::string userInput, SDL_Rect rect) {
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface* surface = nullptr;
    if (nameVisible) {
        surface = TTF_RenderText_Solid(font, "NAME", textColor);
    } else if (!userInput.empty()) {
        surface = TTF_RenderText_Solid(font, userInput.c_str(), textColor);
    }

    // Vérifiez si surface est nullptr avant de procéder
    if (surface != nullptr) {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect textRect;
        textRect.x = rect.x + (rect.w - surface->w) / 2;
        textRect.y = rect.y + (rect.h - surface->h) / 2;
        textRect.w = surface->w;
        textRect.h = surface->h;
        SDL_RenderCopy(renderer, texture, nullptr, &textRect);
        SDL_DestroyTexture(texture);
    }

    SDL_FreeSurface(surface); // Libère la surface même si elle est nullptr
}

void SDL::initializeSDL(SDL_Window* &window, SDL_Renderer* &renderer, TTF_Font* &font) {
    if (TTF_Init() == -1) {
        SDL_Log("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }
    window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("./lib/graphicals/assets/Graphical/arial.ttf", 24);
    if (font == nullptr) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }
}

void SDL::cleanupSDL(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font) {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void SDL::menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    SDL_Rect rect;

    bool running = true;
    bool nameVisible = true;
    bool typingText = false;
    int selectedOptionIndex = 0;
    std::string userInput = "";
    
    // Variables pour stocker les sélections
    std::string selectedLibrary = "";
    std::string selectedGame = "";

    // Variable pour vérifier si START est disponible
    bool startAvailable = false;

    initializeSDL(window, renderer, font);
    
    // Obtenir les dimensions de la fenêtre
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    
    while (running) {
        SDL_Event event;
        handleEvents(event, running, nameVisible, typingText, userInput, rect, libgraphs, libgames, startAvailable);
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        printOptions(renderer, font, libgraphs, libgames, scores, selectedOptionIndex);
        createRectangles(renderer);
        rect.w = 200;
        rect.h = 100;
        rect.x = (1920 - rect.w) / 2;
        rect.y = (1080 - rect.h) / 2;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect);
        
        renderText(renderer, font, nameVisible, userInput, rect);

        // Affichage de "START" si disponible
        if (startAvailable) {
            // Dessiner "START" au milieu vers le haut de la fenêtre
            SDL_Color textColor = {255, 255, 255, 255}; // Blanc
            SDL_Surface* surface = TTF_RenderText_Solid(font, "START", textColor);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

            int textWidth = surface->w;
            int textHeight = surface->h;

            int x = (windowWidth - textWidth) / 2;
            int y = (windowHeight - textHeight) / 4;

            SDL_Rect textRect = {x, y, textWidth, textHeight};
            SDL_RenderCopy(renderer, texture, NULL, &textRect);

            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
        
        SDL_RenderPresent(renderer);
    }
    
    cleanupSDL(window, renderer, font);
}

std::string SDL::getNamePlayer()
{
    return this->username;
}

int SDL::selectLibGraphic()
{
    return this->graphical;
}

int SDL::selectLibGame()
{
    return this->game;
}

KeyEvent SDL::handlekeyevent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return CLOSE;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                case SDLK_z:
                    return UP;
                case SDLK_DOWN:
                case SDLK_s:
                    return DOWN;
                case SDLK_LEFT:
                case SDLK_q:
                    return LEFT;
                case SDLK_RIGHT:
                case SDLK_d:
                    return RIGHT;
                case SDLK_BACKSPACE:
                    return CONFIRM;
                case SDLK_SPACE:
                    return PAUSE;
                case SDLK_m:
                    return NEXTLIB;
                case SDLK_n:
                    return NEXTGAME;
                case SDLK_r:
                    return RESET;
                case SDLK_ESCAPE:
                    return CLOSE;
                default:
                    return NONE;
            }
        }
    }
}

void SDL::showStaticbackground(std::vector<std::vector<std::string>> mapdecor)
{
    for (int i = 0; i < mapdecor.size(); i++) {
        for (int j = 0; j < mapdecor[i].size(); j++) {
            if (mapdecor[i][j] == "2") {
                SDL_Rect rectangle = {j * 20, i * 20, 20, 20};
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(renderer, &rectangle);
            } else if (mapdecor[i][j] == "1") {
                SDL_Rect rectangle = {j * 20, i * 20, 20, 20};
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rectangle);
            }
        }
    }
}


void SDL::showDynamicAssets(std::vector<IObject> assets) 
{
    for (int i = 0; i < assets.size(); i++) {
        if (assets[i].path != "5" && assets[i].path != "10") {
            SDL_Texture* texture = IMG_LoadTexture(renderer, assets[i].path.c_str()); // Load texture using IMG_LoadTexture function
            SDL_Rect rectangle = {assets[i].x * 20, assets[i].y * 20, assets[i].rect[2], assets[i].rect[3]};
            SDL_Rect frameRect = {assets[i].rect[0], assets[i].rect[1], assets[i].rect[2], assets[i].rect[3]};
            SDL_RenderCopy(renderer, texture, &frameRect, &rectangle); // Render texture using SDL_RenderCopy function
        }
        else if (assets[i].path == "5") {
            SDL_Rect rectangle = {assets[i].x * 20 + 5, assets[i].y * 20 + 5, 5, 5};
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rectangle);
        }
        else if (assets[i].path == "10") {
            SDL_Rect rectangle = {assets[i].x * 20 + 5, assets[i].y * 20 + 5, 10, 10};
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rectangle);
        }
    }
}

void SDL::showScore(int score)
{
    TTF_Font* font = TTF_OpenFont("./lib/graphicals/assets/Graphical/font.ttf", 20);
    if (font == NULL)
        std::cout << "je suis Font :)" << SDL_GetError() << std::endl;
    std::string scoreString = "Score: " + std::to_string(score);
    std::cout << scoreString << std::endl;
    SDL_Surface *surface = TTF_RenderText_Solid(font, scoreString.c_str(), {0, 0, 0});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {0, 0, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void SDL::init_windows(int height, int wight)
{
    this->window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wight, height, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    frameTimer = SDL_GetTicks();
}
void SDL::reset_windows()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void SDL::display()
{
    SDL_RenderPresent(renderer);
}

void SDL::clear()
{
    frameTimer = SDL_GetTicks();
    SDL_RenderClear(renderer);
    if (SDL_GetTicks() - frameTimer < 1000 / 30)
        SDL_Delay(1000 / 30 - (SDL_GetTicks() - frameTimer));
}

SDL::~SDL() {}

extern "C" IGraphlib *instanceGraph()
{
    return new SDL();
}