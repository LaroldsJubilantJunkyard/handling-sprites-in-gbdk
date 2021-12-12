#include <gb/gb.h>
#include "SimpleSprite.h"

UINT8 spriteX,spriteY;
INT8 velocityX,velocityY;

void main(void)
{
    DISPLAY_ON;
    SHOW_SPRITES;

    set_sprite_data(0,1,SimpleSprite);
    set_sprite_tile(0,0);
    move_sprite(0,84,88);

    // Set our default position
    spriteX=80;
    spriteY=72;

    // Set our default velocity to be moving down and to the right
    velocityX=0;
    velocityY=0;

    // Loop forever
    while(1) {

        // Apply our velocity
        spriteX+=velocityX;
        spriteY+=velocityY;

        // Position the first sprite at our spriteX and spriteY
        // All sprites are render 8 pixels to the left of their x position and 16 pixels ABOVE their actual y position
        // This means an object rendered at 0,0 will not be visible
        // x+5 and y+12 will center the 8x8 tile at our x and y position
        move_sprite(0,spriteX+4,spriteY+12);

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
