#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODO{
   int info;
  struct NODO *izq;
  struct NODO *der;
}NODO;

NODO *crearNodo(NODO* raiz);
void preorden(NODO *raiz);
void inorden(NODO *raiz);
void posorden(NODO *raiz);
void busqueda(NODO *raiz,int buscar);
NODO *crearNodoArbolBusqueda(NODO* raiz,int info);
NODO *eliminarNodo(NODO *raiz,int info);
int altura(NODO *raiz);

int main(void) {
  
  NODO *raiz=NULL;
  int buscar,info,opt=1;
  
  raiz = malloc(sizeof(NODO));
   printf("INFO: ");
  scanf("%d",&raiz->info);  
  raiz->izq=NULL;
  raiz->der=NULL;
  raiz = crearNodo(raiz);
  printf("Impresion preorden \n");
  preorden(raiz);
  printf("\nImpresion inorden \n");
  inorden(raiz);
   printf("\nImpresion posorden \n");
  posorden(raiz);
  raiz=NULL;
   /*while(opt==1){
      printf("INFO: ");
       scanf("%d",&info);
      raiz = crearNodoArbolBusqueda(raiz,info);
      printf("Continuar: ");
      scanf("%d",&opt);
    }/*
    printf("altura = %d", altura(raiz));
   /* printf("\n\nImpresion preorden \n");
    preorden(raiz);
    printf("\nImpresion inorden \n");
    inorden(raiz);
    printf("\nImpresion posorden \n");
    posorden(raiz);
    printf("\neliminar elemento \n");
    scanf("%d",&buscar);
    raiz = eliminarNodo(raiz,buscar);
    printf("\n\nImpresion preorden \n");
    preorden(raiz);
  printf("\nBuscar elemento \n");
  scanf("%d",&buscar);
  busqueda(raiz,buscar);*/
  return 0;
}

NODO *crearNodo(NODO* raiz){
   
  NODO *nuevo=NULL;  
  int resp;

  printf("crear nodo izquierdo? 1SI -0NO");
  scanf("%d",&resp);
  if(resp==1){
    nuevo = malloc(sizeof(NODO));
    printf("INFO: ");
    scanf("%d",&nuevo->info);  
    raiz->izq=nuevo;
    raiz->izq = crearNodo(raiz->izq);
  } else{
    raiz->izq=NULL;
  }

  printf("crear nodo derecho? 1SI -0NO");
  scanf("%d",&resp);
  if(resp==1){
    nuevo = malloc(sizeof(NODO));
    printf("INFO: ");
    scanf("%d",&nuevo->info);  
    raiz->der=nuevo;
    raiz->der = crearNodo(raiz->der);
  } else{
    raiz->der=NULL;
  }

  return raiz;
  
}

void preorden(NODO *raiz){
   
     if(raiz!=NULL){
         printf("%d  ",raiz->info);
         preorden(raiz->izq);
         preorden(raiz->der);
     }

}

void inorden(NODO *raiz){

     if(raiz!=NULL){
         inorden(raiz->izq);
         printf("%d  ",raiz->info);
         inorden(raiz->der);
     }
}

void posorden(NODO *raiz){

      if(raiz!=NULL){
              posorden(raiz->izq);
              posorden(raiz->der);
              printf("%d  ",raiz->info);
      }
}


void busqueda(NODO *raiz,int buscar){

    if(raiz!=NULL){
      if(buscar<raiz->info){
         busqueda(raiz->izq,buscar);
      }else if(buscar>raiz->info) {
         busqueda(raiz->der,buscar);
      }else{
        printf("la info se encuentra en el árbol");
      }
    }else{
      printf("la info se encuentra en el árbol");
    }
}

NODO *crearNodoArbolBusqueda(NODO* raiz,int info){

    if(raiz==NULL){
         NODO *nuevo = malloc(sizeof(NODO));
         nuevo->info = info;
         nuevo->izq=NULL;
         nuevo->der=NULL;
         raiz=nuevo;

    }else{
       if(info>raiz->info){
          raiz->der=crearNodoArbolBusqueda(raiz->der,info);
       }else{
          raiz->izq=crearNodoArbolBusqueda(raiz->izq,info);
       }

    }
    return raiz;
}

NODO *eliminarNodo(NODO *raiz,int info){
      bool bo = false;
      NODO *otro=NULL,*aux=NULL,*aux1=NULL;

      if(raiz!=NULL){
         if( info < raiz->info){
            raiz->izq= eliminarNodo(raiz->izq,info);
         }else if( info > raiz->info){
            raiz->der= eliminarNodo(raiz->der,info);
         }else{
            otro = raiz;
            if(otro->der == NULL){
               raiz = otro -> izq;
            }else if(otro->izq == NULL){
               raiz = otro -> der;
            }else{
               aux = raiz->izq;
               bo= false;
               while( aux-> der !=NULL){
                   aux1 = aux;
                   aux = aux->der;
                   bo = true;
               }
               raiz->info = aux->info;
               otro = aux;
               if(bo==true){
                  aux1->der= aux->izq;
               }else{
                  raiz->izq = aux->izq;
               }
            }
         }
         free(otro);
      }else{
        printf("la info no se encuentra");
      }
      return raiz;
}

int altura(NODO *raiz){
      int h=0;
      if(raiz!=NULL){
          int hi=0,hd=0;
          hi++;
          hi+=altura(raiz->izq);
          hd++;
          hd+=altura(raiz->der);
          if(hi>hd){
             h = hi;
          }else{
             h= hd;
          }

      }
    return h;
}




