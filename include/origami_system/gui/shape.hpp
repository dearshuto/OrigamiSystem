//
//  shape.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/07.
//
//

#ifndef shape_h
#define shape_h

#include "mouse_event.hpp"

struct ImDrawList;
class Matrix2;

class Shape : public MouseEvent
{
public:
    Shape() = default;
    virtual~Shape() = default;
    
    /** 描画キューに情報をスタックする
     * @param drawList 有効な描画キュー.
     * @param transform 描画するウィンドウ用に座標変換するための行列. */
    virtual void stackDrawData(ImDrawList*const drawList, const Matrix2& transform) = 0;
};

#endif /* shape_h */
