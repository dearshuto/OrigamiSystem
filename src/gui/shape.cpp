//
//  shape.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/27.
//
//

#include <iostream>
#include <imgui.h>
#include "origami_system/gui/shape.hpp"

void Shape::detectMouseEvent()
{
    const auto& kIO = ImGui::GetIO();
    
    if (hasMouseOverlap(kIO.MousePos))
    {
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

void Shape::onLeftButtonClick()
{

}

void Shape::onRightButtonClick()
{
    
}
