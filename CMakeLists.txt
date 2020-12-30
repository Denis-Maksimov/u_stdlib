cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.


# Название проекта
project(hello_world)



# НАзвание исп. файла
set(OUTNAME 
	run
)			
#-----------------
				
#=================
#=== Исходники ===
#=================
set(SOURCES
#-----------------
		./src/u_mallocat.c
		./src/u_string.c
		./src/u_chain.c
		./src/u_vector.c
		./src/u_graph.c

		./u_test.c
		./main.c
		./hex.c
		#./crc16.c
#-----------------
)			

#=====================
#=== Заголовочники ===
#=====================
set(INC_DIRS
#-----------------
		./inc
		./inc/u_mallocat
#-----------------
)		

#==================
#=== Библиотеки ===
#==================
# add_library(netutil STATIC IMPORTED)
# add_library(netutil SHARED IMPORTED)
# set_property(TARGET netutil PROPERTY IMPORTED_LOCATION Binary/game_client/libnetutil.a)


# Расположение заголовочных файлов
include_directories(${INC_DIRS})			
# Создает исполняемый файл
add_executable(${OUTNAME} ${SOURCES})	

#====================================================================================
#Добавление подпроекта, указывается имя дирректории
# add_subdirectory(foo_lib)	

#===========================
# Флаги компиляции
#===========================
set(MYCOMPILE_FLAGS
#-----------------
		-g
#-----------------
)		
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${MYCOMPILE_FLAGS}")
#===========================

#==================
#=== Библиотеки ===
#==================
# target_link_libraries(${OUTNAME} foo)		# Линковка программы с библиотекой
# add_library(${NAME} STATIC ${SOURCE_LIB})# Создание статической библиотеки