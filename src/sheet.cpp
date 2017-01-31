//
//  sheet.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <imgui.h>
#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/matrix.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/sheet.hpp"


Sheet::Sheet()
{
    // 四角形を描く
    // 頂点の順番
    // 1--4
    // |  |
    // 2--3
    
    std::unique_ptr<Vertex2D> v1(new Vertex2D(0, 0));
    std::unique_ptr<Vertex2D> v2(new Vertex2D(0, 1));
    std::unique_ptr<Vertex2D> v3(new Vertex2D(1, 1));
    std::unique_ptr<Vertex2D> v4(new Vertex2D(1, 0));
    
    m_lines.push_back(std::unique_ptr<Line>(new Line(v1.get(), v2.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v2.get(), v3.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v3.get(), v4.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v4.get(), v1.get())));
    
    m_vertices.push_back(std::move(v1));
    m_vertices.push_back(std::move(v2));
    m_vertices.push_back(std::move(v3));
    m_vertices.push_back(std::move(v4));
    
    
}

void Sheet::stackDrawData(ImDrawList *const drawList, const Matrix2 &transform)
{
    for (const auto& line : m_lines)
    {
        line->stackDrawData(drawList, transform);
        line->detectMouseEvent();
    }
    
    for (const auto& vertex : m_vertices)
    {
        vertex->stackDrawData(drawList, transform);
        vertex->detectMouseEvent();
    }
}

bool Sheet::hasMouseOverlap(const ImVec2 &mousePosition)const
{
    return false;
}

std::weak_ptr<Vertex2D> Sheet::addVertex(const Vertex2D &position)
{
    auto vertexPtr = std::make_shared<Vertex2D>(position[0], position[1]);
    m_vertices.push_back(vertexPtr);
    return std::weak_ptr<Vertex2D>(vertexPtr);
}

void Sheet::addLine(Vertex2D*const vertex1, Vertex2D*const vertex2)
{
    m_lines.push_back(std::unique_ptr<Line>(new Line{vertex1, vertex2}));
}

//---- Getters ---------------------------------------------------------------------------------------

const std::vector<std::shared_ptr<Line>>& Sheet::getLines()const
{
    return m_lines;
}
