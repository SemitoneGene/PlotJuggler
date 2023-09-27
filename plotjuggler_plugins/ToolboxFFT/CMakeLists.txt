
include_directories( ../ )

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)

add_subdirectory(KissFFT)

QT6_WRAP_UI ( UI_SRC
    toolbox_FFT.ui
    )

add_library(ToolboxFFT SHARED
    toolbox_FFT.cpp
    toolbox_FFT.h
    ${UI_SRC}  )

target_link_libraries(ToolboxFFT
    Qt6::Widgets
    Qt6::Svg
    Qt6::Xml
    kissfft
    plotjuggler_base
    plotjuggler_qwt)

install(TARGETS ToolboxFFT DESTINATION ${PJ_PLUGIN_INSTALL_DIRECTORY}  )
