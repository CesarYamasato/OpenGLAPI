#ifndef OPENGLAPI_HPP
#define OPENGLAPI_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <filesystem>

#include "common.hpp"
#include "InputManager.hpp"
#include "DebugManager.hpp"
#include "SpriteRenderer.hpp"
#include "Shader.h"
#include "TextureComponent.hpp"
#include "Texture.hpp"
#include "Window.hpp"
#include "animator.hpp"


namespace OpenGLAPI{

    ////////////////////////////////////////////////////////////////////////
    enum class RENDER_TYPE {RECTANGLE, CIRCLE, TRIANGLE};


    typedef struct{
        int red,blue,green;
    }Color4bpp;
    
    typedef struct{
        Color4bpp RED;
        Color4bpp GREEN;
        Color4bpp BLUE;
        Color4bpp YELLOW;
        Color4bpp MAGENTA;
        Color4bpp CYAN;
        Color4bpp GRAY;
        Color4bpp BLACK;
        Color4bpp WHITE;
    }COLORS;

    const COLORS colors =
    {
        .RED = (Color4bpp) {255,0,0},
        .GREEN = (Color4bpp) {0,255,0},
        .BLUE = (Color4bpp) {0,0,255},
        .YELLOW = (Color4bpp) {255,255,0},
        .MAGENTA = (Color4bpp) {255,0,131},
        .CYAN = (Color4bpp) {0,255,255},
        .GRAY = (Color4bpp) {127,127,127},
        .BLACK = (Color4bpp) {0,0,0},
        .WHITE = (Color4bpp) {255,255,255},
    };


    int WindowShouldClose(GLFWwindow * window);

    int libInit(int SCR_WIDTH, int SCR_HEIGHT, const char* name,void framebuffer_size_callback(GLFWwindow* window, int width, int height));

    void* initGlad(const char * name);

    void render(GLFWwindow * window);

    void setwindowTitle(const char* title);

    void Terminate();

    void setDefaultParams(Shader shader);

    void setKeyCallBackFunction(void * keyCallback(GLFWwindow*, int , int, int, int));
    
    //Função responsável por encontrar o path para um determinado diretório a partir do diretório pai
    const char* GetPathTo(std::string directory);
}
#endif