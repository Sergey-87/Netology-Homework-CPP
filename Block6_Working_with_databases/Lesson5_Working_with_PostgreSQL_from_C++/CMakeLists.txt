cmake_minimum_required(VERSION 3.20)

project(ClientsDB)

set(PostgreSQL_ADDITIONAL_VERSIONS "17")

add_executable(ClientsDB main.cpp DB.cpp DB.h)

add_subdirectory("G:\\libpqxx-7.9.2" libpqxx-build)

target_compile_features(ClientsDB PRIVATE cxx_std_17)

target_link_libraries(ClientsDB PRIVATE pqxx)