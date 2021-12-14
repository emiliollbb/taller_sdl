#include <iostream>
#include <string>
#include "game.hpp"
#include "jengine.hpp"

Juego::Juego() {
    x=0;
    y=0;
    vx=0;
    vy=0;
    sheet_y=202;
    flip_h=SDL_FLIP_NONE;
}

Juego::~Juego() {
}

void Juego::render_game(){
    SDL_Rect sdl_rect_origin, sdl_rect_target;
    // Render background
    SDL_RenderCopy(sdl_renderer, texture_background.texture, NULL, NULL);
    
    // Render player
    sdl_rect_origin.x=0;
    sdl_rect_origin.y=sheet_y;
    sdl_rect_origin.w=16;
    sdl_rect_origin.h=23;
    
    sdl_rect_target.x=x;
    sdl_rect_target.y=y;
    sdl_rect_target.w=16*2;
    sdl_rect_target.h=23*2;
    SDL_RenderCopyEx(sdl_renderer, texture_sprites.texture, &sdl_rect_origin,  &sdl_rect_target, 0.0, NULL, flip_h);
}

void Juego::update_game() {
    x+=vx;
    y+=vy;
}

void Juego::load_media() {
    this->load_texture(&texture_background, "background.png");
    this->load_texture(&texture_sprites, "sprites.png");
}

void Juego::close_media() {
    SDL_DestroyTexture(texture_background.texture);
    SDL_DestroyTexture(texture_sprites.texture);
}

void Juego::process_input(SDL_Event *e) {
}
