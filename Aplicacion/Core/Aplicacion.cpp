//
// Created by fquintana on 4/04/18.
//

#include "Aplicacion.h"
#include "../Game/Game.h"
Game *game;

Aplicacion::Aplicacion(unsigned int Width, unsigned int Height, char *Name) : Width(Width), Height(Height),
                                                                              Name(Name) {
    window = createWindow(Width, Height, Name);
    game = new Game(Width, Height);
}

GLfloat deltaTime;
GLfloat lastFrame;

void Aplicacion::run() {
    game->Init();
    while (!glfwWindowShouldClose(window)) {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        game->Render();

        glfwSwapBuffers(window);
    }
    //Exit
    glfwTerminate();
}

Aplicacion::~Aplicacion() {

}

GLFWwindow *Aplicacion::getWindow() const {
    return window;
}
