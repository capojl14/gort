#ifndef PARSE_H
#define PARSE_H 

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>
#include "token.h"
#include <cstring>

using namespace std;

class parse{
	
	public:
		
		string currentToke;
		unordered_map <string,float> *hashBrown;
		parse(unordered_map <string,float> * hash,  vector <token> * copyArr){		
			hashBrown = hash;
			currentToke = getNextToke(copyArr);
			P(hashBrown, copyArr);
		}
		
		string getNextToke( vector <token> * copyArr){
			static int i = 0;
			return copyArr->front().getTokenString();
		}
		bool match(string current, string expect,  vector <token> * copyArr){
			if((strcmp(current.c_str(), expect.c_str())) == 0){
				currentToke = getNextToke(copyArr);
				return true;
			}
			
		return false;
		}
		void S(unordered_map <string,float> *,  vector <token> * copyArr);
		void P(unordered_map <string,float> *,  vector <token> * copyArr);
		void E(unordered_map <string,float> *,  vector <token> * copyArr);
		void E_prime(unordered_map <string,float> *,  vector <token> * copyArr);
		void T(unordered_map <string,float> *,  vector <token> * copyArr);
		void T_prime(unordered_map <string,float> *,  vector <token> * copyArr);
		void F(unordered_map <string,float> *,  vector <token> * copyArr);
		void F_prime(unordered_map <string,float> *,  vector <token> * copyArr);
		void X(unordered_map <string,float> *,  vector <token> * copyArr);

};

#endif
