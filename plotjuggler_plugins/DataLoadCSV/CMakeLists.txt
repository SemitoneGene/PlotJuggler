
include_directories(  ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

QT6_WRAP_UI ( UI_SRC
    dataload_csv.ui
    datetimehelp.ui
    )

SET( SRC
    dataload_csv.cpp
    datetimehelp.cpp
    )

add_library(DataLoadCSV SHARED ${SRC} ${UI_SRC}  )
target_link_libraries(DataLoadCSV
    Qt6::Widgets
    Qt6::Svg
    Qt6::Xml
    plotjuggler_base
    QCodeEditor)


install(TARGETS DataLoadCSV DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )

