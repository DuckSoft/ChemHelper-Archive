#include "equation.h"

Equation::Equation() {
	// �տǷ�����

	cout << "[Equation] Object Initialized. " << endl;
}

void Equation::reset(){
	reactant.clear();
	product.clear();
}


void Equation::parseFormulaList(string strA, string strB) { // ������ѧ����ʽ�ķ�Ӧ���������б� 
	if (strA.empty() || strB.empty()) {	// ��ֹ����Ϊ�� 
		throw MyException("Equation::parseFormulaList: ������ķ�Ӧ���������Ϊ��");
		return;
	}
	
	cout << "Reactant List: " << strA << endl;
	{
		// ��ʼ����
		bool isStarting = true;	// ��־���Ƿ��ǻ�ѧʽ�Ŀ�ͷ
		string strTempA;		// ϵ���洢
		string strTempB;		// ��ѧʽ�洢
	
		for (auto i : strA) {		 
			if (isStarting == true) {	// ��Ϊ��ѧʽ�Ŀ�ͷ 
				if (('0' <= i) && (i <= '9')) { // �ж��Ƿ�Ϊ���� 
					strTempA += i;				// ��Ϊ����ϵ������뵽ϵ���ݴ��� 
				} else {
					isStarting = false;	// �������ʾ���ֲ��ֽ���
					
					if (strTempA.empty()){	// ����û��ϵ������� 
						strTempA = "1";		// ��û��ϵ���������ϵ��"1" 
					}
					
					if (i == '+') {	// ��ֹ��ͷ������"+"�ŵ�������� 
						throw MyException("Equation::parseFormulaList: �б�ͷ�����հ���");
						return;
					} 
					
					strTempB += i;	// �������ַ����뻯ѧʽ�洢�� 
				}
			} else {	// ���ǻ�ѧʽ�Ŀ�ͷ 
				if (i == '+') {	// ��Ϊ"+"�� 
					if (strTempB.empty() || strTempA.empty()) { // ��ֹ��ѧʽ��ϵ��Ϊ��ʱ�����б�
						throw MyException("Equation::parseFormulaList: �б��������հ���");
						return;
					} else {
						reactant.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//
//						cout << "[Debug Output]" << endl; 
//						cout << " Formula:   " << strTempB << endl;
//						cout << " Multiplier:" << strTempA << endl;
						
						// ��ʼ��״̬ 
						strTempA.clear();
						strTempB.clear();
						isStarting = true;
					}
				} else {		// ����"+"�� 
					strTempB += i;	// ֱ�Ӽ��뻯ѧʽ���� 
				}
			}
		}
		// ѭ������
		if (!(strTempA.empty() || strTempB.empty())) { // ������һ�����õĻ�ѧʽ 
			reactant.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//
//			cout << "[Debug Output]" << endl; 
//			cout << " Formula:   " << strTempB << endl;
//			cout << " Multiplier:" << strTempA << endl;
			// ��ʼ��״̬ 
			strTempA.clear();
			strTempB.clear();
			isStarting = true;
		}
	}
	cout << "Product List: " << strB << endl;
	{
		// ��ʼ����
		bool isStarting = true;	// ��־���Ƿ��ǻ�ѧʽ�Ŀ�ͷ
		string strTempA;		// ϵ���洢
		string strTempB;		// ��ѧʽ�洢
	
		for (auto i : strB) {		 
			if (isStarting == true) {	// ��Ϊ��ѧʽ�Ŀ�ͷ 
				if (('0' <= i) && (i <= '9')) { // �ж��Ƿ�Ϊ���� 
					strTempA += i;				// ��Ϊ����ϵ������뵽ϵ���ݴ��� 
				} else {
					isStarting = false;	// �������ʾ���ֲ��ֽ���
					
					if (strTempA.empty()){	// ����û��ϵ������� 
						strTempA = "1";		// ��û��ϵ���������ϵ��"1" 
					}
					
					if (i == '+') {	// ��ֹ��ͷ������"+"�ŵ�������� 
						throw MyException("Equation::parseFormulaList: �б�ͷ�����հ���");
						return;
					} 
					
					strTempB += i;	// �������ַ����뻯ѧʽ�洢�� 
				}
			} else {	// ���ǻ�ѧʽ�Ŀ�ͷ 
				if (i == '+') {	// ��Ϊ"+"�� 
					if (strTempB.empty() || strTempA.empty()) { // ��ֹ��ѧʽ��ϵ��Ϊ��ʱ�����б�
						throw MyException("Equation::parseFormulaList: �б��������հ���");
						return;
					} else {
						product.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));
//						cout << "[Debug Output]" << endl; 
//						cout << " Formula:   " << strTempB << endl;
//						cout << " Multiplier:" << strTempA << endl;
						// ��ʼ��״̬ 
						strTempA.clear();
						strTempB.clear();
						isStarting = true;
					}
				} else {		// ����"+"�� 
					strTempB += i;	// ֱ�Ӽ��뻯ѧʽ���� 
				}
			}
		}
		// ѭ������
		if (!(strTempA.empty() || strTempB.empty())) { // ������һ�����õĻ�ѧʽ 
			product.push_back(make_pair(Formula(strTempB), str2uint(strTempA)));

//			cout << "[Debug Output]" << endl; 
//			cout << " Formula:   " << strTempB << endl;
//			cout << " Multiplier:" << strTempA << endl;
			// ��ʼ��״̬ 
			strTempA.clear();
			strTempB.clear();
			isStarting = true;
		}
	}
	
	// ������� 
}

void Equation::parseEquation(string inStr) { // ��������Ļ�ѧ����ʽ 
	if (inStr.empty() == true) { // ��ֹ����Ϊ�� 
		throw MyException("Equation::parseEquation: ������ַ����ǿյ�");
		return;
	}

	string partLeft, partRight;	// ��Ӧ������ﻺ���� 
	bool isRight = false;		// �Ƿ����������־ 
	bool bAuxFlag = false;		// ������־
	 
	for (auto i : inStr) {
		if (i == '=' || i == '-') {	// ���� = �� - ����ʱ�ж�Ϊ��Ӧ����� 
			isRight = true;
			if (bAuxFlag == true) {	// ���ֳ���һ�ηָ��������ж�Ϊ���� 
				throw MyException("Equation::parseEquation: ���ֶ���һ���ķ�Ӧ��-������ָ���");
				return; 
			}
			continue;
		} else if (i == ' ' || i == '>') {	// ���Ե� ---> ��ʽ�е� > �ַ��Լ��հ��ַ�
			continue;
		} else {
			if (isRight == true) {	// ���ѵ��������ﲿ�� 
				bAuxFlag = true; 	// �趨������־ 
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
