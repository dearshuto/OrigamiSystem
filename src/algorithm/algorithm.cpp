//
//  algorithm.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include "origami_system/algorithm/algorithm.hpp"

void Algorithm::addShape(std::unique_ptr<Shape> shape)
{
    m_renderShapes.push_back(std::move(shape));
}

const std::vector<std::unique_ptr<Shape>>& Algorithm::getRenderShapes()const
{
    return m_renderShapes;
}
