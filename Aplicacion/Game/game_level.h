//
// Created by fquintana on 5/04/18.
//

#ifndef APLICACION_GAME_LEVEL_H
#define APLICACION_GAME_LEVEL_H


#include <vector>
#include "game_object.h"
#include "../Utils/resource_manager.h"

class GameLevel
{
public:
    std::vector<GameObject> Bricks;

    GameLevel() { }
    // Loads level from file
    void Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight);
    // Render level
    void Draw(SpriteRenderer &renderer);
    // Check if the level is completed (all non-solid tiles are destroyed)
    GLboolean IsCompleted();
private:
    // Initialize level from tile data
    void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
};


#endif //APLICACION_GAME_LEVEL_H
