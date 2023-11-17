#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <string>
#include <KeyList.h>
#include <HashMap.h>
#include <catch.hpp>

TEST_CASE("KeyList Test")
{

    SECTION("Adding and Getting <1, 2>")
    {
        KeyList<int, int> test_list;
        test_list.set(1, 2);
        REQUIRE(test_list.get(1) == 2);
    }
    SECTION("To String")
    {
        KeyList<int, int> test_list;
        test_list.set(1, 2);
        REQUIRE(test_list.toString() == "[<1, 2>]");
    }
    SECTION("Adding and getting <2, 3>, <3, 4>")
    {
        KeyList<int, int> test_list;
        test_list.set(1, 2);
        test_list.set(2, 3);
        test_list.set(3, 4);
        REQUIRE(test_list.get(2) == 3);
        REQUIRE(test_list.get(3) == 4);
    }
    SECTION("REMOVE <1, 2> GET 1")
    {
        KeyList<int, int> test_list;
        test_list.set(1, 2);
        test_list.set(2, 3);
        test_list.set(3, 4);
        test_list.remove(1);
        REQUIRE(test_list.get(2) == 3);
        REQUIRE_THROWS_AS(test_list.get(1), std::exception);
    }
}

TEST_CASE("HashMap Test")
{
    SECTION("Adding and Getting <1, 2>")
    {
        HashMap<int, int> test_map;
        test_map.set(1, 2);
        REQUIRE(test_map.get(1) == 2);
    }

    SECTION("Adding and get <1, 'test'>")
    {
        HashMap<int, std::string> test_string_map = HashMap<int, std::string>();
        test_string_map.set(1, "test");
        std::string res = test_string_map.get(1);
        REQUIRE(res == "test");
    }
}
