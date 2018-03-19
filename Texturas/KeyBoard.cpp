//
// Created by fquintana on 19/03/18.
//
#include <GLFW/glfw3.h>
#include "KeyBoard.h"

KeyBoard::KeyBoard(GLFWwindow *win) {
    window = win;
}

KeyState KeyBoard::getKeyState(int Key) {
    return Keys[Key];
}

void KeyBoard::updateKey(int Key, int action) {
    KeyState actual, nuevo;
    if(Keys.find(Key) != Keys.end())
        actual = Keys[Key];
    else
        actual = RELEASED;

    switch (action) {
        case GLFW_PRESS:
            if (actual != PRESSED)
                nuevo = PRESSONCE;
            else
                nuevo = PRESSED;
            break;
        case GLFW_RELEASE:
            if (actual != RELEASED)
                nuevo = RELEASEDONCE;
            else
                nuevo = RELEASED;
            break;
        case GLFW_REPEAT:
            nuevo = PRESSED;
    }

    Keys[Key] = nuevo;

}