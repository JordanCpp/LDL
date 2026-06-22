# LDL — Emscripten / WebAssembly Backend

## Обзор

Emscripten-бэкенд позволяет компилировать LDL-приложения в WebAssembly и
запускать их в браузере.  API остаётся **полностью идентичным** другим
платформам: тот же заголовок `<LDL/LDL.h>`, те же вызовы `LDL_WindowCreate`,
`LDL_WindowGetEvent`, `LDL_WindowPresent`.

| LDL context              | WebGL версия |
|---------------------------|--------------|
| `LDL_ContextOpenGLLegacy` | WebGL 1      |
| `LDL_ContextOpenGLHybrid` | WebGL 1      |
| `LDL_ContextOpenGLModern` | WebGL 2      |

## Зависимости

* **Emscripten** ≥ 3.1 (рекомендуется последний `emsdk`)
* CMake ≥ 3.12

## Сборка

### 1. Активировать Emscripten окружение

```bash
source /path/to/emsdk/emsdk_env.sh
```

### 2. Сконфигурировать через CMake с тулчейном Emscripten

```bash
mkdir build-wasm && cd build-wasm

emcmake cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DLDL_BUILD_LIBRARY_STATIC=ON \
    -DLDL_BUILD_EXAMPLES=ON

cmake --build . -j$(nproc)
```

`emcmake` автоматически передаёт `-DCMAKE_TOOLCHAIN_FILE=...` и устанавливает
переменную `EMSCRIPTEN=1`, по которой срабатывает платформенная ветка в
`CMakeLists.txt`.

### 3. Запустить результат

Выходные файлы появятся в `build-wasm/bin/`:

```
bin/
  OpenGL1_Rotate.html
  OpenGL1_Rotate.js
  OpenGL1_Rotate.wasm
```

Открывать `.html` напрямую из файловой системы **нельзя** из-за политики
браузера CORS.  Запустите локальный HTTP-сервер:

```bash
cd build-wasm/bin
python3 -m http.server 8080
# откройте http://localhost:8080/OpenGL1_Rotate.html
```

## Использование `LDL_AddEmscriptenTarget` в своём проекте

```cmake
# В корневом CMakeLists.txt вашего приложения:
find_package(LDL REQUIRED)
include(${LDL_DIR}/cmake/emscripten/EmscriptenTarget.cmake)

if(EMSCRIPTEN)
    LDL_AddEmscriptenTarget(
        TARGET   MyApp
        SOURCES  src/main.c
        # ASYNCIFY  # раскомментировать, если нужен LDL_Delay внутри loop
    )
else()
    add_executable(MyApp src/main.c)
    target_link_libraries(MyApp PRIVATE LDL::Library)
endif()
```

## Особенности Emscripten-бэкенда

### Главный цикл

В браузере нельзя использовать блокирующий `while(LDL_WindowIsRunning(...))`.
Вместо этого передайте тело цикла в `emscripten_set_main_loop`:

```c
#include <LDL/LDL.h>
#include <emscripten.h>

static LDL_Window* g_Window;

static void MainLoop(void)
{
    LDL_Event event;
    while (LDL_WindowGetEvent(g_Window, &event))
    {
        if (event.Type == LDL_EventIsQuit)
        {
            LDL_WindowStopEvent(g_Window);
            emscripten_cancel_main_loop();
            return;
        }
        /* обработка остальных событий ... */
    }

    /* рендеринг */
    glClear(GL_COLOR_BUFFER_BIT);
    LDL_WindowPresent(g_Window);
}

int main(void)
{
    LDL_Result*  result  = LDL_ResultCreate();
    LDL_Context* context = LDL_ContextCreate(result, LDL_ContextOpenGLModern);

    g_Window = LDL_WindowCreate(result, context,
                             LDL_GetVec2i(0, 0),
                             LDL_GetVec2i(800, 600),
                             "My LDL App", 0);

    emscripten_set_main_loop(MainLoop, 0 /*fps=vsync*/, 1 /*simulate_infinite_loop*/);

    /* Код после emscripten_set_main_loop не выполняется при simulate_infinite_loop=1 */
    return 0;
}
```

> **Совет**: Оберните `#ifdef __EMSCRIPTEN__` вокруг вызова
> `emscripten_set_main_loop`, чтобы код оставался переносимым на нативные
> платформы с обычным `while`-циклом.

### `LDL_WindowPresent`

Функция является **no-op**: WebGL автоматически выполняет swap буферов в конце
каждого кадра `requestAnimationFrame`.

### `LDL_Delay`

Без флага `-s ASYNCIFY=1` реализована как busy-wait.  Для настоящего сна
добавьте `ASYNCIFY` в `LDL_AddEmscriptenTarget`:

```cmake
LDL_AddEmscriptenTarget(TARGET MyApp SOURCES main.c ASYNCIFY)
```

### `LDL_Library` (динамические библиотеки)

`LDL_LibraryOpen` всегда возвращает `false` в WASM — динамическая загрузка
модулей не поддерживается.  Линкуйте всё статически.

### Канвас

Бэкенд всегда использует элемент `<canvas id="canvas">`.  HTML-шелл LDL
(`cmake/emscripten/shell.html`) уже содержит правильную разметку.

## Отладка

* Включите `ASSERTIONS` и `SAFE_HEAP` для дебаг-сборок:
  ```bash
  emcmake cmake .. -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_EXE_LINKER_FLAGS="-s ASSERTIONS=2 -s SAFE_HEAP=1"
  ```
* Используйте вкладку **Sources** в DevTools — исходные файлы C доступны
  через `.wasm` DWARF-секции при сборке с `-g`.

## Поддерживаемые события

| LDL событие           | Источник в браузере                  |
|-----------------------|--------------------------------------|
| `LDL_EventIsKeyboard` | `keydown` / `keyup` на `window`      |
| `LDL_EventIsMouseMove`| `mousemove` на `#canvas`             |
| `LDL_EventIsMouseClick`| `mousedown` / `mouseup` на `#canvas`|
| `LDL_EventIsMouseScroll`| `wheel` на `#canvas`               |
| `LDL_EventIsResize`   | `resize` на `window`                 |
| `LDL_EventIsGainedFocus`| `focusin` на `#canvas`             |
| `LDL_EventIsLostFocus`| `focusout` на `#canvas`              |

> `LDL_EventIsQuit` не генерируется автоматически браузером.
> Для завершения приложения вызовите `LDL_WindowStopEvent` вручную
> (например, по нажатию Escape).
