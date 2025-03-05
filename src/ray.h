#pragma once
#include "vec.h"

class Ray{
  private:
  // Members
  Vec3 m_origin {Vec3()};
  Vec3 m_direction {Vec3()};
  float m_magnitude {1.0f};

  public:
  // Constructor
  Ray() {m_origin = {Vec3()}; m_direction = {Vec3()}; m_magnitude = 1.0f;}
  Ray(Vec3 origin, Vec3 direction, float magnitude) {m_origin = {origin}; m_direction = {direction}; m_magnitude = magnitude;}

  // Getters
  Vec3 origin() const { return m_origin;}
  Vec3 direction() const {return m_direction;}
  float magnitude() {return m_magnitude;}

  // Methods
  Vec3 color();
  bool hitSphere(const Vec3&, float radius);
};
