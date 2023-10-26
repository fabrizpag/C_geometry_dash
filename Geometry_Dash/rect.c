#include "rect.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void buildRect(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m){
    fflush(stdout);
    if(p->down==0&&p->up==0){
        // check se deve cadere. in tal caso imposta p->down a 1
        //ed esegui una goto?
        if (checkDown(m,x,y)==1){
            //scendi
            p->down=1;
            return;
        }else{
            XSetForeground(display, gc, 0x00FF00);
            XFillRectangle(display, window, gc, x, y, 50, 50);
            XFlush(display);
            return;
        }
    }else if(p->up>0 && p->up<25){
        //printf("  p->up:%d   \n",p->up);
        fflush(stdout);
        jumpUp(display,gc,window,p,p->x,p->y,m);
        return;
    }else if(p->up==25){
        p->down=1;
        p->up=0;
    }
    else if(p->down > 0){
        jumpDown(display,gc,window,p,p->x,p->y,m);
        return;
    }    
}

void jumpUp(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m){
    int f = rectJumpUp(m,x,y);
    if(f==0){
        XSetForeground(display, gc, WhitePixel(display, 0));
        XFillRectangle(display, window, gc, x, y, 50, 50);
        XSetForeground(display, gc, 0x00FF00);
        XFillRectangle(display, window, gc, x, y-10, 50, 50);
        XFlush(display);
        p->y=p->y-10;
        p->up=p->up+1;
        return;
    }else{
        //COLLISIONE STOPPA IL GIOCO
    }
    
}
void jumpDown(Display *display,GC gc, Window window, Rect *p,int x,int y,GameMatrix *m){
    int f = rectJumpDown(m,x,y);
    if(f==0){
        XSetForeground(display, gc, WhitePixel(display, 0));
        XFillRectangle(display, window, gc, x, y, 50, 50);
        XSetForeground(display, gc, 0x00FF00);
        XFillRectangle(display, window, gc, x, y+10, 50, 50);
        XFlush(display);
        p->y=p->y+10;
        return;
    }else{
        p->down=0;
    }
}

