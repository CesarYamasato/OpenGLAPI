#ifndef OPENGLAPI_TEXTURE
#define OPENGLAPI_TEXTURE

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OpenGLAPI{
//Classe para texturas
    class Texture 
    {
        public:
        Texture(unsigned int Height,unsigned int Width, GLenum WrapParams_S = GL_REPEAT, GLenum WrapParams_T = GL_REPEAT, GLenum MagParams = GL_LINEAR, GLenum MinParams = GL_LINEAR, unsigned char* data = NULL);
        
        operator GLuint();

        void bind();

        unsigned int getID();

        unsigned int getHeight();

        unsigned int getWidth();
        
        private:
        unsigned int textureID;
        unsigned int Height;
        unsigned int Width;
        unsigned char* Data;
    };
}
#endif