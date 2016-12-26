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

class Vertex2D;

/// 折り紙にできた折り目
class Line
{
    typedef std::weak_ptr<Vertex2D> VertexPtr;
public:
    Line() = delete;
    Line(std::weak_ptr<Vertex2D> vertex1, std::weak_ptr<Vertex2D> vertex2);
    virtual~Line() = default;
    
    const Vertex2D& getVertex1()const;
    const Vertex2D& getVertex2()const;
    
private:
    std::pair<VertexPtr, VertexPtr> m_vertex;
};

#endif /* line_hpp */
