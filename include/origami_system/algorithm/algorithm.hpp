//
//  algorithm.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/02/07.
//
//

#ifndef algorithm_h
#define algorithm_h

class Sheet;

class Algorithm
{
protected:
    Algorithm() = default;
public:
    virtual~Algorithm() = default;
    
    virtual void update() = 0;    
};

#endif /* algorithm_h */
