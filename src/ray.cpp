#include "ray.h"
#include "vec.h"

Vec3 Ray::color() {
  float t = hitSphere(Vec3(0.0f, 0.0f, -1.0f), 0.5f);
  if (t > 0){
    Vec3 N = (this->pointAtParameter(t) - Vec3(0.0f, 0.0f, -1.0f)).unit_vector();
    return 0.5f * (N + 1.0f);
  }
  
  Vec3 unit_direction = this->direction().unit_vector();
  t = 0.5f * (unit_direction.y() + 1.0f);
  return Vec3(1.0f, 1.0f, 1.0f)*(1.0f-t) + Vec3(0.5f, 0.7f, 1.0f)*t;
}

float Ray::hitSphere(const Vec3& sphereCenter, float sphereRadius){
  Vec3 oc = this->origin() - sphereCenter;
  float a = this->direction().dot(this->direction());
  float b = 2.0 * oc.dot(this->direction());
  float c = oc.dot(oc) - (sphereRadius * sphereRadius);
  float descriminant = b*b - 4*a*c;

  if (descriminant < 0){
    return -1.0f;
  }
  else {
    return (-b - sqrt(descriminant))/(2.0f * a);
  }

}
