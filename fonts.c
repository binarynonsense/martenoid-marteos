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
--  file: fonts.c                                                          --
--                                                                         --
--  this file contains the functions used to print strings                 --
--  using a bitmap font                                                    --
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
--                        last update: 02 Jun 09                           --
---------------------------------------------------------------------------*/

#include <string.h>
#include "vga.h"
#include "font.h"
#include "fonts.h"

int *theFont=font_img;
int screenWidth = 320;
int fontWidth=8;
int fontHeight=16;
int fontFileWidth=128;


void bmpfont_print(char *theString, int x, int y,unsigned char *backBuffer){
    int length;
    length = strlen(theString);
    
    int charPosition,charValue,fontPositionX,fontPositionY,color;
    int xf,yf,initX,initY;
    for(charPosition=0;charPosition<length;charPosition++){
        charValue=theString[charPosition];
        if(charValue<128){
            fontPositionY=charValue/16;
            fontPositionX=charValue-(fontPositionY*16);
            initX=fontPositionX*fontWidth;
            initY=fontPositionY*fontHeight;
            for(xf=0;xf<fontWidth;xf++){
                for(yf=0;yf<fontHeight;yf++){
                    color=theFont[fontFileWidth*(yf+initY)+(xf+initX)];
                    if(color!=0){
                        backBuffer[screenWidth*(y+yf)+(x+xf+charPosition*fontWidth)]=224;//white
                    }
                    //ONLY FOR MARTENOID
                    else{
                        backBuffer[screenWidth*(y+yf)+(x+xf+charPosition*fontWidth)]=0;//black
                    }
                }
            }
            
        }
        
    }
}
