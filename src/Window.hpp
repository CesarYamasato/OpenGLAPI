#include <queue>
#include "RenderCall.hpp"



class Window{
    public:

    //Window constructor
    Window(uint window_width, uint window_height, std::string title);

    //Adds a render call to the window
    void addRenderCall(RenderCall * RenderCall);

    //Updates and renders the window
    void update();

    //Sets this window's title
    void setWindowTittle(std::string & title);

    private:
    //window pointer to be used on glfw window related functions
    GLFWwindow* window;

    //Render calls (will be consumed after rendering)
    std::queue<RenderCall*> render_queue;

    //function to be called every udpdate. Will call every render call on the
    //render_queue queue and call glfwSwapBuffers on the window contained in this object.
    //Each RenderCall object will set the uniforms for a shader and call a glDrawArraysFunction
    void render();
};