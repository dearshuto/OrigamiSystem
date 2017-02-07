//
//  mouse_event.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef mouse_event_hpp
#define mouse_event_hpp

struct ImVec2;

class MouseEvent
{
public:
    MouseEvent() = default;
    virtual~MouseEvent() = default;
    
    /** マウスイベントを発生させる. */
    void detectMouseEvent();
    
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

#endif /* mouse_event_hpp */
