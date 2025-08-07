cmake_minimum_required(VERSION 3.20)
project(Spider)
set (PostgreSQL_ADDITIONAL_VERSIONS "17")

# Устанавливаем опцию компилятора для работы с UTF-8
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

# Установка пути к Boost
set(BOOST_ROOT "G:/boost_1_88_0") # Путь к папке, в которой установлен Boost

# Установка пути к Gumbo
set(GUMBO_INCLUDE_DIR "G:/vcpkg/packages/gumbo_x64-windows/include") # Путь к заголовочным файлам Gumbo
set(GUMBO_LIB_DIR "G:/vcpkg/packages/gumbo_x64-windows/lib")         # Путь к библиотекам Gumbo


set(PROJECT_SOURCES
        ParcerINI.h
        ParcerINI.cpp
        HTTPclient.h
        HTTPclient.cpp
        ParcerHTML.h
        ParcerHTML.cpp
        database.h
        database.cpp
        indexator.h
        indexator.cpp
        main.cpp
)

# Поиск и подключение Boost
#find_package(Boost 1.88.0 COMPONENTS locale REQUIRED)
find_package(Boost 1.88.0 COMPONENTS system thread locale REQUIRED)

find_package(OpenSSL REQUIRED)

add_executable(Spider ${PROJECT_SOURCES})

# Включение директорий Boost
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})

# Связывание библиотеки Boost с проектом
#target_link_libraries(Spider ${Boost_LIBRARIES})
target_link_libraries(Spider ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})


# Включение директорий Gumbo
include_directories(${GUMBO_INCLUDE_DIR})
target_link_libraries(Spider "${GUMBO_LIB_DIR}/gumbo.lib")

add_subdirectory("G://libpqxx-7.9.2" libpqxx-build) # Путь к libpq++
target_compile_features(Spider PRIVATE cxx_std_17) # Включение C++17
target_link_libraries(Spider pqxx)