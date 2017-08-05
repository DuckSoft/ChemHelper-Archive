// ===================================
// ChemHelper Project
// ===================================
//   ��ѧʽ����
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
	// TODO: �����㷨 
}

void Formula::combineList(AtomListMap& listParent, AtomListMap& listChild) {	// �ϲ����ӱ� 
	// TODO: �ϲ��㷨 

	for (auto it : listChild) {
		insertList(listParent, make_pair(it.first, it.second)); 
	} 
	return;
}

void Formula::parseSubstring(string& strTodo, AtomListMap& parentList, unsigned int numMultiplier) {
	map<string, unsigned int> thisList;	// ������ε�ԭ���б� 
	
	smatch sm;				// ������ 
	regex e("^([A-Z][a-z]*)(\\d*)");	// ԭ��ƥ������
	regex f("\\*(\\d*)([^*]+)[\\*]??");	// �ηָ���"*"ƥ�� 
	regex g("\\(([^\\*]*)\\)(\\d*)");		// ����ƥ��#1
	regex h("\\(([^\\*\\(]*)\\)(\\d*)");	// ����ƥ��#2
		
//	cout << "Layer: " << strTodo << " # "<<numMultiplier << endl;
	while(!strTodo.empty()) {	// �ǿ���һֱѭ�� 

		regex_search(strTodo, sm, e);	// ��һ��ԭ�� 
										// sm[1]: ԭ������
										// sm[2]: ԭ������(�п���Ϊ�հ�)
		
		if ( !sm[1].length() == 0 ) {	// ���ɹ���ȡ��ԭ��
			unsigned int tempNum;
			if (sm[2].length() == 0) {	// ��û���±� 
				tempNum = 1 * numMultiplier;	// Ĭ���±�Ϊ1 
			} else {	// ���±�
				tempNum = str2uint(sm[2]) * numMultiplier; 
			}
			
//			cout << sm[1] << " - " << tempNum << endl;
 			
 			string tempStr = sm[1];
 			
			insertList(thisList, make_pair(tempStr, tempNum));	// ���������㷨����
			strTodo.erase(0, sm[0].length()); // �Ե�ԭ���ַ��� 
		} else if (strTodo[0] == '*') {	// ����һ�� 
			regex_search(strTodo, sm, f);	// �Ҷ�
			 								// sm[1]: �γ���
											// sm[2]: ������
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
				// TODO: �նεĴ��� 
			} 
		} else if (strTodo[0] == '(') {
			// TODO: ���ŵĴ���
			
			int intCounter = 0;	// ��һ�γ��ֺ������ǰ ǰ�����ų��ֵĴ��� 
			for (auto ch : strTodo) {
				if (intCounter > 2)
					break;
				switch (ch) {
					case '(': intCounter++; break;
					case ')': break;
					case '*': break;
				}
			}
			
			if (intCounter == 1) {	// ����������һ�Σ�˵�����ڲ� 
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
			} else if (intCounter == 2) {	// �����˲�ֹһ�Σ�˵������� 
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

	combineList(parentList, thisList);	// �ϲ����ӱ�
}
