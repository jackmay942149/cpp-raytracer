#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <array>

class Vec3 {
  private:
  // Members
  std::array<float, 3> m_vec3;
  
  public:
  // Constructors
  Vec3(): m_vec3{0, 0, 0}{};
  explicit Vec3(float x, float y, float z): m_vec3{x, y, z}{};
  Vec3(const Vec3& v): m_vec3{v.x(), v.y(), v.z()}{}; 

  // Getters
  float x() const {return m_vec3[0];}
  float y() const {return m_vec3[1];}
  float z() const {return m_vec3[2];}
  int r() {return static_cast<int>(255.99 * m_vec3[0]);}
  int g() {return static_cast<int>(255.99 * m_vec3[1]);}
  int b() {return static_cast<int>(255.99 * m_vec3[2]);}

  // Operators
  Vec3 operator/(const float t) const {return Vec3(m_vec3[0]/t, m_vec3[1]/t, m_vec3[2]/t);} // returns by value
  Vec3 operator*(const float t) const {return Vec3(m_vec3[0]*t, m_vec3[1]*t, m_vec3[2]*t);} // returns by value
  Vec3 operator+(const float t) const {return Vec3(m_vec3[0]+t, m_vec3[1]+t, m_vec3[2]+t);} // returns by value
  Vec3 operator+(const Vec3 other) const {return Vec3(m_vec3[0]+ other.x(), m_vec3[1]+ other.y(), m_vec3[2]+ other.z());}
  Vec3 operator-(const Vec3 other) const {return Vec3(m_vec3[0]- other.x(), m_vec3[1]- other.y(), m_vec3[2]- other.z());}
  Vec3 operator+=(const Vec3 other) {m_vec3[0] += other.x(); m_vec3[1] += other.y(); m_vec3[2] += other.z(); return *this;}
  Vec3 operator/=(const float a) {m_vec3[0] /= a; m_vec3[1] /= a; m_vec3[2] /= a; return *this;}
  Vec3 operator*(const Vec3 other) const {return Vec3{m_vec3[0]*other.x(), m_vec3[1]*other.y(), m_vec3[2]*other.z()};}
                    
  // Methods
  float length() const {return ::sqrt(m_vec3[0]*m_vec3[0] + m_vec3[1]*m_vec3[1] + m_vec3[2]*m_vec3[2]);} // returns r-value
  Vec3 unit_vector() const {return *this / this->length();} // returns by value (does not affect original
  float dot(const Vec3 other) const {return this->x()*other.x() + this->y()*other.y() + this->z()*other.z();}
  void sqrt() {m_vec3[0] = ::sqrt(this->x()); m_vec3[1] = ::sqrt(this->y()); m_vec3[2] = ::sqrt(this->z());} // affects original
  bool reflect(const Vec3& inVector, const Vec3& normal, float refractionIndex);  
};

// Commutative Operators
Vec3 operator*(const float f, const Vec3&);

namespace Vec{
  Vec3 randInUnitSphere();
  Vec3 reflect(const Vec3&, const Vec3&);
}
