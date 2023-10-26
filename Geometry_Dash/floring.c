#include "floring.h"
#include <stdio.h>

long int livello=0;

int buildFloor(Display *display,GC gc, Window window,GameMatrix *m){

    XSetForeground(display, gc, BlackPixel(display, 0));
    XFillRectangle(display, window, gc, 0, 750, 1500, 250);
    if(buildObstacleLV1(display,gc,window,m)==1){return 1;}
    XFlush(display);
    return 0;

}

int buildObstacleLV1(Display *display,GC gc, Window window,GameMatrix *m){
    if(livello>50 && livello <=70){
        //build new Obstacle
        XSetForeground(display, gc, BlackPixel(display, 0));
        XFillRectangle(display,window,gc,1500+500-livello*10,700,livello*10-500,50);  //posizione finale x=1300(2000-livello*10)   y=700  w=200 h =50 
        livello++;
    }else if (livello >70 && livello <500){

        if(livello>70 && livello<=300){
            if(livello==71){
                buildObstacleMatrix(m,1300,700,200,50);
                if(SlideLeftRect(2000-livello*10,700,50,200,display,gc,window,m)==1){return 1;}
            }else{
                if(SlideLeftRect(2000-livello*10,700,50,200,display,gc,window,m)==1){return 1;}
            }
        }
        else{
            //build new Obstacle
            if(livello >300 && livello <=340){
                XSetForeground(display, gc, BlackPixel(display, 0));
                XFillRectangle(display,window,gc,1500+3000-livello*10,650,livello*10-3000,100); //posizione finale x=1100(4500-livello*10) y=650 w=400 h =100
            }else{
                if(livello == 341){
                    buildObstacleMatrix(m,1100,650,400,100);
                    if(SlideLeftRect(4500-livello*10,650,100,400,display,gc,window,m)){return 1;}
                }else{
                    if(SlideLeftRect(4500-livello*10,650,100,400,display,gc,window,m)){return 1;}
                }
            }
        }
        livello++;
    }//finisce con livello == 500
    
    else{
        livello++;
    }
    printf("\nlivello : %ld",livello);
    return 0;
}

int SlideLeftRect(int Xiniz,int Yiniz, int height,int width,Display *display,GC gc, Window window,GameMatrix *m){

    int ret = slideObstacleMatrix(m,Xiniz,Yiniz,width,height);
    if(ret == 0){
        XSetForeground(display, gc, WhitePixel(display, 0));
        XFillRectangle(display,window,gc,Xiniz+10,Yiniz,width,height);
        XSetForeground(display, gc, BlackPixel(display, 0));
        XFillRectangle(display,window,gc,Xiniz-10,Yiniz,width,height);
        return 0;
    }
    else{
        return 1;
        //se ritorna 1, c'è stata una collisione laterale

    }

}
