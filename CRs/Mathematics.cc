//Mathematics.cc

// System Headers:
#include <stdlib.h>

// Local Headers:
#include "Mathematics.h"

// Constructor
Mathematics::Mathematics ( )       
{
  
}

// Destructor
Mathematics::~Mathematics ( )
{
        
}

//Code of func1_1
float Mathematics::fMath1(void)
{
	printf("=== MATHEMATICS: teste da formula da derivada segunda atraves de uma grade de pontos ===\n\n");
 
    // Z vai de 0 a 1, dividido em NPTS pontos
    // Cada ponto i corresponde à posição z = i * dz
 
    double z_min = 0.0;
    double z_max = 1.0;
    double dz    = (z_max - z_min) / (NPTS - 1);  // espaçamento
 
    printf("Grade de z = 0 ate z = 1 com %d pontos:\n", NPTS);
    printf("Espacamento dz = %.4f\n\n", dz);
    printf("  indice i  |  posicao z = i*dz\n");
    printf("  ----------|-------------------\n");
 
    for(int i = 0; i < NPTS; i++){
        double z = z_min + i * dz;
        printf("      %2d    |     %.4f\n", i, z);
    }
 
    printf("\nTeste da formula da derivada segunda d2N/dz2 com N(z) = z*z:\n");
    printf("(resultado esperado = 2.0 em todos os pontos)\n\n");
 
    // Preenche N com z²
    double N[NPTS];
    for(int i = 0; i < NPTS; i++){
        double z = z_min + i * dz;
        N[i] = z * z;
    }
 
    printf("  i  |   N[i-1]  |   N[i]    |   N[i+1]  | d2N/dz2\n");
    printf("  ---|-----------|-----------|-----------|---------\n");
 
    // Só pode calcular nos pontos internos (i=1 até i=NPTS-2) pois i=0 não tem vizinho à esquerda e i=NPTS-1 não tem à direita

    for(int i = 1; i < NPTS-1; i++){
        double d2N = derivada_segunda(N, i, dz);
        printf("  %2d |  %8.5f |  %8.5f |  %8.5f | %.4f\n",
               i, N[i-1], N[i], N[i+1], d2N);
    }
 
    printf("\nResultado: todos os valores d2N/dz2 ~ 2.0. Assim, a formula pode ser usada\n\n");
    return 0;

}


//Code of func2_1
float Mathematics::fMath2(void)
{
  // algorithm
  return 0;
}

double Mathematics::derivada_segunda(double N[], int i, double dz)
{
    return ( N[i+1] - 2.0*N[i] + N[i-1] ) / (dz * dz);
}


