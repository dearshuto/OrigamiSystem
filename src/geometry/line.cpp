//
//  line.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <Eigen/Core>
#include "origami_system/operators.hpp"
#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/matrix.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/gui/window.hpp"

Line::Line(Vertex2D*const vertex1, Vertex2D*const vertex2)
: m_v1(vertex1)
, m_v2(vertex2)
{
    
}

void Line::stackDrawData(ImDrawList *const drawList, const Matrix2& transform)
{
    const Vector2 kV1 = transform * getVertex1();
    const Vector2 kV2 = transform * getVertex2();

    drawList->AddLine(ImVec2{kV1.x(), kV1.y()}
                      , ImVec2{kV2.x(), kV2.y()}
                      , Window::White);
}


bool Line::hasMouseOverlap(const Eigen::Vector2f &mousePosition)const
{
    return false;
}

const Vertex2D& Line::getVertex1()const
{
    return *m_v1;
}

const Vertex2D& Line::getVertex2()const
{
    return *m_v2;
}
