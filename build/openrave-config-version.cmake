set( PACKAGE_VERSION "0.5.0" )
if( "${PACKAGE_FIND_VERSION}" VERSION_EQUAL "0.5.0")
  set(PACKAGE_VERSION_EXACT 1)
endif()
if( "${PACKAGE_FIND_VERSION_MAJOR}.${PACKAGE_FIND_VERSION_MINOR}" EQUAL "0.5" )
  set(PACKAGE_VERSION_COMPATIBLE 1)
  if( "${PACKAGE_FIND_VERSION_MINOR}" GREATER 0 )
    if( "${PACKAGE_FIND_VERSION_MINOR}" LESS 3 )
      set(PACKAGE_VERSION_UNSUITABLE 1)
    endif()
  endif()
endif()
