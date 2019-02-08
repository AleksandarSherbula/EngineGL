#pragma once

#include "math\vector2.h"
#include "math\vector3.h"
#include "math\vector4.h"
#include "math\matrix4.h"

const float PI = 3.14159265358f;

inline float toRadians(float degree) { return degree * (PI / 180.0f); }
inline float toDegree(float radians) { return radians * (180.0f / PI); }