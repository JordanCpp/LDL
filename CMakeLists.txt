project(LDL)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories("include")

add_executable(main "test.cpp" 
 
"source/Windows/Creators.cpp" 
"source/Windows/GL1Win.cpp" 
"source/Windows/RContext.cpp" 
"source/Windows/MainWin.cpp" 
"source/Windows/SoftWin.cpp" 

"source/Graphics/SoftRend.cpp" 
"source/Graphics/GL1Rend.cpp"

"source/Shared/PixPaint.cpp" 
"source/Shared/EHandler.cpp"  
"source/Shared/BaseWin.cpp" 
"source/Shared/String.cpp" 
"source/Shared/BaseRend.cpp" 
"source/Shared/Palette.cpp" 
"source/Shared/BmpLoad.cpp" 
"source/Shared/PixCopy.cpp" 
"source/Shared/PixResz.cpp"
"source/Shared/Surface.cpp" 
"source/Shared/Conv.cpp" 
"source/Shared/EventQ.cpp" 
"source/Shared/Eventer.cpp" 
"source/Shared/Equal.cpp" )
