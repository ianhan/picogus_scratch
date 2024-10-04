if (PICO_SDK)
    add_library(libdlo INTERFACE)
    target_sources(libdlo INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/dlo_grfx.c
            ${CMAKE_CURRENT_LIST_DIR}/dlo_mode.c
            ${CMAKE_CURRENT_LIST_DIR}/dlo_usb.c
            ${CMAKE_CURRENT_LIST_DIR}/libdlo.c
            ${CMAKE_CURRENT_LIST_DIR}/usb.c)
    target_include_directories(libdlo INTERFACE ${CMAKE_CURRENT_LIST_DIR})
endif()
