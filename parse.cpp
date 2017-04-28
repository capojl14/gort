#include <string.h>
#include <iostream>
#include <cstdlib>
#include "parse.h"
#include <vector>
#include <unordered_map>
#include <string.h>

#define MAX_TOKE 280

using namespace std;

void parse::P(unordered_map <string,float> * hashBrown, vector <token> * copyArr){
	if(currentToke == "id" || currentToke == "print"){ 
		S(hashBrown, copyArr);
		P(hashBrown, copyArr);
	}
	else if(currentToke == "nomore"){
		//Epsilon production-->do nothing
	}
	else{
		cerr << "Error on production P()";
		exit(3);
	}
	
}
void parse::S(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "id" ){
		match(currentToke, "id", copyArr);
		if(match(currentToke, "=", copyArr));
		else{
			cerr << "Match failed on S()";
			exit(3);
		}
		E(hashBrown, copyArr);
		match(currentToke, ";", copyArr);
	}
	else if(currentToke == "print"){
		match(currentToke, "print", copyArr);
		if(match(currentToke, ";", copyArr));
		else{
			cerr << "Match failed on S()";
			exit(3);
		}
	}
	else{
		cerr << "Error on production S()";
		exit(3);
	}
}
void parse::E(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "id" || currentToke == "number" || currentToke == "lparen"){
		T(hashBrown, copyArr);
		E_prime(hashBrown, copyArr);
	}
	else{
		cerr << "Error on production E()";
		exit(3);
	}
	
}
void parse::T(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "id" || currentToke == "number" || currentToke == "lparen"){
		F(hashBrown, copyArr);
		T_prime(hashBrown, copyArr);
	}
	else{
		cerr << "Error on production T()";
		exit(3);
	}
}
void parse::E_prime(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "add"){
		if(match(currentToke, "add", copyArr));
		else{
			cerr << "Match failed on E_prime()";
			exit(3);
		}
		T(hashBrown, copyArr);
		E_prime(hashBrown, copyArr);
	}
	else if(currentToke == "subtract"){
		if(match(currentToke, "subtract", copyArr));
		else{
			cerr << "Match failed on E_prime()";
			exit(3);
		}
		T(hashBrown, copyArr);
		E_prime(hashBrown, copyArr);
	}
	else if(currentToke == "rparen" || currentToke == "semi"){
		//Epsilon production --> do nothing
	}
	else{
		cerr << "Error on production E_prime()";
		exit(3);
	}
	
	
}
void parse::F(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if (currentToke == "lparen" || currentToke == "id" || currentToke == "number"){
		X(hashBrown, copyArr);
		F_prime(hashBrown, copyArr);
	}
	else{
		cerr << "Error on production F()";
		exit(3);
	}
}
void parse::T_prime(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "multiply"){
		if(match(currentToke, "multiply", copyArr));
		else{
			cerr << "Match failed on T_prime()";
			exit(3);
		}
		F(hashBrown, copyArr);
		T_prime(hashBrown, copyArr);
	}
	else if(currentToke == "divide"){
		if(match(currentToke,"multiply", copyArr));
		else{
			cerr << "Match failed on T_prime()";
			exit(3);
		}
		F(hashBrown, copyArr);
		T_prime(hashBrown, copyArr);
	}
	else if(currentToke == "add" || currentToke == "subtract" || currentToke == "rparen" || currentToke == "semi"){
		//Epsilon production-->do nothing
	}
	else{
		cerr << "Error on production T_prime()";
		exit(3);
	}
}
void parse::F_prime(unordered_map <string,float> * hashBrown,  vector <token> * copyArr){
	if(currentToke == "exponent"){
		if(match(currentToke, "exponent", copyArr));
		else{
			cerr << "Match failed on F_prime()";
			exit(3);
		}
		X(hashBrown, copyArr);
		F_prime(hashBrown, copyArr);
	}
	else if(currentToke == "add" || currentToke == "subtract" || currentToke == "rparen" || currentToke == "semi" ||
	currentToke == "multiply" || currentToke == "divide"){
		//Epsilon production-->do nothing
	}
	else{
		cerr << "Error on production F_prime()";
		exit(3);
	}
}
void parse::X(unordered_map <string,float> * hashBrown, vector <token> * copyArr){
	if(currentToke == "lparen"){
		match(currentToke, "lparen", copyArr);
		E(hashBrown, copyArr);
		if(match(currentToke, "rparen", copyArr));
		else{
			cerr << "Match failed on X()";
			exit(3);
		}
	}
	else if (currentToke == "id"){
		//Do nothing-->match not really needed
	}
	else if(currentToke == "number"){
		//Do nothing -->match not really needed
	}
		
}

