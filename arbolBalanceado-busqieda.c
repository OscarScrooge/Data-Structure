#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODO{
   int info;
   int fe;
  struct NODO *izq;
  struct NODO *der;
}NODO;


void preorden(NODO *raiz);
void inorden(NODO *raiz);
void posorden(NODO *raiz);
NODO *insertarNodoBalanceado(NODO *nodo,bool bo,int info);
NODO *crearNodoArbolBusqueda(NODO* raiz,int info);
int altura(NODO *raiz);

int main(void) {

  NODO *raiz=NULL;
  int buscar,info,opt=1,i=3;

  while(i>0){
        printf("INFO: ");
         scanf("%d",&info);
        raiz = crearNodoArbolBusqueda(raiz,info);
        i--;
  }
   i=14;
   bool bo = false;
   while(i>0){
      printf("INFO: ");
       scanf("%d",&info);
      raiz = insertarNodoBalanceado(raiz,&bo,info);
      raiz->fe = altura(raiz->der)-altura(raiz->izq);
     bo=false;
      /*printf("Continuar: ");
      scanf("%d",&opt);*/
      i--;
    }
    printf("\n\nImpresion preorden \n");
    preorden(raiz);
    printf("\nImpresion inorden \n");
    inorden(raiz);
    printf("\nImpresion posorden \n");
    posorden(raiz);
    printf("\nAltura: %d \n", altura(raiz));




  return 0;
}


NODO *insertarNodoBalanceado(NODO *nodo,bool &bo,int info){

   NODO *otro,*nodo1,*nodo2;
   //bool bo = false;
   if(nodo!=NULL){
       if(info < nodo->info){
         /* printf("\n %d < %d\n", info,nodo->info );
           printf("\ninserta %d izquierda de %d\n", info,nodo->info );*/
           nodo->izq = insertarNodoBalanceado(nodo->izq,&bo,info);

           if(bo==true){
                  nodo->fe = altura(nodo->der) - altura(nodo -> izq);
                  printf("\nFE de  %d=%d \n",nodo->info,nodo->fe);
                  if(nodo->fe == 1){
                     nodo->fe =0;
                     bo=false;
                  }else if(nodo->fe == 0){
                     nodo->fe =1*(-1);
                  }else if(nodo->fe == -1){
                         nodo1 = nodo->izq;

                     //nodo1 -> fe = altura(nodo1->der) - altura(nodo1 -> izq);
                     if(nodo1->fe<=0){
                         /**
                         ROTACION II
                         **/
                         nodo->izq = nodo1->der;
                         nodo1->der = nodo;
                         nodo->fe =0;
                         nodo = nodo1;
                         //nodo1->fe =0;
                      }else{
                        /**
                        ROTACION ID
                        **/
                         /*nodo2= nodo1->der;
                         nodo -> izq = nodo2->der;
                         nodo2->der = nodo;
                         nodo1->der = nodo2->izq;
                         nodo2->izq = nodo1;*/
                         nodo1->der = nodo2->izq;
                         nodo2->izq = nodo1;
                         nodo->izq = nodo2->der;
                         nodo2->der = nodo;
                         nodo = nodo2;

                         if(nodo2->fe==-1){
                            nodo-> fe = 1;
                         }else{
                            nodo->fe=0;
                         }

                         if(nodo2->fe==1){
                            nodo1->fe=1*(-1);
                          }else{
                            nodo1->fe=0;
                          }
                          nodo = nodo2;
                       /**TERMINA ROTACION ID**/
                      }
  nodo->fe = 0;
                   //bo=false;
                  }


           }
       }else if(info>nodo->info){
            /*printf("\n %d > %d\n", info,nodo->info );
             printf("\ninserta %d derecha de %d\n", info,nodo->info );*/
             nodo->der=insertarNodoBalanceado(nodo->der,&bo,info);

             if(bo==true){
                 nodo -> fe = altura(nodo->der) - altura(nodo -> izq);
                 printf("\nFE de  %d=%d \n",nodo->info,nodo->fe);
                 if(nodo->fe ==-1){
                        nodo->fe =0;
                        bo=false;
                 }else if(nodo->fe == 0){
                        //nodo1->fe =1;
                        nodo->fe =1;
                 }else if(nodo->fe == 1){
                        nodo1 = nodo->der;

                       // nodo1 -> fe = altura(nodo1->der) - altura(nodo1 -> izq);
                        if(nodo1->fe >=0){
                           /**
                           ROTACION DD
                           **/
                           nodo->der = nodo1->izq;
                           nodo1->izq = nodo;
                           nodo->fe =0;
                           //nodo1->fe =0;
                           nodo= nodo1;
                        }else{
                           /**
                           ROTACION DI
                           **/
                           /*nodo2=nodo1->izq;
                           nodo->der = nodo2 -> izq;
                           nodo2 ->izq = nodo;
                           nodo1 ->izq = nodo2->der;
                           nodo2->der = nodo1;*/
                           nodo2=nodo1->izq;
                           nodo1->izq = nodo2->der;
                           nodo2->der = nodo1;
                           nodo->der = nodo2->izq;
                           nodo2->izq = nodo;
                           nodo = nodo2;

                           if(nodo2->fe == 1){
                                nodo->fe = -1;
                           }else{
                                nodo->fe = 0;
                           }

                           if(nodo2->fe == -1){
                                nodo1->fe = 1;
                           }else{
                                nodo1->fe = 0;
                           }
                           nodo=nodo2;
                        }
nodo->fe = 0;
                   //bo = false;
                 }


             }
           }else{
             printf("la informacion ya se encuentra en el arbol");
           }
   }else{
       otro = malloc(sizeof(NODO));
       otro -> info = info;
       otro -> izq = NULL;
       otro -> der = NULL;
       otro -> fe = 0;
       nodo= otro;
       bo = true;
   }
   return nodo;
}



void preorden(NODO *raiz){

     if(raiz!=NULL){
         printf("inf= %d  FE=%d, ",raiz->info,raiz->fe);
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


NODO *crearNodoArbolBusqueda(NODO* raiz,int info){

    if(raiz==NULL){
         NODO *nuevo = malloc(sizeof(NODO));
         nuevo->info = info;
         nuevo->izq=NULL;
         nuevo->der=NULL;
         nuevo->fe=0;
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



