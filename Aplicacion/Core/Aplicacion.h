//
// Created by fquintana on 4/04/18.
//

#ifndef APLICACION_APLICACION_H
#define APLICACION_APLICACION_H

#include "Window.h"

class Aplicacion {
public:
    unsigned int Width, Height;
    char *Name;

    GLFWwindow *window;

    Aplicacion(unsigned int Width, unsigned int Height, char *Name);
    virtual ~Aplicacion();

    GLFWwindow *getWindow() const;
    void run();
};


#endif //APLICACION_APLICACION_H
