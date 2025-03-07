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

Vec3 Vec::reflect(const Vec3& incoming, const Vec3& normal){
  return incoming - 2.0f*(incoming.dot(normal)*normal); 
}

bool Vec3::reflect(const Vec3& inVector, const Vec3& normal, float refractionIndex){
  Vec3 uv = inVector.unit_vector();
  float dt = uv.dot(normal);
  float descriminant = 1.0f - refractionIndex*refractionIndex*(1-dt*dt);
  
  if (descriminant > 0){
    *this = Vec3(refractionIndex*(uv - normal*dt) - normal*::sqrt(descriminant));
    return true;
  }
  return false;
}  
