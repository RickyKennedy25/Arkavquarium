#include "Tank.hpp"
#include <map>
#include <iostream>

Tank::Tank(int width, int height) {
    this->width = width;
    this->height = height;

    this->sdlWindow = NULL;
    this->gScreenSurface = NULL;

    this->quit = false;
}

bool Tank::init() {
    bool success = true;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        if (TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        this->sdlWindow = SDL_CreateWindow(
            "ArkavQuarium",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            this->width,
            this->height,
            SDL_WINDOW_SHOWN
        );
        if (this->sdlWindow == NULL) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            this->gScreenSurface = SDL_GetWindowSurface( this->sdlWindow );
        }
    }

    return success;
}

void Tank::close() {
    for (auto const& x : loadedSurfaces) {
        SDL_FreeSurface( x.second );
    }

    for (auto const& x : loadedFontSizes) {
        TTF_CloseFont( x.second );
    }

    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;

    SDL_Quit();
}

SDL_Surface* Tank::loadSurface(std::string path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if ( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

void Tank::draw_image(std::string filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];

    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, this->gScreenSurface, &dest);
}

void Tank::draw_text(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, this->gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

void Tank::clear_screen() {
    SDL_FillRect(this->gScreenSurface, NULL, SDL_MapRGB(this->gScreenSurface->format, 255, 255, 255));
}

void Tank::update_screen() {
    SDL_UpdateWindowSurface(this->sdlWindow);
}

void Tank::handle_input() {
    SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 )
        {
            if ( e.type == SDL_QUIT ) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                std::cout << e.motion.x << "," << e.motion.y << std::endl;
            } else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
                pressedKeys.insert(e.key.keysym.sym);
                tappedKeys.insert(e.key.keysym.sym);
            } else if (e.type == SDL_KEYUP) {
                pressedKeys.erase(e.key.keysym.sym);
            }
        }
}

bool Tank::quit_pressed() {
    return quit;
}

const std::set<SDL_Keycode>& Tank::get_pressed_keys() {
    return pressedKeys;
}

const std::set<SDL_Keycode>& Tank::get_tapped_keys() {
    return tappedKeys;
}
