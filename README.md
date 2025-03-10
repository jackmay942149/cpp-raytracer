## 🌟 C++ Raytracer  
A personal project where I’m learning raytracing in C++ with guidance from [Raytracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html).  

### 📋 Requirements:
- **g++**: Required to build from source.
- **PPM Viewer**: For viewing output. My personal recommendation is [GIMP](https://www.gimp.org/).  
  Alternatively, you can use my [PPM to BMP Converter](https://github.com/jackmay942149/ppm2bmp-converter) to convert PPM files to BMP format for easier viewing.

### 🔧 **Compilation Steps (Requires g++):**
1. Run `build.bat`.
2. Wait for the build process to complete.

### ⚙️ **Alternative Compilation Steps:**
1. In the top directory, run:
   ```bash
   g++ -o build/main src/vec.cpp src/sphere.cpp src/main.cpp src/scene.cpp src/rand.cpp src/material.cpp
*Note: If compilation errors occur, ensure the command matches the one in `build.bat`.*

2. Execute the generated `build/main.exe`.
3. Open the output file `res/example.ppm` with your preferred PPM viewer or use the [PPM to BMP Converter](https://github.com/jackmay942149/ppm2bmp-converter) to convert it to BMP.
