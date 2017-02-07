//
//  mouse_event.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include <imgui.h>
#include "origami_system/gui/mouse_event.hpp"

void MouseEvent::detectMouseEvent()
{
    const auto& kIO = ImGui::GetIO();
    
    if (hasMouseOverlap(kIO.MousePos))
    {
        MouseOver();
        
        if (kIO.MouseClicked[0])
        {
            onLeftButtonClick();
        }
        if (kIO.MouseClicked[1])
        {
            onRightButtonClick();
        }
    }
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
