#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5

int main(){
    char *nombres[NUM], *aux;

    // Reserva de memoria dinámica
    aux = (char *) malloc(100);

    // Ingresar nombres
    for(int i = 0; i < NUM; i++){
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        gets(aux);
        nombres[i] = (char *) malloc(strlen(aux) + 1);
        strcpy(nombres[i], aux);
    }

    // Mostrar nombres
    printf("Mostrando los nombres ingresados:\n");
    for(int i = 0; i < NUM; i++){
        printf("%d) ", i + 1);
        puts(nombres[i]);
    }

    // Liberar memoria
    free(aux);
    for(int i = 0; i < NUM; i++){
        free(nombres[i]);
    }

    return 0;
}