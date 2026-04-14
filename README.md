*This project has been created as part of the 42 curriculum by hugo-mar.*

# cub3D

## Description

**cub3D** is a 42 graphics project focused on building a simple 3D engine using **ray-casting** and **miniLibX**. It is inspired by early first-person games such as *Wolfenstein 3D* and aims to reproduce the feeling of moving inside a maze from a first-person perspective.

The purpose of the project is to explore practical computer graphics in C through:

- ray-casting fundamentals
- window management with miniLibX
- keyboard event handling
- texture rendering
- color management
- map parsing and validation
- mathematical reasoning applied to graphics

The final program renders a maze in a window, allowing the player to move around and rotate the camera in real time. According to the subject, the project must create a “realistic” 3D graphical representation of the inside of a maze using ray-casting principles.

---

## Project Goals

The core goals of cub3D are:

- to understand how ray-casting works
- to build a graphical application in C
- to manage textures, colors, and user input
- to parse and validate a configuration file
- to strengthen algorithmic thinking and structured program design

This project is also a practical introduction to the use of mathematics in game-style rendering without requiring advanced graphics APIs.

---

## Mandatory Features

The mandatory part of the project requires the program to:

- use **miniLibX**
- display a 3D view inside a maze
- render different wall textures depending on wall orientation:
  - North
  - South
  - East
  - West
- use two different colors for:
  - floor
  - ceiling
- open the scene from a `.cub` file passed as the first argument
- allow movement with:
  - `W`, `A`, `S`, `D`
- allow camera rotation with:
  - left arrow
  - right arrow
- close cleanly when:
  - pressing `ESC`
  - clicking the window close button

The subject also requires the window behaviour to remain smooth, including switching focus or minimizing the window.

---

## Scene File Format

The program must take a scene description file with the `.cub` extension.

### Required identifiers

A valid scene must define:

- `NO` path to the north texture
- `SO` path to the south texture
- `WE` path to the west texture
- `EA` path to the east texture
- `F` floor color in `R,G,B`
- `C` ceiling color in `R,G,B`

Example:

```txt
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
```

### Map rules

The map must:

- be the last element in the file
- be composed only of:
  - `0` empty space
  - `1` wall
  - `N`, `S`, `E`, or `W` player start position and orientation
- be closed and surrounded by walls
- be parsed exactly as it appears in the file
- support spaces as valid map content that must be handled correctly

The subject also states that, except for the map, elements can appear in any order and may be separated by one or more empty lines. Information within non-map elements may also be separated by one or more spaces.

If any invalid configuration is found, the program must exit properly and print:

```txt
Error
<explicit error message>
```

---

## How the Engine Works

At a high level, cub3D works by casting rays from the player's point of view into the 2D map.

For each vertical screen column, the engine:

1. computes a ray direction
2. checks where the ray hits a wall in the map
3. measures the corrected distance to avoid fisheye distortion
4. calculates the wall slice height
5. chooses the correct wall texture based on orientation
6. draws the textured wall slice
7. fills the ceiling and floor with their configured colors

This approach creates the illusion of 3D while the world is still represented internally as a 2D grid.

---

## Instructions

### Requirements

You need:

- a C compiler such as `cc`
- `make`
- **miniLibX**
- the math library
- a valid `.cub` map file
- if used in your project structure, your `libft`

### Compilation

Compile the project with:

```bash
make
```

The subject requires the following Makefile rules:

```bash
make
make all
make clean
make fclean
make re
make bonus
```

### Running the program

Run the program by passing a `.cub` file:

```bash
./cub3D maps/example.cub
```

### Controls

Mandatory controls:

```txt
W / A / S / D      Move
Left Arrow         Rotate left
Right Arrow        Rotate right
ESC                Quit
Red cross          Close window
```

---

## Example Valid Minimal Scene

```txt
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

---

## Technical Considerations

Important implementation concerns for cub3D usually include:

- robust parsing of identifiers and paths
- strict validation of RGB values
- handling irregular maps safely
- detecting whether the map is fully enclosed
- correct player spawn validation
- avoiding segmentation faults on malformed input
- freeing all allocated memory on exit
- destroying images and windows cleanly
- preventing texture-loading failures from leaving resources open

Because the project is graphical and interactive, clean error handling matters a lot.

---

## Bonus Features

The subject lists the following possible bonus features:

- wall collisions
- a minimap system
- doors that can open and close
- animated sprites
- mouse-based view rotation

Bonuses are evaluated only if the mandatory part is complete and flawless.

---

## Learning Outcomes

cub3D is valuable because it brings together several important skills in one project:

- graphics programming fundamentals
- event-driven programming
- geometry and trigonometry in practice
- parser design
- defensive programming
- modular architecture in C

It is also one of the first projects where low-level programming starts to feel visual and interactive.

---

## Resources

### Official / Classic References

- 42 cub3D subject PDF
- miniLibX documentation
- manual pages for:
  - `open`
  - `read`
  - `close`
  - `write`
  - `malloc`
  - `free`
  - `perror`
  - `strerror`
  - `gettimeofday`
- math library documentation
- Lode Vandevenne’s ray-casting tutorial
- Permadi’s ray-casting tutorial
- videos and articles explaining the original Wolfenstein 3D rendering model

### Topics worth studying

- ray-casting
- DDA line stepping
- camera plane and field of view
- texture mapping
- 2D grid map validation
- event hooks in miniLibX
- memory management in graphical projects

### AI Usage

AI was used as a support tool for:

- structuring and writing this README
- clarifying project requirements from the subject
- summarising mandatory and bonus features
- improving the wording of technical explanations
- helping organise the explanation of ray-casting and parser responsibilities

AI was not used as a substitute for understanding or blindly producing core project logic. Any implementation ideas taken from AI should be reviewed, tested, and fully understood before being used.

---

## Final Notes

cub3D is a strong introduction to graphics programming at 42. It combines parsing, maths, rendering, and event handling into a project that is both technically demanding and visually rewarding.

More than just reproducing a classic rendering technique, the project teaches how to transform a 2D map into a responsive first-person experience using clean C code.
