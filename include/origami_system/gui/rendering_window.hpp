//
//  rendering_window.hpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#ifndef rendering_window_hpp
#define rendering_window_hpp

#include "window.hpp"

class RenderingWindow : public Window
{
    typedef Window Super;
public:
    RenderingWindow() = delete;
    RenderingWindow(const std::string& caption);
    ~RenderingWindow() = default;

    void init()override;
};

#endif /* rendering_window_hpp */
