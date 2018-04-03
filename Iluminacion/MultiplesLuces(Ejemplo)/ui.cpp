//
// Created by fquintana on 1/04/18.
//

#include <imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <cstdio>
#include "ui.h"
#include "main.h"

void printLamps();
char * formatStr(const char* fmt, ...);

void printGui() {

    if(ImGui::TreeNode(formatStr("Lamparas"))) {
        printLamps();
        ImGui::TreePop();
    }

    ImGui::ColorEdit3("Color Fondo", (float*)&clear_color);

    ImGui::Text("Dir Luz");
    ImGui::SliderFloat3("Dir", glm::value_ptr(lightPos), -2.0f, 2.0f);

    ImGui::Separator();
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

}

void printLamps(){
    for (int i = 0; i < NLAMPS; i++) {
        char *temp = formatStr("Lampara %i", i + 1);
        if(ImGui::TreeNode(temp)) {
            ImGui::SliderFloat3("Pos", glm::value_ptr(pointLightPositions[i]), -2.0f, 2.0f);
            ImGui::TreePop();
        }
        free(temp);
    }
}

char * formatStr(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char buff[100];
    vsnprintf(buff, sizeof(buff), fmt, args);
    va_end(args);

    //TODO Descubrir porque sin un malloc no funciona
    int size = strlen(buff);
    char *text = (char *) malloc( (size + 1) * sizeof(char));
    strncpy(text, buff, strlen(buff));
    *(text + size) = '\0';
    return text;
}