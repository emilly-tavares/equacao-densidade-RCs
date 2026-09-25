// Prog.cc
// This Program is

#include "Main.h"

int main (int par_exec1, char* pars_exec[])
{    
//Objects creation
	Mathematics * Math = new Mathematics();
    Physics * Phys = new Physics();
//    Atmosphere * Atm = new Atmosphere(); 
	    
    printf("*******COSMIC RAYS*******\n\n");

//Methods (functions) of the classes are called

	// 1) Mostra o que são diferenças finitas (ferramenta matemática)
	Math->fMath1();
	
	//Math->fMath2();

	// 2) Resolve D*d²N/dz² - N/tau = 0  numericamente
	Phys->fPhys1();
	// 3) Compara com a solução analítica
	Phys->fPhys2();
	
	Phys->SalvarDados();

 
//Calls Atmosphere and print its data
/*	Atm->Init(altitude,temperature,pressure,density);
	for(i=0;i<=1480;i++){
		double alt=Atm->GetAltitude(i,altitude);
		double temp=Atm->GetTemperature(i,temperature);
		double press=Atm->GetPressure(i,pressure);
		double dens=Atm->GetDensity(i,density);
		printf("i= %d, h= %.3f km, T= %.3f oC, P= %.3f hPa, dens= %.3f kg/m3\n",i,alt,temp,press,dens);
	}*/
	
	delete Math;
    delete Phys;

	system("pause");
	return 0;
}
