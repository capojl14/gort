#include <string>
#include <math.h>
#include <stdio>

using namespace std;

float attribute::eval(string action, float num1, float num2){
	
	bool expFlag;
	char evalChar;
	if(strcmp(action.c_str(),"**") == 0){
		evalChar = 'e';
	}
	if (strcmp(action.c_str(), "print") == 0){
		evalChar = 'p';
	}
	else{
		evalChar = action[0];
	}
	
	switch (evalChar){
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '+':
			return num1 + num2;
		case '/':
			return num1/num2;
		case 'p':
			cout << num1;
			return -1; //MAKE SURE TO CATCH ON OTHER END
		
		case 'e':
			return pow(num1, num2);
	}
}

