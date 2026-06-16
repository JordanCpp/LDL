
set(LDL_EXAMPLES
    "C++98_Points_FireworksShow"
    "C++98_Points_HyperdriveEffect"
    "C++98_Points_LaserLightShow"
    "C++98_Points_MagicPollen"
    "C++98_Points_MatrixDigitalRain"
    "C++98_Points_SnowfallWonderland"
    "C++98_Points_StarryNightSky"
)

foreach(EXE_NAME ${LDL_EXAMPLES})
    add_executable(${EXE_NAME} ${EXE_NAME}.cpp)
    target_link_libraries(${EXE_NAME} LDL LDL_Ttf)
endforeach()
