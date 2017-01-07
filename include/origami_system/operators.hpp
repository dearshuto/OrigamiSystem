//
//  operators.hpp
//  OrigamiSystem
//
//  Created by Shuto Shikama on 2017/01/07.
//
//

#ifndef operators_hpp
#define operators_hpp

struct ImVec2;

ImVec2 operator+(const ImVec2& v1, const ImVec2& v2);
ImVec2 operator-(const ImVec2& v1, const ImVec2& v2);
ImVec2 operator/(const ImVec2& v, const float div);

#endif /* operators_hpp */
