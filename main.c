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
--  file: main.c                                                           --
--                                                                         --
--  this file contains the main logic of the game                          --
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

#include "main.h"

int main(void){
    
    init();
    gameLoop();
    return 0;
}

/////////////////////////////////////////////////    
int gameLoop(){

    while(!gameOver){               

        move(); 
        checkCollisions();               
        draw();
        blit();//swap buffers
        if(frameNumber>=ballFramesChange){
            frameNumber=0;
        }else{
            frameNumber++;
        }//this is used to adjust the ball's velocity
        ////WAIT  FOR NEXT FRAME////////////////
        nanosleep(&period_ts, NULL);
    }
    draw_gameover(message);
    blit();
    while(getchar()!='q'){
    }//give time to read the message
    return 0;
}

/////////////////////////////////////////////////    
void init(){

    period = 1.0/60.0;
    //period_ts = double_to_timespec(period);  //old versions of MaRTE OS
    double_to_timespec(period,&period_ts); //new versions of MaRTE OS
    
    //make getchar() non-blocking:
    reset_blocking_mode ();
    set_raw_mode ();
    
    ////init vga///////////////////////////
    screenWidth=320;
    screenHeight=200;
    int ret = init_vga(G320x200x256, VGA, PCI_DEVICE_ID_S3_TRIO64V2);
    assert (ret == 0); 
    backBuffer = (unsigned char *)malloc(screenWidth*screenHeight);//virtual canvas for blitting
    memset(backBuffer, 0, screenWidth*screenHeight);
    //////////////////////////////////////
    
    initPalette();//fill palette's colors
    
    areaX=screenWidth/2-areaWidth/2;
    areaY=25;

    backgroundPosX=areaX;
    backgroundPosY=areaY;
    backgroundBorderPosX=areaX-3;
    backgroundBorderPosY=areaY-3;
    
    areaHeight=areaBricksHeight+brickHeight*5;
    
    playerX=areaX+areaWidth/2-playerWidth/2;
    playerY=areaY+areaHeight;
    
    ballX=playerX+playerWidth/2-ballWidth/2;
    ballY=playerY-3*ballHeight;

    //fill the brick images array with a pointer to each brick's data
    bricksImages[0]=brick_1_gray;
    bricksImages[1]=brick_2_orange;
    bricksImages[2]=brick_3_lightblue;
    bricksImages[3]=brick_4_green;
    bricksImages[4]=brick_5_red;
    bricksImages[5]=brick_6_darkblue;
    bricksImages[6]=brick_7_pink;
    bricksImages[7]=brick_8_yellow;
    bricksImages[8]=brick_9_silver;
    bricksImages[9]=brick_10_golden;
    
    //fill the maps array with a pointer to each map's data
    map[0]=map_1;
    map[1]=map_marte;
    map[2]=map_2;
    map[3]=map_4;
    map[4]=map_5;
    map[5]=map_7;
    map[6]=map_19;
    actualMap=0;
    mapBricks=numBricksMap(actualMap);
            
    gameOver = 0;
     
}
/////////////////////////////////////////////////    
void move(){

    //check keyboard
    char key;
    key=getchar();
    //flush buffer
    while(getchar()!=-1){
    }

    if (key=='d' || key=='6'){//move left
        if(playerX+playerWidth+playerVelocity>areaX+areaWidth){
            playerX=areaX+areaWidth-playerWidth;
        }else{
            playerX+=playerVelocity;
        }
        
    }else if (key=='a' || key=='4'){//move right
        if(playerX-playerVelocity<areaX){
            playerX=areaX;
        }else{
            playerX-=playerVelocity;
        }
    //CHEAT!!
    }else if(key=='n'){
        nextLevel();
    }else if(key=='o'){
        ball_dY*=2;
    }else if(key=='p'){
        if(ball_dY>=2)ball_dY/=2;
    }else if(key=='l'){
        if(lives<4){
            lives++;
        }
    }    

}
/////////////////////////////////////////////////    
void checkCollisions(){
    
    if(mapBricks<=0){
        nextLevel();
    }
    
    if(frameNumber==0){//move the ball if it's time to
        ballX+=ball_dX;
        if(ballX<areaX){ballX=areaX;}
        if((ballX+ballWidth)>areaX+areaWidth){ballX=areaX+areaWidth;}
        
        ballY+=ball_dY;
        if(ballY<areaY){ballY=areaY;}
    }

    if(frameNumber==0){//check only if ball moved
        //ball-walls////////////////////////////
        if(ballX<=areaX){
            ballX=areaX;
            ball_dX*=-1;
        }else if(ballX>=areaX+areaWidth-ballWidth){
            ballX=areaX+areaWidth-ballWidth;
            ball_dX*=-1;
        }
        
        if(ballY<=areaY){
            ballY=areaY;
            ball_dY*=-1;
        }else if(ballY>=areaY+areaHeight){//LOSEEEEERRRRRR!!!!! :)
            if(--lives<=0){
                gameOver=1;            
            }else{
                sleep(2);
                ballX=playerX+playerWidth/2-ballWidth/2;
                ballY=playerY-3*ballHeight;
                ball_dX=0;
            }
        }
        
        //ball-player////////////////////////////
        //3 different areas of collision are defined
        //it's a simple approach, didn't want to complicate the code with floats, angles, realistic physics et cetera
        if (((playerX+playerWidth)>ballX)&&((playerY+playerWidth)>ballY)&&((ballX+ballWidth)>playerX)&&((ballY+ballWidth)>playerY)) {
            //collision
            ballY=playerY-ballHeight;
            
            //center area of the bar
            if((ballX + ballWidth / 2) >= (playerX + playerWidth / 2) - playerWidth/6 
                && (ballX + ballWidth / 2) <= (playerX + playerWidth / 2) + playerWidth/6 ) { 
                ball_dX = 0; 
            } 
            //left side pushes ball to left and viceversa
            if( ((ballX + ballWidth / 2) >= (playerX + playerWidth / 2)- 3*playerWidth/8) 
                && ((ballX + ballWidth / 2) <= (playerX + playerWidth / 2)- playerWidth/6)
            ) { 
                ball_dX = -1;
            } 
            else if( ((ballX + ballWidth / 2) >= (playerX + playerWidth / 2)+ playerWidth/6) 
                    && ((ballX + ballWidth / 2) <= (playerX + playerWidth / 2)+ 3*playerWidth/8)
            ) { 
                ball_dX = 1;
            } 
            //left side pushes ball to left and viceversa
            if((ballX + ballWidth / 2) <= (playerX + playerWidth / 2)- 3*playerWidth/8) { 
                ball_dX = -2;
            } 
            else if((ballX + ballWidth / 2) >= (playerX + playerWidth / 2)+ 3*playerWidth/8) { 
                ball_dX = 2;
            } 
            ball_dY*=-1;
        }
        
        //ball-bricks////////////////////////////
        //I don't specially like this 'quick and dirty' code, it can be improved and/or simplified,
        //I just don't have the time... and, anyway, it works well enough :)
        //just checks each corner of the ball's bounding box against the bricks
        int upleft=0,upright=0,downleft=0,downright=0;
        int upLeftX,upLeftY, upRightX,upRightY, downRightX,downRightY, downLeftX,downLeftY;
        if(ballY<areaBricksHeight){
            upLeftX=(ballX-areaX)/brickWidth;
            upLeftY=(ballY-areaY)/brickHeight;
            if(map[actualMap][numBricksWidth*upLeftY+upLeftX]>0){
                if(map[actualMap][numBricksWidth*upLeftY+upLeftX]==9){//grey block has 2 lives
                    map[actualMap][numBricksWidth*upLeftY+upLeftX]=map[actualMap][numBricksWidth*upLeftY+upLeftX]-1;
                }else if(map[actualMap][numBricksWidth*upLeftY+upLeftX]!=10){//golden brick is indestructible
                    map[actualMap][numBricksWidth*upLeftY+upLeftX]=0;
                    mapBricks--;
                }
                upleft=1;
            }
            
            upRightX=(ballX-areaX+ballWidth-1)/brickWidth;
            upRightY=(ballY-areaY)/brickHeight;
            if((upRightX!=upLeftX)||(upRightY!=upLeftY)){
                if(map[actualMap][numBricksWidth*upRightY+upRightX]>0){
                    if(map[actualMap][numBricksWidth*upRightY+upRightX]==9){//grey block has 2 lives
                        map[actualMap][numBricksWidth*upRightY+upRightX]=map[actualMap][numBricksWidth*upRightY+upRightX]-1;
                    }else if(map[actualMap][numBricksWidth*upRightY+upRightX]!=10){
                        map[actualMap][numBricksWidth*upRightY+upRightX]=0;
                        mapBricks--;
                    }
                    upright=1;
                }
            }else{
                upright=upleft;
            }
            
            downRightX=(ballX-areaX+ballWidth-1)/brickWidth;
            downRightY=(ballY-areaY+ballHeight-1)/brickHeight;
            if((downRightX!=upRightX)||(downRightY!=upRightY)){
                if(map[actualMap][numBricksWidth*downRightY+downRightX]>0){
                    if(map[actualMap][numBricksWidth*downRightY+downRightX]==9){//grey block has 2 lives
                        map[actualMap][numBricksWidth*downRightY+downRightX]=map[actualMap][numBricksWidth*downRightY+downRightX]-1;
                    }else if(map[actualMap][numBricksWidth*downRightY+downRightX]!=10){
                        map[actualMap][numBricksWidth*downRightY+downRightX]=0;
                        mapBricks--;
                    }
                    downright=1;
                }
            }else{
                downright=upright;
            }
            
            downLeftX=(ballX-areaX)/brickWidth;
            downLeftY=(ballY-areaY+ballHeight-1)/brickHeight;
            if((downLeftX!=downRightX)||(downLeftY!=downRightY) ){
                if(((downLeftX!=upLeftX)||(downLeftY!=upLeftY))){
                    if(map[actualMap][numBricksWidth*downLeftY+downLeftX]>0){
                        if(map[actualMap][numBricksWidth*downLeftY+downLeftX]==9){//grey block has 2 lives
                            map[actualMap][numBricksWidth*downLeftY+downLeftX]=map[actualMap][numBricksWidth*downLeftY+downLeftX]-1;
                        }else if(map[actualMap][numBricksWidth*downLeftY+downLeftX]!=10){
                            map[actualMap][numBricksWidth*downLeftY+downLeftX]=0;
                            mapBricks--;
                        }
                        downleft=1;
                    }
                }else{
                    downleft=upleft;
                }
            }else{
                downleft=downright;
            }
            //change ball direction depending on which area of the brick it collided
            if((upleft && upright) || (downright && downleft) ){
                ball_dY*=-1;             
            }else if((upleft && downleft) || (upright && downright)){
                ball_dX*=-1;  
            }else if((upleft && !upright) || (!upleft && upright)){
                ball_dX*=-1;
                ball_dY*=-1;
            }else if((downleft && !downright) || (!downleft && downright)){
                ball_dX*=-1;
                ball_dY*=-1;
            }//there're some non-realistic bounce effects doing this that should be fixed
        }
    }   
}
/////////////////////////////////////////////////    
void draw_gameover(int message){
    int i,j,color;
    if(message==0){//GAME OVER :(
        for(i=0;i<190;i++){
            for(j=0;j<40;j++){
                color=gameover_img[190*j+i];
                if(color!=251){
                    backBuffer[screenWidth*((screenHeight/2-40/2)+j)+((screenWidth/2-190/2)+i)]=color;
                }
            }
        }
    }else{//YOU WIN!!!!
        for(i=0;i<190;i++){
            for(j=0;j<40;j++){
                color=win_img[190*j+i];
                if(color!=251){
                    backBuffer[screenWidth*((screenHeight/2-40/2)+j)+((screenWidth/2-190/2)+i)]=color;
                }
            }
        }
    }
}
/////////////////////////////////////////////////    
void draw_border(){//the orange rectangle

    int i,j,color;
    for(i=0;i<backgroundBorderWidth;i++){
        for(j=0;j<backgroundBorderHeight;j++){
            color=background_border[backgroundBorderWidth*j+i];
            if(color!=251){
                backBuffer[screenWidth*(backgroundBorderPosY+j)+(backgroundBorderPosX+i)]=color;
            }
        }
    }
}
/////////////////////////////////////////////////    
void draw_lives(){
    
    int l,i,j,color;
    for(l=1;l<=4;l++){//hard coded, would be better to have a variable for the maxLives
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                if(lives>=l){
                    color=life_img[10*j+i];
                }else{
                    color=0;
                }
                if(color!=251){
                    backBuffer[screenWidth*(8+j)+(areaX+(14*(l-1))+i)]=color;
                }
            }
        }
    }
}

/////////////////////////////////////////////////    
void draw_level(){
    char *theString[10];
    int x,y;
    x=areaX+70;
    y=4;
    //draw string
    sprintf(theString,"Level %d",actualMap+1);
    if(!gameOver){
        bmpfont_print(theString, x, y, backBuffer);
    }
}
/////////////////////////////////////////////////    
void draw(){//paint everything in the buffer    
    
    int x,y;
    int i,j,color;
    int tempX,tempY;
    
    //draw background area////////////////////////////
    for(i=0;i<backgroundWidth;i++){
        for(j=0;j<backgroundHeight;j++){
                color=background_center[backgroundWidth*j+i];
                if(color!=251){
                    if((actualMap+2)%2==0){color+=16*6;}
                    backBuffer[screenWidth*(backgroundPosY+j)+(backgroundPosX+i)]=color;
                }
        }
    }
    
    draw_lives();
    draw_level();

    //draw bricks////////////////////////////
    if(!gameOver){//don't draw the bricks if the game is over
        for(x=0;x<numBricksWidth;x++){
            for(y=0;y<numBricksHeight;y++){
                
                for(i=0;i<brickWidth;i++){
                    for(j=0;j<brickHeight;j++){
                        if(map[actualMap][numBricksWidth*y+x]>0){//0 is empty
                            
                            color=bricksImages[map[actualMap][numBricksWidth*y+x]-1][brickWidth*j+i];
                            if(color!=251){
                                tempX=areaX+x*brickWidth;
                                tempY=areaY+y*brickHeight;
                                backBuffer[screenWidth*(tempY+j)+(tempX+i)]=color;
                            }
                        }
                        
                    }
                }
                
                
            }
        }
    }
    
    
    //draw player////////////////////////////
    for(i=0;i<playerWidth;i++){
        for(j=0;j<playerHeight;j++){
            color=player_img[playerWidth*j+i];
            if(color!=251){
                backBuffer[screenWidth*(playerY+j)+(playerX+i)]=color;
                //backBuffer[screenWidth*(playerY+j+1)+(playerX+i+1)]=0;//shadow
            }
        }
    }
    
    //draw ball////////////////////////////
    for(i=0;i<ballWidth;i++){
        for(j=0;j<ballHeight;j++){
            color=ball_img[ballWidth*j+i];
            if(color!=251){
                backBuffer[screenWidth*(ballY+j)+(ballX+i)]=color;
            }
        }
    }
    
    draw_border();
    

}
/////////////////////////////////////////////////    
int numBricksMap(int mapNumber){//how many bricks need to be destroyed in the map? :)

    int x,y,number;
    number=0;
    for(x=0;x<numBricksWidth;x++){
        for(y=0;y<numBricksHeight;y++){
            if(map[mapNumber][numBricksWidth*y+x]>0 && map[mapNumber][numBricksWidth*y+x]<10){//10 is the golden brick
                number++;
            }
        }
    }
    return number;
    
}
/////////////////////////////////////////////////    
void nextLevel(){//called when all the bricks of the current map are destroyed

    if(++actualMap<numMaps){
        mapBricks=numBricksMap(actualMap);
        ballX=playerX+playerWidth/2-ballWidth/2;
        ballY=playerY-3*ballHeight;
        ball_dX=0;
        if(lives<4){lives++;}
        //ball_dY=1;//1 for real pc, 4 for qemu
        draw();
        sleep(2);
    }else{//the end
        gameOver=1;
        message=1;
    }
}
/////////////////////////////////////////////////        
void blit(){//send the buffer to the video memory (double buffering/blitting) 
   
    //vga_waitretrace();//wait for vertical blank, not sure it really works :P
    vga_drawscansegment(backBuffer,0,0,screenWidth*screenHeight);     
 
}    
/////////////////////////////////////////////////        
void initPalette(){ 

    //fill the 256 colors of the VGA palette
    vga_setpalette(0, 0, 0, 0);
    vga_setpalette(1, 7, 5, 2);
    vga_setpalette(2, 5, 3, 1);
    vga_setpalette(3, 18, 18, 18);
    vga_setpalette(4, 63, 63, 63);
    vga_setpalette(5, 6, 6, 6);
    vga_setpalette(6, 4, 4, 4);
    vga_setpalette(7, 2, 2, 2);
    vga_setpalette(8, 1, 1, 1);
    vga_setpalette(9, 11, 13, 7);
    vga_setpalette(10, 8, 10, 3);
    vga_setpalette(11, 5, 7, 1);
    vga_setpalette(12, 3, 5, 0);
    vga_setpalette(13, 19, 14, 10);
    vga_setpalette(14, 17, 12, 8);
    vga_setpalette(15, 15, 10, 6);
    vga_setpalette(16, 63, 45, 45);
    vga_setpalette(17, 61, 42, 42);
    vga_setpalette(18, 60, 40, 40);
    vga_setpalette(19, 58, 37, 37);
    vga_setpalette(20, 57, 35, 35);
    vga_setpalette(21, 55, 33, 33);
    vga_setpalette(22, 54, 30, 30);
    vga_setpalette(23, 52, 28, 28);
    vga_setpalette(24, 50, 26, 26);
    vga_setpalette(25, 49, 24, 24);
    vga_setpalette(26, 47, 22, 22);
    vga_setpalette(27, 46, 21, 21);
    vga_setpalette(28, 44, 19, 19);
    vga_setpalette(29, 43, 17, 17);
    vga_setpalette(30, 41, 15, 15);
    vga_setpalette(31, 40, 14, 14);
    vga_setpalette(32, 38, 12, 12);
    vga_setpalette(33, 37, 11, 11);
    vga_setpalette(34, 35, 10, 10);
    vga_setpalette(35, 34, 8, 8);
    vga_setpalette(36, 32, 7, 7);
    vga_setpalette(37, 31, 6, 6);
    vga_setpalette(38, 29, 5, 5);
    vga_setpalette(39, 28, 4, 4);
    vga_setpalette(40, 26, 3, 3);
    vga_setpalette(41, 25, 2, 2);
    vga_setpalette(42, 23, 1, 1);
    vga_setpalette(43, 22, 1, 1);
    vga_setpalette(44, 20, 1, 1);
    vga_setpalette(45, 19, 0, 0);
    vga_setpalette(46, 17, 0, 0);
    vga_setpalette(47, 16, 0, 0);
    vga_setpalette(48, 63, 58, 55);
    vga_setpalette(49, 63, 56, 52);
    vga_setpalette(50, 63, 54, 49);
    vga_setpalette(51, 63, 52, 46);
    vga_setpalette(52, 63, 51, 44);
    vga_setpalette(53, 63, 49, 41);
    vga_setpalette(54, 63, 47, 38);
    vga_setpalette(55, 63, 46, 36);
    vga_setpalette(56, 63, 44, 32);
    vga_setpalette(57, 61, 42, 30);
    vga_setpalette(58, 59, 40, 28);
    vga_setpalette(59, 57, 38, 26);
    vga_setpalette(60, 55, 36, 24);
    vga_setpalette(61, 53, 34, 22);
    vga_setpalette(62, 51, 32, 20);
    vga_setpalette(63, 50, 31, 19);
    vga_setpalette(64, 47, 30, 18);
    vga_setpalette(65, 44, 28, 17);
    vga_setpalette(66, 42, 27, 16);
    vga_setpalette(67, 40, 26, 15);
    vga_setpalette(68, 38, 24, 14);
    vga_setpalette(69, 35, 23, 13);
    vga_setpalette(70, 33, 21, 12);
    vga_setpalette(71, 31, 20, 11);
    vga_setpalette(72, 29, 19, 10);
    vga_setpalette(73, 26, 17, 9);
    vga_setpalette(74, 23, 16, 8);
    vga_setpalette(75, 20, 15, 7);
    vga_setpalette(76, 18, 13, 6);
    vga_setpalette(77, 15, 11, 5);
    vga_setpalette(78, 12, 10, 4);
    vga_setpalette(79, 10, 8, 3);
    vga_setpalette(80, 59, 59, 59);
    vga_setpalette(81, 57, 57, 57);
    vga_setpalette(82, 55, 55, 55);
    vga_setpalette(83, 54, 54, 54);
    vga_setpalette(84, 52, 52, 52);
    vga_setpalette(85, 50, 50, 50);
    vga_setpalette(86, 49, 49, 49);
    vga_setpalette(87, 47, 47, 47);
    vga_setpalette(88, 45, 45, 45);
    vga_setpalette(89, 44, 44, 44);
    vga_setpalette(90, 42, 42, 42);
    vga_setpalette(91, 41, 41, 41);
    vga_setpalette(92, 39, 39, 39);
    vga_setpalette(93, 37, 37, 37);
    vga_setpalette(94, 36, 36, 36);
    vga_setpalette(95, 34, 34, 34);
    vga_setpalette(96, 32, 32, 32);
    vga_setpalette(97, 31, 31, 31);
    vga_setpalette(98, 29, 29, 29);
    vga_setpalette(99, 27, 27, 27);
    vga_setpalette(100, 26, 26, 26);
    vga_setpalette(101, 24, 24, 24);
    vga_setpalette(102, 22, 22, 22);
    vga_setpalette(103, 21, 21, 21);
    vga_setpalette(104, 19, 19, 19);
    vga_setpalette(105, 17, 17, 17);
    vga_setpalette(106, 16, 16, 16);
    vga_setpalette(107, 14, 14, 14);
    vga_setpalette(108, 13, 13, 13);
    vga_setpalette(109, 11, 11, 11);
    vga_setpalette(110, 9, 9, 9);
    vga_setpalette(111, 8, 8, 8);
    vga_setpalette(112, 29, 63, 27);
    vga_setpalette(113, 27, 59, 25);
    vga_setpalette(114, 25, 55, 23);
    vga_setpalette(115, 23, 51, 21);
    vga_setpalette(116, 22, 47, 19);
    vga_setpalette(117, 20, 43, 17);
    vga_setpalette(118, 18, 39, 15);
    vga_setpalette(119, 16, 36, 13);
    vga_setpalette(120, 15, 32, 11);
    vga_setpalette(121, 13, 28, 10);
    vga_setpalette(122, 11, 24, 8);
    vga_setpalette(123, 9, 20, 6);
    vga_setpalette(124, 7, 16, 5);
    vga_setpalette(125, 5, 12, 3);
    vga_setpalette(126, 4, 8, 2);
    vga_setpalette(127, 2, 5, 1);
    vga_setpalette(128, 47, 41, 35);
    vga_setpalette(129, 45, 39, 33);
    vga_setpalette(130, 43, 37, 31);
    vga_setpalette(131, 41, 35, 29);
    vga_setpalette(132, 39, 33, 27);
    vga_setpalette(133, 38, 31, 26);
    vga_setpalette(134, 36, 30, 24);
    vga_setpalette(135, 34, 28, 22);
    vga_setpalette(136, 32, 26, 21);
    vga_setpalette(137, 30, 24, 19);
    vga_setpalette(138, 29, 23, 18);
    vga_setpalette(139, 27, 21, 16);
    vga_setpalette(140, 25, 20, 15);
    vga_setpalette(141, 23, 18, 13);
    vga_setpalette(142, 21, 16, 12);
    vga_setpalette(143, 20, 15, 11);
    vga_setpalette(144, 39, 32, 24);
    vga_setpalette(145, 35, 29, 20);
    vga_setpalette(146, 32, 26, 18);
    vga_setpalette(147, 29, 23, 15);
    vga_setpalette(148, 25, 20, 12);
    vga_setpalette(149, 22, 17, 10);
    vga_setpalette(150, 19, 14, 8);
    vga_setpalette(151, 16, 12, 6);
    vga_setpalette(152, 30, 31, 24);
    vga_setpalette(153, 27, 28, 21);
    vga_setpalette(154, 25, 26, 19);
    vga_setpalette(155, 22, 24, 17);
    vga_setpalette(156, 20, 21, 14);
    vga_setpalette(157, 17, 19, 12);
    vga_setpalette(158, 15, 17, 10);
    vga_setpalette(159, 13, 15, 9);
    vga_setpalette(160, 63, 63, 28);
    vga_setpalette(161, 58, 54, 21);
    vga_setpalette(162, 53, 46, 16);
    vga_setpalette(163, 48, 38, 11);
    vga_setpalette(164, 43, 30, 7);
    vga_setpalette(165, 38, 22, 4);
    vga_setpalette(166, 33, 16, 1);
    vga_setpalette(167, 28, 10, 0);
    vga_setpalette(168, 63, 63, 63);
    vga_setpalette(169, 63, 54, 54);
    vga_setpalette(170, 63, 46, 46);
    vga_setpalette(171, 63, 38, 38);
    vga_setpalette(172, 63, 30, 30);
    vga_setpalette(173, 63, 23, 23);
    vga_setpalette(174, 63, 15, 15);
    vga_setpalette(175, 63, 7, 7);
    vga_setpalette(176, 63, 0, 0);
    vga_setpalette(177, 59, 0, 0);
    vga_setpalette(178, 56, 0, 0);
    vga_setpalette(179, 53, 0, 0);
    vga_setpalette(180, 50, 0, 0);
    vga_setpalette(181, 47, 0, 0);
    vga_setpalette(182, 44, 0, 0);
    vga_setpalette(183, 41, 0, 0);
    vga_setpalette(184, 38, 0, 0);
    vga_setpalette(185, 34, 0, 0);
    vga_setpalette(186, 31, 0, 0);
    vga_setpalette(187, 28, 0, 0);
    vga_setpalette(188, 25, 0, 0);
    vga_setpalette(189, 22, 0, 0);
    vga_setpalette(190, 19, 0, 0);
    vga_setpalette(191, 16, 0, 0);
    vga_setpalette(192, 57, 57, 63);
    vga_setpalette(193, 49, 49, 63);
    vga_setpalette(194, 42, 42, 63);
    vga_setpalette(195, 35, 35, 63);
    vga_setpalette(196, 28, 28, 63);
    vga_setpalette(197, 20, 20, 63);
    vga_setpalette(198, 13, 13, 63);
    vga_setpalette(199, 6, 6, 63);
    vga_setpalette(200, 0, 0, 63);
    vga_setpalette(201, 0, 0, 56);
    vga_setpalette(202, 0, 0, 50);
    vga_setpalette(203, 0, 0, 44);
    vga_setpalette(204, 0, 0, 38);
    vga_setpalette(205, 0, 0, 32);
    vga_setpalette(206, 0, 0, 26);
    vga_setpalette(207, 0, 0, 20);
    vga_setpalette(208, 63, 63, 63);
    vga_setpalette(209, 63, 58, 54);
    vga_setpalette(210, 63, 53, 46);
    vga_setpalette(211, 63, 49, 38);
    vga_setpalette(212, 63, 44, 30);
    vga_setpalette(213, 63, 40, 22);
    vga_setpalette(214, 63, 35, 14);
    vga_setpalette(215, 63, 31, 6);
    vga_setpalette(216, 60, 28, 5);
    vga_setpalette(217, 58, 27, 3);
    vga_setpalette(218, 55, 25, 3);
    vga_setpalette(219, 53, 23, 2);
    vga_setpalette(220, 50, 21, 1);
    vga_setpalette(221, 48, 19, 0);
    vga_setpalette(222, 45, 17, 0);
    vga_setpalette(223, 43, 16, 0);
    vga_setpalette(224, 63, 63, 63);
    vga_setpalette(225, 63, 63, 53);
    vga_setpalette(226, 63, 63, 44);
    vga_setpalette(227, 63, 63, 35);
    vga_setpalette(228, 63, 63, 26);
    vga_setpalette(229, 63, 63, 17);
    vga_setpalette(230, 63, 63, 8);
    vga_setpalette(231, 63, 63, 0);
    vga_setpalette(232, 41, 15, 0);
    vga_setpalette(233, 39, 13, 0);
    vga_setpalette(234, 36, 11, 0);
    vga_setpalette(235, 33, 8, 0);
    vga_setpalette(236, 19, 14, 9);
    vga_setpalette(237, 16, 11, 6);
    vga_setpalette(238, 13, 8, 4);
    vga_setpalette(239, 11, 6, 2);
    vga_setpalette(240, 0, 0, 20);
    vga_setpalette(241, 0, 0, 17);
    vga_setpalette(242, 0, 0, 14);
    vga_setpalette(243, 0, 0, 11);
    vga_setpalette(244, 0, 0, 8);
    vga_setpalette(245, 0, 0, 5);
    vga_setpalette(246, 0, 0, 2);
    vga_setpalette(247, 0, 0, 0);
    vga_setpalette(248, 63, 39, 16);
    vga_setpalette(249, 63, 57, 18);
    vga_setpalette(250, 63, 30, 63);
    vga_setpalette(251, 63, 0, 63);
    vga_setpalette(252, 51, 0, 51);
    vga_setpalette(253, 39, 0, 38);
    vga_setpalette(254, 27, 0, 26);
    vga_setpalette(255, 41, 26, 26);
} 

