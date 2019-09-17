#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int distancia2Puntos(int x, int y, int h,int k);
float getPi(float area,float radio);

void main(){

   srand(time(NULL));

   int m = 0,x,y,h,k,radio,cont=0, distancia;
   float pi=0;

   printf("radio: ");
   scanf("%d",&radio);

   printf("h: ");
   scanf("%d",&h);

   printf("k: ");
   scanf("%d",&k);

     do{

   	    x = rand()%(radio-m+1)+0;
   	    y = rand()%(radio-m+1)+0;

   	    distancia = distancia2Puntos(x,y,h,k);

   	    

   	    if(distancia<=radio){
            cont++;            
            pi = getPi(cont,radio);
            //printf("(%d , %d)\n",x,y);
   	        //printf("distancia - (%d , %d),(%d , %d) = %d\n",x,y,h,k,distancia);
   	        printf("area: %d \n",cont);
            printf("pi: %f \n", pi);
   	    }
   	    //usleep(300000);

   } while(pi < 3.14);

}


int distancia2Puntos(int x, int y, int h,int k){

    int distancia,a,b;

    a = (x-h)*(x-h);
    b = (y-k)*(y-k);

    distancia = sqrt(a+b);

    return distancia;
   

}

float getPi(float area,float radio){

	float pi = area / (radio*radio);

    return pi;

}

