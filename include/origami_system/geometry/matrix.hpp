//
//  matrix.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/14.
//
//

#ifndef matrix_hpp
#define matrix_hpp

#include <Eigen/Core>
#include <Eigen/Geometry>

class Matrix2 : public Eigen::Translation2d
{
public:
    Matrix2() = default;
    ~Matrix2() = default;
};

#endif /* matrix_hpp */
