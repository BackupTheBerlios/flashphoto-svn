#ifndef _ESTATS_RAY_TRACER_HXX_
#define _ESTATS_RAY_TRACER_HXX_

class Estats
{
protected:
  static Estats inst;
  Estats(){}
  
  /*
    segons enunciat
    ===============
    * N�mero total de lineas trazadas
    * N�mero lineas trazadas desde la c�mara
    * N�mero lineas trazadas para el c�lculo de sombras
    * N�mero lineas trazadas para el c�lculo de reflejos
    * N�mero lineas trazadas para el c�lculo de refracci�n y reflejos
    * N�mero total de tests de intersecci�n hechos
    * N�mero de tests de intersecci�n con resultado positivo y el porcentaje respecto al total.
   */
  int lineas;
  int camera;
  int sombra;
  int reflexe;
  int refrac_reflex;
  int intersects;
  int interok;
  int interbad;
public:
  static Estats& getInstance(){return inst;}
  void incLine(){lineas++;}
  void incCamera(){camera++;}
  void incSombra(){sombra++;}
  void incReflexe(){reflexe++;}
  void incRefrac(){refrac_reflex++;}
  void incIntersects(){intersects++;}
  void incIntersectsOK(){interok++;}
  void incIntersectsNO(){interbad++;}
  //
  void printStats()
  {
    std::cout << "* N�mero total de lineas trazadas: " 
	      << lineas
	      << std::endl;
    std::cout << "* N�mero lineas trazadas desde la c�mara: " 
	      << camera
	      << std::endl;
    std::cout << "* N�mero lineas trazadas para el c�lculo de sombras: " 
	      << sombra
	      << std::endl;
    std::cout << "* N�mero lineas trazadas para el c�lculo de reflejos: " 
	      << reflexe
	      << std::endl;
    std::cout << "* N�mero lineas trazadas para el c�lculo de refracci�n y reflejos: " 
	      << refrac_reflex
	      << std::endl;
    std::cout << "* N�mero total de tests de intersecci�n hechos: " 
	      << intersects
	      << std::endl;
    std::cout << "* N�mero de tests de intersecci�n con resultado positivo y el porcentaje respecto al total: " 
	      << interok << "/" << interbad
	      << std::endl;
  }
};


#endif
