/**
  EL ALUMNO DESARROLLARA LAS SIGUIENTES FUNCIONLIDADES:

  * ELIMINAR DE FIN A INICIO.
  *BUSCAR DE FIN A INICIO
  * MODIFICAR NODO DE FIN A INICIO
  *MODIFICAR NODO DE INICIO A FINS 
**/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
   int id;
   struct Node *next;
   struct Node *previous;
}Node;

Node *newNodeToStart(int id,Node *head,Node **last);
Node *newNodeToEnd(int id,Node **head,Node *last);
void printByStart(Node *head);
void printByEnd(Node *last);
Node* search(Node *head, int id);
Node* delete(Node *head,Node **last,int id);
Node *newNodeMiddle(Node *head, Node ** last,int id, int value);

void printList(Node *head,Node **last);

void main(){

    int opcion=1;
    
    Node *head = NULL, *last=NULL;

    while(opcion != 8){

       printf("\n");
       printf("1.- Insertar al inicio\n2.- Insertar al final\n3.- Insertar en cualquier posicion de inicio a fin\n");
       printf("4.- Imprimir por el inicio\n5.- Imprimir por el final\n6.- Buscar nodo\n7.- Eliminar nodo\n8.- Salir\n\nOpcion:");       
       scanf("%d",&opcion);
       system("clear");

       switch(opcion){
           
           case 1:{
                  
                  int id;

                  printf("\nAGREGA NUMEROS AL INICIO DE LA LISTA, PRESIONE 0 PARA TERMINAR\n");
                  scanf("%d",&id);   

                  while(id != 0){
                  	
                  	if(head==NULL){
        				 head = newNodeToStart(id,NULL,&last);      	
      				}else{
         			     head = newNodeToStart(id,head, &last);
      				}
				      printf("\nAREGAR NUEVO NUMERO");
                      scanf("%d",&id);                          
                  }
                  break;
           }

           case 2:{

                  int id;

                  printf("\nAGREGA NUMEROS AL FINAL DE LA LISTA, PRESIONE 0 PARA TERMINAR\n");
                  scanf("%d",&id);   

                  while(id != 0){
                  	
                  	if(head==NULL){
                       last = newNodeToEnd(id,&head,NULL);      	
                    }else{
                       last = newNodeToEnd(id,&head, last);
                    }
				    printf("\nAREGAR NUEVO NUMERO");
                    scanf("%d",&id);                          
                  }
                  break;

           }

           case 3:{           	                                        
           	      int id,value;
           	      printf("ID PARA ANIADIRA LA LISTA ANTES DE UN ELEMENTO DADO ");
                  scanf("%d",&id);
                  printf("\nVALOR ");
                  scanf("%d",&value);
                  head = newNodeMiddle(head, &last, id, value);
                  break;
           }

           case 4:{           	                                        
           	      printByStart(head);           	                                         
                  break;
           }

           case 5:{
           	      printByEnd(last);
           	      break;
           }

           case 6:{
           	      int id;
           	      Node* finded;
           	      printf("indique que id a buscar:");
           	      scanf("%d",&id);
           	      finded = search(head,id);
           	      if(finded != NULL){
           	        printf("el nodo con id %d fue encontrado:", finded -> id);	
           	      }else{
           	      	printf("no se encontro el nodo con id %d", id);	
           	      }                  
              
           	      break;
           }

           case 7:{

           	      int id;
           	      
           	      printf("indique que id a eliminar:");
           	      scanf("%d",&id);
           	      head = delete(head,&last,id);
           	      break;
           }

           case 8:{
           	      break;
           }

           default: {
           	      break;
           } 

       }



    }


   

}


Node *newNodeToStart(int id,Node *head,Node **last){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> id = id;
    newNode -> next = head;
    newNode -> previous = NULL;

    if(head == NULL){
      head = newNode;	
      *last = head;
    }else{
      head -> previous = newNode;
      head = newNode;
    }


    return head;
}

Node *newNodeToEnd(int id,Node **head,Node *last){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> id = id;
    newNode -> next = NULL;
    newNode -> previous = last;

    if(last == NULL){
      last = newNode;	
      *head = last;
    }else{
      last -> next = newNode;
      last = newNode;
      printf(" previo %i\n", last->previous->id);
    }


    return last;
}

void printByStart(Node *head){

     Node *aux;
     aux = head;
     printf("\n");
     while(aux != NULL){
           printf("|%i|<=>", aux -> id);
           aux = aux -> next;
     }    
     printf("\n\n");
}

void printByEnd(Node *last){

     Node *aux;
     aux = last;
     printf("\n");
     
     while(aux != NULL){
           printf("|%i|<=>", aux -> id);
           aux = aux -> previous;           

     }    
     printf("\n\n");
}

Node* search(Node *head, int id){

     Node *aux;
     aux = head;
     printf("\n");
     while(aux != NULL){
           if(aux ->id == id){
                 return aux;
           }
           aux = aux -> next;
     }    
     return NULL;
}

Node* delete(Node *head,Node **last,int id){

     Node *current,*previous,*next;
     current = head;

     printf("\n");
     while(current != NULL){
           if(current ->id == id){

           	     if(current == head){
           	     	head = current -> next;
           	     	head -> previous = NULL;
           	     	free(current);

           	     }else if(current == *last){           	     	
                 	*last = (*last) -> previous;
                 	(*last) -> next = NULL;
                 	free(current);
           	     }else{

           	     	current -> previous -> next = current -> next;
                    current -> next -> previous = current -> previous;
                 	free(current);

           	     }               
                 return head;
           }
           
           current = current -> next;                      
     }    
     return head;
}



Node *newNodeMiddle(Node *head, Node ** last,int id, int value){

    Node *newNode,*current,*previous;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> id = value;
    newNode -> next = NULL;
    newNode -> previous = NULL;

    if(head ==NULL){
    	head = newNode;
    	(*last) = newNode;
    	return head;
    }
    
    current = head;

    while(current!=NULL){

        if(current -> id == id){
           
           if(current == head){
             head -> previous = newNode;
             newNode -> next = head;
             head = newNode;
           }else if(current == *last){
             previous -> next = newNode;
             newNode -> previous = previous;
             newNode -> next = *last;
             (*last) -> previous = newNode;

           }else{              
              previous -> next = newNode;
              newNode -> previous = previous;
              current -> previous = newNode;
              newNode -> next = current;

           }
        }
        previous = current;
        current = current -> next;        

    }
    return head;   
}