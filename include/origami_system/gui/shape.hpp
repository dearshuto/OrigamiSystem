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
class Matrix2;

class Shape
{
public:
    Shape() = default;
    virtual~Shape() = default;
    
    /** 描画キューに情報をスタックする
     * @param drawList 有効な描画キュー.
     * @param transform 描画するウィンドウ用に座標変換するための行列. */
    virtual void stackDrawData(ImDrawList*const drawList, const Matrix2& transform) = 0;
    
    /** マウスイベントを発生させる. */
    void detectMouseEvent();
private:

    /** マウスとオーバラップが発生しているかを判定する. detectMouseEvent() はこの関数の結果をもとにマウスイベントを発行する.
     * マウスイベントが必要ないときは, つねにfalseを返すようにオーバーライドしてください. */
    virtual bool hasMouseOverlap(const ImVec2& mousePosition)const = 0;

    /** マウスでポインティングされていると呼ばれるイベント. */
    virtual void MouseOver();
    
    /** 左ボタンをクリックすると呼ばれるイベント. */
    virtual void onLeftButtonClick();

    /** 右ボタンをクリックすると呼ばれるイベント. */
    virtual void onRightButtonClick();
};

#endif /* shape_h */
