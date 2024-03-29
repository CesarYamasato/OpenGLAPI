#ifndef OPENGLAPI_SHADER
#define OPENGLAPI_SHADER

#include <Shader.h>

namespace OpenGLAPI{ namespace ShaderComponent{

class Component{
    public:
    virtual ~Component() {}
    virtual void Draw(float x, float y,float sizex,float sizey) const = 0;
    Component(Shader * shader);
    Component(const char * vertex_path, const char * fragment_path);

    private:
    Shader * shader;
};

class ConcreteComponent : public Component{
    public:
    
    virtual void Draw(float x, float y,float sizex,float sizey) const override;
};

class Decorator : public Component{
    protected:
    Component * component;

    public:
    Decorator(Component* shaderComponent, Shader * shader);
    Decorator(Component* shaderComponent, const char * vertex_path, const char * fragment_path);

};

};} //namespace OpenGLAPI::ShaderComponent
#endif