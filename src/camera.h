#pragma once

#include "ray.h"
#include "vec.h"

class Camera{
  private:
  Vec3 m_origin;
  Vec3 m_lowerLeftCorner;
  Vec3 m_horizontal;
  Vec3 m_vertical;

  public:
  Camera():
    m_origin {Vec3(0.0f, 0.0f, 0.0f)},
    m_lowerLeftCorner {Vec3(-2.0f, -1.0f, -1.0f)},
    m_horizontal {Vec3(4.0f, 0.0f, 0.0f)},
    m_vertical {Vec3(0.0f, 2.0f, 0.0f)}{};

  Ray getRay(float u, float v) {return Ray(m_origin, m_lowerLeftCorner + u*m_horizontal + v*m_vertical - m_origin, 1.0f);}
};
