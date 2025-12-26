# SeeImageViewer

Get it See and C lol

## Features
- Simple C image viewer using SDL2 and standard libraries in C

## Dependencies
- SDL2 library

## Installation on fedora
```bash
sudo dnf install SDL2-devel
```

## Compilation and Usage

To run the program, make sure you have SDL2 installed on your system.

Compile the program using:
```bash
gcc -Wall -Wextra -g -o iv iv.c `sdl2-config --cflags --libs`
```

Run the program by piping an image file:
```bash
cat redbull.ppm | ./iv
```

- Only PPM format is supported.