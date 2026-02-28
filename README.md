# Pong Game (SFML 3)

A small, simple arcade-style paddle-and-ball game made with C++ and **SFML 3**. It includes basic obstacles, score and lives, and uses a clean, organized folder structure.

> **Requires SFML 3.x** — this project is not compatible with SFML 2.x.

**Highlights**

- Clean `src/` + `include/` architecture
- Centered tile grid with dynamic obstacle collisions
- Paused/game-over messaging and HUD
- Simple asset management under `assets/`

**Folder Structure**

- `src/`: C++ source files (`main.cpp`, `Bat.cpp`, `Ball.cpp`)
- `include/`: Public headers (`Bat.h`, `Ball.h`)
- `assets/`: Game assets
  - `images/background.jpg`
  - `fonts/KOMIKAP_.ttf`
- `examples/`: Experimental/demo programs (`tile.cpp`, `temp.cpp`)
- `LICENSE`: Project license
- `README.md`: This guide

**Build Requirements**

- C++ compiler with C++17 support (MSVC, MinGW, or Clang)
- **SFML 3.x** (Graphics / Window / System modules)

Install SFML 3 via your preferred method (e.g., prebuilt binaries from [sfml-dev.org](https://www.sfml-dev.org/) or vcpkg: `vcpkg install sfml`) and ensure library/include paths are configured.

**Quick Build (MinGW on Windows)**

```
g++ -std=c++17 -I include -I <SFML-include> -L <SFML-lib> \
	src/main.cpp src/Bat.cpp src/Ball.cpp -o pong \
	-lsfml-graphics -lsfml-window -lsfml-system

./pong
```

Replace `<SFML-include>` and `<SFML-lib>` with your local SFML 3 paths.

**Quick Build (MSVC Developer Command Prompt)**

```
cl /std:c++17 /I include /I <SFML-include> src\main.cpp src\Bat.cpp src\Ball.cpp \
	/link /LIBPATH:<SFML-lib> sfml-graphics.lib sfml-window.lib sfml-system.lib \
	/out:pong.exe

pong.exe
```

**Run**

- Ensure assets are in `assets/` as laid out above; the game loads `assets/images/background.jpg` and `assets/fonts/KOMIKAP_.ttf` at startup.

**Controls**

- `Enter`: Start / restart
- `Left/Right`: Move paddle
- `Escape`: Quit

**Notes**

- The ball starts above the paddle; break tiles to score.
- Collision logic distinguishes side vs. top/bottom hits for obstacles.
- This project targets **SFML 3.x** and uses its updated API (`sf::Event` variant model, `Vector2f`-only setters, `sf::Font::openFromFile`, `findIntersection`, etc.). It will **not** compile against SFML 2.x.

**Credits**

- Built by Deepak Kumar Behera
- Engine: [SFML](https://www.sfml-dev.org/)

Play around with it however you like — happy to accept contributions and experiments!
