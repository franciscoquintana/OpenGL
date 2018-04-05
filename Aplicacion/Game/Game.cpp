//
// Created by fquintana on 5/04/18.
//

#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"

SpriteRenderer *renderer;

GameObject *player;

glm::vec2 PLAYER_SIZE(100, 20);

GLfloat PLAYER_VELOCITY(500.0f);

Game::Game(unsigned int Width, unsigned int Height) : State(GAME_ACTIVE), Width(Width), Height(Height) {}

Game::~Game() {
    delete renderer;
}

void Game::Init()
{
    ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.fs", nullptr, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, (float) this->Width, (float) this->Height, 0.0f, -1.0f, 1.0f);
    Shader spriteShader = ResourceManager::GetShader("sprite");
    spriteShader.Use().SetInteger("image", 0);
    spriteShader.SetMatrix4("projection", projection);

    ResourceManager::LoadTexture("res/ejemplo.png", GL_TRUE, "example");
    ResourceManager::LoadTexture("res/barrita.png", GL_TRUE, "barrita");


    ResourceManager::LoadTexture("res/background.jpg", GL_FALSE, "background");
    ResourceManager::LoadTexture("res/block.png", GL_FALSE, "block");
    ResourceManager::LoadTexture("res/block_solid.png", GL_FALSE, "block_solid");

    // Load levels
    GameLevel one; one.Load("res/levels/one.lvl", this->Width, this->Height * 0.5);
    GameLevel two; two.Load("res/levels/one.lvl", this->Width, this->Height * 0.5);
    GameLevel three; three.Load("res/levels/one.lvl", this->Width, this->Height * 0.5);
    GameLevel four; four.Load("res/levels/one.lvl", this->Width, this->Height * 0.5);
    this->Levels.push_back(one);
    this->Levels.push_back(two);
    this->Levels.push_back(three);
    this->Levels.push_back(four);
    this->Level = 1;


    glm::vec2 playerPos = glm::vec2(
            this->Width / 2 - PLAYER_SIZE.x / 2,
            this->Height - PLAYER_SIZE.y
    );
    player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::GetTexture("barrita"));

    renderer = new SpriteRenderer(spriteShader);

}

void Game::Render()
{
    if(this->State == GAME_ACTIVE)
    {
        renderer->DrawSprite(ResourceManager::GetTexture("background"),
                             glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f
        );


        this->Levels[this->Level].Draw(*renderer);
    }
    renderer->DrawSprite(ResourceManager::GetTexture("example"), glm::vec2(200, 200), glm::vec2(171, 206), 0.0f);
    player->Draw(*renderer);
}