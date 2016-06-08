// ===================================
// ChemHelper Project
// ===================================
//   带误差的数据计算
//
#include "advnum.h"

void AdvNum::setValue (double valueToSet) {
	numInner = numMax = numMin = valueToSet;
}

AdvNum::AdvNum() {													// 构造：0
	numInner = numMax = numMin = 0; 
} 

AdvNum::AdvNum(double numInit) {									// 构造：精确数
	numInner = numMax = numMin = numInit;
}

AdvNum::AdvNum(double numCenter, double numError) {					// 构造：中心数+误差 
	numInner = numCenter;
	numMin = numCenter - numError;
	numMax = numCenter + numError;
}  

AdvNum::AdvNum(double numCenter, double numInMin, double numInMax){	// 构造：中心数+最大最小数 
	numInner = numCenter;
	numMin = numInMin;
	numMax = numInMax;
}

AdvNum AdvNum::operator+ (AdvNum inNum) {	// 加法 
	return AdvNum(this->numInner + inNum.numInner, this->numMin + inNum.numMin, this->numMax + inNum.numMax);
}

AdvNum AdvNum::operator- (AdvNum inNum) {	// 减法 
	return AdvNum(this->numInner - inNum.numInner, this->numMin - inNum.numMax, this->numMax - inNum.numMin);
}

AdvNum AdvNum::operator* (AdvNum inNum) {	// 乘法 
	return AdvNum(this->numInner * inNum.numInner, this->numMin * inNum.numMin, this->numMax * inNum.numMax);
}

AdvNum AdvNum::operator/ (AdvNum inNum) {	// 除法 
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


