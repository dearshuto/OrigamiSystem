//
//  vertex_2d.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#ifndef vertex_2d_hpp
#define vertex_2d_hpp

#include <array>
#include "vector.hpp"
#include "origami_system/gui/shape.hpp"

class Vertex2D : public Shape/*インフェース*/, public Vector2
{
    typedef Vector2 Super;
public:
    Vertex2D();
    Vertex2D(const float x, const float y);
    virtual~Vertex2D() = default;

    /** @copydoc Super::render() */
    void stackDrawData(ImDrawList*const drawList, const Matrix2& transform)override;
    
private:
    /** @copydoc Super::render() */
    bool hasMouseOverlap(const ImVec2& mousePosition)const override;
    
    /** @copydoc Super::onLeftButtonClick() */
    void onLeftButtonClick()override;
    
    /** @copydoc Super::onRightButtonClick() */
    void onRightButtonClick()override;
};

#endif /* vertex_2d_hpp */
