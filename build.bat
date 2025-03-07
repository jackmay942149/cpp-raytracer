@echo off
:: Compile the program
echo Compiling program...
g++ -o build/main src/vec.cpp src/sphere.cpp src/main.cpp src/scene.cpp src/rand.cpp src/material.cpp

:: Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed with error code %errorlevel%.
    exit /b %errorlevel%
)

:: If successful, run the compiled program
echo Compilation successful! Running the program...
start "" /wait build/main.exe

:: Launch image
start ./res/example.ppm

echo Done.
exit
