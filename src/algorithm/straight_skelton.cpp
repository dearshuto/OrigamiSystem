//
//  straight_skelton.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include <iostream>
#include "origami_system/algorithm/straight_skelton.hpp"
#include "origami_system/geometry/vertex_2d.hpp"

void StraightSkelton::update()
{
    static int i = 0;
    std::cout << ++i << std::endl;
    addShape(std::unique_ptr<Vertex2D>{new Vertex2D{50, 50}});
    
//    for (const auto& shape : getRenderShapes())
//    {
//        if (shape->detectMouseEvent() != MouseEvent::Event::Non)
//        {
//            
//        }
//    }
}

bool StraightSkelton::hasMouseOverlap(const Eigen::Vector2f &mousePosition)const
{
    const bool kIsWithinRangeX = (0 <= mousePosition.x()) && (mousePosition.x() <= 1.0);
    const bool kIsWithinRangeY = (0 <= mousePosition.y()) && (mousePosition.y() <= 1.0);
    
    return (kIsWithinRangeX && kIsWithinRangeY) ? true : false;
}
