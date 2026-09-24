file(GLOB_RECURSE SRCs ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(INCs ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ember PRIVATE ${INCs})
target_sources(ember PRIVATE ${SRCs})
