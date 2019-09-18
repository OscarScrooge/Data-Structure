#include <stdio.h>

struct Persona
{
	char nombre[50];
	unsigned int edad;
	char fechaNacimiento[15];	
	
};

struct Trabajador
{

	unsigned int numeroEmpleado;
	struct Persona persona;
	
};

struct Estudiante
{
	unsigned int matricula;
	struct Persona persona;
	
};

struct Trabajador setTrabajador(char nombre[50],int edad,char fecha[15],int numeroEmpleado);
struct Trabajador setTrabajadorRef(struct Trabajador trabajador);



void main()
{
	
    struct Trabajador trabajador1,trabajador2;

    trabajador1 = setTrabajador("pepito",30,"12-12-12",353453);

    printf("\n\n");
    getchar();
   trabajador2 =  setTrabajadorRef(trabajador2);


	

	printf("\n\n");
	printf("DATOS DEL TRABAJADOR 1: \n\n");
	printf("NOMBRE DEL TRABAJADOR 1: %s\n",trabajador1.persona.nombre);
	printf("EDAD: %d\n",trabajador1.persona.edad);
	printf("FECHA DE NACIMIENTO: %s\n",trabajador1.persona.fechaNacimiento);
	printf("NUMERO: %d\n",trabajador1.numeroEmpleado);

	printf("\n\n");
	printf("DATOS DEL TRABAJADOR 2: \n\n");
	printf("NOMBRE DEL TRABAJADOR 2: %s\n",trabajador2.persona.nombre);
	printf("EDAD: %d\n",trabajador2.persona.edad);
	printf("FECHA DE NACIMIENTO: %s\n",trabajador2.persona.fechaNacimiento);
	printf("NUMERO: %d\n",trabajador2.numeroEmpleado);


    
	
		
}

struct Trabajador setTrabajador(char nombre[50],int edad,char fecha[15],int numeroEmpleado){


	struct Trabajador trabajador;


	printf("Nombre del trabajador: ");
	fgets(trabajador.persona.nombre,sizeof(trabajador.persona.nombre),stdin);	
	printf("\nEdad: ");
	scanf("%d",&trabajador.persona.edad);
	printf("\nFecha de nacimiento: ");
	getchar();
	fgets(trabajador.persona.fechaNacimiento,sizeof(trabajador.persona.fechaNacimiento),stdin);
	printf("\numero: ");
	scanf("%d",&trabajador.numeroEmpleado);

	return trabajador;
}

struct Trabajador setTrabajadorRef(struct Trabajador trabajador){

    printf("Nombre del trabajador 2: ");
	fgets(trabajador.persona.nombre,sizeof(trabajador.persona.nombre),stdin);	
	printf("\nEdad: ");
	scanf("%d",&trabajador.persona.edad);
	printf("\nFecha de nacimiento: ");
	getchar();
	fgets(trabajador.persona.fechaNacimiento,sizeof(trabajador.persona.fechaNacimiento),stdin);
	printf("\nnumero: ");
	scanf("%d",&trabajador.numeroEmpleado);

	return trabajador;
    

}