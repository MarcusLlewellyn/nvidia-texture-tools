
option(BUILD_TESTS "Build tests" ON)
option(BUILD_TOOLS "Build tools" ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${NV_SOURCE_DIR}/extern/poshlib)
INCLUDE_DIRECTORIES(${NV_SOURCE_DIR}/extern/stb)

SUBDIRS(nvcore)
SUBDIRS(nvmath)
SUBDIRS(nvimage)
SUBDIRS(nvthread)
SUBDIRS(nvtt)
SUBDIRS(bc6h)
SUBDIRS(bc7)

# OpenGL
#INCLUDE(FindOpenGL)
#IF(OPENGL_FOUND)
#	MESSAGE(STATUS "Looking for OpenGL - found")
#ELSE(OPENGL_FOUND)
#	MESSAGE(STATUS "Looking for OpenGL - not found")
#ENDIF(OPENGL_FOUND)

# GLUT
#INCLUDE(FindGLUT)
#IF(GLUT_FOUND)
#	MESSAGE(STATUS "Looking for GLUT - found")
#ELSE(GLUT_FOUND)
#	MESSAGE(STATUS "Looking for GLUT - not found")
#ENDIF(GLUT_FOUND)

# DirectX
#INCLUDE(${NV_CMAKE_DIR}/FindDirectX.cmake)
#IF(DX10_FOUND)
#	MESSAGE(STATUS "Looking for DirectX - found")
#ELSE(DX10_FOUND)
#	MESSAGE(STATUS "Looking for DirectX - not found")
#ENDIF(DX10_FOUND)

# GLEW
#INCLUDE(${NV_CMAKE_DIR}/FindGLEW.cmake)
#IF(GLEW_FOUND)
#	MESSAGE(STATUS "Looking for GLEW - found")
#ELSE(GLEW_FOUND)
#	MESSAGE(STATUS "Looking for GLEW - not found")
#ENDIF(GLEW_FOUND)

# Cg
#INCLUDE(${NV_CMAKE_DIR}/FindCg.cmake)
#IF(CG_FOUND)
#	MESSAGE(STATUS "Looking for Cg - found")
#ELSE(CG_FOUND)
#	MESSAGE(STATUS "Looking for Cg - not found")
#ENDIF(CG_FOUND)

# CUDA
#FIND_PACKAGE(CUDA)
IF(CUDA_FOUND)
    IF(MINGW)
        MESSAGE(STATUS "Looking for CUDA - not supported on MinGW")
        UNSET(CUDA_FOUND)
    ENDIF(MINGW)
    IF(CUDA_FOUND)
        SET(HAVE_CUDA ${CUDA_FOUND} CACHE BOOL "Set to TRUE if CUDA is found, FALSE otherwise")
        MESSAGE(STATUS "Looking for CUDA - found")
    ENDIF(CUDA_FOUND)
ELSE(CUDA_FOUND)
    MESSAGE(STATUS "Looking for CUDA - not found")
ENDIF(CUDA_FOUND)

# OpenMP
# if (NOT APPLE)
#     INCLUDE(FindOpenMP)
#     IF(OPENMP_FOUND)
#         SET(HAVE_OPENMP ${OPENMP_FOUND} CACHE BOOL "Set to TRUE if OpenMP is found, FALSE otherwise")
#         MESSAGE(STATUS "Looking for OpenMP - found")
#         SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#         SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#     ELSE(OPENMP_FOUND)
#         MESSAGE(STATUS "Looking for OpenMP - not found")
#     ENDIF(OPENMP_FOUND)
# endif()


# Threads
FIND_PACKAGE(Threads REQUIRED)
MESSAGE(STATUS "Use thread library: ${CMAKE_THREAD_LIBS_INIT}")
SET(LIBS ${LIBS} ${CMAKE_THREAD_LIBS_INIT})

# configuration file
INCLUDE(CheckIncludeFiles)

CHECK_INCLUDE_FILES("unistd.h" HAVE_UNISTD_H)
CHECK_INCLUDE_FILES("stdarg.h" HAVE_STDARG_H)
CHECK_INCLUDE_FILES("signal.h" HAVE_SIGNAL_H)
CHECK_INCLUDE_FILES("execinfo.h" HAVE_EXECINFO_H)
CHECK_INCLUDE_FILES("malloc.h" HAVE_MALLOC_H)
CHECK_INCLUDE_FILES("dispatch/dispatch.h" HAVE_DISPATCH_H)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/nvconfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/nvconfig.h)

