//
//  sheet.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#ifndef sheet_hpp
#define sheet_hpp

#include "origami_system/gui/shape.hpp"
#include <memory>
#include <vector>

class Line;
class Vertex2D;

/// 正方形の紙
/** 左上が(0, 0)で、右方向+下方向に軸をとる. また, 0.0~1.0で正規化した座標をとるものとする.  */
class Sheet : public Shape
{
public:
    Sheet();
    virtual~Sheet() = default;
    
    /** @copydoc */
    void stackDrawData(ImDrawList*const drawList, const Matrix2& transform)override;

    
    /** @brief 折り紙のエッジ上に点をうつ
     * @param position 要素が0.0~1.0におさまってる二次元の位置.
     * @return 追加した頂点へのポインタ.  */
    std::weak_ptr<Vertex2D> addVertex(const Vertex2D& position);
    
    /** @brief 折り目を作る. 
     * @param vertex1 折り紙上にある点.
     * @param vertex2 折り紙上にある点. */
    void addLine(Vertex2D*const vertex1, Vertex2D*const vertex2);
    

    const std::vector<std::shared_ptr<Line>>& getLines()const;
    
private:
    std::vector<std::shared_ptr<Line>> m_lines;
    std::vector<std::shared_ptr<Vertex2D>> m_vertices;
};

#endif /* sheet_hpp */
