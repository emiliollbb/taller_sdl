#include <iostream>
#include <string>
#include "game.hpp"
#include "jengine.hpp"

Juego::Juego() {
}

Juego::~Juego() {
}

void Juego::render_game(){ 
    //cout <<"Render game" <<endl;
    // Render background
    SDL_RenderCopy(sdl_renderer, texture_background.texture, NULL, NULL);
}

void Juego::update_game() {
    //cout <<"Update game" <<endl;
}

void Juego::load_media() {
    this->load_texture(&texture_background, "background.png");    
}

void Juego::close_media()
{
    cout << "close media" <<endl;
  // Destroy background texture
  SDL_DestroyTexture(texture_background.texture);
}
