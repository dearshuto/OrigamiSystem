//
//  window.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include "origami_system/operators.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/gui/app.hpp"
#include "origami_system/gui/shape.hpp"
#include "origami_system/gui/window.hpp"

unsigned int Window::White = ImGui::ColorConvertFloat4ToU32(ImVec4{256, 256, 256, 256});

Window::Window(const std::string& caption)
: m_caption(caption)
{
    
}

void Window::render()
{
    initializeWindow();
    
    ImDrawList*const drawList = ImGui::GetWindowDrawList();
    for (auto& shape: m_shapes)
    {
        shape->stackDrawData(drawList, getWindowTransformMatrix());
    }
    
    ImGui::End();
}

void Window::addShape(std::unique_ptr<Shape> shape)
{
    m_shapes.push_back(std::move(shape));
}

void Window::initializeWindow()
{
    bool canOpen = false;
    const auto kPosition = getWindowTransformMatrix().translation();
    ImGui::SetNextWindowPos(ImVec2{kPosition.x(), kPosition.y()});
    ImGui::SetNextWindowSize(m_size);
    ImGui::Begin(getCaption().c_str(), &canOpen, m_flag);
}

Vertex2D Window::getMoousePositionOnThisWindow()const
{
    const auto kRelatedMousePosition = ImGui::GetIO().MousePos - ImGui::GetCursorScreenPos();
    return {kRelatedMousePosition.x, kRelatedMousePosition.y};
}

const std::string& Window::getCaption()const
{
    return m_caption;
}

const Matrix2& Window::getWindowTransformMatrix()const
{
    return m_transform;
}

void Window::setWindowSettingFlag(const int flag)
{
    m_flag = flag;
}

void Window::setWindowSize(const ImVec2 &size)
{
    m_size = size;
}
