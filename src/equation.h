// ===================================
// ChemHelper Project
// ===================================
//   化学方程式抽象
//

#ifndef _886E7BF14D65628587C4531FCD166760
#define _886E7BF14D65628587C4531FCD166760

#include "advnum.h"
#include "formula.h"
#include "rmm.h" 

using namespace std;

class Equation {
	public:
		vector<pair<Formula, unsigned int> > reactant;
		vector<pair<Formula, unsigned int> > product;

		Equation();
		bool checkBalance();
		void parseEquation(string inStr);
		void reset();
	private:
		void parseFormulaList(string strA, string strB);
};
#endif
