#pragma once
#include "shape.h"
#include "vec.h"
#include <vector>

class Scene{
  private:
  std::vector<Shape*> m_shapeList;

  public:
  Scene(): m_shapeList{}{};

  void add(Shape* shape);
  bool hit(const Ray& ray, float tMin, float tMax, HitData& hitData);
  Vec3 rayTrace(const Ray& ray, float tMin, float tMax, HitData& hitData, int depth);
};




