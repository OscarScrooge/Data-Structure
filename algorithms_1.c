#include <stdio.h>


int main(){

     float numero_1, numero_2;

     printf("numero 1 = ");
     scanf("%f",&numero_1); 
     printf("\n");
     
     printf("numero 2 = ");
     scanf("%f",&numero_2) ;
     printf("\n");
     
     if(numero_1 == numero_2){
         printf("3(%f + %f) = %f",numero_1,numero_2,3*(numero_1+numero_2));
     }else{
         printf("%f + %f = %f",numero_1,numero_2,numero_1+numero_2);
     }

     printf("\n\n");

    return 0;
} 