
call "C:\VC6\VC98\Bin\VCVARS32.BAT"

CL /O2 /FeLDL_Ttf.dll -LD -GX /I..\include /I../source /I..\dependencies\freetype-2.14.3\include /Dinline=__inline /D_WIN32_WINNT=0x0300 /DFT2_BUILD_LIBRARY /DLDL_SHARED_LIBRARY ^
..\source\LDL_Ttf\*.c ^
..\dependencies\freetype-2.14.3\src\sfnt\sfdriver.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttcmap.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttsbit.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttcolr.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttcpal.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttsvg.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttload.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttkern.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttmtx.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttpost.c ^
..\dependencies\freetype-2.14.3\src\sfnt\sfobjs.c ^
..\dependencies\freetype-2.14.3\src\sfnt\ttbdf.c ^
..\dependencies\freetype-2.14.3\src\sfnt\sfwoff.c ^
..\dependencies\freetype-2.14.3\src\base\ftglyph.c ^
..\dependencies\freetype-2.14.3\src\base\ftcid.c ^
..\dependencies\freetype-2.14.3\src\base\ftbitmap.c ^
..\dependencies\freetype-2.14.3\src\base\ftfstype.c ^
..\dependencies\freetype-2.14.3\src\base\ftgxval.c ^
..\dependencies\freetype-2.14.3\src\base\ftbbox.c ^
..\dependencies\freetype-2.14.3\src\base\ftbdf.c ^
..\dependencies\freetype-2.14.3\src\base\ftpatent.c ^
..\dependencies\freetype-2.14.3\src\base\ftmm.c ^
..\dependencies\freetype-2.14.3\src\base\ftgasp.c ^
..\dependencies\freetype-2.14.3\src\autofit\autofit.c ^
..\dependencies\freetype-2.14.3\src\base\ftotval.c ^
..\dependencies\freetype-2.14.3\src\base\ftinit.c ^
..\dependencies\freetype-2.14.3\src\base\ftbase.c ^
..\dependencies\freetype-2.14.3\src\base\ftwinfnt.c ^
..\dependencies\freetype-2.14.3\src\base\ftsynth.c ^
..\dependencies\freetype-2.14.3\src\base\fttype1.c ^
..\dependencies\freetype-2.14.3\src\base\ftstroke.c ^
..\dependencies\freetype-2.14.3\src\base\ftpfr.c ^
..\dependencies\freetype-2.14.3\src\bzip2\ftbzip2.c ^
..\dependencies\freetype-2.14.3\src\pcf\pcf.c ^
..\dependencies\freetype-2.14.3\src\cid\type1cid.c ^
..\dependencies\freetype-2.14.3\src\gzip\ftgzip.c ^
..\dependencies\freetype-2.14.3\src\bdf\bdf.c ^
..\dependencies\freetype-2.14.3\src\lzw\ftlzw.c ^
..\dependencies\freetype-2.14.3\src\cff\cff.c ^
..\dependencies\freetype-2.14.3\src\pfr\pfr.c ^
..\dependencies\freetype-2.14.3\src\cache\ftcache.c ^
..\dependencies\freetype-2.14.3\src\raster\raster.c ^
..\dependencies\freetype-2.14.3\src\pshinter\pshinter.c ^
..\dependencies\freetype-2.14.3\src\smooth\smooth.c ^
..\dependencies\freetype-2.14.3\src\svg\svg.c ^
..\dependencies\freetype-2.14.3\src\sdf\sdf.c ^
..\dependencies\freetype-2.14.3\src\type42\type42.c ^
..\dependencies\freetype-2.14.3\src\winfonts\winfnt.c ^
..\dependencies\freetype-2.14.3\builds\windows\ftdebug.c ^
..\dependencies\freetype-2.14.3\builds\windows\ftsystem.c ^
..\dependencies\freetype-2.14.3\src\psnames\psnames.c ^
..\dependencies\freetype-2.14.3\src\truetype\truetype.c ^
..\dependencies\freetype-2.14.3\src\psaux\psaux.c ^
..\dependencies\freetype-2.14.3\src\type1\type1.c ^
LDL.lib ^
gdi32.lib ^
opengl32.lib ^
winmm.lib   ^
user32.lib

del *.obj

pause
