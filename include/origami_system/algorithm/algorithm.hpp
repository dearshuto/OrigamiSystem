//
//  algorithm.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef algorithm_h
#define algorithm_h

#include <vector>
#include "origami_system/gui/mouse_event.hpp"
#include "origami_system/gui/shape.hpp"

class Algorithm : public MouseEvent
{
protected:
    Algorithm() = default;
public:
    virtual~Algorithm() = default;
    
    virtual void update() = 0;
    
    Event detectMouseEvent(const Eigen::Vector2f& mousePosition)override;
    
protected:
    void addShape(std::unique_ptr<Shape> shape);

public:
    const std::vector<std::unique_ptr<Shape>>& getRenderShapes()const;

private:
    std::vector<std::unique_ptr<Shape>> m_renderShapes;
};

#endif /* algorithm_h */
