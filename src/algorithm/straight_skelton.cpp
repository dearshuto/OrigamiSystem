//
//  straight_skelton.cpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#include <iostream>
#include "origami_system/geometry/sheet.hpp"
#include "origami_system/algorithm/straight_skelton.hpp"

void StraightSkelton::update()
{
    static int i = 0;
    std::cout << ++i << std::endl;
}
