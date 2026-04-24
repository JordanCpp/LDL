
call "C:\VC6\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL.dll -LD -GX /DLDL_SHARED_LIBRARY ^
..\source\LDL\*.c ^
..\source\LDL\OpenGL\*.c ^
..\source\LDL\Win9x\*.c ^
/I..\include\ ^
/I..\source\ ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

cl /O2 -FeOpenGL1_Animated3DTerrain.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Animated3DTerrain.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_FallingParticles.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_FallingParticles.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_FireworksShow.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_FireworksShow.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_FirstPersonMaze.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_FirstPersonMaze.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_Interactive3DCube.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Interactive3DCube.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_Move.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Move.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_Rect.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Rect.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_Rotate.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Rotate.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_RotatingColorfulTorus.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_RotatingColorfulTorus.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_Rotating3DCube.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_Rotating3DCube.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_SnowfallParticles.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_SnowfallParticles.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_SolarSystem.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_SolarSystem.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_TargetShooter.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_TargetShooter.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_TerrainFlight.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_TerrainFlight.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_WaterWaveSimulation.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_WaterWaveSimulation.c /link LDL.lib opengl32.lib
cl /O2 -FeOpenGL1_3DAtomModel.exe -GX /I..\include ..\examples\OpenGL1\OpenGL1_3DAtomModel.c /link LDL.lib opengl32.lib

cl /O2 -FeOpenGL3_Rect.exe -GX /I..\include ..\examples\OpenGL3\OpenGL3_Rect.c /link LDL.lib opengl32.lib

del *.obj

pause
