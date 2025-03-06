#pragma once

#include "shape.h"
#include "vec.h"
#include "material.h"

class Sphere : public Shape {
  private:
  Vec3 m_centre;
  float m_radius;
  Material* m_material; 

  public:
  Sphere(): m_centre{Vec3{0.0f, 0.0f, 0.0f}}, m_radius{0.0f}, m_material{}{};
  Sphere(Vec3 v, float r, Material* m): m_centre(v), m_radius(r), m_material{m}{};
  bool hit(const Ray& ray, float tMin, float tMax, HitData& hitData) const override;
};
