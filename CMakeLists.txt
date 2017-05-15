cmake_minimum_required(VERSION 3.6)
project(airport)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Failure.cpp
        Failure.h
        Main.cpp
        Test.cpp
        Test.h
        TestHarness.h
        TestRegistry.cpp
        TestRegistry.h
        TestResult.cpp
        TestResult.h
        TestAirport.cpp
        Reservation.cpp Reservation.h Airport.cpp Airport.h Plane.cpp Plane.h User.cpp User.h Client.cpp Client.h)

add_executable(CppUnitLite ${SOURCE_FILES})