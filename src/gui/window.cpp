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
    m_transform = Matrix2::Identity();
    ImGui::GetIO().WantCaptureMouse = true;
}

void Window::render()
{
    initializeWindow();
    
    ImDrawList*const drawList = ImGui::GetWindowDrawList();
    for (auto& shape: m_shapes)
    {
        shape->stackDrawData(drawList, getWindowTransformMatrix());
        shape->detectMouseEvent();
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
    
    // ウィンドウの移動を許可しないときは, 指定された位置に描画する
    if (getWindowSettingFlag() & ImGuiWindowFlags_NoMove)
    {
        ImGui::SetNextWindowPos(getWindowPosition());
    }
    
    // ウィンドウのリサイズを許可しないときは, 指定されたサイズで描画する
    if (getWindowSettingFlag() & ImGuiWindowFlags_NoResize)
    {
        ImGui::SetNextWindowSize(getWindowSize());
    }
    
    ImGui::Begin(getCaption().c_str(), &canOpen, getWindowSettingFlag());
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

const ImVec2& Window::getWindowPosition()const
{
    return m_position;
}

void Window::setWindowPosition(const ImVec2 &position)
{
    m_position = position;
}

ImGuiWindowFlags Window::getWindowSettingFlag()const
{
    return m_flag;
}

void Window::setWindowSettingFlag(const int flag)
{
    m_flag = flag;
}

const ImVec2& Window::getWindowSize()const
{
    return m_size;
}

void Window::setWindowSize(const ImVec2 &size)
{
    m_size = size;
}

const Matrix2& Window::getTransformMatrix()const
{
    return m_transform;
}

void Window::applyTransformMatrix(const Matrix2 &transform)
{
    m_transform = transform * m_transform;
}
