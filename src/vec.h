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
  float x() const {return m_vec3[0];}
  float y() const {return m_vec3[1];}
  float z() const {return m_vec3[2];}
  int r() {return static_cast<int>(255.99 * m_vec3[0]);}
  int g() {return static_cast<int>(255.99 * m_vec3[1]);}
  int b() {return static_cast<int>(255.99 * m_vec3[2]);}

  // Operators
  Vec3 operator/(const float t) {return Vec3(m_vec3[0]/t, m_vec3[1]/t, m_vec3[2]/t);} // returns by value
  Vec3 operator*(const float t) {return Vec3(m_vec3[0]*t, m_vec3[1]*t, m_vec3[2]*t);} // returns by value
  Vec3 operator+(const Vec3 other) {return Vec3(m_vec3[0]+ other.x(), m_vec3[1]+ other.y(), m_vec3[2]+ other.z());}
  Vec3 operator-(const Vec3 other) {return Vec3(m_vec3[0]- other.x(), m_vec3[1]- other.y(), m_vec3[2]- other.z());}
                    
  // Methods
  float length() {return sqrt(m_vec3[0]*m_vec3[0] + m_vec3[1]*m_vec3[1] + m_vec3[2]*m_vec3[2]);} // returns r-value
  Vec3 unit_vector() {return *this / this->length();} // returns by value
  float dot(const Vec3 other){return this->x()*other.x() + this->y()*other.y() + this->z()*other.z();}
  
};
