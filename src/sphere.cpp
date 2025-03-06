#include "sphere.h"
#include <iostream>

bool Sphere::hit(const Ray& ray, float tMin, float tMax, HitData& hitData) const{
  Vec3 oc = ray.origin() - this->m_centre;
  float a = ray.direction().dot(ray.direction());
  float b = oc.dot(ray.direction());
  float c = oc.dot(oc) - (this->m_radius * this->m_radius);
  float descriminant = b*b - a*c;

  if (descriminant <= 0){
    return false;
  }
  
  float temp = (-b - sqrt(descriminant))/a;
  if (tMin < temp && temp < tMax){
    hitData.t = temp;
    hitData.point = ray.pointAtParameter(temp);
    hitData.normal = (hitData.point - this->m_centre)/this->m_radius;
    return true;
  }

  temp = (-b + sqrt(descriminant))/a;
  if (tMin < temp && temp < tMax){
    
    hitData.t = temp;
    hitData.point = ray.pointAtParameter(temp);
    hitData.normal = (hitData.point - this->m_centre)/this->m_radius;  
    return true;
  }
  return false;
}
