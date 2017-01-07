//
//  sheet.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include "origami_system/geometry/line.hpp"
#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/sheet.hpp"

std::weak_ptr<Vertex2D> Sheet::addVertex(const Vertex2D &position)
{
    auto vertexPtr = std::make_shared<Vertex2D>(position[0], position[1]);
    m_vertices.push_back(vertexPtr);
    return std::weak_ptr<Vertex2D>(vertexPtr);
}

void Sheet::addLine(const std::weak_ptr<Vertex2D> &vertex1, const std::weak_ptr<Vertex2D> &vertex2)
{
//    m_lines.push_back(std::make_shared<Line>(vertex1, vertex2));
}

//---- Getters ---------------------------------------------------------------------------------------

const std::vector<std::shared_ptr<Line>>& Sheet::getLines()const
{
    return m_lines;
}
