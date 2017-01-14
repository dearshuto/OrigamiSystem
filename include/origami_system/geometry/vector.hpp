//
//  vector.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/14.
//
//

#ifndef vector_hpp
#define vector_hpp

#include <Eigen/Core>

class Vector2 : public Eigen::Vector2f
{
    typedef Eigen::Vector2f Super;
public:
    Vector2() = default;
     virtual~Vector2() = default;
    
    Vector2(const float x, const float y);
    
    // This constructor allows you to construct MyVectorType from Eigen expressions
    template<typename OtherDerived>
    Vector2(const Eigen::MatrixBase<OtherDerived>& other)
    : Super(other)
    {
        
    }
    // This method allows you to assign Eigen expressions to MyVectorType
    template<typename OtherDerived>
    Vector2 & operator= (const Eigen::MatrixBase <OtherDerived>& other)
    {
        this->Super::operator=(other);
        return *this;
    }

};

#endif /* vector_hpp */
