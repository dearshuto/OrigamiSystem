//
//  line.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include "origami_system/geometry/vertex_2d.hpp"
#include "origami_system/geometry/line.hpp"

Line::Line(std::weak_ptr<Vertex2D> vertex1, std::weak_ptr<Vertex2D> vertex2)
: m_vertex({vertex1, vertex2})
{
    
}

const Vertex2D& Line::getVertex1()const
{
    return *(m_vertex.first.lock());
}

const Vertex2D& Line::getVertex2()const
{
    return *(m_vertex.second.lock());
}
