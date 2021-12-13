#include <iostream>
#include <string>
#include "game.hpp"
#include "jengine.hpp"

Juego::Juego() {
    x=0;
    y=0;
}

Juego::~Juego() {
}

void Juego::render_game(){ 
    SDL_Rect sdl_rect_origin, sdl_rect_target;
    // Render background
    SDL_RenderCopy(sdl_renderer, texture_background.texture, NULL, NULL);
    
    // Render player
    sdl_rect_origin.x=0;
    sdl_rect_origin.y=0;
    sdl_rect_origin.w=18;
    sdl_rect_origin.h=35;
    
    sdl_rect_target.x=x;
    sdl_rect_target.y=y;
    sdl_rect_target.w=18;
    sdl_rect_target.h=35;
    SDL_RendererFlip flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(sdl_renderer, texture_sprites.texture, &sdl_rect_origin,  &sdl_rect_target, 0.0, NULL, flip);
}

void Juego::update_game() {
    x+=vx;
    y+=vy;
}

void Juego::load_media() {
    this->load_texture(&texture_background, "background.png");
    this->load_texture(&texture_sprites, "sprites.png");
}

void Juego::close_media()
{
    cout << "close media" <<endl;
  // Destroy background texture
  SDL_DestroyTexture(texture_background.texture);
}
