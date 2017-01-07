//
//  line.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include "origami_system/operators.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/geometry/line.hpp"
#include "origami_system/gui/window.hpp"

Line::Line(Vertex2D*const vertex1, Vertex2D*const vertex2)
: m_v1(vertex1)
, m_v2(vertex2)
{
    
}

void Line::stackDrawData(ImDrawList *const drawList, const ImVec2& windowOrigin)
{
    const ImVec2 kV1 = ImVec2{m_v1->x(), m_v1->y()} + windowOrigin;
    const ImVec2 kV2 = ImVec2{m_v2->x(), m_v2->y()} + windowOrigin;
    
    drawList->AddLine(kV1, kV2, Window::White);
}

const Vertex2D& Line::getVertex1()const
{
    return *m_v1;
}

const Vertex2D& Line::getVertex2()const
{
    return *m_v2;
}
