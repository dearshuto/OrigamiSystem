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
#include <memory>
#include <vector>
#include <imgui.h>
#include "shape.hpp"

/// ウィンドウの中で描画されるウィンドウ
class Window
{
public:
    Window() = delete;
    Window(const std::string& caption);
    virtual~Window() = default;
    
    virtual void init() = 0;
    
    /** 指定した位置にウィンドウを描画する. */
    void render();
    
    ImVec2 getMoousePositionOnThisWindow()const;
    
    const std::string& getCaption()const;
    
    virtual ImVec2 getWindowPosition()const = 0;
    
    void addShape(std::unique_ptr<Shape> shape);
protected:
    virtual void initializeWindow(const int flag = 0, const ImVec2& size = ImVec2{320, 240});
    
    virtual void setupContents() = 0;
    
private:
    std::string m_caption;
    
    std::vector<std::unique_ptr<Shape>> m_shapes;
    
public:
    static ImU32 White;
};

#endif /* window_hpp */
