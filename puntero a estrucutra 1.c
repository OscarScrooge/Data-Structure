#include <stdio.h>

typedef struct{

    char *nombre;
    int edad;
    int peso;

}persona;


void main(){

     persona empleado = {"Juan Mendez",34,75};

     persona *ptr_empleado;

     ptr_empleado = &empleado;

     printf("Nombre: %s \n", ptr_empleado->nombre);
     printf("Edad: %d \n", ptr_empleado->edad);
     printf("Peso: %d \n", ptr_empleado->peso);

}