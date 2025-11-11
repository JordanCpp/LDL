# 🌉 LDL - Little Directmedia Layer  
**Bridge Between Eras: Compatible Multimedia Layer**

![License](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)
![C++ Standard](https://img.shields.io/badge/C++-98-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-green.svg)
![API](https://img.shields.io/badge/API-SDL%20%7C%20SDL3%20%7C%20GLUT-orange.svg)

LDL is not just a cross-platform library, but a **bridge between different development eras**. We provide compatible APIs for popular multimedia libraries, allowing modern code to run on legacy platforms and vice versa.

🕰️ The Human Story Behind the Code
"I am passionate about studying the history of IT. For me, it's not merely about computers and programs, but about the remarkable human endeavor behind them."

🌟 The Deeper Narrative of Computing

💡 A Chronicle of Human Ingenuity

Exploring information technology history transcends mere timelines of processors and operating systems.
It's a profound immersion into the saga of human thought, perseverance, and incredible inventiveness.
Each breakthrough represents triumphs achieved within often severely constrained resources.

👥 The Architects of Our Digital World

Behind every byte, algorithm, and system architecture stand extraordinary individuals.
Visionary engineers, pioneering programmers, and brilliant minds whose monumental labor.
Their often-invisible work laid the foundation for our entire digital reality.

🎨 The Art of Computational Problem-Solving

Analyzing legacy systems reveals embodied intellectual battles with computing machines.
Every line of code was meticulously crafted and earned through intense effort.
Each command represented a small victory in making limited hardware perform miracles.

🔮 From Abstract Theory to Tangible Reality

Witness how abstract logical constructs and mathematical theories transformed into world-changing devices.
This alchemy of human determination turning concepts into functional technology.
Stands as one of humanity's most remarkable demonstrations of creative genius.

👥 The Birth of Digital Communities

Beyond technical specifications lies the rich tapestry of creative contexts and enthusiast communities.
Early programmers forming the first collaborative cultures around primitive machines.
Sharing ingenious hacks and establishing development traditions that shaped modern IT.

🏛️ Preserving Intellectual Heritage

Projects like LDL serve as guardians of technological legacy.
We maintain not just functional code, but fragments of intellectual inheritance.
Each preserved system honors someone's contribution to our collective progress.

📖 The Living History of Innovation

Every deprecated library represents a chapter in humanity's quest for knowledge.
My fascination stems from understanding not what was built, but how and by whom.
Seeking to comprehend the very spirit of each era and the people who shaped it.

"We stand on the shoulders of giants whose names we often forget, but whose work continues to shape our world every day."

---

## 🎯 Concept: Bridge Between Eras

LDL **is not a replacement** for existing libraries, but serves as a **compatibility layer** that:

*   **🔄 Provides backward compatibility** - run code written for modern SDL/SDL3 on legacy systems (Windows 95, old Linux distributions)
*   **📡 Offers unified API** - use familiar SDL, SDL3 and GLUT interfaces without being tied to specific library versions
*   **🏗️ Preserves legacy** - enable old projects to work on modern hardware and OS
*   **🔮 Future-proof** - write code today that will work tomorrow and yesterday

---

## 🏗️ Unified Architecture, Not Just Compatibility

LDL is not just a compatibility layer - it's a unified core that serves as the foundation for all compatible APIs:

```
    ┌─────────────────────────────────────────────────────┐
    │           Your Applications & Libraries             │
    └─────────────────────────────────────────────────────┘
    ┌─────────────┬─────────────┬─────────────┬───────────┐
    │   SDL1 API  │   SDL2 API  │   SDL3 API  │   GLUT    │ ← Thin Compatibility Layers
    │  (surface)  │  (surface)  │  (surface)  │   API     │
    └─────────────┴─────────────┴─────────────┴───────────┘
    ┌─────────────────────────────────────────────────────┐
    │              LDL Core API (Unified Core)            │ ← Single Implementation
    │           Optimized Codebase                        │
    └─────────────────────────────────────────────────────┘
    ┌─────────────────────────────────────────────────────┐
    │        Windows 95+  │  Linux  │  Other Platforms    │ ← Platform Abstraction
    └─────────────────────────────────────────────────────┘
```

Key Difference: Other libraries are built ON TOP of LDL, not the other way around!

## 🎯 How It Works: Single Foundation Architecture

Core Philosophy
LDL implements a unified multimedia foundation with multiple compatibility layers on top. Unlike traditional wrappers that translate between different implementations, all LDL compatibility layers share the same optimized core:

// Traditional approach: Wrappers with separate implementations:

- SDL1 → SDL1 Implementation
- SDL2 → SDL2 Implementation  
- SDL3 → SDL3 Implementation

// LDL approach: Single foundation with API surfaces:

- SDL1 Layer → LDL Core
- SDL2 Layer → LDL Core
- SDL3 Layer → LDL Core
- GLUT Layer → LDL Core

---

## 📊 Implementation Status

**SDL 1.2 API**
- SDL_Init
- SDL_Quit
- SDL_SetVideoMode
- SDL_Flip
- SDL_CreateRGBSurface
- SDL_CreateRGBSurfaceFrom
- SDL_FreeSurface
- SDL_LoadBMP
- SDL_BlitSurface
- SDL_malloc
- SDL_free
- SDL_memset
- SDL_PollEvent
- SDL_SetError
- SDL_GetError
- SDL_ClearError

**SDL 3.x API**
- SDL_Init
- SDL_Quit
- SDL_PollEvent
- SDL_GetError
- SDL_CreateWindow
- SDL_DestroyWindow
- SDL_CreateRenderer
- SDL_DestroyRenderer
- SDL_RenderPresent
- SDL_RenderClear
- SDL_SetRenderDrawColor
- SDL_GetRenderDrawColor
- SDL_CreateTexture
- SDL_DestroyTexture
- SDL_GetTextureSize
- SDL_CreateTextureFromSurface
- SDL_RenderTexture
- SDL_CreateSurface
- SDL_CreateSurfaceFrom
- SDL_DestroySurface
- SDL_LoadBMP
- SDL_malloc
- SDL_free
- SDL_AppInit
- SDL_AppEvent
- SDL_AppIterate
- SDL_AppQuit

**GLUT API**
- glutInit
- glutSwapBuffers
- glutMainLoop
- glutInitWindowPosition
- glutInitWindowSize
- glutCreateWindow
- glutDisplayFunc
- glutReshapeFunc

**CORE COMPONENTS** ✅ COMPLETE
- Graphics subsystem (windows, rendering contexts)
- Input handling (keyboard, mouse, event system)
- System utilities (timers, platform abstraction)
- Multi-platform support (Windows 95+ to modern Linux)

**RENDERING BACKENDS** ✅ COMPLETE 
- OpenGL 1.0 through 4.6 support
- Simple 2D rendering pipeline
- Software fallback renderer
- Multiple graphics driver support

🔧 **COMPATIBILITY & API**
✅ **Unified LDL API** - consistent interface across all layers

🏗️ **ARCHITECTURE**
✅ **Single consistent LDL API** for all compatibility layers
✅ Unified error handling and initialization
✅ Common resource management across all backends
✅ Coherent design patterns throughout

**API COMPATIBILITY** ✅ COMPLETE
- SDL1 API minimal functional 
- SDL3 API base functional
- GLUT-style interface
- Cross-platform consistency

**DEMONSTRATION** ✅ COMPLETE
- 12+ functional code examples
- TileMap rendering samples
- Graphics capability showcases

**PENDING** ❌ INCOMPLETE
- Audio subsystem implementation
  
---

## 🔄 Supported APIs & Compatibility

### ✅ Implemented Compatible APIs

| API | Status | Description |
|-----|---------|-----------|
| **SDL 1.2** | 🚧 In Development | Compatibility with classic SDL 1.2 |
| **SDL 2.0** | 🚧 In Development | Most commonly used functions |
| **SDL3** | 🚧 In Development | Support for new SDL3 architecture |
| **GLUT** | 🚧 In Development | Compatibility with OpenGL Utility Toolkit |

### 💡 Example: Using SDL-Compatible API

```c
// Same code works with both original SDL and LDL
#include <SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    // ... your code works unchanged
    return 0;
}
```

---

## ✨ Key Principles

*   **🌉 Bridge, Not Replacement** - we complement the ecosystem, don't compete with it
*   **🆓 Free for Everyone** - completely free for any use
*   **💡 Open to Ideas** - we consider and welcome all community ideas
*   **🔄 Old & New Platform Support** - from Windows 95 to modern systems
*   **🏛️ Legacy Preservation** - let old code live in the new world
*   **🔧 Developer Freedom** - we don't restrict the developer
*   **🌍 Cross-Platform** - work across multiple operating systems
*   **📚 Static & Dynamic Linking** - developer chooses the build method

---

## 🛠️ Quick Start

### Using SDL-Compatible API

```bash
# Clone repository
git clone https://github.com/JordanCpp/Lib-LDL.git
cd Lib-LDL

# Build like a regular SDL library
cmake -B build
cmake --build build

# In your project, just link with LDL instead of SDL
target_link_libraries(${PROJECT_NAME} LDL)
```

### Build for Linux

```bash
# Install dependencies
sudo apt-get install libx11-dev libgl1-mesa-dev

# Clone and build
git clone https://github.com/JordanCpp/Lib-LDL.git
cd Lib-LDL
cmake -B build
cmake --build build
```

### Build for Windows

```bash
git clone https://github.com/JordanCpp/Lib-LDL.git
cd Lib-LDL
# ... (use your development environment, e.g., Visual Studio)
```

### Adding to CMake Project

```cmake
# Clone LDL as submodule to your project folder
git clone https://github.com/JordanCpp/Lib-LDL.git your_project/dependencies/LDL

# In your CMakeLists.txt add:
add_subdirectory(dependencies/LDL)
include_directories(dependencies/LDL/include)
target_link_libraries(${PROJECT_NAME} LDL)
```

---

## 📋 Supported Platforms

| Platform | SDL 1.2 | SDL 2.0 | GLUT |
|----------|---------|---------|------|
| Windows 95+ | ✅ | ✅ | ✅ |
| Linux (XLib) | ✅ | ✅ | ✅ |
| Linux (Wayland) | 🚧 | 🚧 | 🚧 |

---

## 🎨 Supported Renders

| Render | SDL-Compatible | GLUT-Compatible |
|--------|----------------|-----------------|
| OpenGL 1.0 | ✅ | ✅ |
| OpenGL 3.0 | ✅ | ✅ |
| Software Render | ✅ | ❌ |
| 3dfx Glide | ✅ | ❌ |
| DirectDraw | 🚧 | ❌ |
| DirectX 5 Direct3D | 🚧 | ❌ |
| DirectX 9 Direct3D | 🚧 | ❌ |

---

## ⚙️ Supported Compilers

*   MinGW (GCC 3+)
*   GCC 3+
*   Visual C++ 4.0+
*   Open Watcom V2
*   Borland C++ 6.0+

---

## 💡 Why Choose LDL?

### For Legacy Projects:
```c
// Your old SDL 1.2 code will work on modern systems
// without rewriting for SDL2/SDL3
```

### For New Projects:
```c
// Write with modern SDL3 API but with legacy platform support
// One codebase - everywhere!
```

### For Educational Purposes:
```c
// Learn computer graphics with GLUT supporting modern compilers
```

---

## 🚀 Roadmap

*   **🔜 Full SDL3 API Compatibility**
*   **🔜 Wayland Support for All APIs**
*   **🔜 Additional Backends for Legacy Graphics APIs**
*   **🔜 Companion Libraries (LDL_image, LDL_mixer, etc.)**

---

## 📄 License

![Boost License](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)

Project is distributed under the **Boost Software License - Version 1.0**.

---

## 🔗 Links & Materials

*   **🎥 C++ Russia 2023 Talk:** [Watch](https://cppconf.ru/talks/16ef41e0e5ec48bfb25b36f8b2a0b540/?referer=/talks/)
*   **📝 Habr Article:** [Read](https://habr.com/ru/post/700668/)

---

## 💬 Communication & Feedback

We welcome everyone! Main communication language is English. No restrictions on ideas and functionality. Ready to discuss any questions, suggestions and ideas.

*   **gamedev.ru Forum:** [Discussion on gamedev.ru](https://gamedev.ru/projects/forum/?id=273184)
*   **old-games.ru Forum:** [Discussion on old-games.ru](https://www.old-games.ru/forum/threads/pishu-frejmvork-ldl-analog-sdl-no-na-s-i-s-podderzhkoj-staryx-sistem.106435/)

---

## 💎 Acknowledgments

Special thanks to community members for ideas and support:

*   **old-games.ru:** Tigoro, Bobbie
*   **gamedev.ru:** Vitorio, Mirrel, gamedevfor, vka123, u960
*   **habr:** Kotofay

---

## 🖼️ Screenshots

| | |
| :---: | :---: |
| ![TileMap Example](Screenshots/12_TileMap2.jpg) | ![TileMap Example](Screenshots/10_TileMap.jpg) |
| ![Example 1](Screenshots/1.jpg) | ![Example 2](Screenshots/2.jpg) |
| ![Example 3](Screenshots/3.jpg) | ![Example 4](Screenshots/4.jpg) |
| ![Example 5](Screenshots/5.jpg) | |

---

## 🏗️ Building from Source

### Prerequisites
- CMake 3.10+
- C++98 compatible compiler
- Platform-specific dependencies (X11, OpenGL, etc.)

### Build Instructions
```bash
git clone https://github.com/JordanCpp/Lib-LDL.git
cd Lib-LDL
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

### Available CMake Options
- `-DBUILD_SHARED_LIBS=ON` - Build shared libraries (default: ON)
- `-DLDL_BUILD_EXAMPLES=ON` - Build example applications (default: ON)
- `-DLDL_BUILD_TESTS=ON` - Build test suite (default: OFF)

---

## 🤝 Contributing

We welcome contributions! Whether it's:
- Bug reports and fixes
- New feature implementations
- Documentation improvements
- Platform porting
- API compatibility enhancements

Please feel free to open issues and pull requests.

---

**LDL - One Foundation, Many Interfaces. Built to Last.** 🚀

**LDL - Preserving the past, enabling the future.** 🚀

LDL is not just a compatibility layer - it's a unified core that serves as the foundation for all compatible APIs:
    ┌─────────────────────────────────────────────────────┐
    │           Your Applications & Libraries              │
    └─────────────────────────────────────────────────────┘
    ┌─────────────┬─────────────┬─────────────┬───────────┐
    │   SDL1 API  │   SDL2 API  │   SDL3 API  │   GLUT    │ ← Thin Compatibility Layers
    │  (surface)  │  (surface)  │  (surface)  │   API     │
    └─────────────┴─────────────┴─────────────┴───────────┘
    ┌─────────────────────────────────────────────────────┐
    │              LDL Core API (Unified Core)            │ ← Single Implementation
    │           Optimized Codebase                        │
    └─────────────────────────────────────────────────────┘
    ┌─────────────────────────────────────────────────────┐
    │        Windows 95+  │  Linux  │  Other Platforms    │ ← Platform Abstraction
    └─────────────────────────────────────────────────────┘

Key Difference: Other libraries are built ON TOP of LDL, not the other way around!
