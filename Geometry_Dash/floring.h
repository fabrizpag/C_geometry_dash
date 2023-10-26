#include <X11/Xlib.h>
#include "matrix.h"

int buildFloor(Display *display,GC gc, Window window,GameMatrix *m);
int buildObstacleLV1(Display *display,GC gc, Window window,GameMatrix *m);
int SlideLeftRect(int Xiniz,int Yiniz, int height,int width,Display *display,GC gc, Window window,GameMatrix *m);