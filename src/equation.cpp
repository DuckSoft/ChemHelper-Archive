#include "equation.h"

Equation::Equation() {
	// 空壳放在这

	cout << "[Equation] Object Initialized. " << endl;
}

void Equation::reset(){
	reactant.clear();
	product.clear();
}


void Equation::parseFormulaList(string strA, string strB) { // 分析化学方程式的反应物生成物列表 
	if (strA.empty() || strB.empty()) {	// 防止输入为空 
		throw MyException("Equation::parseFormulaList: 所输入的反应物或生成物为空");
		return;
	}
	
	cout << "Reactant List: " << strA << endl;
	{
		// 开始处理
		bool isStarting = true;	// 标志：是否是化学式的开头
		string strTempA;		// 系数存储
		string strTempB;		// 化学式存储
	
		for (auto i : strA) {		 
			if (isStarting == true) {	// 若为化学式的开头 
				if (('0' <= i) && (i <= '9')) { // 判定是否为数字 
					strTempA += i;				// 若为数字系数则加入到系数暂存器 
				} else {
					isStarting = false;	// 若非则表示数字部分结束
					
					if (strTempA.empty()){	// 处理没有系数的情况 
						strTempA = "1";		// 给没有系数的项添加系数"1" 
					}
					
					if (i == '+') {	// 防止开头就遇到"+"号的垃圾情况 
						throw MyException("Equation::parseFormulaList: 列表开头遇到空白项");
						return;
					} 
					
					strTempB += i;	// 将本个字符塞入化学式存储器 
				}
			} else {	// 若非化学式的开头 
				if (i == '+') {	// 若为"+"号 
					if (strTempB.empty() || strTempA.empty()) { // 防止化学式或系数为空时加入列表
						throw MyException("Equation::parseFormulaList: 列表内遇到空白项");
						return;
					} else {
						reactant.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//
//						cout << "[Debug Output]" << endl; 
//						cout << " Formula:   " << strTempB << endl;
//						cout << " Multiplier:" << strTempA << endl;
						
						// 初始化状态 
						strTempA.clear();
						strTempB.clear();
						isStarting = true;
					}
				} else {		// 若非"+"号 
					strTempB += i;	// 直接加入化学式缓冲 
				}
			}
		}
		// 循环后处理
		if (!(strTempA.empty() || strTempB.empty())) { // 若还有一个可用的化学式 
			reactant.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//
//			cout << "[Debug Output]" << endl; 
//			cout << " Formula:   " << strTempB << endl;
//			cout << " Multiplier:" << strTempA << endl;
			// 初始化状态 
			strTempA.clear();
			strTempB.clear();
			isStarting = true;
		}
	}
	cout << "Product List: " << strB << endl;
	{
		// 开始处理
		bool isStarting = true;	// 标志：是否是化学式的开头
		string strTempA;		// 系数存储
		string strTempB;		// 化学式存储
	
		for (auto i : strB) {		 
			if (isStarting == true) {	// 若为化学式的开头 
				if (('0' <= i) && (i <= '9')) { // 判定是否为数字 
					strTempA += i;				// 若为数字系数则加入到系数暂存器 
				} else {
					isStarting = false;	// 若非则表示数字部分结束
					
					if (strTempA.empty()){	// 处理没有系数的情况 
						strTempA = "1";		// 给没有系数的项添加系数"1" 
					}
					
					if (i == '+') {	// 防止开头就遇到"+"号的垃圾情况 
						throw MyException("Equation::parseFormulaList: 列表开头遇到空白项");
						return;
					} 
					
					strTempB += i;	// 将本个字符塞入化学式存储器 
				}
			} else {	// 若非化学式的开头 
				if (i == '+') {	// 若为"+"号 
					if (strTempB.empty() || strTempA.empty()) { // 防止化学式或系数为空时加入列表
						throw MyException("Equation::parseFormulaList: 列表内遇到空白项");
						return;
					} else {
						product.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//						cout << "[Debug Output]" << endl; 
//						cout << " Formula:   " << strTempB << endl;
//						cout << " Multiplier:" << strTempA << endl;
						// 初始化状态 
						strTempA.clear();
						strTempB.clear();
						isStarting = true;
					}
				} else {		// 若非"+"号 
					strTempB += i;	// 直接加入化学式缓冲 
				}
			}
		}
		// 循环后处理
		if (!(strTempA.empty() || strTempB.empty())) { // 若还有一个可用的化学式 
			product.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));

//			cout << "[Debug Output]" << endl; 
//			cout << " Formula:   " << strTempB << endl;
//			cout << " Multiplier:" << strTempA << endl;
			// 初始化状态 
			strTempA.clear();
			strTempB.clear();
			isStarting = true;
		}
	}
	
	// 处理完毕 
}

void Equation::parseEquation(string inStr) { // 分析输入的化学方程式 
	if (inStr.empty() == true) { // 防止输入为空 
		throw MyException("Equation::parseEquation: 输入的字符串是空的");
		return;
	}

	string partLeft, partRight;	// 反应物、生成物缓冲区 
	bool isRight = false;		// 是否到了生成物标志 
	bool bAuxFlag = false;		// 辅助标志
	 
	for (auto i : inStr) {
		if (i == '=' || i == '-') {	// 出现 = 或 - 符号时判定为反应物结束 
			isRight = true;
			if (bAuxFlag == true) {	// 若又出现一次分隔符，则判定为错误 
				throw MyException("Equation::parseEquation: 出现多于一个的反应物-生成物分隔符");
				return; 
			}
			continue;
		} else if (i == ' ' || i == '>') {	// 忽略掉 ---> 格式中的 > 字符以及空白字符
			continue;
		} else {
			if (isRight == true) {	// 若已到了生成物部分 
				bAuxFlag = true; 	// 设定辅助标志 
			}
		}
		
		if (isRight) {
			partRight += i;
		} else {
			partLeft += i;
		}
	}
	
	parseFormulaList(partLeft, partRight);
}
