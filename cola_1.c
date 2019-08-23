#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{

   int index;
   
}Customer;

typedef struct Node{

     Customer customer;      
     int counter;
     struct Node *next;

}Node;


Node* push(Node *node, Node **lastCutomer, int index);
Node* pop(Node *topLine);
void printLine(Node *line);
Node* emptyLine(Node *line);

static int m=0,n = 100;


void main(){

	 srand(time(NULL));

     Node *lineCustomer, *lastCutomer;
     lineCustomer = NULL;
     lastCutomer = NULL;

     int option=1;

     while(option != 5){

         printf("\n\n");
         printf("1- Aniadir cliente a la cola\n2- Quitar cliente de la cola\n3- Vaciar cola\n4- Imprimir cola\n5- Salir\n Opcion: ");
         scanf("%d",&option);
         system("clear");

         switch(option){
            
            case 1:{

            	
                int index = -1;                   
 
                printf("Aniadir clientes, presione 0 para salir\n");

            	while( index != 0){
            	    
            	    printf("\nAniadir nuevo cliente: ");            		
            		scanf("%d",&index);                        		            		            		
            		if(index != 0){

            	      lineCustomer=push(lineCustomer,&lastCutomer,index);	
            	    }
            		
            	}

            	break;
            }

            case 2:{

            	lineCustomer = pop(lineCustomer);
            	break;
            	
            }

            case 3:{

            	lineCustomer = emptyLine(lineCustomer);
            	break;
            	
            }

            case 4:{
                printf("\n\n");
            	printLine(lineCustomer);
            	break;
            	
            }


            default:{break;}



         }

     }

     
     

}


Node* push(Node *node, Node **lastCustomer, int index){

    
     Node *newNode;

     newNode = (Node*) malloc(sizeof(Node));
     newNode -> customer.index = index;     
     newNode -> next = NULL;
     
     if (node == NULL)
     {
         node = newNode;
         *lastCustomer = newNode; 
         return node;
     }


     (*lastCustomer) -> next =newNode;
     *lastCustomer = newNode;

     return node;         

}


Node* pop(Node *topLine){

	if(topLine == NULL){
		printf("NO HAY ELEMENTOS PARA QUITAR DE LA COLA\n\n");
		return NULL;
	}

    
     Node *topAux;

     topAux = topLine;

     topLine = topAux -> next;

     free(topAux);

     return topLine;


}

void printLine(Node *line){


	if(line == NULL){
		printf("LA COLA ESTA VACIA\n\n");

	}else{
     Node *stackAux;
     stackAux = line;

     while(stackAux != NULL){

          
          printf("|%d|=>",stackAux -> customer.index);                    
          stackAux = stackAux -> next;

     }
    }


}




Node* emptyLine(Node *line){


	if(line == NULL){
		printf("LA COLA ESTA VACIA\n\n");

	}else{
     Node *stackAux;
     stackAux = line;

	     while(stackAux != NULL){
	          line = stackAux -> next;
	          free(stackAux);
	          stackAux = line;
	          
	     }
    }

    return line;

}