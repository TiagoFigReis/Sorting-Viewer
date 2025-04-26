# Sorting-Viewer
This is a project that allows the visualization of basic sorting algorithms.

## Instructions to Run the Project

1. Open the terminal in the folder containing the project and type the following commands:

```bash
mkdir build
cd build
run cmake .. or cmake .. -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++ to specify that you want to use g++
cmake --build .
./sortViewer