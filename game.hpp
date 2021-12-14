#include "jengine.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Juego: public JEngine {
    private:
    protected:
    public:
        Juego(void);
        ~Juego(void);
        void render_game(void);
        void update_game(void);
        void load_media(void);
        void close_media(void);
        void process_input(SDL_Event *e);
};

#endif
