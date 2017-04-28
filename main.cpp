#include "token.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#define MAX_TOKE 250

using namespace std;


int main(int argc, char * argv []){

    token toke("NULL");
    
    if(argc < 2){
        cerr << "File argument not specified\n";
        exit(3);} 

    ifstream myfile (argv[1]);
    
	if (myfile.fail()){
		cout << "Unable to open file"; 
		exit(3);
	}
	toke.getTokens(myfile);
    myfile.close();
}
