# SDL Library 

This library is my attemp of emcapsulating SDL2 functionality into C++ classes,
making it easier to use and keeping all memory managment inside said classes.

## Requirements

To use these classes you must download at least SDL2 version 2.30.9, SDL image
version 2.8.2, SDL ttf version 2.22.0 and SDL mixer version 2.8.0 then link
the relevant files on your compiler/IDE, further information on how to do this
can be found here:
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php

## Class descriptions

### Init

This class takes care of all your initialization needs, in the most basic form
it inits the video mode only. It also takes care of cleanup upon program exit.

### Window

Takes care of creating an SDL window and wraps memory operations, meaning that
all memory allocated will be freed upon object destruction avoiding possible
leaks.

### Surface

Creates an SDL Surface object, this class can load bitmaps and other image
formats, optimize them, set the transparent color and blit it to the window. all
memory operations are taken care of.

### Renderer

Creates a rendering context object that can be used to render textures and draw
simple geometry into the context. It also takes care of presenting these
rendered images onto the widndow. As above, all memory allocations are safely
guarded.

### Texture

Provides Texture support, including load, setting blends, color modulation and
transparency. All memory usage taken care of.

### Font

Simple class used to load fonts anc encapsulate them to be used in textures.

### SoundFx

Used to load and play small sound effects, loads .wav files.

### Music

Loads and plays music files, providing methods to play, pause, resume and
stopping them.
