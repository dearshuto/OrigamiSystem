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

void RenderingWindow::initializeWindow(const int flag)
{
    Super::initializeWindow(ImGuiWindowFlags_NoMove);
}

void RenderingWindow::setupContents()
{
    auto drawList = ImGui::GetWindowDrawList();

    const auto kCurrentScreenPosition = getWindowPosition() + ImVec2{20.0, 20.0};
    const auto kWindowSize = ImGui::GetWindowSize();
    drawList->AddRect(kCurrentScreenPosition, kCurrentScreenPosition + ImVec2{50, 50}, ImColor{256, 256, 256});
    
    //        for(const auto line: sheet.getLines())
    //        {
    //            const auto& vertex1 = line->getVertex1();
    //            const auto& vertex2 = line->getVertex2();
    
    const ImVec2 kBegin = {kCurrentScreenPosition.x, kCurrentScreenPosition.y};
    const ImVec2 kEnd = kCurrentScreenPosition + ImVec2{100, 100};
    
    drawList->AddLine(kBegin, kEnd, ImColor{256, 256, 256});
    //        }
    
    const auto kMoousePotision = getMoousePositionOnThisWindow();
    std::cout << kMoousePotision.x << " " << kMoousePotision.y << std::endl;
}

ImVec2 RenderingWindow::getWindowPosition()const
{
    return {0.0, 0.0};
}
