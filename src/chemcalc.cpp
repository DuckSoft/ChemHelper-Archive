// ===================================
// ChemHelper Project
// ===================================
//   化学计算抽象 
//
#include "chemcalc.h"


ChemCalc::ChemCalc(){
	cout << "[ChemCalc] 初始化完毕" << endl; 
}

void ChemCalc::setMolarMassDatabase(RMDatabase* refDatabase) {
	databasePointer = refDatabase;
}

void ChemCalc::setEquation(Equation* refEquation) {
	equationPointer = refEquation;
}

bool ChemCalc::searchCompoundOfEquation(string strCompound, double& refMultiplier){
	for (auto it : equationPointer->reactant) {
		if (it.first.strRaw == strCompound) {
			refMultiplier = it.second; 
			return true;
		}
	}
	
	for (auto it : equationPointer->product) {
		if (it.first.strRaw == strCompound) {
			refMultiplier = it.second; 
			return true;
		}
	}
	
	return false;
}

bool ChemCalc::calcMWithM(string strCompound, string strCompoundRef, AdvNum amountOfCompoundRef, AdvNum& numResult) {
	double numMultiplier;
	double numRefMultiplier;
	
	if (searchCompoundOfEquation(strCompound, numMultiplier) == false) {
		return false;
	}
		
	if (searchCompoundOfEquation(strCompoundRef, numRefMultiplier) == false) {
		return false;
	}

	Formula formulaToGet(strCompound);
	Formula formulaRef(strCompoundRef);
	AdvNum result;
	
	result = amountOfCompoundRef * numMultiplier * formulaToGet.getMolarMass(databasePointer) / formulaRef.getMolarMass(databasePointer) / numRefMultiplier;
	numResult.numInner = result.numInner;
	numResult.numMin = result.numMin;
	numResult.numMax = result.numMax;
	
	return true;
}
