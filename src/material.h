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

namespace N_Material {
  float shlick(float cos, float refIndx);
}

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

class Metal : public Material {
  private:
  Vec3 m_albedo;
  float m_fuzziness;

  public:
  Metal(): m_albedo{Vec3{0.0f, 0.0f, 0.0f}}, m_fuzziness(1.0f) {};
  Metal(const Vec3& albedo, float f): m_albedo{albedo} {if (f < 1) m_fuzziness = f; else m_fuzziness = 1.0f;};
  virtual bool scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scattered) const override {
    Vec3 reflected = Vec::reflect(rayIn.direction().unit_vector(), hitData.normal);
    scattered = Ray(hitData.point, reflected + m_fuzziness*Vec::randInUnitSphere(), 1.0f);
    attenuation = m_albedo;
    return scattered.direction().dot(hitData.normal) > 0; 
  }
};

class Dielectric: public Material {
  private:
  float m_refractionIndex;

  public:
  Dielectric(): m_refractionIndex{0.0f}{};
  Dielectric(float refIndex): m_refractionIndex{refIndex}{};
    
  virtual bool scatter(const Ray& rayIn, const HitData& hitData, Vec3& attenuation, Ray& scattered) const override {
    Vec3 outwardNormal;
    Vec3 reflected = Vec::reflect(rayIn.direction(), hitData.normal);
    float refIndex;
    attenuation = Vec3{1.0f, 1.0f, 1.0f};
    Vec3 refracted;
    float reflectProbe;
    float cos;

    if (rayIn.direction().dot(hitData.normal) > 0){
      outwardNormal = Vec3{0.0f, 0.0f, 0.0f} - hitData.normal;
      cos = m_refractionIndex*(rayIn.direction().dot(hitData.normal)/rayIn.direction().length());
      refIndex = m_refractionIndex;
    }
    else {
      outwardNormal = hitData.normal;
      refIndex = 1.0f / m_refractionIndex;
      cos = - rayIn.direction().dot(hitData.normal) / rayIn.direction().length();
    }

    if (refracted.reflect(rayIn.direction(), outwardNormal, refIndex)){
      reflectProbe = N_Material::shlick(cos, m_refractionIndex);
    }
    else {
      scattered = Ray(hitData.point, reflected, 1.0f);
      reflectProbe = 1.0f;
    }
    
    if (Rand::random(0.0f, 1.0f) < reflectProbe){
      scattered = Ray(hitData.point, reflected, 1.0f);
    }
    else{
      scattered = Ray(hitData.point, refracted, 1.0f);
    }
    return true;
  }
};

