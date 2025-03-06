#pragma once

#include "ray.h"
#include "vec.h"

class Material;

struct HitData {
  float t;
  Vec3 point;
  Vec3 normal;
  Material* material;
};

class Shape {
  public:
  virtual bool hit(const Ray& ray, float tMin, float tMax, HitData& hitData) const {return false;};
};
