MaRTEnoid for MaRTE OS
=================

MaRTEnoid was programmed as an example for MaRTE OS of how
to use its vga driver in C with double buffering. 

The code is not optimized and can be improved in some areas 
like collision detection and ball physics, but the goal of 
this program was making a quick, working and hopefully fun 
example, not making the perfect game implementation :)

This code is distributed for educational purposes only.
License: GPL v2

This is the original version I made in 2009.

Video: https://www.youtube.com/watch?v=FWex5FDVWXA

/////////////////////////////////////////////////////

0- INSTALLATION:

A makefile is provided to easily generate the program, however, 
you may need to change the path to the svga driver to the one 
corresponding to your MaRTE OS installation.

1- BASIC CONTROLS:

left arrow or "a" = move left
right arrow or "d" = move right

2- GAMEPLAY:

This is a little tribute to the classic Arkanoid, so most things 
are similar. 
Silver (dark gray) bricks need to be hit two times to be destroyed,
Golden ones can't be destroyed.

There're 7 levels.