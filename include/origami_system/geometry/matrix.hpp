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

class Matrix2 : public Eigen::Transform<float, 2/*dimension*/, Eigen::TransformTraits::Affine>
{
public:
    Matrix2() = default;
    ~Matrix2() = default;
    
    typedef Eigen::Translation2f Base;
    
    // This constructor allows you to construct MyVectorType from Eigen expressions
    template<typename OtherDerived>
    Matrix2(const Eigen::MatrixBase<OtherDerived>& other)
    : Base(other)
    {
        
    }
//    // This method allows you to assign Eigen expressions to MyVectorType
//    Matrix2 & operator= (const Eigen::Translation2f& other)
//    {
//        this->Base::operator=(other);
//        return *this;
//    }
};

#endif /* matrix_hpp */
