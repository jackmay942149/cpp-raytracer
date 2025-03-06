#pragma once

#include "ray.h"
#include "vec.h"
#include "shape.h"
#include "rand.h"
#include <iostream>

class Material {
  public:
  virtual bool scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scattered) const {return true;}
};

class Lambertian : public Material {
  private:
  Vec3 m_albedo;

  public:
  Lambertian(): m_albedo{Vec3{0.0f, 0.0f, 0.0f}} {};
  Lambertian(const Vec3& albedo): m_albedo{albedo} {};
  virtual bool scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scattered) const override {
    Vec3 target = hitData.point + hitData.normal + Vec::randInUnitSphere();
    scattered = Ray(hitData.point, target - hitData.point, 1.0f);
    attenuation = m_albedo;
    return true; 
  }
};

