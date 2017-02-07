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
#include "origami_system/geometry/sheet.hpp"
#include "origami_system/operators.hpp"
#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/gui/rendering_window.hpp"

RenderingWindow::RenderingWindow(const std::string& caption)
: Super(caption)
{
    Matrix2 affine;
    affine.setIdentity();
    affine.translate(Eigen::Vector2f{10.0, 10.0});
    affine.scale(100.0f);
    applyTransformMatrix(affine);
}

void RenderingWindow::init()
{
    // 動かせない && 大きさ固定
    const ImGuiWindowFlags kWindowFlag = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
    setWindowSettingFlag(kWindowFlag);
    setWindowSize(ImVec2{300, 300});
    
    addShape(std::unique_ptr<Shape>{new Sheet});
}
