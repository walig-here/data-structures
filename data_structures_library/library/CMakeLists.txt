add_library(
    ${LIB_TARGET_NAME}
    STATIC
    "src/dynamic-array.cpp"
)

target_include_directories(
    ${LIB_TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(
    ${LIB_TARGET_NAME}
    PROPERTIES 
        OUTPUT_NAME ${LIB_TARGET_NAME}
        PREFIX ""
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
