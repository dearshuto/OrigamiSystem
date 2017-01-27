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
#include "origami_system/geometry/matrix.hpp"

class Vertex2D;

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
    
    Vertex2D getMoousePositionOnThisWindow()const;
    
    const std::string& getCaption()const;
    
    void addShape(std::unique_ptr<Shape> shape);
protected:
    virtual void initializeWindow();
    
    const Matrix2& getWindowTransformMatrix()const;
    
    ImGuiWindowFlags getWindowSettingFlag()const;
    
    void setWindowSettingFlag(const int flag);
    
    const ImVec2& getWindowSize()const;
    
    void setWindowSize(const ImVec2& size);
    
    const ImVec2& getWindowPosition()const;
    
    void setWindowPosition(const ImVec2& position);
    
    const Matrix2& getTransformMatrix()const;
    
    void applyTransformMatrix(const Matrix2& transform);
private:
    std::string m_caption;
    
    ImGuiWindowFlags m_flag;
    
    ImVec2 m_size{100, 100};
    
    ImVec2 m_position{0, 0};
    
    std::vector<std::unique_ptr<Shape>> m_shapes;

    // ウィンドウ内の座標変換
    Matrix2 m_transform;
public:
    static unsigned int White;
};

#endif /* window_hpp */
