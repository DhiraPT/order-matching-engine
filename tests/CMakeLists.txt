# Fetch Catch2 using FetchContent
include(FetchContent)

FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v3.4.0 # Use the latest version
)

FetchContent_MakeAvailable(Catch2)

# Add the test executable
add_executable(OrderMatchingTests main.cpp)

# Link Catch2 with main function and your library
target_link_libraries(OrderMatchingTests PRIVATE Catch2::Catch2WithMain OrderMatchingLib)

# Enable automatic test discovery
include(CTest)
include(Catch)
catch_discover_tests(OrderMatchingTests)
