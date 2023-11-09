#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, num, suma;
    suma = 0;
    printf ("Estimado usuario, por favor ingrese un numero: \n");
    scanf("%d", &n);

    while (n > 0)
    {
        num = n % 10;
        suma = suma + num;
        n = n / 10;

        printf ("%d + ", num);
    }
    
    printf (" = %d", suma);
}

//strl buscar función
//buscar función para medir tamaños
//size para meir vectores o lenght