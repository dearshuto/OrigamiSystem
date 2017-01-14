//
//  line.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#ifndef line_hpp
#define line_hpp

#include <memory>
#include <tuple>
#include "origami_system/gui/shape.hpp"

class Vertex2D;

/// 折り紙にできた折り目
class Line : public Shape
{
public:
    Line() = delete;
    Line(Vertex2D*const vertex1, Vertex2D*const vertex2);
    virtual~Line() = default;
    
    /** @copydoc Super::render() */
    void stackDrawData(ImDrawList*const drawList, const Matrix2& transform)override;

    
    const Vertex2D& getVertex1()const;
    const Vertex2D& getVertex2()const;
    
private:
    Vertex2D*const m_v1;
    Vertex2D*const m_v2;
};

#endif /* line_hpp */
