#include "matrix.h"
#include "stdio.h"
typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;
int antani = 0;
void startSetUpMatrix(GameMatrix *m){
    // x length 150    y length 100
    
    for(int y=99;y>=0;y--){
        for(int x=0;x<150;x++){
            if(y<=25){
                m->point[y][x]=1;
            }
            else if((x>9&&x<15)&&(y<31&&y>25)){
                m->point[y][x]=1;
            }
            else{
                m->point[y][x]=0;
            }
        }
    }
    //printMatrix(m);
}
void buildObstacleMatrix(GameMatrix *m,int x,int y,int w,int h){
    x=x/10;
    y=100-y/10;
    w=w/10;
    h=h/10;
    for(int Y=y-h;Y<=y;Y++){
        for(int X=x;X<x+w;X++){
            m->point[Y][X]=1;
        }

    }
    //printMatrix(m);
}
int slideObstacleMatrix(GameMatrix *m,int x,int y,int w,int h){
    x=x/10;
    y=100-y/10;
    w=w/10;
    h=h/10;
    //fai il check a sx, se non si presentano collisioni continua e restituisci 0;
    //MANCA IL CHECK A SX
    //
    if(x+w<10){
         //elimina l'ostacolo dalla matrice
        for(int Y=y-h+1;Y<=y;Y++){
            for(int X=0;X<=w;X++){
                m->point[Y][X]=0;
            }
        }
    }else{
        //effettua lo slide
        if(x<=0){
        }else{
            if(checkSX(m,x,y,h) == 1){
                return 1;
            }
            for(int Y=y-h+1;Y<=y;Y++){
                m->point[Y][x+w]=0;
            }
            x= x-1;
            for(int Y=y-h;Y<=y;Y++){
                for(int X=x;X<x+w;X++){
                    m->point[Y][X]=1;
                }
            }
        }
        if(x==25){
             printMatrix(m);
        }
    }
    return 0;
}

int checkSX(GameMatrix *m,int startX,int startY,int h){
    Bool flag = TRUE;
    for(int Y=startY-h+1;Y<=startY;Y++){
        if(m->point[Y][startX-1]==1){
            flag = FALSE;
            break;
        }
    }
    if(flag == TRUE){
        return 0; // niente collisione sx
    }else{
        return 1; // collisione sinistra ferma il giorco
    }


}

int checkDown(GameMatrix *m,int startX,int startY){
    startX = startX/10;
    startY = startY/10;
    startY = 100-startY;
    Bool flag = TRUE;
    for(int x = startX;x<startX+5;x++){
        if(m->point[startY-5][x]==1){
            flag=FALSE;
            break;
        }
    }
    if(flag == TRUE){
        //scendi
        return 1;
        printMatrix(m);
    }else{
        //non scendere
        return 0;
    }
}

int rectJumpUp(GameMatrix *m,int startX,int startY){
    startX = startX/10;
    startY = startY/10;
    startY = 100-startY;
    //printf("startX mod:%d   startY mod%d",startX,startY);
    Bool flag=FALSE;

    for(int x = startX;x<startX+5;x++){
        if(m->point[startY+1][x]==1){
            flag=TRUE;
            break;
        }
    }
    if(flag==FALSE){
        for(int x = startX;x<startX+5;x++){
            m->point[startY+1][x]=1;
        }
        for(int x = startX;x<startX+5;x++){
            m->point[startY-4][x]=0;
        }
        return 0;
    }else{
        //collisione
        return 1;
    }

}
int rectJumpDown(GameMatrix *m,int startX,int startY){
    startX = startX/10;
    startY = startY/10;
    startY = 100-startY;
    //printf("startX mod:%d   startY mod%d",startX,startY);
    Bool flag=FALSE;

    for(int x = startX;x<startX+5;x++){
        if(m->point[startY-5][x]==1){
            flag=TRUE;
            break;
        }
    }
    if(flag==FALSE){
        for(int x = startX;x<startX+5;x++){
            m->point[startY-5][x]=1;
        }
        for(int x = startX;x<startX+5;x++){
            m->point[startY][x]=0;
        }
        return 0;
    }else{
        printf("toccato il fondo");
        //collisione
        //printMatrix(m);
        return 1;
    }

}



void printMatrix(GameMatrix *m){
        for(int y = 0;y<100;y++){
            for(int x = 0;x<150;x++){
                printf("%d",m->point[y][x]);
            }
            printf("\n");
        }
}