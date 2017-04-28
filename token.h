#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class token{
	private: 
		string userId;
		string toke;
		float idValue;
		float num;
	public:
		token(string id, string token);
		token(float number, string token);
		token(string token);
		float getIdVal(){return idValue;}
		float getnumVal(){return num;}
		string getTokenString(){return toke;}
		void getTokens(ifstream &);
};

#endif
