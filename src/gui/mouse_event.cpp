//
//  mouse_event.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include <imgui.h>
#include <Eigen/Core>
#include "origami_system/gui/mouse_event.hpp"

MouseEvent::Event MouseEvent::detectMouseEvent(const Eigen::Vector2f& mousePosition)
{
    const auto& kIO = ImGui::GetIO();
    uint8_t event = static_cast<uint8_t>(Event::Non);

    if (hasMouseOverlap(mousePosition))
    {
        MouseOver();
        event |= static_cast<uint8_t>(Event::Over);

        if (kIO.MouseClicked[0])
        {
            onLeftButtonClick();
            event |= static_cast<uint8_t>(Event::LeftClick);
        }
        if (kIO.MouseClicked[1])
        {
            onRightButtonClick();
            event |= static_cast<uint8_t>(Event::RightClick);
        }
    }
    
    return static_cast<MouseEvent::Event>(event);
}

void MouseEvent::MouseOver()
{
    
}

void MouseEvent::onLeftButtonClick()
{
    
}

void MouseEvent::onRightButtonClick()
{
    
}
