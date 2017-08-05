// ===================================
// ChemHelper Project
// ===================================
//   ���������ݼ���
//
#include "advnum.h"

void AdvNum::setValue (double valueToSet) {
	numInner = numMax = numMin = valueToSet;
}

AdvNum::AdvNum() {													// ���죺0
	numInner = numMax = numMin = 0; 
} 

AdvNum::AdvNum(double numInit) {									// ���죺��ȷ��
	numInner = numMax = numMin = numInit;
}

AdvNum::AdvNum(double numCenter, double numError) {					// ���죺������+��� 
	numInner = numCenter;
	numMin = numCenter - numError;
	numMax = numCenter + numError;
}  

AdvNum::AdvNum(double numCenter, double numInMin, double numInMax){	// ���죺������+�����С�� 
	numInner = numCenter;
	numMin = numInMin;
	numMax = numInMax;
}

AdvNum AdvNum::operator+ (AdvNum inNum) {	// �ӷ� 
	return AdvNum(this->numInner + inNum.numInner, this->numMin + inNum.numMin, this->numMax + inNum.numMax);
}

AdvNum AdvNum::operator- (AdvNum inNum) {	// ���� 
	return AdvNum(this->numInner - inNum.numInner, this->numMin - inNum.numMax, this->numMax - inNum.numMin);
}

AdvNum AdvNum::operator* (AdvNum inNum) {	// �˷� 
	return AdvNum(this->numInner * inNum.numInner, this->numMin * inNum.numMin, this->numMax * inNum.numMax);
}

AdvNum AdvNum::operator/ (AdvNum inNum) {	// ���� 
	return AdvNum(this->numInner / inNum.numInner, this->numMin / inNum.numMax, this->numMax / inNum.numMin);
}


AdvNum AdvNum::operator+ (double inDouble) {
	AdvNum result;
	result.numInner = this->numInner + inDouble;
	result.numMin = this->numMin + inDouble;
	result.numMax = this->numMax + inDouble;
	
	return result;
}

AdvNum AdvNum::operator- (double inDouble) {
	AdvNum result;
	result.numInner = this->numInner - inDouble;
	result.numMin = this->numMin - inDouble;
	result.numMax = this->numMax - inDouble;
	
	return result;
}

AdvNum AdvNum::operator* (double inDouble) {
	AdvNum result;
	result.numInner = this->numInner * inDouble;
	result.numMin = this->numMin * inDouble;
	result.numMax = this->numMax * inDouble;
	
	return result;
}

AdvNum AdvNum::operator/ (double inDouble) {
	AdvNum result;
	result.numInner = this->numInner / inDouble;
	result.numMin = this->numMin / inDouble;
	result.numMax = this->numMax / inDouble;
	
	return result;
}


void AdvNum::centerize() {
	numInner = (numMax + numMin) / 2; 
} 

double AdvNum::getCentricNumber() {
	return (numMax + numMin) / 2;
}


