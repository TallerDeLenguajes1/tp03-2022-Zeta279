#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} typedef Producto;

struct Cliente{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} typedef Cliente;

int main(){
    int cantClientes, numAux;
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    char *aux;
    float costoTotal;
    Cliente *listaClientes;

    // Ingresar la cantidad de clientes
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    // Reservar memoria dinámicamente
    listaClientes = (Cliente *) malloc(cantClientes * sizeof(struct Cliente));
    aux = (char *) malloc(100);

    srand(time(NULL));

    for(int i = 0; i < cantClientes; i++){
        (listaClientes + i)->ClienteID = i + 1;

        fflush(stdin);
        printf("Ingresar el nombre del cliente: ");
        gets(aux);
        (listaClientes + i)->NombreCliente = (char *) malloc(strlen(aux + 1));
        strcpy((listaClientes + i)->NombreCliente, aux);

        // Generar aleatoriamente la cantidad de productos a pedir
        (listaClientes + i)->CantidadProductosAPedir = 1 + rand() % 5;

        // Reserva dinámica de memoria para almacenar los productos
        (listaClientes + i)->Productos = (Producto *) malloc((listaClientes + i)->CantidadProductosAPedir * sizeof(struct Producto));

        for(int j = 0; j < (listaClientes + i)->CantidadProductosAPedir; j++){
            (((listaClientes + i)->Productos) + j)->ProductoID = j + 1;
            (((listaClientes + i)->Productos) + j)->Cantidad = 1 + rand() % 10;
            numAux = rand() % 5;
            (((listaClientes + i)->Productos) + j)->TipoProducto = (char *) malloc(strlen(TiposProductos[numAux]));
            strcpy((((listaClientes + i)->Productos) + j)->TipoProducto, TiposProductos[numAux]);
            (((listaClientes + i)->Productos) + j)->PrecioUnitario = 10 + rand() % 91;
        }
    }

    printf("Mostrando los datos: ");

    for(int i = 0; i < cantClientes; i++){
        printf("Cliente %d\n\n", i + 1);
        printf("ID del cliente: %d\n", (listaClientes + i)->ClienteID);
        printf("Nombre del cliente: %s\n", (listaClientes + i)->NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", (listaClientes + i)->CantidadProductosAPedir);

        costoTotal = 0;

        printf("Productos del cliente %d:\n", i + 1);
        for(int j = 0; j < (listaClientes + i)->CantidadProductosAPedir; j++){
            printf("Producto %d\n", j + 1);
            printf("ID del producto: %d\n", (((listaClientes + i)->Productos) + j)->ProductoID);
            printf("Cantidad del producto: %d\n", (((listaClientes + i)->Productos) + j)->Cantidad);
            printf("Tipo de producto: %s\n", (((listaClientes + i)->Productos) + j)->TipoProducto);
            printf("Precio del producto: %.2f\n", (((listaClientes + i)->Productos) + j)->PrecioUnitario);
            costoTotal += (((listaClientes + i)->Productos) + j)->PrecioUnitario * (((listaClientes + i)->Productos) + j)->Cantidad;
        }

        printf("Costo total de productos del cliente: %.2f\n", costoTotal);
    }

    return 0;
}