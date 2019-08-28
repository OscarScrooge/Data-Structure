#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>




int *makeList(int *list);
int *quicksort(int *list, int leftLimit, int rightLimit);
void printList(int *list);


int const size=10, m=0, n = 50;


void main(int argc, char const *argv[])
{

	

	int option=-1;
	int *list = malloc(size*sizeof(int));

	srand(time(NULL));

	while(option != 4){
        printf("1- Crear lista\n2- Ordenar lista\n3- Imprimir lista\n4- Salir\n\n Opcion: ");
        scanf("%d",&option);
        system("clear");

        switch(option){

        	case 1:{
                  list = makeList(list);
                  break;
        	}

        	case 2:{
                 list = quicksort(list,0,size-1);
                 break;
        	}

        	case 3 :{
        		printList(list);
        		break;

        	}

        	default:{break;}
        }


	}

	
	
}



int *makeList(int *list){
    
     int nRand;     
     int *listAux;
     listAux = list;

     for (int i = 0; i < size; ++i)
     {
     	nRand = rand()%(n-m+1)+m;     	
     	listAux[i] = nRand;
        	
     }
     printf("Lista creada exitosamente \n");
     return listAux;   

}

int *quicksort(int *list, int leftLimit, int rightLimit){


	 int left, right, temp, pivote;

	 left = leftLimit;
	 right = rightLimit;
	 pivote = list[(left + right)/2];

	 do{

	 	while(list[left] < pivote && left < rightLimit){
              left++;
	 	}
	 	while(pivote < list[right] && right > leftLimit){
              right--;
	 	}

	 	if(left <= right){
           temp = list[left];
           list[left] = list[right] ;
           list[right] = temp;
           left++;
           right--;
	 	}

        printf("Ordenando lista \n");
	 	printList(list);
	 	printf("\n");
	 	sleep(2);


	 }while(left <= right);

	 if(leftLimit < right){
	 	quicksort(list,leftLimit,left);
	 }

	 if(rightLimit > left){
	 	quicksort(list, left,rightLimit);
	 }
    
     
     return list;   

}

void printList(int *list){

    printf("\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d =>", list[i]);
	}
	printf("\n\n");
	

}

