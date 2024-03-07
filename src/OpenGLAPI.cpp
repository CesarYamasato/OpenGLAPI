
#include "OpenGLAPI.hpp"

using namespace OpenGLAPI;
    void APIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

    GLFWwindow * OpenGLAPI::window;

    int OpenGLAPI::libInit(int SCR_WIDTH, int SCR_HEIGHT, const char* name, void framebuffer_size_callback(GLFWwindow* window, int width, int height)){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        OpenGLAPI::window  = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, name, NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return 0;
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
        glfwSwapInterval(1);
        return 1;
    }

    void* OpenGLAPI::initGlad(const char * name){
        return (void*) glfwGetProcAddress(name);
    }

    void OpenGLAPI::render(GLFWwindow * window){
        glfwSwapBuffers(OpenGLAPI::window);
        glfwPollEvents();
    }

    int OpenGLAPI::WindowShouldClose(GLFWwindow * window){
        return glfwWindowShouldClose(window);
    }

    void OpenGLAPI::setwindowTitle(const char* title){
        glfwSetWindowTitle(window,title);
    }

    void OpenGLAPI::Terminate(){
        glfwTerminate();
    }

    void OpenGLAPI::setDefaultParams(Shader shader){
            int width,height;
            double resolution[2];
            resolution[0] = width;
            resolution[1] = height;
            
            glfwGetFramebufferSize(OpenGLAPI::window,&width,&height);
            Manager::InputManager * manager = Manager::InputManager::getInputManager();
            shader.setVec4("Mouse", manager->getMouse());
            shader.setFloat("Time", glfwGetTime());
            shader.setVec2("Resolution", resolution);
    }

    //Função responsável por encontrar o path para um determinado diretório a partir do diretório pai
    const char* OpenGLAPI::GetPathTo(const std::string directory){
        std::filesystem::path path = std::filesystem::current_path();
        std::string * parentPath = new std::string(path.parent_path().string());
        std::string * finalPath = new std::string (*parentPath + directory);
        const char * returnPath = ((*finalPath).c_str());
        return returnPath;
    }