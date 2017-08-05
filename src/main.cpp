// ===================================
// ChemHelper Project
// ===================================
//   ����ģ����������
//

#include "equation.h"
#include "chemcalc.h"
#include "misc.h"
int main() {
	using namespace std;
	cout << "ChemHelper ����ƽ̨" << endl;

	cout  << ">>> "; 
	string userInput;			// ��ȡ�û����� 
	getline(cin, userInput);
	
	RMDatabase database;
	database.loadDataDefault();
	
	Equation equTest;
	equTest.parseEquation(userInput);
	
//	for (auto itemReactant : equTest.reactant) {
//		cout << "[��ѧʽ]:"			<< itemReactant.first.strRaw << endl; 
//		cout << "[��ѧ������]:"		<< itemReactant.second << endl;
//		cout << "[��Է�������]:"	<<  "  ";
//		cout << itemReactant.first.getMolarMass(&database).numMin;
//		cout << " ~ ";
//		cout << itemReactant.first.getMolarMass(&database).numMax;
//		cout << " (";
//		cout << itemReactant.first.getMolarMass(&database).numInner;
//		cout << ") " << endl << endl;
//	}
//	
//	for (auto itemProduct : equTest.product) {
//		cout << "[��ѧʽ]:"			<< itemProduct.first.strRaw << endl; 
//		cout << "[��ѧ������]:"		<< itemProduct.second << endl;
//		cout << "[��Է�������]:" 	<< "  ";
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
