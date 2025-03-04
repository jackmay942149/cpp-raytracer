#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <array>

class Vec3 {
  private:
  // Members
  std::array<float, 3> m_vec3 = {0, 0, 0};
  
  public:
  // Constructors
  Vec3() {m_vec3 = {0, 0, 0};}
  explicit Vec3(float x, float y, float z) {m_vec3 = {x, y, z};}

  // Getters
  float x() {return m_vec3[0];}
  float y() {return m_vec3[1];}
  float z() {return m_vec3[2];}
  float r() {return m_vec3[0];}
  float g() {return m_vec3[1];}
  float b() {return m_vec3[2];}

  // Methods
  
  
};
