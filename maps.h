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
--  file: maps.h                                                           --
--                                                                         --
--  this file contains the level maps used in the game                     --
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
--                        last update: 28 May 09                           --
---------------------------------------------------------------------------*/

#define numBricksWidth 13
#define numBricksHeight 26

/*
8 normal: 50pts+10
grey orange bluelight green red blue pink yellow
1        2     3         4   5   6    7     8
2 special:
greydark gold dark
9-11      12
*/

int map_19[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,10,10,10,10,10,10,10,0,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,4,5,6,7,0,7,6,5,4,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,4,5,6,7,10,7,6,5,4,0,0,
    0,0,0,10,10,10,10,10,10,10,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

int map_7[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,8,8,7,0,0,0,0,0,
    0,0,0,0,8,8,7,7,6,0,0,0,0,
    0,0,0,8,8,7,7,6,6,5,0,0,0,
    0,0,0,8,7,7,6,6,5,5,0,0,0,
    0,0,8,7,7,6,6,5,5,4,4,0,0,
    0,0,7,7,6,6,5,5,4,4,3,0,0,
    0,0,7,6,6,5,5,4,4,3,3,0,0,
    0,0,6,6,5,5,4,4,3,3,2,0,0,
    0,0,6,5,5,4,4,3,3,2,2,0,0,
    0,0,5,5,4,4,3,3,2,2,1,0,0,
    0,0,0,4,4,3,3,2,2,1,0,0,0,
    0,0,0,4,3,3,2,2,1,1,0,0,0,
    0,0,0,0,3,2,2,1,1,0,0,0,0,
    0,0,0,0,0,2,1,1,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

int map_5[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,8,0,0,0,0,0,8,0,0,0,
    0,0,0,8,0,0,0,0,0,8,0,0,0,
    0,0,0,0,8,0,0,0,8,0,0,0,0,
    0,0,0,0,8,0,0,0,8,0,0,0,0,
    0,0,0,9,9,9,9,9,9,9,0,0,0,
    0,0,0,9,9,9,9,9,9,9,0,0,0,
    0,0,9,9,5,9,9,9,5,9,9,0,0,
    0,0,9,9,5,9,9,9,5,9,9,0,0,
    0,9,9,9,9,9,9,9,9,9,9,9,0,
    0,9,9,9,9,9,9,9,9,9,9,9,0,
    0,9,9,9,9,9,9,9,9,9,9,9,0,
    0,9,0,9,9,9,9,9,9,9,0,9,0,
    0,9,0,9,0,0,0,0,0,9,0,9,0,
    0,9,0,9,0,0,0,0,0,9,0,9,0,
    0,0,0,0,9,9,0,9,9,0,0,0,0,
    0,0,0,0,9,9,0,9,9,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

int map_1[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    4,4,4,4,4,4,4,4,4,4,4,4,4,
    3,3,3,3,3,3,3,3,3,3,3,3,3,
    2,2,2,2,2,2,2,2,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

int map_2[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,0,0,0,0,0,0,0,0,
    1,2,0,0,0,0,0,0,0,0,0,0,0,
    1,2,3,0,0,0,0,0,0,0,0,0,0,
    1,2,3,1,0,0,0,0,0,0,0,0,0,
    1,2,3,1,2,0,0,0,0,0,0,0,0,
    1,2,3,1,2,3,0,0,0,0,0,0,0,
    1,2,3,1,2,3,1,0,0,0,0,0,0,
    1,2,3,1,2,3,1,2,0,0,0,0,0,
    1,2,3,1,2,3,1,2,3,0,0,0,0,
    1,2,3,1,2,3,1,2,3,1,0,0,0,
    1,2,3,1,2,3,1,2,3,1,2,0,0,
    1,2,3,1,2,3,1,2,3,1,2,3,0,
    9,9,9,9,9,9,9,9,9,9,9,9,9,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};


int map_marte[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    4,0,0,0,4,0,0,0,3,3,3,3,0,
    4,4,0,4,4,2,2,2,3,0,0,0,3,
    4,0,4,0,4,2,0,2,3,3,3,3,3,
    4,0,0,0,4,2,2,2,3,0,0,3,0,
    4,0,0,0,4,2,0,2,3,0,0,0,3,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,6,6,6,0,5,5,5,0,0,0,
    0,0,0,0,6,0,0,5,0,0,0,0,0,
    0,0,0,0,6,0,0,5,5,5,0,0,0,
    0,0,0,0,6,0,0,5,0,0,0,0,0,
    0,0,0,0,6,0,0,5,5,5,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

int map_4[numBricksWidth*numBricksHeight]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,2,3,5,9,6,0,8,1,2,3,5,0,
    0,3,5,9,6,7,0,1,2,3,5,9,0,
    0,5,9,6,7,8,0,2,3,5,9,6,0,
    0,9,6,7,8,1,0,3,5,9,6,5,0,
    0,6,7,8,1,2,0,5,9,6,5,5,0,
    0,7,8,1,2,3,0,9,6,5,5,3,0,
    0,8,1,2,3,5,0,6,5,5,3,2,0,
    0,1,2,3,5,9,0,5,5,3,2,5,0,
    0,2,3,5,9,6,0,5,3,2,5,2,0,
    0,3,5,9,6,5,0,3,2,5,2,6,0,
    0,5,9,6,5,1,0,2,5,2,6,7,0,
    0,9,6,5,1,3,0,5,2,6,7,10,0,
    0,6,5,1,3,2,0,2,6,7,10,10,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0
};

///////blank map template://////////
// int map_1[numBricksWidth*numBricksHeight]=
// {
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0
// };
