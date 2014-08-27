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
--  file: fonts.h                                                          --
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

void bmpfont_print(char *theString, int x, int y,unsigned char *backBuffer);
