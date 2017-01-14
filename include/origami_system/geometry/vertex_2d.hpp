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
#include "origami_system/gui/shape.hpp"

class Vertex2D : public Shape
{
public:
    Vertex2D();
    Vertex2D(const float x, const float y);
    virtual~Vertex2D() = default;

    float& operator[](const size_t index);
    float operator[](const size_t index)const;

    float& x();
    float x()const;
    float& y();
    float y()const;

    /** @copydoc Super::render() */
    void stackDrawData(ImDrawList*const drawList, const ImVec2& windowOrigin)override;
    
private:
    std::array<float, 2> m_components;
};

#endif /* vertex_2d_hpp */
