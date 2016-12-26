//
//  sheet.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#ifndef sheet_hpp
#define sheet_hpp

#include <memory>
#include <vector>

class Line;
class Vertex2D;

/// 正方形の紙
/** 左上が(0, 0)で、右方向+下方向に軸をとる. また, 0.0~1.0で正規化した座標をとるものとする.  */
class Sheet
{
public:
    Sheet() = default;
    ~Sheet() = default;
    
    
    /** @brief 折り紙のエッジ上に点をうつ
     * @param position 要素が0.0~1.0におさまってる二次元の位置.
     * @return 追加した頂点へのポインタ.  */
    std::weak_ptr<Vertex2D> addVertex(const Vertex2D& position);
    
    /** @brief 折り目を作る.
     * @param vertex1, vertex2 はこのクラスに要録済みの頂点であること. */
    void addLine(const std::weak_ptr<Vertex2D>& vertex1, const std::weak_ptr<Vertex2D>& vertex2);
    

    const std::vector<std::shared_ptr<Line>>& getLines()const;
    
private:
    std::vector<std::shared_ptr<Line>> m_lines;
    std::vector<std::shared_ptr<Vertex2D>> m_vertices;
};

#endif /* sheet_hpp */
