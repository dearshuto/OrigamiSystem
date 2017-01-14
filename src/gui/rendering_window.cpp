//
//  rendering_window.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include <iostream>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "origami_system/sheet.hpp"
#include "origami_system/operators.hpp"
#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/gui/rendering_window.hpp"

RenderingWindow::RenderingWindow(const std::string& caption)
: Super(caption)
{
    
}

void RenderingWindow::init()
{
    // 動かせない && 大きさ固定
    const int kWindowFlag = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;
    setWindowSettingFlag(kWindowFlag);
    setWindowSize(ImVec2{300, 300});
    m_transform
    
    addShape(std::unique_ptr<Shape>{new Sheet});
}
