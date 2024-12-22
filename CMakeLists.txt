cmake_minimum_required(VERSION 3.10)
project(RaylibProject LANGUAGES CXX)

# Define a versão do C++ utilizada
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona o diretório dos headers (include)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Adiciona o diretório das bibliotecas (lib)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Busca todos os arquivos .cpp na pasta src
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/Algoritmos/*.cpp)

# Cria o executável
add_executable(sortViewer ${SRC_FILES})

# Linka a Raylib e bibliotecas adicionais de acordo com o sistema operacional
if (WIN32)
    target_link_libraries(sortViewer raylib opengl32 gdi32 winmm)
elseif (UNIX)
    target_link_libraries(sortViewer raylib GL m pthread dl rt X11)
endif()
