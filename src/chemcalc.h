// ===================================
// ChemHelper Project
// ===================================
//   化学计算抽象 
//

#ifndef _E3D985A02D6111E6BDF40800200C9A66
#define _E3D985A02D6111E6BDF40800200C9A66

#include "misc.h"
#include "equation.h"
#include "formula.h"

using namespace std;

class ChemCalc {
	public:
		ChemCalc();
		void setMolarMassDatabase(RMDatabase* refDatabase);
		void setEquation(Equation* refEquation); 
		bool calcMWithN(string strCompound, string strCompoundRef, AdvNum amountOfCompoundRef, AdvNum& numResult);
		bool calcMWithM(string strCompound, string strCompoundRef, AdvNum massOfCompoundRef, AdvNum& numResult); 
		bool searchCompoundOfEquation(string strCompound, double& refMultiplier);
	private:
		RMDatabase* databasePointer;
		Equation* equationPointer; 
		

}; 
 
#endif
