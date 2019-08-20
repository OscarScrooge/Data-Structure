#include <stdio.h>
#include <stdlib.h>

typedef struct{
 int info;
 struct Nodo* next;
}Nodo;



int main(){

    Nodo *previous =NULL,*n1 = NULL,*p1;
    int add,*number;
    

    while(add!=0){

         printf("Add oumber to list = ");
         scanf("%i",&number);
         p1=(Nodo*) malloc(sizeof(Nodo));
         p1->info = number;
         p1->next = NULL;
         if(previous == NULL){
         	previous = p1;
         	n1 = previous;
         }else{
            previous->next = p1;
            n1 = p1;
         }
         scanf("%i",&add);
    }

    while(p1!=NULL){
    	printf("%i\n",p1->info );
    	p1 = p1->next;
    }

	return 0;
}