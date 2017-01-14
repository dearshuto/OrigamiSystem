//
//  window.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include "origami_system/operators.hpp"
#include "origami_system/gui/app.hpp"
#include "origami_system/gui/shape.hpp"
#include "origami_system/gui/window.hpp"

ImU32 Window::White = ImGui::ColorConvertFloat4ToU32(ImVec4{256, 256, 256, 256});

Window::Window(const std::string& caption)
: m_caption(caption)
{
    
}

void Window::render()
{
    initializeWindow();
    setupContents();
    
    ImDrawList*const drawList = ImGui::GetWindowDrawList();
    for (auto& shape: m_shapes)
    {
        shape->stackDrawData(drawList, getWindowPosition());
    }
    
    ImGui::End();
}

void Window::addShape(std::unique_ptr<Shape> shape)
{
    m_shapes.push_back(std::move(shape));
}

void Window::initializeWindow(const int flag, const ImVec2& size)
{
    bool canOpen = false;
    ImGui::SetNextWindowPos(getWindowPosition());
    ImGui::SetNextWindowSize(size);
    ImGui::Begin(getCaption().c_str(), &canOpen, flag);
}

ImVec2 Window::getMoousePositionOnThisWindow()const
{    
    return ImGui::GetIO().MousePos - ImGui::GetCursorScreenPos();
}

const std::string& Window::getCaption()const
{
    return m_caption;
}
