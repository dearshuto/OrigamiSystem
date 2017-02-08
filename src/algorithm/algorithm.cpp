//
//  algorithm.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include "origami_system/algorithm/algorithm.hpp"

MouseEvent::Event Algorithm::detectMouseEvent(const Eigen::Vector2f &mousePosition)
{
    bool hasShapeEvent = true;
    for (auto& shape : m_renderShapes)
    {
        hasShapeEvent = (hasShapeEvent && (shape->detectMouseEvent(mousePosition) != Event::Non));
    }

    if (hasShapeEvent)
    {
        return Event::Non;
    }
    else
    {
        return MouseEvent::detectMouseEvent(mousePosition);
    }
}

void Algorithm::addShape(std::unique_ptr<Shape> shape)
{
    m_renderShapes.push_back(std::move(shape));
}

const std::vector<std::unique_ptr<Shape>>& Algorithm::getRenderShapes()const
{
    return m_renderShapes;
}
