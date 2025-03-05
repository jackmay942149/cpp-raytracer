#include "ray.h"
#include "vec.h"

Vec3 Ray::color() {
  Vec3 unit_direction = this->direction().unit_vector();
  float t = 0.5f * (unit_direction.y() + 1.0f);
  return Vec3(1.0f, 1.0f, 1.0f)*(1.0f-t) + Vec3(0.5f, 0.7f, 1.0f)*t;
}
