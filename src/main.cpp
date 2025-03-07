#include <iostream>
#include <fstream>
#include "material.h"
#include "shape.h"
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "scene.h"
#include "float.h"
#include "camera.h"
#include "rand.h"

int main(){
 
  // Define # of coloumns and rows
  int nx = 1920/2;
  int ny = 1080/2;
  int ns = 1;
  
  // Define output file
  std::ofstream outFile("res/example.ppm");
  
  // Output to file
  outFile << "P3\n" << nx << " " << ny << "\n255\n";

 // Define Scene
  Camera cam;
  Lambertian redMatte {Lambertian{Vec3{0.8f, 0.3f, 0.3f}}};
  Dielectric airMat {1.0f};
  Dielectric glassMat {1.5f};
  Dielectric diamondMat {2.4f};
  
  Sphere s1 {Sphere(Vec3{0.0f, 0.0f, -1.0f}, 0.5f, &redMatte)};
  Sphere s2 {Sphere(Vec3{0.0f, -100.5f, -1.5f}, 100.0f, new Lambertian{Vec3{0.8f, 0.8f, 0.0f}})};
  Sphere s3 {Sphere(Vec3{1.0f, 0.0f, -1.0f}, 0.5f, new Metal(Vec3{0.8f, 0.8f, 0.8f}, 0.3))};
  Sphere s4 {Sphere(Vec3{-1.0f, 0.0f, -1.0f}, 0.5f, &glassMat)};
  Sphere s5 {Sphere(Vec3{-1.0f, 0.0f, -1.0f}, -0.45f, &glassMat)};
  Scene scene;
  scene.add(&s1);
  scene.add(&s2);
  scene.add(&s3);
  scene.add(&s4);
  scene.add(&s5);

  for (int j = ny-1; j >=0; j--){
    for (int i = 0; i < nx; i++){

      Vec3 color {0.0f, 0.0f, 0.0f};

      for (int s = 0; s < ns; s++){
        
        // Define current uv coord
        float u = float(i + Rand::random(0.0f, 1.0f)) / float(nx);
        float v = float(j + Rand::random(0.0f, 1.0f)) / float(ny);

        // Define current ray and test it
        Ray ray = cam.getRay(u, v);
        HitData hit;

        color += scene.rayTrace(ray, 0.001f, 10000.0f, hit, 0);
      }

      // Average color samples
      color /= ns;
      color.sqrt(); // gamma correction
      
      // Output to file
      outFile << color.r() << " " << color.g() << " " << color.b() << "\n";
    }
  }

    // Close the file
    outFile.close();
    
}
