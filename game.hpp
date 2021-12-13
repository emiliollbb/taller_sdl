#include "jengine.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Juego: public JEngine {
    private:
        // Textura fondo
        struct sized_texture texture_background;
        struct sized_texture texture_sprites;
        int vx, vy, x, y;
    protected:
    public:
        Juego(void);
        ~Juego(void);
        void render_game(void);
        void update_game(void);
        void load_media(void);
        void close_media(void);
};



#endif
