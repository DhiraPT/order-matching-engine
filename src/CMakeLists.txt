# CMakeList.txt : CMake project for OrderMatchingEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(OrderMatchingEngine main.cpp)

# Link the library to the executable
target_link_libraries(OrderMatchingEngine PRIVATE OrderMatchingLib)

# TODO: Add tests and install targets if needed.
