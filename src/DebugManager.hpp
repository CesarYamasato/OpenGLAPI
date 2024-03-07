#ifndef OPENGLAPI_DEBUGMANAGER
#define OPENGLAPI_DEBUGMANAGER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace OpenGLAPI{
//Classe responsável por ativar e desativar mensagens de debug

    class DebugManager
    {
        public:

        static DebugManager * getDebugManager();

        void DisableDebug();

        void EnableDebug();

        private:

        DebugManager();
    };
}
#endif