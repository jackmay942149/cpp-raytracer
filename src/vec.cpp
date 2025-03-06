#include "vec.h"
#include "rand.h"

Vec3 operator*(const float f, const Vec3& v){return v*f;}

Vec3 Vec::randInUnitSphere(){
  float x;
  float y;
  float z;
  
  do {
    x = Rand::random(0.0f, 1.0f);
    y = Rand::random(0.0f, 1.0f);
    z = Rand::random(0.0f, 1.0f);
  }
  while (x*x + y*y + z*z < 1); 
  return Vec3{x, y, z};
}
