cmake_minimum_required(VERSION 3.23)
project(java_jni)

set(CMAKE_CXX_STANDARD 17)
find_package(Java REQUIRED)
find_package(JNI REQUIRED)

set(PROJ_JSRC HelloWorld)
#create .cpp file if not exists
file(APPEND ${PROJ_JSRC}.cpp "")
#generate .h file from .java file
add_custom_command(OUTPUT ${PROJ_JSRC}.h
        COMMAND ${Java_JAVAC_EXECUTABLE} -h ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_JSRC}.java
        DEPENDS ${PROJ_JSRC}.java)
set(PROJ_SRC ${PROJ_JSRC}.cpp ${PROJ_JSRC}.h)

add_library(${PROJECT_NAME} SHARED ${PROJ_SRC})
target_link_libraries(${PROJECT_NAME} ${JNI_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${JNI_INCLUDE_DIRS})
#compile .java file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${Java_JAVAC_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_JSRC}.java)
#copy compiled .dll file to root folder with different name
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:${PROJECT_NAME}>
        ${CMAKE_CURRENT_SOURCE_DIR}/${PROJ_JSRC}${CMAKE_SHARED_LIBRARY_SUFFIX})
#run java .class file dependent on .dll file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${Java_JAVA_EXECUTABLE} -Djava.library.path=${CMAKE_CURRENT_SOURCE_DIR} -cp ${CMAKE_CURRENT_SOURCE_DIR} ${PROJ_JSRC})