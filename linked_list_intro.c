#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
 int info;
 struct Nodo* next;
}Nodo;



int main(){

    Nodo *begin=NULL,*end = NULL,*newNode;
    int add=-1,number;
    

    while(add!=0){

         printf("Add oumber to list = ");
         scanf("%i",&number);
         newNode=(Nodo*) malloc(sizeof(Nodo));
         newNode->info = number;
         newNode->next = NULL;
         if(begin == NULL){
         	begin = newNode;
         	end = begin;
         }else{
            end->next = newNode;
            end=newNode;           
         }
         scanf("%i",&add);
    }

    while(begin!=NULL){
    	printf("%i\n",begin->info );
    	begin = begin->next;
    }

	return 0;
}
