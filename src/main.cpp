#include <iostream>
#include <fstream>
#include <random>
#include "shape.h"
#include "vec.h"
#include "ray.h"
#include "sphere.h"
#include "scene.h"
#include "float.h"
#include "camera.h"



float random(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
};

int main(){
  // Define # of coloumns and rows
  int nx = 1920/2;
  int ny = 1080/2;
  int ns = 100;
  
  // Define output file
  std::ofstream outFile("res/example.ppm");
  
  // Output to file
  outFile << "P3\n" << nx << " " << ny << "\n255\n";

    // Define Scene
  Camera cam;
  Sphere s1 {Sphere(Vec3{0.0f, 0.0f, -1.0f}, 0.5f)};
  Sphere s2 {Sphere(Vec3{0.0f, -100.5f, -1.5f}, 100.0f)};
  Sphere s3 {Sphere(Vec3(0.0f, 0.0f, -0.5f), 0.2f)};
  Scene scene;
  scene.add(&s1);
  scene.add(&s2);
  scene.add(&s3);
    

  for (int j = ny-1; j >=0; j--){
    for (int i = 0; i < nx; i++){

      Vec3 color {0.0f, 0.0f, 0.0f};

      for (int s = 0; s < ns; s++){
        
        // Define current uv coord
        float u = float(i + random(0.0f, 1.0f)) / float(nx);
        float v = float(j + random(0.0f, 1.0f)) / float(ny);

        // Define current ray and test it
        Ray ray = cam.getRay(u, v);
        HitData hit;
        
        if (scene.hit(ray, 0.0f, 10000.0f, hit)){
          color += 0.5f * (hit.normal + 1.0f);
        }
        else {
          Vec3 unit_direction = ray.direction().unit_vector();
          float t = 0.5f * (unit_direction.y() + 1.0f);
          color += Vec3(1.0f, 1.0f, 1.0f)*(1.0f-t) + Vec3(0.5f, 0.7f, 1.0f)*t;
        }
      }

      // Average color samples
      color /= ns;
      
      // Output to file
      outFile << color.r() << " " << color.g() << " " << color.b() << "\n";
    }
  }

    // Close the file
    outFile.close();
    
}
