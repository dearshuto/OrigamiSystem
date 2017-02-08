//
//  vertex_2d.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <iostream>
#include <Eigen/Core>
#include <imgui.h>
#include "origami_system/gui/window.hpp"
#include "origami_system/geometry/matrix.hpp"
#include "origami_system/geometry/vertex_2d.hpp"

Vertex2D::Vertex2D()
: Vertex2D(0.0f, 0.0f)
{
    
}

Vertex2D::Vertex2D(const float x, const float y)
: Super(x, y)
{
    
}

void Vertex2D::stackDrawData(ImDrawList *const drawList, const Matrix2& transform)
{
    const Vector2 kTransformedCenter = transform * (*this);
    const ImVec2& kCenter{kTransformedCenter.x(), kTransformedCenter.y()};
    const float kRadius = 5;
    drawList->AddCircle(kCenter, kRadius, Window::White);
}

bool Vertex2D::hasMouseOverlap(const Eigen::Vector2f &mousePosition)const
{
    const float kSquaredDiffX  = std::pow<float>(this->x() - mousePosition.x(), 2);
    const float kSquaredDiffY  = std::pow<float>(this->y() - mousePosition.y(), 2);

    return (kSquaredDiffX + kSquaredDiffY) < 25.0f;
}

void Vertex2D::onLeftButtonClick()
{
    std::cout << "Left Click" << std::endl;
}

void Vertex2D::onRightButtonClick()
{
    std::cout << "Right Click" << std::endl;
}
