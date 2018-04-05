//
// Created by fquintana on 5/04/18.
//

#ifndef APLICACION_GAME_H
#define APLICACION_GAME_H

#include "game_level.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};
class Game {
    GameState State;
    unsigned int Width, Height;
    std::vector<GameLevel> Levels;
    GLuint                 Level;

public:
    Game(unsigned int Width, unsigned int Height);

    virtual ~Game();

    void Init();

    void Render();

};


#endif //APLICACION_GAME_H
