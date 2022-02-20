
#include <genesis.h>
#include "include/body.h"

int main()
{
    VDP_drawText("Smash genesis!", 10,13);
    while(1)
    {
        SYS_doVBlankProcess();
    }
    return (0);
}
