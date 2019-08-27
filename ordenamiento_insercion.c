/**

ESTE PROGRAMA INICIA UNA LISTA SIMPLEMENTE ENLAZADA Y AGREGA LOS ELEMENTOS EN LA CABEZA DE LA LISTA

**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



typedef struct Node{

   int value;
   int counter;
   struct Node *next;

}Node;

Node *newNodeToHeader(int value, Node *head);
Node *ordenamientoSeleccion(Node *list);
Node *ordenamientoInsercion(Node *list,int newValue);

void printList(Node *head);

const int m=0,n = 5000;


void main(){

    int yes=1,option=-1;
    int value =-1;
    Node *head = NULL;

    int counter = 0;

    srand(time(NULL));

    while(option !=5){

          printf("\n\n");
          printf("1- Agregar numueros a lista\n2- Ordenar numeros de la lista\n3- Agregar nuevo numero\n4- Imprimir lista\n5- Salir\nOpcion:");
          scanf("%d",&option);
          system("clear");

          switch(option){
  
              case 1:{
                      // printf("Agrega numeros, presiona 0 para salir\n\n");                   

                       // printf("Numero: ");                   
                       // scanf("%d",&value);

                      while(counter != 10){

                           if(head==NULL){
                             head = newNodeToHeader(value,NULL);        
                          }else{
                             head = newNodeToHeader(value,head);
                          }
                          counter++;
                          // printf("Numero: \n");                   
                          // scanf("%d",&value);
                          

                      }   
                      counter = 0;
                      printf("Lista creada\n");

                      break;            

              }

              case 2:{
                      
                 head = ordenamientoSeleccion(head);                            
                 break;
                    
              }

              case 3:{
                      int new;
                      printf("Aniade nuevo nuevo numero: ");
                      scanf("%d",&new);
                      head = ordenamientoInsercion(head, new);
                      break;
              }

              case 4:{

                      printList(head);
                      break;
              }

              default:{break;}



          }


    }


   
   

}

Node *newNodeToHeader(int value,Node *prev){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = rand()%(n-m+1)+m;
    newNode -> next = prev;

    if(prev == NULL){
      newNode -> counter = 1;      
    }else{
      newNode -> counter = (prev -> counter)+1;      
    }

    return newNode;
}

Node *ordenamientoSeleccion(Node *head){

    Node *aux,*aux2;

    int minor, first, position =0, r;
    
    int n = head->counter;
  

    aux2 = head;

    printf("aux 2 = \n");
    printList(aux2);
    printf("\n\n\n");

    first = aux2 -> value;
    minor = first;
    for(int i = 0; i<n;i++){
       
       aux = aux2; 
       r = 1;   
      while(aux -> next != NULL){         

	      	if((minor) > (aux -> next -> value)){
                     position = r;                          
	                 minor = aux -> next -> value;	                 	                                    
	        }
	        r++;                            
           aux = aux -> next;
      } 

      aux = aux2;

      aux -> value = minor;
          
      while(position>0){     
         aux = aux -> next; 
         position--;        
      }

      aux -> value = first;

      aux2 = aux2 -> next;

      if(aux2 == NULL){
      	break;
      }

      printf("\naux2 -> value: %d\n", aux2->value);

      first = aux2 -> value;
      minor = first;   
 
      printList(head);
      sleep(2);

    }   
    return head;


}

Node *ordenamientoInsercion(Node *list, int newValue){

    Node *newNode, *aux,*prev;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = newValue;
    newNode -> next = NULL;

    if(list == NULL){
       return newNode;
    }

    aux=list;
    prev = aux;
    while(prev != NULL){

          if(aux -> next == NULL){
            prev = aux;     
            aux = newNode;
            prev -> next = aux;
            return list;
         }else if (newValue < aux -> value && aux == list){
            
            newNode ->next = aux;
            newNode -> counter = (aux -> counter) + 1;
            aux = newNode;
            return aux;
         }else if(newValue < aux -> value){
           
            prev -> next = newNode;
            newNode -> next = aux;
            return list;
         }

         prev =  aux;
         aux = aux -> next;

    }
    return NULL;
}

void printList(Node *head){

     printf("\n\n");
     Node *aux;
     aux = head;
     while(aux != NULL){
           printf("%d => ", aux -> value);
           aux = aux -> next;

     }

}







