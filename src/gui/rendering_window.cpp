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
    const auto kOrigin = getWindowPosition() + ImVec2{20.0, 30.0};
    const ImVec2 kWindowSize = {320, 320};//ImGui::GetWindowSize();

    // 四角形を描く
    const float kLength = kWindowSize.x * 0.90;
    const auto kLeftUp = kOrigin;
    const auto kLeftDown = kLeftUp + ImVec2{0, kLength};
    const auto kRightUp = kLeftUp + ImVec2{kLength, 0};
    const auto kRightDown = kLeftUp + ImVec2{kLength, kLength};

    std::unique_ptr<Vertex2D> v1(new Vertex2D(20, 20));
    std::unique_ptr<Vertex2D> v2(new Vertex2D(120, 120));
    std::unique_ptr<Line> line(new Line(v1.get(), v2.get()));
    
    addShape(std::move(v1));
    addShape(std::move(v2));
    addShape(std::move(line));
    
//    drawList->AddLine(kRightDown, kRightUp, Window::Shape::White);
//    drawList->AddLine(kLeftDown, kRightDown, Window::Shape::White);
//    drawList->AddLine(kRightUp, kLeftUp, Window::Shape::White);
//    drawList->AddLine(kLeftDown, kLeftUp, Window::Shape::White);
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
