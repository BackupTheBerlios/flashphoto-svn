#include <stdio.h>
#include "line.h"

/*-<==>-----------------------------------------------------------------
/ Builds a default empty line
/----------------------------------------------------------------------*/
CLine:: CLine() :  level(0), loc(0,0,0), dir (1,0,0),color(0,0,0), t(-1e6), obj(NULL) {
  }

/*-<==>-----------------------------------------------------------------
/ Builds a line with specific loc and direction
/----------------------------------------------------------------------*/
CLine::CLine (const VECTOR &nloc, const VECTOR &ndir, int nlevel)
	: level (nlevel), loc (nloc), dir (ndir) , color(0,0,0), t(-1e6), obj(NULL) {
  dir.normalize();
}

/*-<==>-----------------------------------------------------------------
/
/----------------------------------------------------------------------*/
CLine CLine::getReflected(const VECTOR &nloc, const VECTOR &normal)
{
  CLine c;
  dir.normalize();
  c.level=level+1;
  c.loc=nloc;
  c.dir=(dir+(2*dir.dot(-normal))*normal);
  c.dir.normalize();
  c.t=-1;

  return c;
}

CLine CLine::getRefracted(const VECTOR &nloc, const VECTOR &normal, const SCALAR& factor){
	dir.normalize();

	// El coseno de theta i es el escalar de la normal por el vector incidente
	const SCALAR cosi = dir.dot(normal);
	/*
	 * El seno de theta t al cuadrado es el factor de refraccion al cuadrado
	 * multiplicado por (1- cos cuadrado de theta i)
	 */
	const SCALAR sin2t = (factor*factor)*(1-(cosi*cosi));

	// Si el seno es mayor que uno
	if(sin2t>1.0){
		// Problema, no es valido
		std::cerr << "[ERROR] CLine::getRefracted() sen2t>1.0" << std::endl;
	}

	// El vector refractado
	VECTOR dirRefr = factor*dir - (factor + std::sqrt(1.0 - sin2t))*normal;
	dirRefr.normalize();
	// Construimos la linea del haz reflejado
	CLine refr(nloc, dirRefr);
	// Aumentamos el nivel
	refr.level =level+1;
	refr.t=-1;
	// Y ponemos el color a 0
	refr.color=COLOR(0.0,0.0,0.0);

	return refr;
}

const CLine& CLine::operator++()
{
  level++;
  return *this;
}


/*-<==>-----------------------------------------------------------------
/
/----------------------------------------------------------------------*/
VECTOR CLine::getIntersection() const {
  return loc + (dir*t);
}

/*-<==>-----------------------------------------------------------------
/ return current recursion level
/----------------------------------------------------------------------*/
int CLine::getLevel() const {
  return level;
}

/*-<==>-----------------------------------------------------------------
/ add a color amount to color of this line
/----------------------------------------------------------------------*/
void CLine::addColor(const VECTOR &amount)
{
    // No sumamos luz negativa
    if(amount.x<0)
        return;
    if(amount.y<0)
        return;
    if(amount.z<0)
        return;
  color += amount;
  if(color.x>1)
    color.x=1;
  if(color.y>1)
    color.y=1;
  if(color.z>1)
    color.z=1;

  // NOTE: y esto para que?
  /*
    aixo era per si arrivaben a mes de 1 en un posar blanc del tot
  if((color.x>1)||(color.y>1)||(color.z>1))
    {
      color.x=1;
      color.y=1;
      color.z=1;
    }
  */

  //color.normalize();
}
