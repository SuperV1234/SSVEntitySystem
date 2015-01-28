FIND_PATH(SSVENTITYSYSTEM_INCLUDE_DIR
  NAMES SSVEntitySystem/SSVEntitySystem.hpp
  PATH_SUFFIXES include/
  PATHS
  "${PROJECT_SOURCE_DIR}/../SSVEntitySystem/"
  ${SSVENTITYSYSTEM_ROOT}
  $ENV{SSVENTITYSYSTEM_ROOT}
  /usr/local/
  /usr/
  /sw/
  /opt/local/
  /opt/csw/
  /opt/
  "${PROJECT_SOURCE_DIR}/extlibs/SSVEntitySystem/"
  "${CMAKE_CURRENT_LIST_DIR}/../../"

  NO_DEFAULT_PATH
)

message("\nFound SSVEntitySystem include at: ${SSVENTITYSYSTEM_INCLUDE_DIR}.\n")

IF(SSVENTITYSYSTEM_INCLUDE_DIR)
#{
  SET(SSVENTITYSYSTEM_FOUND TRUE)
#}
ELSE(SSVENTITYSYSTEM_INCLUDE_DIR)
#{
  SET(SSVENTITYSYSTEM_FOUND FALSE)
#}
ENDIF(SSVENTITYSYSTEM_INCLUDE_DIR)

IF(SSVENTITYSYSTEM_FOUND)
#{
  MESSAGE(STATUS "Found SSVEntitySystem in ${SSVENTITYSYSTEM_INCLUDE_DIR}")
#}
ELSE(SSVENTITYSYSTEM_FOUND)
#{
  IF(SSVENTITYSYSTEM_FIND_REQUIRED)
  #{
    MESSAGE(FATAL_ERROR "Could not find SSVEntitySystem library")
  #}
  ENDIF(SSVENTITYSYSTEM_FIND_REQUIRED)
#}
ENDIF(SSVENTITYSYSTEM_FOUND)

MARK_AS_ADVANCED(SSVENTITYSYSTEM_INCLUDE_DIR)