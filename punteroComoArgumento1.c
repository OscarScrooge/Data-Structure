#include <stdio.h>


int suma(int *numero1, int *numero2);

void main(){

     int n1 = 5;
     int n2 = 23;
     int res=0;
   
     res = suma (&n1,&n2);

     printf("Resultado = %i", res);
}

int suma(int *numero1, int *numero2){


    return *numero1 + *numero2;


}