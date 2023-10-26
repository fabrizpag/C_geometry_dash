
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rect.h"
#include "game.h"
#include "floring.h"



void startGame(Display *display,Window *w,XEvent *e , GC *g){

    Window window = *w ;
    XEvent event = *e;
    GC gc = *g;
    Rect *rect = malloc(sizeof(Rect));
    rect->x=100;
    rect->y=700;
    rect->up=0;
    rect->down=0;
    GameMatrix *Matrix = malloc(sizeof(GameMatrix));
    startSetUpMatrix(Matrix);
    
    int iterazione=0;
    //metti a 1 i bit della palla e della pavimentazione


    //gestore eventi
    while (1) {
        //printf("iterazione: %d  ",iterazione);
        fflush(stdout);
        buildRect(display,gc,window,rect,rect->x,rect->y,Matrix);
        if( buildFloor(display,gc,window,Matrix)==1 ){break;}
        if (XPending(display) > 0) {
            XNextEvent(display, &event);
            if (event.type == Expose) {
                printf("dentro Expose");
            }
            if (event.type == KeyPress) {
                if (event.xkey.keycode == 9) {
                    break;
                }
                if (event.xkey.keycode == 65){
                    printf("Tasto premuto: %d\n", event.xkey.keycode);
                    rect->up=1;
                    XFlush(display);
                }
            }
        usleep(15000);
        iterazione++;
    } else {
        // Nessun evento disponibile, attendi per un breve periodo o esegui altre operazioni
        usleep(15000);
        iterazione++;
    }
}
    return;
    
}
