#include "factory.hpp"
#include "base.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main(int argc, char** argv) {
	Factory fact = Factory(); 
	argv++;
	argc--;   
	Base* base = fact.parse(argv, argc);
	cout << base->evaluate() << " = " << base->stringify() << endl;  
	//system("clear"); 
	//cout << "we cleared the screen" << endl;
	//cout << "some more things " << endl;  
}
