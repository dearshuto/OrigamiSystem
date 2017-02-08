//
//  mouse_event.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef mouse_event_hpp
#define mouse_event_hpp

namespace Eigen {
    template<typename _Scalar, int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols>
    class Matrix;
    typedef Matrix<float, 2, 1, 0/*ColMajor*/, 2, 1> Vector2f;
}

class MouseEvent
{
public:
    enum class Event : uint8_t
    {
        Non = 0,
        Over = 1,
        RightClick = 2,
        LeftClick = 4,
    };
    
public:
    MouseEvent() = default;
    virtual~MouseEvent() = default;
    
    /** マウスイベントを発生させる. */
    virtual Event detectMouseEvent(const Eigen::Vector2f& mousePosition);
    
private:
    /** マウスとオーバラップが発生しているかを判定する. detectMouseEvent() はこの関数の結果をもとにマウスイベントを発行する.
     * マウスイベントが必要ないときは, つねにfalseを返すようにオーバーライドしてください. */
    virtual bool hasMouseOverlap(const Eigen::Vector2f& mousePosition)const = 0;
    
    /** マウスでポインティングされていると呼ばれるイベント. */
    virtual void MouseOver();
    
    /** 左ボタンをクリックすると呼ばれるイベント. */
    virtual void onLeftButtonClick();
    
    /** 右ボタンをクリックすると呼ばれるイベント. */
    virtual void onRightButtonClick();
};

#endif /* mouse_event_hpp */
