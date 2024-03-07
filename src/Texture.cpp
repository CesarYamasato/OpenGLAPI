#include "Texture.hpp"

    //////////////////////////////////////////////////////////////////////////////////////////////
    //TexturaClass                                                                              //
    //////////////////////////////////////////////////////////////////////////////////////////////
    //Classe para texturas
    OpenGLAPI::Texture::Texture(unsigned int Height,unsigned int Width, GLenum WrapParams_S, GLenum WrapParams_T, GLenum MagParams, GLenum MinParams, unsigned char* data)
    {  

        glGenTextures(1,&textureID);
        glBindTexture(GL_TEXTURE_2D,textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, WrapParams_S);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, WrapParams_T);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MinParams);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MagParams);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        this->Height = Height;
        this->Width = Width;

        glBindTexture(GL_TEXTURE_2D, 0);

        Data = data;
    }
    
    OpenGLAPI::Texture::operator GLuint(){
        return textureID;
    }

    void OpenGLAPI::Texture::bind(){
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    unsigned int OpenGLAPI::Texture::getID(){
        return textureID;
    }

    unsigned int OpenGLAPI::Texture::getHeight(){
        return Height;
    }

    unsigned int OpenGLAPI::Texture::getWidth(){
        return Width;
    }