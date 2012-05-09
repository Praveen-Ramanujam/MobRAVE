#############################
# qtosgrave openrave plugin #
#############################

# OpenRave
include(${CMAKE_MODULE_PATH}/FindOpenRAVE.cmake)
if( NOT OPENRAVE_FOUND )
  message(FATAL_ERROR "could not find openrave, check for openrave-config in path")
endif( NOT OPENRAVE_FOUND )

include_directories(${OPENRAVE_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} . ../../ ../include)
link_directories(${OPENRAVE_LINK_DIRS})

if(APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -undefined dynamic_lookup")
endif(APPLE)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

include(${CMAKE_SOURCE_DIR}/modules-cmake/FindGLEW.cmake)
if(GLEW_FOUND)
  include_directories(${GLEW_INCLUDE_PATH})
else()
  if( MSVC )
    set(GLEW_LIBRARY glew32)
  else()
    MESSAGE(FATAL_ERROR "Looking for glew.h -- not found\n")
  endif()
endif()

if( MSVC )
  set(QT_MOC_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/moc.exe")
else()
  find_package(Qt4)
endif()

# Include directories for QT4.
include_directories(${QT_INCLUDE_DIR})
include_directories(${QT_QTOPENGL_INCLUDE_DIR})
message(STATUS "QT dirs: " ${QT_INCLUDE_DIR} " OPENGL: " ${QT_QTOPENGL_INCLUDE_DIR})

include(${CMAKE_SOURCE_DIR}/modules-cmake/FindOSG.cmake)

if ( OSG_FOUND )

  include_directories(${OSG_INCLUDE_DIR})
  set(OPENRAVE_LINK_DIRS ${OPENRAVE_LINK_DIRS} "/usr/lib" "/usr/share/qt4/lib")
  
  
  include(${CMAKE_SOURCE_DIR}/modules-cmake/FindGLEW.cmake)
  link_directories(${OPENRAVE_LINK_DIRS})

  message(STATUS "Detected Qt/OSG GUI, making plugin")

#  set(QTOSG_SRCS objecttree.cpp treemodel.cpp Item.cpp treeitem.cpp qtosgviewer.cpp qtosgravemain.cpp GraphicsWindowQt.cpp osgviewerQtContext.h osgpick.cpp)
  set(QTOSG_SRCS objecttree.cpp treemodel.cpp Item.cpp treeitem.cpp qtosgviewer.cpp qtosgravemain.cpp osgviewerQtContext.h osgpick.cpp)
  set(QTOSG_MOCS qtosgviewer.h treemodel.h)
  set(QTOSG_RCCS qtosgviewer.qrc)

  # generate rules for building source files from the resources
  qt4_add_resources(QTOSG_RCC_SRCS ${QTOSG_RCCS})

  # generate rules for building source files that moc generates
  #if( MSVC )
  #  set(QTCOIN_MOC_SRCS "${CMAKE_CURRENT_BINARY_DIR}/moc_qtcoinviewer.cpp")
  #  add_custom_command(
  #    OUTPUT ${QTCOIN_MOC_SRCS}
  #    COMMAND ${QT_MOC_EXECUTABLE}
  #    ARGS -I${CMAKE_SOURCE_DIR}/inc/qt/include -I${CMAKE_SOURCE_DIR}/inc/qt/include/qt -I${CMAKE_SOURCE_DIR}/inc/qt/include/qtgui -I${CMAKE_SOURCE_DIR}/inc/qt/include/qtcore -I${CMAKE_SOURCE_DIR}/inc/qt/include/qtopengl -o ${QTCOIN_MOC_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/qtcoinviewer.h
  #    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/qtcoinviewer.h
  #    )
  #else()
    include( ${QT_USE_FILE} )
    qt4_wrap_cpp(QTOSG_MOC_SRCS ${QTOSG_MOCS})
  #endif()

  # build sources, moc'd sources, and rcc'd sources
  add_library(qtosgrave SHARED ${QTOSG_SRCS} ${QTOSG_MOC_SRCS} ${QTOSG_RCC_SRCS})

  set (extLIBS ${QT_LIBRARIES} ${LIBXML2_LIBRARIES} ${OSG_LIBRARY} ${OSGDB_LIBRARY} 
               ${OSGGA_LIBRARY} ${OSGTEXT_LIBRARY} ${OSGVIEWER_LIBRARY} ${OSGMANIPULATOR_LIBRARY}
               ${OSGQT_LIBRARY} ${OSGSHADOW_LIBRARY}
               ${GLEW_LIBRARY} ${PTHREADS_LIBRARY} ${FFMPEG_LIBRARIES} ${QT_QTOPENGL_LIBRARY})

  if( MSVC )
    set (extLIBS ${extLIBS} opengl32 glu32 imm32 winmm ws2_32 vfw32 glew32)
  endif()

  if( AVSTUFF_FOUND )
    set(extLIBS ${extLIBS} ${FFMPEG_LIBRARIES})
  endif()

  # Debug.
  if (QT_QTOPENGL_FOUND )
      message(STATUS "QTOPENGL library FOUND")
      message(STATUS "QTOPENGL lib: " ${QT_QTOPENGL_LIBRARY})
  else()
      message(STATUS "QTOPENGL library NOT FOUND!!!")
  endif()
  
  # Debug.
  message(STATUS "Link libraries: " ${extLIBS})
  
  target_link_libraries (qtosgrave ${extLIBS} ${OPENRAVE_LIBRARY})
  include_directories("${CMAKE_SOURCE_DIR}")

  add_dependencies(qtosgrave ${OPENRAVE_LIBRARY})

  set(QTOSG_COMPILE_FLAGS "${PLUGIN_COMPILE_FLAGS}")
  set(QTOSG_LINK_FLAGS "${PLUGIN_LINK_FLAGS}")
  if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # have to turn off optimizations or else qtcoin crashes!!
    # (probably something to do with this being  a plugin and SoQt relies on static variables?)
    # another possiblity is that openrave-core also links to Coin3D...
    set(QTOSG_COMPILE_FLAGS "${QTOSG_COMPILE_FLAGS} -O0")
  endif()

  if( MSVC )
    # soqt libs not compiled correct so multiply defined symbols
    set(QTOSG_LINK_FLAGS "${QTOSG_LINK_FLAGS} /FORCE:MULTIPLE")
  endif()

  set_target_properties(qtosgrave PROPERTIES COMPILE_FLAGS "${QTOSG_COMPILE_FLAGS} ${OPENRAVE_CXXFLAGS}" 
                                      LINK_FLAGS "${QTOSG_LINK_FLAGS} ${OPENRAVE_LINK_FLAGS} ${PLUGIN_LINK_FLAGS}")
  install(TARGETS qtosgrave DESTINATION share/openrave/plugins)

else()
    message(SEND_ERROR "ERROR: Could not find OSG. Please install OSG (http://www.openscenegraph.org/projects/osg)")
endif()
