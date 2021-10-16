#include "JEngine.hpp"

#ifndef JUEGO_HPP
#define JUEGO_HPP

class Juego: public JEngine {
    private:
        // Textura fondo
        struct sized_texture texture_background;
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
