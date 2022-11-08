This directory contains all SDK components.

To ensure compatability with all editors, all tabs have been replaced
with spaces in all source files.

BIN:
    Sample app executables
  
INC:
    contains include files for DirectDraw, Direct3D, DirectSound, DirectInput
    and DirectPlay

LIB:
    contains library files for DirectDraw, DirectSound, and DirectPlay
    *.LIB : COFF libraries (used by Microsoft Visual C++ 2.0 or higher)
    *.LBW : 32-bit OMF libraries (used by Watcom C/C++ 10.0)

SAMPLES:
    Contains all sample code.   See readme.txt file in this directory for
    more details.

Setting up your DirectX build environment
-----------------------------------------
To setup your DirectX build environment, edit the <dxsdk>\sdk\samples\dxsetenv.bat
file to point to the location of your compiler, assembler, and the location
of the DirectX and platform SDKs. Run the dxsetenv.bat batch file.
See <dxsdk>\sdk\samples\readme.txt for further info.

Notes for users of Visual C++ 4.2
---------------------------------
Visual C++ 4.2 includes the DX2 header files and libraries.  If you are
getting errors compiling, make sure that the DX3 include
and lib paths come before the MSVC++ 4.2 include and lib paths.
