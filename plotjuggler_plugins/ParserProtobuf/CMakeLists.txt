
include_directories( ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

find_package(Protobuf CONFIG REQUIRED)

if( Protobuf_FOUND)
    message(STATUS "[Protobuf] found")
    QT6_WRAP_UI ( UI_SRC
        protobuf_parser.ui
        )

    include_directories(${Protobuf_INCLUDE_DIRS})

    add_library(ProtobufParser SHARED
        error_collectors.cpp
        protobuf_parser.cpp
        protobuf_factory.cpp
        protobuf_parser.h
        ${UI_SRC}  )

    target_link_libraries(ProtobufParser
        Qt6::Widgets
        Qt6::Svg
        Qt6::Xml
        ${Protobuf_LIBRARIES}
        plotjuggler_base
        plotjuggler_qwt)

    install(TARGETS ProtobufParser DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )
else()
    message("[Protobuf] not found: skipping compilatiopn of plugin ProtobufParser")
endif()
