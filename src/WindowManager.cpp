#include "WindowManager.hpp"

//TODO: Implement

//Window manager pointer initialiation
WindowManager * WindowManager::manager = nullptr;


WindowManager* WindowManager::getWindowManager(){
    bool getWindowManager_was_not_called = !WindowManager::manager;
    if(getWindowManager_was_not_called) WindowManager::manager = new WindowManager();
    else return WindowManager::manager;
}

void WindowManager::add(){

}

void WindowManager::update(float delta_time){

}

WindowManager::~WindowManager(){

}

void WindowManager::deleteWindow(std::list<Window*>::iterator &Window){

}


WindowManager::WindowManager(){
    
}

