
include_directories(  ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

QT6_WRAP_UI ( UI_SRC
    ../selectlistdialog.ui
    ulog_parameters_dialog.ui
    )

SET( SRC
    dataload_ulog.cpp
    ulog_parser.cpp
    ulog_parameters_dialog.cpp
    )

add_library(DataLoadULog SHARED ${SRC} ${UI_SRC}  )

target_link_libraries(DataLoadULog
    Qt6::Widgets
    Qt6::Svg
    Qt6::Xml
    plotjuggler_base)

install(TARGETS DataLoadULog DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )

