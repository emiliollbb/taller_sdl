#include "JEngine.hpp"

#ifndef JUEGO_HPP
#define JUEGO_HPP

class Juego: public JEngine {
    private:
    protected:
    public:
        Juego(void);
        ~Juego(void);
        void render_game(void);
        void update_game(void); 
};



#endif
