//Physics.cc

#include <fstream>

// System Headers:
#include <stdlib.h>

#include <math.h>

// Local Headers:
#include "Physics.h"


// Constructor
Physics::Physics ( )       
{
    Math = new Mathematics();
 
    D   = 1.0;    // coeficiente de difusão 
    tau = 1.0;    // tempo de escape 
    q  = 5.0;     // fonte
 
    z_min = 0.0;
    z_max = 1.0;
    dz    = (z_max - z_min) / (NPTS - 1);
 
    // condição inicial: N = 0 em toda a grade
    for(int i = 0; i < NPTS; i++) N[i] = 0.0;
}

// Destructor
Physics::~Physics ( )
{
    delete Math;
}

//Codigo da func1_2
float Physics::fPhys1(void)
{
	printf("=== PHYSICS: Resolucao Numerica (metodo de relaxacao) ===\n\n");
   
    printf("Equacao: D*d2N/dz2 - N/tau + q = 0\n");
    printf("D = %.1f,  tau = %.1f,  q = %.1f\n", D, tau, q);

    printf("z de %.1f ate %.1f,  %d pontos,  dz = %.4f\n\n",
           z_min, z_max, NPTS, dz);
 
    // 1 - Condições de contorno (bordas fixas em zero) 
    N[0]      = 0.0;
    N[NPTS-1] = 0.0;
 
    // 2 - chute inicial nos pontos internos
    // N[i] = 1.0 para todos os pontos internos
    // Pode ser qualquer valor inicial
    printf("N[i] = 1.0 para todos os pontos internos.\n\n");
    for(int i = 1; i < NPTS-1; i++) N[i] = 1.0;
    
    for(int i = 0; i < NPTS; i++) N0[i] = N[i]; //adicionei
    
 
    // 3 - iterações de relaxação 
    // O denominador (2D/dz² + 1/tau) não muda 
    double dz2    = dz * dz;
    double denom  = 2.0*D/dz2 + 1.0/tau;
 
    int max_iter = 10000;  // número máximo de iterações
 
    printf("Iterando (max %d iteracoes)...\n\n", max_iter);
 
    // Imprime o estado a cada 2000 iterações
    printf("  iter  |  N[1]      N[2]      N[3]  ...  N[NPTS-2]\n");
    printf("  ------|--------------------------------------------------\n");
 
    for(int iter = 0; iter < max_iter; iter++){
 
        // mostra algumas iterações para mostrar a convergência (ADICIONEI)
        if(iter == 0 || iter == 1  || iter == 2  || iter == 3  || iter == 20 || iter == 50 ||
           iter == 100 || iter == max_iter-1){
            printf("  %5d |", iter);
            for(int i = 1; i < NPTS-1; i++)
                printf("  %7.5f", N[i]);
            printf("\n");
        }
 
        // Atualiza cada ponto interno usando a fórmula de relaxação:
        // N[i] = D*(N[i+1] + N[i-1])/dz²  /  (2D/dz² + 1/tau)
        for(int i = 1; i < NPTS-1; i++){
        	
            N[i] = ( D*(N[i+1] + N[i-1]) / dz2  +  q ) / denom; 
            
        }
        
        //adicionado
        if(iter == 0){
   			for(int i = 0; i < NPTS; i++) N1[i] = N[i];
		}
		
		if(iter == 1){
  			for(int i = 0; i < NPTS; i++) N2[i] = N[i];
		}
		// a partir daqui as interações são gravadas
		if(iter == 2){
    		for(int i = 0; i < NPTS; i++) N3[i] = N[i];
		}
		
		if(iter == 4){
    		for(int i = 0; i < NPTS; i++) N5[i] = N[i];
		}
		
		if(iter == 9){
    		for(int i = 0; i < NPTS; i++) N10[i] = N[i];
		}
		
		if(iter == 14){
    		for(int i = 0; i < NPTS; i++) N15[i] = N[i];
		}
		
		if(iter == 19){
    		for(int i = 0; i < NPTS; i++) N20[i] = N[i];
		}
		
		if(iter == 99){
    		for(int i = 0; i < NPTS; i++) N100[i] = N[i];
		}
    }
 
    // Resultado final 
    printf("\n\nResultado final apos %d iteracoes:\n\n", max_iter);
    printf("  indice i |  posicao z  |  N[i] numerico\n");
    printf("  ---------|-------------|----------------\n");
 
    for(int i = 0; i < NPTS; i++){
        double z = z_min + i * dz;
        printf("     %2d   |   %.4f    |   %.8f\n", i, z, N[i]);
    }
    printf("\n");
 
    return 0;
}



float Physics::fPhys2(void)
{
    printf("=== PHYSICS: Solucao Analitica (Modelo de Disco Galactico) ===\n\n");

    double L = sqrt(D * tau);
    printf("L = %.4f | q = %.1f\n", L, q);

    printf("  i  |    z     | N analitico  | N numerico\n");
    printf("  ---|---------|--------------|-----------\n");

    for(int i = 0; i < NPTS; i++){
        double z = z_min + (double)i * dz;
        
        double arg1 = (z - 0.5) / L;
        double arg2 = 0.5 / L;
        
        // Se o argumento for muito grande, N_analit tende a q*tau (saturacao)
        double N_analit;
        if (arg2 > 20.0) { 
            // Em regiões longe das bordas na Galaxia, a densidade satura em q*tau
            N_analit = q * tau; 
            if (z < 0.001 || z > 0.999) N_analit = 0.0; // Mantém as bordas em zero
        } else {
            N_analit = q * tau * (1.0 - cosh(arg1) / cosh(arg2));
        }

        // Segurança: garante que i nao ultrapasse o tamanho do vetor N
        if (i < NPTS) {
            printf("  %2d | %.4f  | %.8f  | %.8f\n", i, z, N_analit, N[i]);
        }
    }

    return 0;
}


void Physics::SalvarDados() {
    // escreve o arquivo de texto com os dados obtidos
    std::ofstream arquivo("dados_raios_cosmicos.txt");

    if (arquivo.is_open()) {
       
        //arquivo << "z\tN_numerico" << std::endl; 
        //arquivo << "z\tN0\tN1\tN2\tN3" << std::endl;
        arquivo << "z\tN3\tN5\tN10\tN15\tN20\tN100" << std::endl;

        for(int i = 0; i < NPTS; i++) {
            double z = z_min + (double)i * dz;
            // Salva a posição z e o valor N 
            //arquivo << z << "\t" << N[i] << std::endl;
            
            
           // arquivo << z << "\t" << N0[i] << "\t" << N1[i] << "\t" << N2[i] << "\t" << N3[i] << std::endl; // adicionei
            arquivo << z << "\t" << N3[i] << "\t" << N5[i] << "\t" << N10[i] << "\t" << N15[i] << "\t" << N20[i] << "\t" << N100[i] << std::endl; // adicionei
        }
        arquivo.close();
        printf("Arquivo 'dados_raios_cosmicos.txt' gerado com sucesso!\n");
    } else {
        printf("Erro ao criar o arquivo de dados.\n");
    }
}


