#include <gb/gb.h>
#include "SimpleSprite.h"

UINT8 spriteX,spriteY;
INT8 velocityX,velocityY=0;

void main(void)
{
    DISPLAY_ON;
    SHOW_SPRITES;

    set_sprite_data(0,1,SimpleSprite);
    set_sprite_tile(0,0);

    spriteX=80;
    spriteY=72;

    velocityX=1;
    velocityY=1;

    // Loop forever
    while(1) {

        spriteX+=velocityX;
        spriteY+=velocityY;

        if(spriteX>156&&velocityX>0){
            velocityX=-velocityX;
            spriteX=156;
        }

        if(spriteY>140&&velocityY>0){
            velocityY=-velocityY;
            spriteY=140;
        }

        if(spriteX<4&&velocityX<0){
            velocityX=-velocityX;
            spriteX=4;
        }

        if(spriteY<4&&velocityY<0){
            velocityY=-velocityY;
            spriteY=4;
        }

        move_sprite(0,spriteX+4,spriteY+12);

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
