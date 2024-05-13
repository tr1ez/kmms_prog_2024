target_sources(${SCL_LIB} 
	PRIVATE
		
	PUBLIC
		vector_deque.hpp
		vector_deque.сpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/deque
)
