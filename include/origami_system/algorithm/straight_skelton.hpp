//
//  straight_skelton.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef straight_skelton_hpp
#define straight_skelton_hpp

#include "algorithm.hpp"

class StraightSkelton : public Algorithm
{
public:
    StraightSkelton() = default;
    ~StraightSkelton() = default;
    
    void update()override;
};

#endif /* straight_skelton_hpp */
