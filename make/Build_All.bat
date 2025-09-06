
call %1

set pth=..\examples\Lessons\
call %2 01_WindowAndRender %pth%
call %2 02_Color %pth%
call %2 03_Line %pth%
call %2 04_Rect %pth%
call %2 05_Surface %pth%
call %2 06_Texture %pth%
call %2 07_TileMapRandom %pth%
call %2 08_Memory %pth%

set pth=..\examples\BeginEnd\
call %2 01_FirstProgram %pth%
call %2 02_PointLineTriangleCircle %pth%
call %2 04_WeWriteMinesweeperGame %pth%

set pth=..\examples\OpenGL1\
call %2 Figures %pth%
call %2 Primitive %pth%
call %2 Sierpinski2D %pth%
call %2 Tetrahedron %pth%
call %2 Triangle %pth%

set pth=..\examples\SDL3\
call %2 SDL3_01_Window %pth%
call %2 SDL3_02_Renderer %pth%
call %2 SDL3_03_Clear %pth%
