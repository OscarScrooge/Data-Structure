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
Node *bubbleSort(Node *list);

void printList(Node *head);

const int m=0,n = 5000;


void main(){

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
                      
                 head = bubbleSort(head);
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

Node *bubbleSort(Node *head){

    Node *aux,*lower,*greatest;
    
    int n = head->counter;
  

    for(int i = 0; i<n;i++){
      
      aux = head;

      while(aux -> next != NULL){

           
       
           if((aux -> value) > (aux -> next -> value)){

                 int mayor = aux-> value;
                 int menor = aux -> next -> value;
                 

                 aux -> next ->value = mayor;
                 aux -> value = menor; 

           }           
           
           aux = aux -> next;

      } 

    }   
    return head;


}

void printList(Node *head){

     printf("\n\n");
     while(head != NULL){
           printf("%d =>", head -> value);
           head = head -> next;

     }

}







