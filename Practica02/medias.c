#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float media_aritmetica(float datos[], int n);
float media_harmonica(float datos[], int n);
float media_geometrica(float datos[], int n);

int main (int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error: Se debe ingresar un opcion (A, H, G) y despues una serie de numeros.\n");
        return -1;
    }

    char opcion = argv[1][0];

    float datos[argc - 1];
    for (int i = 2; i < argc; i++)
    {
        datos[i - 2] = atof(argv[i]);
    }

    if (opcion == 'A')
    {
        printf("Media aritmetica: %.2f\n", media_aritmetica(datos, argc - 2));
        return 0;
    }
    else if (opcion == 'H')
    {
        printf("Media harmonica: %.2f\n", media_harmonica(datos, argc - 2));
        return 0;
    }
    else if (opcion == 'G')
    {
        printf("Media geometrica: %.2f\n", media_geometrica(datos, argc - 2));
        return 0;
    }
    else
    {
        printf("Error: Opcion no valida. Las opciones validas son: A, G, H\n");
        return -1;
    }
}

float media_aritmetica(float datos[], int n)
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += datos[i];
    }
    return suma / n;
}

float media_harmonica(float datos[], int n)
{
    float bottom = 0;
    for (int i = 0; i < n; i++)
    {
        bottom += 1 / datos[i];
    }
    return n / bottom;
}

float media_geometrica(float datos[], int n)
{
    float mult = 1;
    for (int i = 0; i < n; i++)
    {
        mult *= datos[i];
    }
    return pow(mult, 1 / n);
}