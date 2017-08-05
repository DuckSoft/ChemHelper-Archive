// ===================================
// ChemHelper Project
// ===================================
//   ���������ݼ���

// TODO: ���Ƽ����㷨

#ifndef _5625ED5085F47D3B6779A525B4F9A7C6
#define _5625ED5085F47D3B6779A525B4F9A7C6
#include <iostream>
class AdvNum {
	public:
		double numInner;	// �ڲ�double 
		double numMax;		// ����� 
		double numMin;		// ��С�� 
		
		// ���캯��ϵ�� 
		AdvNum();	// 0 
		AdvNum(double numInit); // ��ͨ��
		AdvNum(double numCenter, double numError);	// �ֶ�ָ����� 
		AdvNum(double numCenter, double numInMin, double numInMax); // �ֶ�ָ�������С 
		
		void setValue (double valueToSet);
		
		// �Ӽ��˳��������� 
		AdvNum operator+ (AdvNum inNum);
		AdvNum operator- (AdvNum inNum);
		AdvNum operator* (AdvNum inNum);
		AdvNum operator/ (AdvNum inNum);

		AdvNum operator+ (double inDouble);
		AdvNum operator- (double inDouble);
		AdvNum operator* (double inDouble);
		AdvNum operator/ (double inDouble);
		

		// ���ϵ��
		void centerize();	// ���Ļ� 
		double getCentricNumber(); 

};
#endif
