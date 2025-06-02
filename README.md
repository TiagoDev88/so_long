<h1 align="center">
	🍄 so_long - Super Mario Edition
</h1>

<p align="center">
	<b><i>2D Game Engine using minilibx</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/TiagoDev88/so_long?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/TiagoDev88/so_long?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/TiagoDev88/so_long?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/TiagoDev88/so_long?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/TiagoDev88/so_long?color=green" />
</p>

<h3 align="center">
	<a href="#️-about">About</a>
	<span> · </span>
	<a href="#️-gameplay">Gameplay</a>
	<span> · </span>
	<a href="#️-bonus">Bonus</a>
	<span> · </span>
	<a href="#️-installation">Installation</a>
</h3>

---

## 💡 About

> _This project consists in creating a simple 2D game using the MiniLibX graphics library. The player must collect all collectibles and reach the exit. This version is inspired by **Super Mario**._

What I learned:
- 2D rendering with MiniLibX
- Event handling (keyboard, window close, etc.)
- Map validation and flood fill algorithm
- Asset management and sprite animation
- Modular game architecture
- Bonus logic: enemies, moves counter, animations

---

## 🎮 Gameplay

- Move Mario using `W`, `A`, `S`, `D`
- Collect all coins 🍄
- Avoid enemies 👾 (bonus)
- Reach the flag 🚩 to win!

### Valid Map Example:

``` bash
111111
1P0C01
100001
1C0E01
111111
```
**Legend:**
``` bash
- `1` = Wall  
- `0` = Empty space  
- `P` = Player  
- `C` = Collectible  
- `E` = Exit  
```
## **🪄 Bonus Features**

``` bash
✅ Enemy patrol (Goomba-like behavior)  
✅ Move counter on screen  
✅ Sprite animations (Mario walking, idle, etc.)  
✅ Game over & win screens  
✅ Custom textures and sound support  
✅ Window resize protection 
```

## **🛠️ Installation**

### Requirements

- Linux
- `make`
- `gcc`
- `mlx` (MiniLibX)

> Tip: On Linux, use the [MiniLibX Linux version](https://harm-smits.github.io/42docs/libs/minilibx)

### Instructions

```bash
git clone https://github.com/TiagoDev88/so_long.git
cd so_long
make
```

**To run the game:**
```bash
./so_long maps/map1.ber
```
Map files must have .ber extension.

## **🗺️ Maps**
Custom maps can be placed in the maps/ directory.
Make sure they are rectangular, enclosed by walls, and contain at least:

1 Player P

1 Exit E

1 Collectible C

## **📁 Files Overview**
src/ → Game logic and rendering

maps/ → Example .ber maps

textures/ → Sprites (Mario, Goomba, coins, etc.)

so_long.h → Prototypes and structs

Makefile → Build automation

## **👤 Author**
42 login: tfilipe-
GitHub: @TiagoDev88
