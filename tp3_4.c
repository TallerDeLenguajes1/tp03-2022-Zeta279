#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int num;
    char *aux;

    // Ingresar la cantidad de nombres a escribir
    printf("Ingresar la cantidad de nombres: ");
    scanf("%d", &num);

    // Controlar que se ingrese una cantidad correcto
    while(num <= 0){
        printf("Ingresar una cantidad valida: ");
        scanf("%d", &num);
    }

    // Creamos la lista de usuarios
    char *nombres[num];

    // Reserva de memoria dinámica
    aux = (char *) malloc(100);

    // Ingresar nombres
    for(int i = 0; i < num; i++){
        fflush(stdin);
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        gets(aux);
        nombres[i] = (char *) malloc(strlen(aux) + 1);
        strcpy(nombres[i], aux);
    }

    // Mostrar nombres
    printf("Mostrando los nombres ingresados:\n");
    for(int i = 0; i < num; i++){
        printf("%d) ", i + 1);
        puts(nombres[i]);
    }

    // Liberar memoria
    free(aux);
    for(int i = 0; i < num; i++){
        free(nombres[i]);
    }

    return 0;
}