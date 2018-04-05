#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Utils/Shader.h"
#include "stb_image.h"
#include "main.h"
#include "Core/Aplicacion.h"

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;


int main() {

    Aplicacion app(SCR_WIDTH, SCR_HEIGHT, "APP");
    app.run();

    return 0;
}
