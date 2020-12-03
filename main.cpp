#include "factory.hpp"
#include "base.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main(int argc, char** argv) {
	Factory fact = Factory(); 
	argv++;
	argc--;
	bool check = false; 
	bool power = false;   
	bool countIsOdd = true; 
	for(int i = 0; i < argc; ++i){
		if(*argv[i] == '*' && *argv[i+1] == '*'){
			if(power == false) {
				power = true;
				countIsOdd = false; 		 
			}
			else{ 
				power = false;
				countIsOdd = true; 
			} 
			++i; 
		} 
		if(power == false && (i%2 == 0) && (*argv[i] > 57 || *argv[i] < 48)){check = true;}
		if(power == true){
			if((i%2 == 1) && (*argv[i] > 57 || *argv[i] < 48)){
				check = true;
				//power = false;  
			}
		} 
	//	cout << *argv[i] << endl; 	
	}
	
	//if(countIsOdd == true && argc%2 == 0)
	
	if(argc < 3 || check == true || (countIsOdd == true && argc%2 == 0) || (countIsOdd == false && argc%2 == 1)){cout << "Error - incorrect input" << endl;}
	else{   
	Base* base = fact.parse(argv, argc);
        cout << base->evaluate() << " = " << base->stringify() << endl;  
	}
	
	//system("clear"); 
	//cout << "we cleared the screen" << endl;
	//cout << "some more things " << endl;  
}
