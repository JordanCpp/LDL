# 🌉 LDL - Little Directmedia Layer  
**Bridge Between Eras: Compatible Multimedia Layer**

[![License: LGPL v3](https://img.shields.io/badge/License-LGPLv3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0)
[![License: CC0 (Examples)](https://img.shields.io/badge/License-CC0%20(Examples)-lightgrey.svg)](https://creativecommons.org/publicdomain/zero/1.0/)
[![C Standard](https://img.shields.io/badge/C-Standard%20C89%2FANSI%20C-blue.svg)](https://en.wikipedia.org/wiki/ANSI_C)
[![Windows](https://img.shields.io/badge/Windows-✅%20Supported-0078D6?logo=windows)](https://www.microsoft.com/windows)
[![Linux](https://img.shields.io/badge/Linux-✅%20Supported-0078D6?logo=linux)](https://kernel.org)
[![FreeBSD](https://img.shields.io/badge/FreeBSD-✅%20Supported-0078D6?logo=freebsd)](https://freebsd.org)
[![macOS](https://img.shields.io/badge/macOS-✅%20Supported-000000?logo=apple)](https://www.apple.com/macos/)

LDL is not just a cross-platform library, but a **bridge between different development eras**. We provide compatible APIs for popular multimedia libraries, allowing modern code to run on legacy platforms and vice versa.

---

<details>
<summary><b>The Philosophy of the LDL Library (Click to expand)</b></summary>
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
</details>

---

## Features

| Feature | Support |
|---------|---------|
| **Windowing** | ✅ Create, resize, move, close |
| **Events** | ✅ Keyboard, mouse, resize, quit, focus |
| **Keyboard** | ✅ Full key mapping (including F1–F15, numpad, modifiers) |
| **Mouse** | ✅ Move, click (LMB/RMB/MMB), scroll wheel |
| **2D Render** | ✅ Draw: Line, Fill, Texture, Texture alpha |
| **OpenGL 1.0** | ✅ Immediate mode, fixed pipeline |
| **OpenGL 1.1–1.5** | ✅ Extensions, texture objects, VBO |
| **OpenGL 2.0–2.1** | ✅ GLSL 1.20, shaders, FBO |
| **OpenGL 3.0–3.3** | ✅ GLSL 3.30, VAO, geometry shaders |
| **OpenGL 4.0–4.6** | ✅ GLSL 4.60, compute shaders, tessellation |

---

## Supported Platforms

| Operating System | Versions | Status |
|------------------|----------|--------|
| **Windows** | 95, 98, ME, 2000, XP, Vista, 7, 8, 10, 11 | ✅ Full support |
| **Linux** | Kernel 2.0+ (1996–present) | ✅ Full support |
| **FreeBSD** | 3.0+ (1998–present) | ✅ Full support |
| **macOS** | 10.12-10.15, 11-26 (2016-present) | ✅ Full support* |
| **OS X** | 10.8–10.11 (2012–2015) | ✅ Full support |
| **Mac OS X** | 10.6, 10.7 (2009-2011) | ✅ Full support |

> *Note: due to [Apple's policy](https://developer.apple.com/documentation/scenekit/scnview/openglcontext), macOS does not support OpenGL 4.1+ 

---

### Retro & Modern

- **Classic systems:** Windows 95/98/ME, old Linux kernels, legacy FreeBSD, OSX
- **Modern systems:** Windows 10/11, modern Linux distributions, latest FreeBSD, macOS

---

### Tested Compilers

| Platform | Compilers |
|----------|-----------|
| Windows | MSVC 6.0–2022, MinGW, Borland C++ 5.5, OpenWatcom |
| Linux | GCC 2.95–14, Clang 3.0–18 |
| FreeBSD | GCC (system default), Clang |
| macOS | Apple clang version 14.0.0 |

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

## 🛠️ Build & Install

# Installation Guide for LDL

This guide explains how to build and install the LDL library using CMake.

## Prerequisites

Ensure you have the following installed:
- CMake 3.12 or higher
- A C++ compiler (GCC, Clang, or MSVC)
- Development libraries for X11 and OpenGL (on Linux)

## Build Options

You can customize the build using the following CMake options:

| Option | Description | Default |
| :--- | :--- | :--- |
| `LDL_BUILD_LIBRARY_STATIC` | Build LDL as a static library (.a / .lib) | `ON` |
| `LDL_BUILD_LIBRARY_SHARED` | Build LDL as a shared library (.so / .dll) | `OFF` |
| `LDL_BUILD_EXAMPLES`       | Enable building example projects | `OFF` |
| `LDL_ENABLE_INSTALL`       | Enable the install target | `OFF` |

## Quick Start (Terminal)

1. **Clone the repository:**
   ```bash
   git clone https://github.com/JordanCpp/LDL.git
   cd LDL
   ```

2. **Configure the project:**
   Use the `-B` flag to create a build directory and `-D` to set options. For example, to build a static library with examples:
   ```bash
   cmake -B build -DLDL_BUILD_LIBRARY_STATIC=ON -DLDL_BUILD_EXAMPLES=ON
   ```

3. **Build the project:**
   ```bash
   cmake --build build
   ```

4. **Install (Optional):**
   If you enabled `LDL_ENABLE_INSTALL`, run:
   ```bash
   sudo cmake --install build
   ```

## Example: Building with Specific OpenGL Versions
If you want to build specific examples, you can toggle them:
```bash
cmake -B build -DLDL_BUILD_EXAMPLES=ON -DLDL_BUILD_EXAMPLES_OPENGL3=ON
cmake --build build
```

---

## 🤝 Contributing

We welcome contributions! Whether it's:
- Bug reports and fixes
- New feature implementations
- Documentation improvements
- Platform porting
- API compatibility enhancements

Please feel free to open issues and pull requests.

## License

| Component | License |
|-----------|---------|
| **LDL library** | [LGPLv3](https://www.gnu.org/licenses/lgpl-3.0) |
| **Examples** | [CC0 1.0 Universal](https://creativecommons.org/publicdomain/zero/1.0/) (Public Domain) |

- The **LDL library** is licensed under the GNU Lesser General Public License v3.0.
  You can use it in both open-source and proprietary projects (with dynamic linking).

- The **example code** is dedicated to the public domain under CC0 1.0.
  You can copy, modify, and use the examples in any project without restrictions.

---

## Screenshots

### Fonts examples

| | | |
|:-:|:-:|:-:|
| ![fireworksshow](Screenshots/fonts/fireworksshow.png) | ![font1](Screenshots/Fonts/Font1.png) | ![font2](Screenshots/Fonts/Font2.png) |
| *fireworksshow* | *font1* | *font2* |
| ![fontsizegallery](Screenshots/Fonts/FontSizeGallery.png) | ![fontstylemixer](Screenshots/Fonts/FontStyleMixer.png) | ![fontstylemixer2](Screenshots/Fonts/FontStyleMixer2.png) |
| *fontsizegallery* | *fontstylemixer* | *fontstylemixer2* |
| ![fontstylemixer3](Screenshots/Fonts/FontStyleMixer3.png) | ![fontstylemixer4](Screenshots/Fonts/FontStyleMixer4.png) | ![fontstylemixer5](Screenshots/Fonts/FontStyleMixer5.png) |
| *fontstylemixer3* | *fontstylemixer4* | *fontstylemixer5* |
| ![fontstylemixer6](Screenshots/Fonts/FontStyleMixer6.png) | ![fontstylemixer7](Screenshots/Fonts/FontStyleMixer7.png) | ![fontstylemixer8](Screenshots/Fonts/FontStyleMixer8.png) |
| *fontstylemixer6* | *fontstylemixer7* | *fontstylemixer8* |

---

### 2D Render Examples

| | | |
|:-:|:-:|:-:|
| ![Boids Simulation](Screenshots/2DRender/Boids%20Simulation.jpg) | ![Conway's Game of Life](Screenshots/2DRender/Conways%20Game%20of%20Life.jpg) | ![Firework Demo](Screenshell/2DRender/Firework%20Demo.jpg) |
| *Boids Simulation* | *Conway's Game of Life* | *Firework Demo* |
| ![Fog of War Demo](Screenshots/2DRender/Fog%20of%20War%20Demo.jpg) | ![Fractal Tree](Screenshots/2DRender/Fractal%20Tree.jpg) | ![Fractal Tree 2](Screenshots/2DRender/Fractal%20Tree%202.jpg) |
| *Fog of War Demo* | *Fractal Tree* | *Fractal Tree 2* |
| ![Kaleidoscope Demo](Screenshots/2DRender/Kaleidoscope%20Demo.jpg) | ![Particle System](Screenshots/2DRender/Particle%20System.jpg) | ![Rain Effect](Screenshots/2DRender/Rain%20Effect.jpg) |
| *Kaleidoscope Demo* | *Particle System* | *Rain Effect* |
| ![Spirograph](Screenshots/2DRender/Spirograph.jpg) | ![Tile map](Screenshots/2DRender/Tile%20map.jpg) | |
| *Spirograph* | *Tile map* | |

---

### OpenGL 1.2 Examples

| | | |
|:-:|:-:|:-:|
| ![3D Atom Model](Screenshots/OpenGL1_3DAtomModel.jpg) | ![Animated 3D Terrain](Screenshots/OpenGL1_Animated3DTerrain.jpg) | ![Falling Particles](Screenshots/OpenGL1_FallingParticles.jpg) |
| *3D Atom Model* | *Animated 3D Terrain* | *Falling Particles* |
| ![Fireworks Show](Screenshots/OpenGL1_FireworksShow.jpg) | ![First Person Maze](Screenshots/OpenGL1_FirstPersonMaze.jpg) | ![Interactive 3D Cube](Screenshots/OpenGL1_Interactive3DCube.jpg) |
| *Fireworks Show* | *First Person Maze* | *Interactive 3D Cube* |
| ![Move](Screenshots/OpenGL1_Move.jpg) | ![Rotate](Screenshots/OpenGL1_Rotate.jpg) | ![Rotating 3D Cube](Screenshots/OpenGL1_Rotating3DCube.jpg) |
| *Move* | *Rotate* | *Rotating 3D Cube* |
| ![Rotating Colorful Torus](Screenshots/OpenGL1_RotatingColorfulTorus.jpg) | ![Snowfall Particles](Screenshots/OpenGL1_SnowfallParticles.jpg) | ![Solar System](Screenshots/OpenGL1_SolarSystem.jpg) |
| *Rotating Colorful Torus* | *Snowfall Particles* | *Solar System* |
| ![Terrain Flight](Screenshots/OpenGL1_TerrainFlight.jpg) | ![Water Wave Simulation](Screenshots/OpenGL1_WaterWaveSimulation.jpg) | |
| *Terrain Flight* | *Water Wave Simulation* | |

---

### OpenGL 2.1 Examples

| | | |
|:-:|:-:|:-:|
| ![Shader Cube](Screenshots/OpenGL2_ShaderCube.jpg) | ![Solar System](Screenshots/OpenGL2_SolarSystem.jpg) | ![Textured Terrain](Screenshots/OpenGL2_TexturedTerrain.jpg) |
| *Shader Cube* | *Solar System* | *Textured Terrain* |

---

### OpenGL 3.3 Examples

| | | |
|:-:|:-:|:-:|
| ![Animated Water Surface](Screenshots/OpenGL3_AnimatedWaterSurface.jpg) | ![Planet With Moon](Screenshots/OpenGL3_PlanetWithMoon.jpg) | ![Rotating Cube](Screenshots/OpenGL3_RotatingCube.jpg) |
| *Animated Water Surface* | *Planet With Moon* | *Rotating Cube* |
| ![Textured Sphere](Screenshots/OpenGL3_TexturedSphere.jpg) | | |
| *Textured Sphere* | | |

---

### Legend

| Icon | Meaning |
|------|---------|
| 🟢 OpenGL 1.2 | Immediate mode, fixed pipeline, retro style |
| 🔵 OpenGL 2.1 | VBO, shaders, modern pipeline foundations |
| 🔴 OpenGL 3.3 | Core profile, VAO, advanced shaders |

---

**LDL - One Foundation, Many Interfaces. Built to Last.** 🚀
