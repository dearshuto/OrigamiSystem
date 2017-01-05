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
#include "origami_system/gui/rendering_window.hpp"

RenderingWindow::RenderingWindow(const std::string& caption)
: Super(caption)
{
    
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
    

    // 四角形を描く
    const float kLength = kWindowSize.x * 0.90;
    const auto kLeftUp = kOrigin;
    const auto kLeftDown = kLeftUp + ImVec2{0, kLength};
    const auto kRightUp = kLeftUp + ImVec2{kLength, 0};
    const auto kRightDown = kLeftUp + ImVec2{kLength, kLength};
    
    drawList->AddLine(kRightDown, kRightUp, White);
    drawList->AddLine(kLeftDown, kRightDown, White);
    drawList->AddLine(kRightUp, kLeftUp, White);
    drawList->AddLine(kLeftDown, kLeftUp, White);
    
}

ImVec2 RenderingWindow::getWindowPosition()const
{
    return {0.0, 0.0};
}
