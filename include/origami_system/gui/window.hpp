//
//  window.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#ifndef window_hpp
#define window_hpp

#include <string>
#include <imgui.h>

ImVec2 operator+(const ImVec2& v1, const ImVec2& v2);
ImVec2 operator-(const ImVec2& v1, const ImVec2& v2);

class Window
{
public:
    Window() = delete;
    Window(const std::string& caption);
    virtual~Window() = default;
    
    /** 指定した位置にウィンドウを描画する. */
    virtual void render()
    {
        initializeWindow();
        setupContents();
        endWindowSetup();
    }
    
    ImVec2 getMoousePositionOnThisWindow()const;
    
    const std::string& getCaption()const;
    
    virtual ImVec2 getWindowPosition()const = 0;
protected:
    virtual void initializeWindow(const int flag = 0);
    
    virtual void setupContents() = 0;
    
    void endWindowSetup();
    
private:
    std::string m_caption;
};

#endif /* window_hpp */
