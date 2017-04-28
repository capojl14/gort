#include "token.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include "parse.h"


using namespace std;

vector <token> tokeArr;
unordered_map<string, float> hashMap;

token::token(string id, string token){ //constructor for user id
	userId = id;
	toke = token;
	idValue = 0;	
}

token::token(float number, string token){ //constructor for numbers
	num = number;
	toke = token;
}

token::token(string token){
	toke = token;
}


void token::getTokens(ifstream & ifs){
	int state = 0;
	float digit;
	char ch;
	bool flag = false;
	string udv;
	string dig;
	string printString = "print";
	do{
		
		ifs.get(ch);
		while(ch == ' '){  //ignore whitespace
			ifs.get(ch);
		} 
		int c = ifs.peek();
		if (c == EOF) {
			flag = true;
		}
		else {
			flag = false;
		}
		switch(state){ 
			case 0:
				if(ch == '('){
				  token current("lparen");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(ch == ')'){
				  token current("rparen");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(ch == '+'){
				  token current("add");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(isalpha(ch)){
				  udv += ch;
				  state = 13;
				  break;
				}
				else if(ch == '/'){
				  token current("divide");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(ch == '='){
				  token current("assign");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(ch == ';'){
				  token current("semi");
				  tokeArr.push_back(current);
				  state = 0;
				  break;
				}
				else if(ch == '*'){
				  state = 7;
				  break;
				}
				else if(isdigit(ch)){
				  dig += ch;
				  state = 9;
				  break;
				}
				else if(ch == '-'){
					token old  = tokeArr.front();
				  if(old.getTokenString() == "id" || old.getTokenString() == "rparen" || old.getTokenString() == "number"){ //subtraction case
					token current("subtract");
					tokeArr.push_back(current);
					state = 0;
					break;
				  }
				  else{
					state = 10;
					dig += ch;
					break;
				  }
			  
				}

				else if(ch == '.'){
				  state = 12;
				  dig += ch;
				  break;
				}
				
			case 1://lparen
			case 2://rparen
			case 3://add
			case 4://divide
			case 5://assign
			case 6://semi
			  break;
			case 7:
			  if(ch == '*'){
				token current("exponent");
				tokeArr.push_back(current);
				state = 0;
				break;
			  }
			  else{
				ifs.unget();
				token current("multiply");
				tokeArr.push_back(current);
				state = 0;
				break;
			  }
			  
			case 8:
			  cerr << "Case error\n";
			  exit(3);
			  
			case 9:
			  if(isdigit(ch)){
				state = 10;
				dig += ch;
				break;
			  }
			  else if(ch == '.'){
				dig += ch;
				state = 11;
				break;
			  }
			  else{
				ifs.unget();
				digit = stof(dig);
				token current(digit, "number");
				tokeArr.push_back(current);
				state = 0;
				dig.clear();
				break;
			  }
			case 10:
			  if(isdigit(ch)){
				dig += ch;
				state = 10;
				break;

			  }
			  else if(ch == '.'){
				dig += ch;
				state = 11;
				break;
			  }
			  else{
				ifs.unget();
				digit = stof(dig);
				token current(digit, "number");
				tokeArr.push_back(current);
				state = 0;
				dig.clear();
				break;
			  }
			case 11:
			  if(isdigit(ch)){
				dig += ch;
				state = 12;
				break;
			  }
			  else{
				ifs.unget();
				digit = stof(dig);
				token current(digit, "number");
				tokeArr.push_back(current);
				state = 0;
				dig.clear();
				break;
			  }
			case 12:
			  if(isdigit(ch)){
				dig += ch;
				state = 12;
				break;
			  }
			  else if(!isdigit(ch)){
				ifs.unget();
				digit = stof(dig);
				token current(digit, "number");
				tokeArr.push_back(current);
				state = 0;
				dig.clear();
				break;
			  }
			 
			  else{
				cerr << "Lexical error\n";
				exit(3);
			  }
			case 13:
			  if(isalpha(ch) | ch == '_'){
				udv += ch;
				state = 13;
				break;
			  }
			  else{
				ifs.unget();
				
				if((strcmp(udv.c_str(), printString.c_str())) == 0){
				  token current("print");
				  tokeArr.push_back(current);
				  state = 0;
				  udv.clear();
				  break;
				}
				else{
					token current(udv, "id");
					tokeArr.push_back(current);
					hashMap.emplace(udv, 0); //push with no value until parsed
					state = 0;
					udv.clear();
					break;
				}   
				        
			  }
		
		   }
      
	}while(!flag);	
	parse parseObj(&hashMap, &tokeArr);
	
  }//end function

