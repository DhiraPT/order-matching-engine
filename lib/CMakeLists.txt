# Build the library
add_library(OrderMatchingLib
    order.cpp
    order_book.cpp
)

# Include directory for the library
target_include_directories(OrderMatchingLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
