cmake_minimum_required(VERSION 3.10)

# Назва проєкту
project(FavoriteColors)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Увімкнути Debug за замовчуванням, якщо не задано явно
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Debug)
endif()

# Вказуємо, що треба зібрати виконуваний файл з main.cpp
add_executable(FavoriteColors FavoriteColors.cpp)
