// ===================================
// ChemHelper Project
// ===================================
//   化学式抽象
//

#include "formula.h"

 
Formula::Formula(string inFormula) {
	strRaw = inFormula;
	parseSubstring(inFormula, atoms, 1);
}

void Formula::showAtomList() {
	cout << "Formula::showAtomList: Output: " << endl;
	for (auto it : atoms) {
		cout << it.first << " - " << it.second << "  "; 
	}
	cout << endl;
}

AdvNum Formula::getMolarMass(RMDatabase* databaseFrom) {
	AdvNum MolarMass = 0;
	
	for (auto it : atoms) {
		MolarMass = MolarMass + (databaseFrom->queryAtom(it.first) * AdvNum(it.second));	 
	}
	
	return MolarMass;
} 

void Formula::insertList(AtomListMap& listToInsert, str_uint_pair pairToInsert) {
	listToInsert[pairToInsert.first] = listToInsert[pairToInsert.first] + pairToInsert.second;  
	// TODO: 插入算法 
}

void Formula::combineList(AtomListMap& listParent, AtomListMap& listChild) {	// 合并亲子表 
	// TODO: 合并算法 

	for (auto it : listChild) {
		insertList(listParent, make_pair(it.first, it.second)); 
	} 
	return;
}

void Formula::parseSubstring(string& strTodo, AtomListMap& parentList, unsigned int numMultiplier) {
	map<string, unsigned int> thisList;	// 本程序段的原子列表 
	
	smatch sm;				// 正则结果 
	regex e("^([A-Z][a-z]*)(\\d*)");	// 原子匹配正则
	regex f("\\*(\\d*)([^*]+)[\\*]??");	// 段分隔符"*"匹配 
	regex g("\\(([^\\*]*)\\)(\\d*)");		// 括号匹配#1
	regex h("\\(([^\\*\\(]*)\\)(\\d*)");	// 括号匹配#2
		
//	cout << "Layer: " << strTodo << " # "<<numMultiplier << endl;
	while(!strTodo.empty()) {	// 非空则一直循环 

		regex_search(strTodo, sm, e);	// 找一坨原子 
										// sm[1]: 原子名称
										// sm[2]: 原子数量(有可能为空白)
		
		if ( !sm[1].length() == 0 ) {	// 若成功提取出原子
			unsigned int tempNum;
			if (sm[2].length() == 0) {	// 若没有下标 
				tempNum = 1 * numMultiplier;	// 默认下标为1 
			} else {	// 有下标
				tempNum = str2uint(sm[2]) * numMultiplier; 
			}
			
//			cout << sm[1] << " - " << tempNum << endl;
 			
 			string tempStr = sm[1];
 			
			insertList(thisList, make_pair(tempStr, tempNum));	// 交给插入算法处理
			strTodo.erase(0, sm[0].length()); // 吃掉原有字符串 
		} else if (strTodo[0] == '*') {	// 又来一段 
			regex_search(strTodo, sm, f);	// 找段
			 								// sm[1]: 段乘数
											// sm[2]: 段内容
//			cout << sm[0] << endl;
//			cout << sm[1] << endl;
//			cout << sm[2] << endl;

			if ( sm[2].length() != 0) {
				unsigned int tempNum;
				if(sm[1].length() == 0) {
					tempNum = 1;
				} else {
					tempNum = str2uint(sm[1]);
				}

				string strTemp = sm[2]; 
				strTodo.erase(0, sm[0].length());
				parseSubstring(strTemp, thisList, tempNum);
			} else {
				// TODO: 空段的处理 
			} 
		} else if (strTodo[0] == '(') {
			// TODO: 括号的处理
			
			int intCounter = 0;	// 第一次出现后半括号前 前半括号出现的次数 
			for (auto ch : strTodo) {
				if (intCounter > 2)
					break;
				switch (ch) {
					case '(': intCounter++; break;
					case ')': break;
					case '*': break;
				}
			}
			
			if (intCounter == 1) {	// 仅仅出现了一次，说明在内层 
				regex_search(strTodo, sm, h);
				
				if ( sm[1].length() != 0) {
					unsigned int tempNum;
					
					if (sm[2].length() == 0) {
						tempNum = 1 * numMultiplier;
					} else {
						tempNum = str2uint(sm[2]) * numMultiplier;
					}
					
					string strTemp = sm[1];
					strTodo.erase(0, sm[0].length()); 
					parseSubstring(strTemp, thisList, tempNum);
					
				} else {
					
				}
			} else if (intCounter == 2) {	// 出现了不止一次，说明在外层 
				regex_search(strTodo, sm, g);
				
//				cout << sm[0] << endl;

				unsigned int tempNum;
				
				if (sm[2].length() == 0) {
					tempNum = 1 * numMultiplier;
				} else {
					tempNum = str2uint(sm[2]) * numMultiplier;
				}
				
				string strTemp = sm[1];	
				strTodo.erase(0, sm[0].length()); 
				parseSubstring(strTemp, thisList, tempNum);
			} 
		} else {
			cout << "unprocessed char:" << strTodo[0] << endl;
			system("pause");
		}
	}

	combineList(parentList, thisList);	// 合并亲子表
}
