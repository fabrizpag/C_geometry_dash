
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "game.h"


int main() {
    Display *display;
    Window window;
    XEvent event;
    GC gc; 

    // Inizializza la connessione con il server X
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Impossibile connettersi al server X\n");
        return 1;
    }

    window = XCreateSimpleWindow(display, RootWindow(display, 0), 0, 0, 1500, 1000, 0, BlackPixel(display, 0), WhitePixel(display, 0));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);
    gc = XCreateGC(display, window, 0, 0);


    startGame(display,&window,&event,&gc);

    

    XCloseDisplay(display);

    return 0;
}




/*
 gcc -o a main.c rect.c game.c floring.c matrix.c -lX11

if (XPending(x11env->d)) dove d è il display       XNextEvent(x11env->d, &xevt);
*/

