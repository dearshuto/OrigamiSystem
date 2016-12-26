//
//  main.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//


#include <iostream>
#include "origami_system/gui/app.hpp"

int main(int argc, char** argv)
{
    App app;
    
    if (!app.init())
    {
        std::cout << "Cannot initialize me." << std::endl;
        app.terminate();
    }
    
    app.mainloop();
    app.terminate();
    
    return 0;
}
