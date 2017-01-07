//
//  vertex_2d.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <imgui.h>
#include "origami_system/gui/window.hpp"
#include "origami_system/geometry/vertex_2d.hpp"

Vertex2D::Vertex2D()
: Vertex2D(0.0f, 0.0f)
{
    
}

Vertex2D::Vertex2D(const float x, const float y)
: m_components({{x, y}})
{
    
}

float& Vertex2D::operator[](const size_t index)
{
    return m_components[index];
}

float Vertex2D::operator[](const size_t index)const
{
    return m_components[index];
}

float& Vertex2D::x()
{
    return m_components[0];
}

float Vertex2D::x()const
{
    return m_components[0];
}

float& Vertex2D::y()
{
    return m_components[1];
}

float Vertex2D::y()const
{
    return m_components[1];
}

void Vertex2D::stackDrawData(ImDrawList *const drawList, const ImVec2 &windowOrigin)
{
    const ImVec2& kCenter{x(), y()};
    const float kRadius = 5;
    drawList->AddCircle(kCenter, kRadius, Window::White);
}
