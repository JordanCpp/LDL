#ifndef Arcanum_Platforms_hpp
#define Arcanum_Platforms_hpp

#if defined(_WIN32)
    #define CURRENT_DIRECTORY_PATH "*.*"
#elif defined(__unix__)
    #define CURRENT_DIRECTORY_PATH "./"
#endif

#endif    