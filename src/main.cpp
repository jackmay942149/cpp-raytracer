#include<iostream>
#include<fstream>
#include "vec.h"
#include "ray.h"

int main(){
  // Define # of coloumns and rows
  int nx = 1920/2;
  int ny = 1080/2;

  // Define output file
  std::ofstream outFile("res/example.ppm");
  
  // Output to file
  outFile << "P3\n" << nx << " " << ny << "\n255\n";

  // Define screen coords
  Vec3 lowerLeftCorner {-2.0f, -1.0f, -1.0f};
  Vec3 horizontal {4.0f, 0.0f, 0.0f};
  Vec3 vertical {0.0f, 2.0f, 0.0f};
  Vec3 origin {0.0f, 0.0f, 0.0f};

  for (int j = ny-1; j >=0; j--){
    for (int i = 0; i < nx; i++){
      // Define current uv coord
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);

      // Define current ray and test it
      Ray ray {origin, lowerLeftCorner + u*(horizontal) + v*(vertical), 1.0f};
      Vec3 color = ray.color();

      // Output to file
      outFile << color.r() << " " << color.g() << " " << color.b() << "\n";
    }
  }

    // Close the file
    outFile.close();
    
}
