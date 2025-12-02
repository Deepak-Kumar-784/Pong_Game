# Pong Game (SFML)

An energetic, modern take on the arcade classic. This project uses C++ and SFML to deliver a smooth paddle–ball experience with obstacles, score tracking, lives, and a tidy, production-style folder layout.

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
- C++ compiler (MSVC, MinGW, or Clang)
- SFML (Graphics/Window/System)

Install SFML via your preferred method (e.g., prebuilt binaries or vcpkg) and ensure library/include paths are configured.

**Quick Build (MinGW on Windows)**
```
g++ -I include -I <SFML-include> -L <SFML-lib> \
	src/main.cpp src/Bat.cpp src/Ball.cpp -o pong \
	-lsfml-graphics -lsfml-window -lsfml-system

./pong
```
Replace `<SFML-include>` and `<SFML-lib>` with your local SFML paths.

**Quick Build (MSVC Developer Command Prompt)**
```
cl /I include /I <SFML-include> src\main.cpp src\Bat.cpp src\Ball.cpp \
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

**Credits**
- Built by Deepak Kumar Behera
- Engine: [SFML](https://www.sfml-dev.org/)

Enjoy hacking on it — contributions and experiments welcome!
