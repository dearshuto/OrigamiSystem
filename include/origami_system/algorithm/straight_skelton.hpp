//
//  straight_skelton.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef straight_skelton_hpp
#define straight_skelton_hpp

#include "algorithm.hpp"

class StraightSkelton : public Algorithm
{
public:
    StraightSkelton() = default;
    ~StraightSkelton() = default;
    
    void update()override;
    
private:
    /** マウスとオーバラップが発生しているかを判定する. detectMouseEvent() はこの関数の結果をもとにマウスイベントを発行する.
     * マウスイベントが必要ないときは, つねにfalseを返すようにオーバーライドしてください. */
    bool hasMouseOverlap(const Eigen::Vector2f& mousePosition)const override;

};

#endif /* straight_skelton_hpp */
