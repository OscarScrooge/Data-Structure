#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



typedef struct Node{

   int value;
   struct Node *next;

}Node;

Node *newNodeToHeader(int value, Node *head);
Node *ordenamientoSeleccion(Node *list);

void printList(Node *head);

const int m=0,n = 5000;


int main(){

    int yes=1,option=-1;
    int value =-1;
    Node *head = NULL;

    int counter = 0;

    srand(time(NULL));

    while(option !=4){

          printf("\n\n");
          printf("1- Agregar numueros a lista\n2- Ordenar numeros de la lista\n3- Imprimir lista\n4- Salir\nOpcion:");
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
                 printList(head);                 
                 break;
                    
              }

              case 3:{

                      printList(head);
                      break;
              }

              default:{break;}



          }


    }


   
   

}

Node *newNodeToHeader(int value,Node *head){
   
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));
    newNode -> value = rand()%(n-m+1)+m;
    newNode -> next = NULL;

   if(head ==NULL){

     return newNode;
   }else{
     Node *aux = head;
     while(aux->next!=NULL){
       aux = aux->next;
     }
     aux->next= newNode;
   }



    return head;
}

Node *ordenamientoSeleccion(Node *head){

    Node *aux,*aux2;

    int minor, first, position =0, r;
    
  

    aux2 = head;

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

      first = aux2 -> value;
      minor = first;   
 
      printList(head);
      sleep(6);

    }   
    return head;


}

void printList(Node *head){

     printf("\n\n");
     while(head != NULL){
           printf("%d => ", head -> value);
           head = head -> next;

     }

}


