
call %1

set pth=C:\Repos\Lib-LDL\Examples\Graphics\

call %2 01_WindowAndRender %pth%
call %2 02_Color %pth%
call %2 03_Line %pth%
call %2 04_Rect %pth%
call %2 05_Texture %pth%
call %2 06_Click %pth%
call %2 07_Motion %pth%
call %2 08_Surface %pth%
call %2 09_ColorKey %pth%
call %2 10_TileMap %pth%
call %2 11_Resize %pth%
call %2 12_TileMap2 %pth%
call %2 13_TileMapBatcher %pth%

set pth=C:\Repos\Lib-LDL\Tutorials\NeHe\

call %2 01_SettingUpAnOpenGLWindow %pth%
call %2 02_YourFirstPolygon %pth%
call %2 03_AddingColor %pth%
call %2 04_Rotation %pth%
call %2 05_3DShapes %pth%
call %2 06_TextureMapping %pth%

set pth=C:\Repos\Lib-LDL\test\Allocators\

call %2 Allocator %pth%
call %2 FixedLinear %pth%
