#include "misc.h"

double str2double(std::string str){
	using namespace std;
	
	istringstream iss(str);  
	double x;  
	if (iss >> x)  
		return x;  
	return 0.0; //TODO: 异常处理
} 

unsigned int str2uint(std::string str) {
	using namespace std;
	
	istringstream iss(str);  
	unsigned int x;  
	if (iss >> x)  
		return x;  
	return 0; //TODO: 异常处理 
}
