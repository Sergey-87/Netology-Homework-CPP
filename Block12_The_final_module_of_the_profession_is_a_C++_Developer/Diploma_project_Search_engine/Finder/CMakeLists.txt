cmake_minimum_required(VERSION 3.20)
project(Finder)
set (PostgreSQL_ADDITIONAL_VERSIONS "17")

# Устанавливаем опцию компилятора для работы с UTF-8
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

# Путь к библиотекам Boost
set(BOOST_ROOT "G:/boost_1_88_0")

# Пути к файлам в проекте Spyder относительно Finder
set(SPIDER_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../Spider")

# Файлы для добавления из Spyder в Finder
set(SPIDER_FILES
    ${SPIDER_SOURCE_DIR}/database.h
    ${SPIDER_SOURCE_DIR}/database.cpp
    ${SPIDER_SOURCE_DIR}/ParcerINI.h
    ${SPIDER_SOURCE_DIR}/ParcerINI.cpp
)

set(PROJECT_SOURCES
    finder.h
    finder.cpp
    main.cpp
)


add_executable(Finder ${PROJECT_SOURCES} ${SPIDER_FILES})

# Включение директорий Boost
set(BOOST_ROOT ${EXT_BOOST_DIR})
set(BOOST_LIBRARYDIR "${EXT_BOOST_DIR}/stage/lib")
find_package(Boost 1.88.0 COMPONENTS system thread locale REQUIRED)
if(Boost_FOUND)
  target_include_directories(Finder PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_directories(Finder PRIVATE ${BOOST_LIBRARYDIR})
endif()

# Связывание библиотеки Boost с проектом
target_link_libraries(Finder ${Boost_LIBRARIES})

add_subdirectory("G://libpqxx-7.9.2" libpqxx-build) # Путь к libpq++
target_compile_features(Finder PRIVATE cxx_std_17) # Включим C++17
target_link_libraries(Finder pqxx)