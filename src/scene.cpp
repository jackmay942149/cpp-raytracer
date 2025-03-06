#include "scene.h"
#include "ray.h"
#include "shape.h"
#include "vec.h"
#include "material.h"

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

Vec3 Scene::rayTrace(const Ray& ray, float tMin, float tMax, HitData& hitData, int depth){
  HitData hd;
  if (this->hit(ray, tMin, tMax, hd)){
    Ray scattered;
    Vec3 attenuation;
    if(depth < 50 && hd.material->scatter(ray, hd, attenuation, scattered)){ 
      return (attenuation * Scene::rayTrace(scattered, tMin, tMax, hd, depth+1));
    }
    else {
      return Vec3{0.0f, 0.0f, 0.0f};
    }
  }
  else {
    Vec3 unit_direction = ray.direction().unit_vector();
    float t = 0.5f * (unit_direction.y() + 1.0f);
    return Vec3(1.0f, 1.0f, 1.0f)*(1.0f-t) + Vec3(0.5f, 0.7f, 1.0f)*t;
  }
};
