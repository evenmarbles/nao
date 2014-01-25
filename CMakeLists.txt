cmake_minimum_required(VERSION 2.8)
project(nao)

find_package(qibuild)

add_definitions(" -DDEBUG ")
add_definitions(" -DWALL ")

include_directories(BEFORE "${CMAKE_CURRENT_SOURCE_DIR}")

# Create a list of source files
set(NAO_SRC_WRAPPED
    core/common/worldobject.cpp
    core/common/ball.cpp
    core/common/worldobjectmanager.cpp
)
set(NAO_SRC
    core/vision/detector.cpp
    core/vision/debug/debugballdetector.cpp
    core/vision/balldetector.cpp
    naointerface.cpp
    main.cpp
    ${NAO_SRC_WRAPPED}
)

# List of the public headers which are wrapped
# chek it against swit -MM naointerface.i
set(NAO_H_WRAPPED
    core/common/worldobject.h
    core/common/ball.h
    core/common/worldobjectmanager.h
)
set(NAO_H
    core/common/enums.h
    core/vision/detector.h
    core/vision/debug/debugballdetector.h
    core/vision/balldetector.h
    naointerface.h
    ${NAO_H_WRAPPED}
)

option(NAO_IS_REMOTE
    "nao is compiled as a remote module (ON or OFF)"
    ON)

if(NAO_IS_REMOTE)
    add_definitions(" -DNAO_IS_REMOTE ")
    # Create a executable named nao
    # with the source file: main.cpp
    qi_create_bin(nao ${NAO_SRC} ${NAO_H})
else()
    # Create a plugin, that is a shared library, and make
    # sure it is build in lib/naoqi
    qi_create_lib(nao SHARED ${NAO_SRC} ${NAO_H} SUBFOLDER naoqi)
endif()

# Tell CMake that nao-vision depends on ALCOMMON.
# This will set the libraries to link nao-vision with,
# the include paths.
qi_use_lib(nao ALCOMMON ALVISION OPENCV2_CORE OPENCV2_IMGPROC OPENCV2_HIGHGUI)

set(SWIG_MODULE_naointerface_DEPS "${CMAKE_CURRENT_SOURCE_DIR}/naointerface.i")
#foreach(dep IN LISTS NAO_H_WRAPPED)
#    list(APPEND SWIG_MODULE_naointerface_DEPS "${CMAKE_CURRENT_SOURCE_DIR}/${dep}")
#endforeach()
#qi_stage_lib(nao nao
#    CUSTOM_CODE
#    "set(SWIG_MODULE_naointerface_DEPS \"${CMAKE_CURRENT_SOURCE_DIR}\" CACHE INTERNAL \"\" FORCE)"
#)
qi_install_header(${NAO_H} KEEP_RELATIVE_PATHS)

qi_add_optional_package(PYTHON)
include(qibuild/swig/python)
set(SWIG_MODULE_naointerface_EXTRA_DEPS ${NAO_H_WRAPPED})
qi_swig_wrap_python(naointerface naointerface.i SRC ${NAO_SRC_WRAPPED})
qi_install_header(naointerface.i KEEP_RELATIVE_PATHS)

# Add a simple test:
enable_testing()
qi_create_test(test_nao "test.cpp")
