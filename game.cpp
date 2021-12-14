#include <iostream>
#include <string>
#include "game.hpp"
#include "jengine.hpp"

Juego::Juego() {
}

Juego::~Juego() {
}

void Juego::render_game(){
    // Render background
    SDL_RenderCopy(sdl_renderer, texture_background.texture, NULL, NULL); 
}

void Juego::update_game() {
}

void Juego::load_media() {
    this->load_texture(&texture_background, "background.png");
}

void Juego::close_media() {
    // Destroy background texture
    SDL_DestroyTexture(texture_background.texture);
}

void Juego::process_input(SDL_Event *e) {
}
