target_sources(${SCL_LIB} 
	PRIVATE
		
	PUBLIC
		doubly_linked_list.hpp
		doubly_linked_list.сpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/list
)
