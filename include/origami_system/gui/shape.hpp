//
//  shape.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/07.
//
//

#ifndef shape_h
#define shape_h

struct ImVec2;
struct ImDrawList;

class Shape
{
public:
    Shape() = default;
    virtual~Shape() = default;
    
    /** 描画キューに情報をスタックする
     * @param drawList 有効な描画キュー.
     * @param windowPosition 描画するウィンドウの原点. ここからの相対位置に描画する. */
    virtual void stackDrawData(ImDrawList*const drawList, const ImVec2& windowOrigin) = 0;
};

#endif /* shape_h */
