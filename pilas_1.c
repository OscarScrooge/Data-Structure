#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{

   int index;
   char book_name[50];   

}Book;

typedef struct Node{

     Book book;
     int counter;
     struct Node *next;

}Node;


Node* push(Node *node, char book_name[]);
Node* pop(Node *topStack);
void printStack(Node *stack);
Node* emptyStack(Node *stack);

static int m=0,n = 100;


void main(){

	 srand(time(NULL));

     Node *stackBooks;
     stackBooks = NULL;

     int option=1;

     while(option != 5){

         printf("\n\n");
         printf("1- Aniadir libros a la pila\n2- Quitar libros de la pila\n3- Vaciar pila\n4- Imprimir pila\n5- Salir\n Opcion: ");
         scanf("%d",&option);
         system("clear");

         switch(option){
            
            case 1:{
            	
            	
            	char book_name[50]={"-1"};

                printf("Aniadir libros, presione 0 para salir\n");

            	while(strcmp(book_name,"0") != 0){
            	    
            	    printf("\nAniadir nuevo libro: ");            		
            		scanf("%*c%[^\n]",book_name);                        		            		            		
            		if(strcmp(book_name,"0") != 0){

            	      stackBooks=push(stackBooks,book_name);	
            	    }
            		
            	}

            	break;
            }

            case 2:{

            	stackBooks = pop(stackBooks);
            	break;
            	
            }

            case 3:{

            	stackBooks = emptyStack(stackBooks);
            	break;
            	
            }

            case 4:{
                printf("\n\n");
            	printStack(stackBooks);
            	break;
            	
            }


            default:{break;}



         }

     }

     
     

}


Node* push(Node *node, char book_name[]){

    
     Node *newNode;

     newNode = (Node*) malloc(sizeof(Node));
     newNode -> book.index = rand()%(n-m+1)+m;     
     strcpy(newNode -> book.book_name,book_name);

     
     if(node == NULL){
        newNode -> counter =1;
     }else{
     	newNode -> counter++;
     }
     
     newNode -> next = node;
     node = newNode;

     return newNode;


}


Node* pop(Node *topStack){

	if(topStack == NULL){
		printf("NO HAY ELEMENTOS PARA QUITAR DE LA PILA\n\n");
		return NULL;
	}

    
     Node *topAux;

     topAux = topStack;

     topStack = topAux -> next;

     free(topAux);

     return topStack;


}

void printStack(Node *stack){


	if(stack == NULL){
		printf("LA PILA ESTA VACIA\n\n");

	}else{
     Node *stackAux;
     stackAux = stack;

     while(stackAux != NULL){

          
          printf("|%d   %s|\n\n",stackAux -> book.index,stackAux -> book.book_name );                    
          stackAux = stackAux -> next;

     }
    }


}




Node* emptyStack(Node *stack){


	if(stack == NULL){
		printf("LA PILA ESTA VACIA\n\n");

	}else{
     Node *stackAux;
     stackAux = stack;

	     while(stackAux != NULL){
	          stack = stackAux -> next;
	          free(stackAux);
	          stackAux = stack;

	     }
    }

    return stack;

}