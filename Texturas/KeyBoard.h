//
// Created by fquintana on 19/03/18.
//

#ifndef TEXTURAS_KEYBOARD_H
#define TEXTURAS_KEYBOARD_H

#include <map>
enum KeyState {RELEASED, PRESSED, PRESSONCE, RELEASEDONCE};


class KeyBoard {
    std::map<int, KeyState> Keys;
    GLFWwindow *window;
public:
    KeyBoard(GLFWwindow *win);
    KeyState getKeyState(int Key);
    void updateKey(int Key, int action);
};


#endif //TEXTURAS_KEYBOARD_H
