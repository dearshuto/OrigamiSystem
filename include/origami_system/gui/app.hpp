//
//  app.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#ifndef app_hpp
#define app_hpp

#include <memory>
#include <vector>
#include "origami_system/algorithm/algorithm.hpp"
#include "window.hpp"

struct GLFWwindow;

class App
{
public:
    App() = default;
    ~App() = default;
    
    bool init();
    void mainloop();
    void terminate();
    
    static GLFWwindow* GetMainWindow();
    
    static unsigned int GetDisplayWidth();
    
    static unsigned int GetDisplayHeight();
private:
    void fetchDisplaySize()const;
private:
    std::vector<std::unique_ptr<Window>> m_windows;
    
    static int DisplayWidth;
    
    static int DisplayHeight;
    
private:
    std::unique_ptr<Algorithm> m_algorithm;
};

#endif /* app_hpp */
