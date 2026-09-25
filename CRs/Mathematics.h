// System Headers
//#include <iostream.h>
//#include <strstream.h>

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <math.h>
#include <stdio.h>

// Quantos pontos vai ter na "régua" de z
#define NPTS 10

class Mathematics
{
 private:
 	float a,b,c;
  	//double ;
    
 public:
	#define pi 3.141592654
	#define rad2deg (180./pi)

  //! Constructor of the class.
  Mathematics ( );

  //! Destructor of the class.
  ~Mathematics ( );

  //Declaration of the method Mathematics
  float fMath1(void);

  //Declaration of the method Mathematics
  float fMath2(void);
  
  double derivada_segunda(double N[], int i, double dz);
};

#endif







