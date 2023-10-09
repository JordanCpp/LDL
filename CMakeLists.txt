project(LDL)

add_definitions(-DLDL_STATIC_LIBRARY)

find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

include_directories("include")

file(GLOB_RECURSE SHARED_FILES "source/Shared/*.cpp")

file(GLOB_RECURSE SOURCE_PLATFORM "source/Platforms/Linux/*.cpp")

file(GLOB_RECURSE SOURCE_FREETYPE 
    "dependencies/freetype/src/sfnt/sfdriver.c"
    "dependencies/freetype/src/sfnt/ttcmap.c"
    "dependencies/freetype/src/sfnt/ttsbit.c"
    "dependencies/freetype/src/sfnt/ttcolr.c"
    "dependencies/freetype/src/sfnt/ttcpal.c"
    "dependencies/freetype/src/sfnt/ttsvg.c"
    "dependencies/freetype/src/sfnt/ttload.c"
    "dependencies/freetype/src/sfnt/ttkern.c"
    "dependencies/freetype/src/sfnt/ttmtx.c"
    "dependencies/freetype/src/sfnt/ttpost.c"
    "dependencies/freetype/src/sfnt/sfobjs.c"
    "dependencies/freetype/src/sfnt/ttbdf.c"
    "dependencies/freetype/src/sfnt/sfwoff.c"
    "dependencies/freetype/src/base/ftglyph.c"
    "dependencies/freetype/src/base/ftcid.c"
    "dependencies/freetype/src/base/ftbitmap.c"
    "dependencies/freetype/src/base/ftfstype.c"
    "dependencies/freetype/src/base/ftgxval.c"
    "dependencies/freetype/src/base/ftbbox.c"
    "dependencies/freetype/src/base/ftbdf.c"
    "dependencies/freetype/src/base/ftpatent.c"
    "dependencies/freetype/src/base/ftmm.c"
    "dependencies/freetype/src/base/ftgasp.c"
    "dependencies/freetype/src/autofit/autofit.c"
    "dependencies/freetype/src/base/ftotval.c"
    "dependencies/freetype/src/base/ftinit.c"
    "dependencies/freetype/src/base/ftbase.c"
    "dependencies/freetype/src/base/ftwinfnt.c"
    "dependencies/freetype/src/base/ftsynth.c"
    "dependencies/freetype/src/base/fttype1.c"
    "dependencies/freetype/src/base/ftstroke.c"
    "dependencies/freetype/src/base/ftpfr.c"
    "dependencies/freetype/src/bzip2/ftbzip2.c"
    "dependencies/freetype/src/pcf/pcf.c"
    "dependencies/freetype/src/cid/type1cid.c"
    "dependencies/freetype/src/gzip/ftgzip.c"
    "dependencies/freetype/src/bdf/bdf.c"
    "dependencies/freetype/src/lzw/ftlzw.c"
    "dependencies/freetype/src/cff/cff.c"
    "dependencies/freetype/src/pfr/pfr.c"
    "dependencies/freetype/src/cache/ftcache.c"
    "dependencies/freetype/src/raster/raster.c"
    "dependencies/freetype/src/pshinter/pshinter.c"
    "dependencies/freetype/src/smooth/smooth.c"
    "dependencies/freetype/src/svg/svg.c"
    "dependencies/freetype/src/sdf/sdf.c"
    "dependencies/freetype/src/type42/type42.c"
    "dependencies/freetype/src/winfonts/winfnt.c"
    "dependencies/freetype/src/psnames/psnames.c"
    "dependencies/freetype/src/truetype/truetype.c"
    "dependencies/freetype/src/psaux/psaux.c"
    "dependencies/freetype/src/type1/type1.c")

add_definitions(-DFT2_BUILD_LIBRARY)
include_directories(dependencies/freetype/include)

add_compile_options(-fPIC)

add_definitions(-DHAVE_FCNTL_H)
add_library(freetype STATIC ${SOURCE_FREETYPE}
  "dependencies/freetype/src/base/ftdebug.c"
  "dependencies/freetype/builds/unix/ftsystem.c")

set(SOURCE_ALL ${SHARED_FILES} ${SOURCE_PLATFORM})

add_library(${PROJECT_NAME} SHARED ${SOURCE_ALL})		

target_link_libraries(${PROJECT_NAME} X11 GL dl freetype)

add_subdirectory("Examples")
add_subdirectory("test")
add_subdirectory("ArcanumWorld")