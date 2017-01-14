//
//  sheet.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <imgui.h>
#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/sheet.hpp"

Sheet::Sheet()
{
    // 四角形を描く
    
    const auto kOrigin = ImVec2{20.0, 30.0};
    const ImVec2 kWindowSize = {320, 320};
    
    const float kLength = kWindowSize.x * 0.90;
    const auto kLeftUp = kOrigin;
//    const auto kLeftDown = kLeftUp + ImVec2{0, kLength};
//    const auto kRightUp = kLeftUp + ImVec2{kLength, 0};
//    const auto kRightDown = kLeftUp + ImVec2{kLength, kLength};
    
    // 頂点の順番
    // 1--4
    // |  |
    // 2--3
    
    std::unique_ptr<Vertex2D> v1(new Vertex2D(20, 20));
    std::unique_ptr<Vertex2D> v2(new Vertex2D(20, 120));
    std::unique_ptr<Vertex2D> v3(new Vertex2D(120, 120));
    std::unique_ptr<Vertex2D> v4(new Vertex2D(120, 20));
    
    m_lines.push_back(std::unique_ptr<Line>(new Line(v1.get(), v2.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v2.get(), v3.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v3.get(), v4.get())));
    m_lines.push_back(std::unique_ptr<Line>(new Line(v4.get(), v1.get())));
    
    m_vertices.push_back(std::move(v1));
    m_vertices.push_back(std::move(v2));
    m_vertices.push_back(std::move(v3));
    m_vertices.push_back(std::move(v4));
}

void Sheet::stackDrawData(ImDrawList *const drawList, const ImVec2 &windowOrigin)
{
    for (const auto& line : m_lines)
    {
        line->stackDrawData(drawList, windowOrigin);
    }
    
    for (const auto& vertex : m_vertices)
    {
        vertex->stackDrawData(drawList, windowOrigin);
    }
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
