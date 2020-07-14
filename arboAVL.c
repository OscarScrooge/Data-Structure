#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Nodo
{
    int id;
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
}Nodo;

int max(int a, int b);
Nodo* nuevoNodo(int id);
Nodo* rotacionDerecha(Nodo* nodo);
Nodo* rotacionIzquierda(Nodo* nodo);
Nodo* rotacionIzquierdaDerecha(Nodo* nodo);
Nodo* rotacionDerechaIzquierda(Nodo* nodo);
int obtenerBalance(Nodo *nodo);
int buscar(Nodo *raiz, int valor);
Nodo* insertar(Nodo* nodo, int id);
void preOrden(Nodo *raiz);
void graficarArbol(Nodo *raiz);
Nodo * minValueNode(Nodo* node);
Nodo* eliminar(Nodo* raiz, int id);
void opciones(Nodo *raiz);
void graf(Nodo *raiz, FILE* fichero);
void graficarArbolS(Nodo *raiz, Nodo *hijo, FILE* fichero);
Nodo *reequilibra(Nodo *raiz);
int altura(Nodo *raiz);

int main()
{
  Nodo *raiz = NULL;
  opciones(raiz);
  return 0;
}

int max(int a, int b)
{
    if(a > b){
        return a;
    }else if(a < b){
        return b;
    }else{
        return a;
    }
}


Nodo* nuevoNodo(int id)
{
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->id   = id;
    nodo->hijoIzquierdo  = NULL;
    nodo->hijoDerecho = NULL;
    return(nodo);
}

Nodo* rotacionDerecha(Nodo* nodo){
   
    Nodo* nodo1;
    nodo1 = nodo->hijoDerecho;
    nodo->hijoDerecho = nodo1->hijoIzquierdo;
    nodo1 ->hijoIzquierdo = nodo;
    return nodo1;
    
}

Nodo* rotacionIzquierda(Nodo* nodo){
 
    Nodo* nodo1;
    nodo1 = nodo ->hijoIzquierdo;
    nodo->hijoIzquierdo = nodo1->hijoDerecho;
    nodo1 ->hijoDerecho = nodo;
    return nodo1;
    
}

Nodo* rotacionIzquierdaDerecha(Nodo* nodo){

    Nodo* nodo1;
    Nodo* nodo2;

    nodo1 = nodo ->hijoIzquierdo;
    nodo2 = nodo1 -> hijoDerecho;

    nodo1->hijoDerecho = nodo2->hijoIzquierdo;
    nodo2 ->hijoIzquierdo = nodo1;
    nodo->hijoIzquierdo = nodo2->hijoDerecho;
    nodo2->hijoDerecho = nodo;

    return nodo2;
}

Nodo* rotacionDerechaIzquierda(Nodo* nodo){
  
    Nodo* nodo1;
    Nodo* nodo2;

    nodo1 = nodo ->hijoDerecho;
    nodo2 = nodo1 -> hijoIzquierdo;

    nodo1->hijoIzquierdo = nodo2->hijoDerecho;
    nodo2 ->hijoDerecho = nodo1;
    nodo->hijoDerecho = nodo2->hijoIzquierdo;
    nodo2->hijoIzquierdo = nodo;
    return nodo2;
}

int obtenerBalance(Nodo *nodo)
{
    if (nodo == NULL){
        return 0;
    }
    int al;
    al= altura(nodo->hijoDerecho) - altura(nodo->hijoIzquierdo) ;
    return al;
}

int buscar(Nodo *raiz, int valor){

    if(raiz == 0){
        return 0;
    }else{
        if(raiz->id == valor){
            return 1;
        }else{
            if(valor > raiz->id && raiz->hijoDerecho != 0){
                return  buscar(raiz->hijoDerecho, valor);
            }else if(valor < raiz->id && raiz->hijoIzquierdo != 0){
                return buscar(raiz->hijoIzquierdo, valor);
            }
        }
    }
    return 0;
}

Nodo* insertar(Nodo* nodo, int id)
{

    if (nodo == NULL){
        return(nuevoNodo(id));
    }else{
        if(buscar(nodo, id) == 0){
            if (id < nodo->id){
                nodo->hijoIzquierdo  = insertar(nodo->hijoIzquierdo, id);
            }else if (id > nodo->id){
                nodo->hijoDerecho = insertar(nodo->hijoDerecho, id);
            }
            else{
                printf("Nodo duplicado\n");
                return nodo;
            }
            nodo = reequilibra(nodo);

        }else{
            printf("Nodo duplicado\n");
            printf("\nPresione enter para continuar...\n");
            getchar();
            getchar();
        }
    }
    return nodo;
}

Nodo *reequilibra(Nodo *raiz){

     Nodo *nodo = raiz;


              printf("ALTURA %d = %d\n\n",nodo->id, altura(nodo));
               int factorEquilibrio = obtenerBalance(nodo);
              printf("BALANCE %d = %d\n\n",nodo->id, factorEquilibrio);


              if(factorEquilibrio < -1){

                       factorEquilibrio =  obtenerBalance(nodo->hijoIzquierdo);
                       if(factorEquilibrio <=0){
                            printf("\n\nROTACION IZQUIERDA\n\n");
                          return rotacionIzquierda(nodo);
                      }else{
                             printf("\n\nROTACION IZQUIERDA DERECHA\n\n");

                          return rotacionIzquierdaDerecha(nodo);
                      }


              }else if(factorEquilibrio >1){

                       factorEquilibrio =  obtenerBalance(nodo->hijoDerecho);
                       if(factorEquilibrio >=0){
                            printf("\n\nROTACION DERECHA\n\n");
                            return rotacionDerecha(nodo);
                       }else{
                           printf("\n\nROTACION DERECHA IZQUIERDA\n\n");
                           return rotacionDerechaIzquierda(nodo);

                       }

              }

       return nodo;
}

void preOrden(Nodo *raiz)
{
    if(raiz != NULL)
    {
        printf("Dato: %d -> ", raiz->id);
        preOrden(raiz->hijoIzquierdo);
        preOrden(raiz->hijoDerecho);
    }
}

void graficarArbol(Nodo *raiz){
    //system("cls");
    FILE* fichero;
    fichero = fopen("arbol.dot", "wt");
    fputs("digraph Arbol{\n", fichero);
    if(raiz!= 0){
        graf(raiz, fichero);
    }else{
        fputs("Vacio", fichero);
    }
    fputs("}", fichero);
    fclose(fichero);
    system("dot -Tpng arbol.dot -o arbol.png");
    return;
}

void graf(Nodo *raiz, FILE* fichero){
    if(raiz != 0){
        if(raiz->hijoIzquierdo != 0){
            graficarArbolS(raiz, raiz->hijoIzquierdo, fichero);
            graf(raiz->hijoIzquierdo, fichero);
        }
        if(raiz->hijoDerecho  != 0){
            graficarArbolS(raiz, raiz->hijoDerecho, fichero);
            graf(raiz->hijoDerecho, fichero);
        }

        if(raiz->hijoIzquierdo == 0 && raiz->hijoDerecho == 0){
            int n = raiz->id;
            char * cad = malloc(12 * sizeof(char));
            sprintf(cad, "%i", n);
            fputs(cad, fichero);
            fputs("\n", fichero);
        }
    }
}

void graficarArbolS(Nodo *raiz, Nodo *hijo, FILE* fichero){
    int n = raiz->id;
    int n2 = hijo->id;
    char * cad = malloc(12 * sizeof(char));
    char * cad2 = malloc(12 * sizeof(char));
    sprintf(cad, "%i", n);
    sprintf(cad2, "%i", n2);
    fputs(cad, fichero);
    fputs("->", fichero);
    fputs(cad2, fichero);
    fputs("\n", fichero);
}

Nodo * minValueNode(Nodo* node)
{
    Nodo* current = node;
    while (current->hijoIzquierdo != 0){
        current = current->hijoIzquierdo;
    }
    return current;
}

Nodo* eliminar(Nodo* raiz, int id){
     bool bo = false;
          Nodo *otro=NULL,*aux=NULL,*aux1=NULL;

          if(raiz!=NULL){
             if( id < raiz->id){
                raiz->hijoIzquierdo= eliminar(raiz->hijoIzquierdo,id);
             }else if( id > raiz->id){
                raiz->hijoDerecho= eliminar(raiz->hijoDerecho,id);
             }else{
                otro = raiz;
                if(otro->hijoDerecho == NULL){
                   raiz = otro -> hijoIzquierdo;
                }else if(otro->hijoIzquierdo == NULL){
                   raiz = otro -> hijoDerecho;
                }else{
                   aux = raiz->hijoIzquierdo;
                   bo= false;

                   while( aux-> hijoDerecho !=NULL){
                       aux1 = aux;
                       aux = aux->hijoDerecho;
                       bo = true;
                   }
                   raiz->id = aux->id;
                   otro = aux;
                   if(bo==true){
                      aux1->hijoDerecho= aux->hijoIzquierdo;
                      raiz->hijoIzquierdo = reequilibra(  raiz->hijoIzquierdo);
                   }else{
                      raiz->hijoIzquierdo = aux->hijoIzquierdo;
                   }
                }
    			free(otro);
             }
             if(raiz!= NULL){
                raiz = reequilibra(raiz);
             }

          }else{
            printf("la id no se encuentra");
          }
          return raiz;
}

void opciones(Nodo *raiz){
   // system("cls");
    int x = 0,i=0;
    int ingre = 1;
    //int valores[17]={58,43,75,86,65,70,67,73,93,69,25,66,68,47,62,10,60};
    int valores[5]={5,7,9,12};
    printf("\nSeleccione una opcion:\n1- Insertar\n2- Eliminar\n3- Buscar\n4- impresion Preoprden\n 5- Salir\nOpcion: ");
    scanf("%d", &x);
    switch(x){
    case 1:
        system("cls");
        while(i <4){
            //printf("\nIngrese un valor: ");
           // scanf("%d", &ingre);
            //if(ingre != 0){
                raiz = insertar(raiz, valores[i]);
                preOrden(raiz);
                graficarArbol(raiz);
                i++;
            //}
        }
        system("cls");
        opciones(raiz);
        break;
    case 2:
       // system("cls");
        ingre=1;
        while(ingre!=0){
            printf("Ingrese un valor para eliminar: ");
            scanf("%d", &ingre);
            if(ingre!=0){
                 raiz = eliminar(raiz, ingre);
                 graficarArbol(raiz);
            }
        }
        opciones(raiz);
        break;
    case 3:
        system("cls");
        printf("Ingrese un valor para buscar: ");
        scanf("%d", &ingre);
        int a = buscar(raiz, ingre);
        if(a == 0){
            printf("El valor %d no se encuentra en el arbol\n", ingre);
        }else{
            printf("El valor %d si se encuentra en el arbol\n", ingre);
        }
        printf("\nPresione enter para continuar...\n");
        getchar();
        getchar();
        opciones(raiz);
        break;
    case 4:
        preOrden(raiz);
        break;
    case 5:
        system("cls");
        printf("Salir\n");
        system("exit");
        break;
    default:
        printf("\nIngrese una opcion correcta\n");
        getchar();
        getchar();
        opciones(raiz);
    }
}

int altura(Nodo *raiz){
      int h=0;
      if(raiz!=NULL){
          int hi=0,hd=0;
          hi++;
          hi+=altura(raiz->hijoIzquierdo);
          hd++;
          hd+=altura(raiz->hijoDerecho);
          if(hi>hd){
             h = hi;
          }else{
             h= hd;
          }

      }
    return h;
}