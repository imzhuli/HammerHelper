project(sample_${libname})

# macro
set(IPDB X_USE_IP2LOC_DB)

# dependencies:
if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(PLATFORM_LIBRARIES ws2_32 Mswsock)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(PLATFORM_LIBRARIES dl rt)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
	find_library(COCOA_LIBRARY Cocoa REQUIRED)
	find_library(IOKIT_LIBRARY IOKit REQUIRED)
	set(PLATFORM_LIBRARIES dl ${IOKIT_LIBRARY} ${COCOA_LIBRARY})
endif()

# local dependencies
include_directories(
	${X_INCLUDE_DIRS}
	${LIB3RD_INCLUDE_DIRS}
	)
link_directories(
	${X_LIBRARY_DIRS}
	${LIB3RD_LIBRARY_DIRS}
	)

set(shared_lib_dependency_private
	${X_LIBRARIES}
	${LIB3RD_LIBRARIES}
	${PLATFORM_LIBRARIES}
	${cpp}
	)

aux_source_directory(./base/              LIB_SOURCE_CODE)
add_library(pcbase ${LIB_SOURCE_CODE})

function(make_source sub_dir_name)
	aux_source_directory(${sub_dir_name} LOCAL_SOURCE_CODE)
	add_executable(x_${sub_dir_name}  ${LOCAL_SOURCE_CODE} ${COMMON_SOURCE_CODE})
	target_link_libraries(x_${sub_dir_name} PRIVATE pcbase ${libname})
	target_link_libraries(x_${sub_dir_name} PRIVATE ${shared_lib_dependency_private})
if (X_OPTION_STATIC)
	target_compile_definitions(x_${sub_dir_name} PRIVATE X_OPTION_STATIC)
endif()
	target_compile_definitions(x_${sub_dir_name} PRIVATE ${IPDB})
endfunction()

function(do_test target)
	add_test(
		NAME ${target}
		COMMAND x_${target}
	)
endfunction()

#####
make_source(cards)
do_test(cards)
make_source(three_card_poker)
do_test(three_card_poker)

install(TARGETS
	x_cards
	x_three_card_poker

	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	)