#include "scene.h"
#include "shape.h"

void Scene::add(Shape* shape){
  this->m_shapeList.push_back(shape);
}

bool Scene::hit(const Ray& ray, float tMin, float tMax, HitData& hitData){
  bool hitSomething {false};

  for (Shape* s : this->m_shapeList){
    HitData tempHD;
    if (s->hit(ray, tMin, tMax, tempHD)){
      hitSomething = true;
      hitData = tempHD;
      tMax = hitData.t;
    }
  }

  
  return hitSomething;
}
