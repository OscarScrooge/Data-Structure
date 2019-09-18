#include <stdio.h>
#include <math.h>



typedef struct 
{	
	float x, y;	
}Punto;


float distancia(Punto p1, Punto p2);



void main()
{

    
    
    printf("Mi numero real es: %f\n",real);
    printf("Mi numero natural es: %d\n",natural);

    Punto p1,p2;

    p1.x = 3;
    p1.y = 4;
    printf("P1(%f,%f)\n",p1.x,p1.y);
    p2.x = -1;
    p2.y = -9;
    printf("P2(%f,%f)\n",p2.x,p2.y);

    printf("Distancia = %f\n",distancia(p1,p2));

		
}


float distancia(Punto p1, Punto p2){

    float distancia,a,b;

    a = (p2.x-p1.x)*(p2.x-p1.x);
    b = (p2.y -p1.y)*(p2.y -p1.y);

    distancia = sqrt(a+b);

    return distancia;


}




 