#include "Window.hpp"
#include <list>


//TODO: add threaded window support

//Standart singleton implementation, only one pointer to the manager may exist at a time
class WindowManager{
    public:
    //Returns the single pointer of the manager that must exist
    static WindowManager * getWindowManager();

    //Funcions to add Windows o the windows manager list
    void add();

    //TODO: decide on arguments
    //Iterate through the list of Windows, calling Update on each one and removing windows that should close from the list
    void update(float delta_time);

    //Delete all the Windows in the list 
    virtual ~WindowManager();

    private:
    //This pointer will be instantiated as a nullptr at first and will hold the Window Manager once the first getWindowManager call is made
    static WindowManager * manager;

    //The list is used to iterate through the windows, updating them (checking if it should close, handling input and render calls)
    std::list<Window*> windows;

    //Function that is called by the Manager to remove a window (Merely auxiliary)
    void deleteWindow(std::list<Window*>::iterator &Window);

    WindowManager();
};