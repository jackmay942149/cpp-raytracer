#pragma once

#include "shape.h"
#include "vec.h"

class Sphere : public Shape {
  private:
  Vec3 m_centre;
  float m_radius;

  public:
  Sphere(): m_centre{Vec3{0.0f, 0.0f, 0.0f}}, m_radius{0.0f}{};
  Sphere(Vec3 v, float r): m_centre(v), m_radius(r){};
  virtual bool hit(const Ray& ray, float tMin, float tMax, HitData& hitData) const;
};
