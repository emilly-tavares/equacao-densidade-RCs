// System Headers
//#include <iostream.h>
//#include <strstream.h>

#ifndef PHYSICS_H
#define PHYSICS_H

#include <math.h>
#include <stdio.h>
#include "Mathematics.h"

class Physics
{
 private:
  //double ;
 	double D;        // coeficiente de difusão
	double tau;      // tempo de escape
	
	double q; //caso tenha fonte, caso não tenha, comentar
    //nesse caso, q = 0  
    
    double z_min, z_max, dz;
    double N[NPTS];  // array da solução numérica
 	double N0[NPTS];  // armazena o estado N(0) adicionei
 	double N1[NPTS];  // armazena o estado N(1) adicionei
 	double N2[NPTS];  // armazena o estado N(2) adicionei
 	
 	double N3[NPTS];  // armazena o estado N(3) adicionei
 	double N5[NPTS];  // armazena o estado N(5) adicionei
 	double N10[NPTS];  // armazena o estado N(10) adicionei
 	double N15[NPTS];  // armazena o estado N(15) adicionei
 	double N20[NPTS];  // armazena o estado N(20) adicionei
 	double N100[NPTS];  // armazena o estado N(100) adicionei
    Mathematics *Math;  // classe Mathematics aqui dentro
  
    
 public:
  //! Constructor of the class.
  Physics ( );

  //! Destructor of the class.
  ~Physics ( );

  //declaration of the method Physics
  float fPhys1(void);

  //declaration of the method Physics
  float fPhys2(void);
  
  void SalvarDados();
};


#endif





