//
//  operators.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/07.
//
//

#include <imgui.h>
#include "origami_system/operators.hpp"

ImVec2 operator+(const ImVec2& v1, const ImVec2& v2)
{
    return ImVec2{v1.x + v2.x, v1.y + v2.y};
}

ImVec2 operator-(const ImVec2& v1, const ImVec2& v2)
{
    return ImVec2{v1.x - v2.x, v1.y - v2.y};
}

ImVec2 operator/(const ImVec2& v, const float div)
{
    return ImVec2{v.x /div, v.y / div};
}
