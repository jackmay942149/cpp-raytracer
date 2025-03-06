#pragma once
#include "shape.h"
#include <vector>

class Scene{
  private:
  std::vector<Shape*> m_shapeList;

  public:
  Scene(): m_shapeList{}{};

  void add(Shape* shape);
  bool hit(const Ray& ray, float tMin, float tMax, HitData& hitData);
};




