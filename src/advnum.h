// ===================================
// ChemHelper Project
// ===================================
//   带误差的数据计算

// TODO: 完善计算算法

#ifndef _5625ED5085F47D3B6779A525B4F9A7C6
#define _5625ED5085F47D3B6779A525B4F9A7C6
#include <iostream>
class AdvNum {
	public:
		double numInner;	// 内部double 
		double numMax;		// 最大数 
		double numMin;		// 最小数 
		
		// 构造函数系列 
		AdvNum();	// 0 
		AdvNum(double numInit); // 普通数
		AdvNum(double numCenter, double numError);	// 手动指定误差 
		AdvNum(double numCenter, double numInMin, double numInMax); // 手动指定最大最小 
		
		void setValue (double valueToSet);
		
		// 加减乘除四则运算 
		AdvNum operator+ (AdvNum inNum);
		AdvNum operator- (AdvNum inNum);
		AdvNum operator* (AdvNum inNum);
		AdvNum operator/ (AdvNum inNum);

		AdvNum operator+ (double inDouble);
		AdvNum operator- (double inDouble);
		AdvNum operator* (double inDouble);
		AdvNum operator/ (double inDouble);
		

		// 误差系列
		void centerize();	// 中心化 
		double getCentricNumber(); 

};
#endif
