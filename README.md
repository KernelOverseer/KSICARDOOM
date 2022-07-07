# KSICARDOOM - GameDev like it's the 90's

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_menu.gif">
<p>

KSICARDOOM is an advanced ray-casting game written from scratch in C, with an engine that supports :

- Multiple sectors with different floor and ceiling heights.
- Wall, floor and ceiling textures.
- Fixed, animated, 360° sprites.
- 3D camera movements, jumping and crouching.
- Projectiles, collectibles, and events.
- Loadable map files.
- Simple multiplayer using UNIX sockets.
- Background and event triggered sounds.
- Modular design, and ready interface for implementing bots.

## The Game :

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_projectile.gif">
<p>

> Projectiles have animations when destroyed, and make sound.

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_stairs.gif">
<p>

> Stairs, Elevators and floors which are impossible in traditional ray-casting are implemented in this engine.

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_non_euclidean.gif">
<p>

> Normal World Rules don't apply to the engine's world


## The Map Editor :
The map editor is using a GUI library build from scratch, on top of SDL2, that supports :
- Buttons
- Check-boxes
- Sliders
- Tabs
- Lists
- Canvas

The editor can either create a new map, or edit an existing one, the map format is a special KSICARDOOM file, containing assets, map layout and sprite positions.

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_editor_walls.gif">
<p>

> Can add, and edit, walls, portals and sprites.

<p align="center">
<img src="https://kerneloverseer.github.io/static/ksicardoom_editor_floor_ceiling.gif">
<p>

> Can change height of floor and ceiling in addition to brightness for each sector.

## Ray-casting Explained :

<p align="center">
<img width="400px" src="https://kerneloverseer.github.io/static/ksicardoom_youtube_thumbnail.jpg">
<p>

Following lots of requests from students at 1337 school, I have published a video on YouTube (In Moroccan Darija) titled "[Raycasting Engine, as fast as possible (with code)](https://www.youtube.com/watch?v=DFZnzCbmlng)", and provided some P5.js sketches you can play with, to better understand how all components work, (Camera, DDA, Drawing, Textures).

Here is the link to the sketches :
- [Camera](https://editor.p5js.org/KernelOverseer/full/FGwOXIrHf)
- [DDA algorithm](https://editor.p5js.org/KernelOverseer/full/Nhdg1PvMt)
- [Camera + DDA + Wall Drawing](https://editor.p5js.org/KernelOverseer/full/Ilst053ZC)
- [Camera + DDA + Wall Drawing + Textures](https://editor.p5js.org/KernelOverseer/full/SQAqsHP6A)
## Special Thanks :
- Thanks to all my peers at **1337 Coding School**, who appreciated my work and encouraged me to add new features.
- Special thanks to **!SilentCorner** and the computer graphics guys, for being competitive in their creativity, and my friend ksikso (couscous) for suggesting the name.
- Deep thanks to [msidqi](https://github.com/msidqi), [MBarkErras](https://github.com/MBarkErras) and [ilkou](https://github.com/ilkou) for their contributions to the project, and always being there to discuss new ideas, even with their limited free-time.
