#include<iostream>
#include<fstream>
#include "vec.h"

int main(){
  // Define # of coloumns and rows
  int nx = 200;
  int ny = 100;

  // Define output file
  std::ofstream ofile("res/example.ppm");  

  // Output to file
  ofile << "P3\n" << nx << " " << ny << "\n255\n";

  for (int j = ny-1; j >=0; j--){
    for (int i = 0; i < nx; i++){
      Vec3 color {float(i)/float(nx), float(j)/float(ny), 0.2f}; // [0-1] Space
      int ir = int(255.99*color.r());
      int ig = int(255.99*color.g());                                  // [0-255] Space
      int ib = int(255.99*color.b());
      ofile << ir << " " << ig << " " << ib << "\n";
    }
  }

    // Close the file
    ofile.close();
}
