#include "scene.h"
#include "ray.h"
#include "shape.h"
#include "vec.h"

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

Vec3 Scene::rayTrace(const Ray& ray, float tMin, float tMax, HitData& hitData){
  if (this->hit(ray, tMin, tMax, hitData)){
    Vec3 target = hitData.point + hitData.normal + Vec::randInUnitSphere();
    return 0.5*this->rayTrace(Ray(hitData.point, target, 1.0f), tMin, tMax, hitData);
  }
  else {
    Vec3 unit_direction = ray.direction().unit_vector();
    float t = 0.5f * (unit_direction.y() + 1.0f);
    return Vec3(1.0f, 1.0f, 1.0f)*(1.0f-t) + Vec3(0.5f, 0.7f, 1.0f)*t;
  }
};
