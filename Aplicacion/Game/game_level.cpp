//
// Created by fquintana on 5/04/18.
//

#include <fstream>
#include <sstream>
#include "game_level.h"



void GameLevel::Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight)
{
    // Clear old data
    this->Bricks.clear();
    // Load from file
    GLuint tileCode;
    GameLevel level;

    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<GLuint>> brickData;

    if (fstream)
    {
        while (std::getline(fstream, line))
        {
            std::istringstream sstream(line);
            std::vector<GLuint> row;
            while (sstream >> tileCode)
                row.push_back(tileCode);
            brickData.push_back(row);
        }
        if (brickData.size() > 0)
            this->init(brickData, levelWidth, levelHeight);
    }
}

void GameLevel::init(std::vector<std::vector<GLuint>> tileData, GLuint lvlWidth, GLuint lvlHeight)
{
    // Calculate dimensions
    GLuint height = tileData.size();
    GLuint width = tileData[0].size();
    GLfloat unit_width = lvlWidth / static_cast<GLfloat>(width);
    GLfloat unit_height = lvlHeight / height;
    // Initialize level tiles based on tileData
    for (GLuint y = 0; y < height; ++y)
    {
        for (GLuint x = 0; x < width; ++x)
        {
            // Check block type from level data (2D level array)
            if (tileData[y][x] == 1) // Solid
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                GameObject obj(pos, size,
                               ResourceManager::GetTexture("block_solid"),
                               glm::vec3(0.8f, 0.8f, 0.7f)
                );
                obj.IsSolid = GL_TRUE;
                this->Bricks.push_back(obj);
            }
            else if (tileData[y][x] > 1)
            {
                glm::vec3 color = glm::vec3(1.0f); // original: white
                if (tileData[y][x] == 2)
                    color = glm::vec3(0.4f, 0.6f, 1.0f);
                else if (tileData[y][x] == 3)
                    color = glm::vec3(0.0f, 0.3f, 0.0f);
                else if (tileData[y][x] == 4)
                    color = glm::vec3(0.4f, 0.7f, 0.6f);
                else if (tileData[y][x] == 5)
                    color = glm::vec3(3.0f, 1.2f, 4.0f);

                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                this->Bricks.push_back(
                        GameObject(pos, size, ResourceManager::GetTexture("block"), color)
                );
            }
        }
    }
}

void GameLevel::Draw(SpriteRenderer &renderer)
{
    for (GameObject &brick : this->Bricks)
        if (!brick.Destroyed)
            brick.Draw(renderer);
}

GLboolean GameLevel::IsCompleted()
{
    for (GameObject &brick : this->Bricks)
        if (!brick.IsSolid && !brick.Destroyed)
            return GL_FALSE;
    return GL_TRUE;
}
