#include "main.cpp"

//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>
//юнит-тесты
List list;
TEST_CASE("Test PushBack", "[PushBack]") {
    list.PushBack(8);
    list.PushBack(15);
    REQUIRE(list.Size() == 2);
}
TEST_CASE("Test PushFront", "[PushFront]") {
    list.PushFront(3);
    list.PushFront(5);
    REQUIRE(list.Size() == 4);
}
TEST_CASE("Test PopBack", "[PopBack]") {
    list.PopBack();
    list.PopBack();
    REQUIRE(list.Size() == 2);
}
TEST_CASE("Test PopFront", "[PopFront]") {
    list.PopFront();
    list.PopFront();
    REQUIRE(list.Size() == 0);
}
TEST_CASE("Empty", "[Check empty list]") {
    SECTION("PopBack") {
        REQUIRE_THROWS(list.PopBack());
    }
    SECTION("PopFront") {
        REQUIRE_THROWS(list.PopFront());
    }
}