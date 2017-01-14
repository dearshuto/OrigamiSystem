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
#include "origami_system/sheet.hpp"
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
    addShape(std::unique_ptr<Shape>{new Sheet});
}

void RenderingWindow::initializeWindow(const int flag, const ImVec2& size)
{
    const int kWindowFlag = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;
    const auto kWindowSize = ImGui::GetWindowSize();
    Super::initializeWindow(kWindowFlag, kWindowSize);
}

void RenderingWindow::setupContents()
{
    auto drawList = ImGui::GetWindowDrawList();
    const auto kMoousePotision = ImGui::GetIO().MousePos;
    const auto kOrigin = getWindowPosition() + ImVec2{20.0, 30.0};
    const auto kWindowSize = ImGui::GetWindowSize();
    
    //        for(const auto line: sheet.getLines())
    //        {
    //            const auto& vertex1 = line->getVertex1();
    //            const auto& vertex2 = line->getVertex2();


    
}

ImVec2 RenderingWindow::getWindowPosition()const
{
    return {0.0, 0.0};
}
