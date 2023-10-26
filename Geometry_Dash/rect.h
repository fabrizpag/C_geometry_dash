#include <X11/Xlib.h>
#include "matrix.h"

typedef struct r{
    short int x;
    short int y;
    short int up;
    short int down;
}Rect;
void buildRect(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m);
void jumpUp(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m);
void jumpDown(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m);