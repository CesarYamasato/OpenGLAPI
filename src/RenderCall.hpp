#include <list>
#include <glm/glm.hpp>
#include "RenderCallArgs.hpp"
#include "Texture.hpp"
#include "Shader.h"

class RenderCall{
    public:


    //RenderCall constructor takes in whatever type of drawing to be made to call the glDrawArrays function
    //GLenum possible values:  GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES,
    //GL_LINE_STRIP_ADJACENCY, GL_LINES_ADJACENCY, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, 
    //GL_TRIANGLES, GL_TRIANGLE_STRIP_ADJACENCY, GL_TRIANGLES_ADJACENCY and GL_PATCHES
    RenderCall(GLenum mode, GLuint VAO, Shader shader);

    //Function sets the uniform values contained on the uniform_arguments list
    //to the Shader and ultimately calls the glDrawArrays function
    void call();


    //Adds a uniform argument to the list
    void add(RenderCallArgs argument);

    private:
    std::list<RenderCallArgs *> uniform_arguments;
    GLenum mode;
    GLuint VAO;
    Shader shader;
};