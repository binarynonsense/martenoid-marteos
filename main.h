/*---------------------------------------------------------------------------
--                               MaRTEnoid                                 -- 
-----------------------------------------------------------------------------
--                                                                         --
--  MaRTEnoid is an example game for MaRTE OS.                             --
--  This code is distributed for educational purposes only.                --
--                                                                         --
--  author:   Alvaro Garcia Cuesta                                         --
--  email:    alvaro@binarynonsense.com                                    --
--  website:  www.binarynonsense.com                                       --
--                                                                         --
--  file: main.h                                                           --
--                                                                         --
--  this file is the header for main.c                                     --
-----------------------------------------------------------------------------
--                               License                                  -- 
-----------------------------------------------------------------------------
--                                                                         --
-- MaRTEnoid is free software; you can redistribute it and/or modify it    --
-- under the terms of the GNU General Public License version 2 as          -- 
-- published by the Free Software Foundation.                              --
-- See COPYING file for more info about the license                        --
--                                                                         --
-----------------------------------------------------------------------------
--                        last update: 03 Jun 09                           --
---------------------------------------------------------------------------*/

#include "vga.h"
#include <assert.h> // assert
#include <time.h>   // timespec, nanosleep
#include <math.h>   // sin
#include <misc/timespec_operations.h>  // double_to_timespec
#include <misc/console_management.h> // reset_blocking.. set_raw_mode
#include <string.h> //memset

#define PCI_DEVICE_ID_S3_TRIO64V2 35073

#include "images.h"
#include "maps.h"
#include "fonts.h"

//VARIABLES///////////////////

int gameOver;
double period;
struct timespec period_ts;
int screenWidth,screenHeight;

unsigned char *backBuffer;

#define brickWidth 10
#define brickHeight 5
#define numBricksWidth 13
#define numBricksHeight 26

//ball velocity can be adjusted setting the following variables:
//ballFramesChange, ball_dY, and the period
int frameNumber=0;
int ballFramesChange=0;

int actualMap=0;
int numMaps=7;
int *map[7];
int mapBricks=0;

int *bricksImages[10];

int areaX=0;
int areaY=0;
int areaWidth=numBricksWidth*brickWidth;
int areaBricksHeight=numBricksHeight*brickHeight;
int areaHeight;

int playerWidth=20;
int playerHeight=5;
int playerX=0;
int playerY=0;
int playerVelocity=6;//6 for real pc, 6 for qemu

int ballWidth=5;
int ballHeight=4;
int ballX=0;
int ballY=0;
int ball_dX=0;
int ball_dY=1;//1 for real pc, 4 for qemu

int backgroundBorderWidth=136;
int backgroundBorderHeight=171;
int backgroundBorderPosX,backgroundBorderPosY;
int backgroundWidth=130;
int backgroundHeight=165;
int backgroundPosX,backgroundPosY;

char text[50];
int lives=3;
int message=0;//0 is gameover 1 is win

//FUNCTIONS///////////////////

void init();

void initPalette();

void draw_border();

void draw_gameover(int message);

void draw();

void move();

void checkCollisions();

int numBricksMap(int mapNumber);

void nextLevel();

void blit();

int gameLoop();

