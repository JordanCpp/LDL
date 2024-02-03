add_definitions(-DLDL_SUPPORT_OPENGL1)

add_executable(01Window "01Window.cpp")
target_link_libraries(01Window LDLGL1)

add_executable(02Render "02Render.cpp")
target_link_libraries(02Render LDLGL1)

add_executable(03Fps "03Fps.cpp")
target_link_libraries(03Fps LDLGL1)

add_executable(04Clear "04Clear.cpp")
target_link_libraries(04Clear LDLGL1)

#add_executable(05Img "05Img.cpp")
#target_link_libraries(05Img ${libs})
