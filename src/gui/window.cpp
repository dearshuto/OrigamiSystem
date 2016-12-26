//
//  window.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include "origami_system/gui/app.hpp"
#include "origami_system/gui/window.hpp"

ImVec2 operator+(const ImVec2& v1, const ImVec2& v2)
{
    return ImVec2{v1.x + v2.x, v1.y + v2.y};
}

ImVec2 operator-(const ImVec2& v1, const ImVec2& v2)
{
    return ImVec2{v1.x - v2.x, v1.y - v2.y};
}

Window::Window(const std::string& caption)
: m_caption(caption)
{
    
}

void Window::initializeWindow(const int flag)
{
    bool canOpen = false;
    ImGui::SetNextWindowPos(getWindowPosition());
    ImGui::Begin(getCaption().c_str(), &canOpen, flag);
}

void Window::endWindowSetup()
{
    ImGui::End();
}

ImVec2 Window::getMoousePositionOnThisWindow()const
{    
    return ImGui::GetIO().MousePos - ImGui::GetCursorScreenPos();
}

const std::string& Window::getCaption()const
{
    return m_caption;
}
