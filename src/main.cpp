// ===================================
// ChemHelper Project
// ===================================
//   测试模型用主程序
//

#include "equation.h"
#include "chemcalc.h"
#include "misc.h"
int main() {
	using namespace std;
	cout << "ChemHelper 测试平台" << endl;

	cout  << ">>> "; 
	string userInput;			// 获取用户输入 
	getline(cin, userInput);
	
	RMDatabase database;
	database.loadDataDefault();
	
	Equation equTest;
	equTest.parseEquation(userInput);
	
//	for (auto itemReactant : equTest.reactant) {
//		cout << "[化学式]:"			<< itemReactant.first.strRaw << endl; 
//		cout << "[化学计量数]:"		<< itemReactant.second << endl;
//		cout << "[相对分子质量]:"	<<  "  ";
//		cout << itemReactant.first.getMolarMass(&database).numMin;
//		cout << " ~ ";
//		cout << itemReactant.first.getMolarMass(&database).numMax;
//		cout << " (";
//		cout << itemReactant.first.getMolarMass(&database).numInner;
//		cout << ") " << endl << endl;
//	}
//	
//	for (auto itemProduct : equTest.product) {
//		cout << "[化学式]:"			<< itemProduct.first.strRaw << endl; 
//		cout << "[化学计量数]:"		<< itemProduct.second << endl;
//		cout << "[相对分子质量]:" 	<< "  ";
//		cout << itemProduct.first.getMolarMass(&database).numMin;
//		cout << " ~ ";
//		cout << itemProduct.first.getMolarMass(&database).numMax;
//		cout << " (";
//		cout << itemProduct.first.getMolarMass(&database).numInner;
//		cout << ") " << endl << endl;
//	}
//	
	ChemCalc calc;
	calc.setEquation(&equTest);
	calc.setMolarMassDatabase(&database);
	
	string strCondition;
	string numCondition;
	string strToGet;
	AdvNum numToGet;
	
	cout << "Input Condition Formula: ";
	getline(cin, strCondition);
	
	cout << "Input Condition Mass: ";
	getline(cin, numCondition);
	
	
	
	cout << "Input Target Formula: ";
	getline(cin, strToGet);
	
	while(!strToGet.empty()) {
	calc.calcMWithM(strToGet, strCondition, AdvNum(str2uint(numCondition)), numToGet);
		cout << numToGet.numMin;
		cout << " ~ ";
		cout << numToGet.numMax;
		cout << " (";
		cout << numToGet.numInner;
		cout << ") " << endl << endl;
	
	cout << "Error Level:" << (numToGet.numMax - numToGet.numMin)/2 << endl;
	
	cout << "Input Target Formula: ";
	getline(cin, strToGet);
	}
}
