#include "factory.hpp"
#include "base.hpp"
#include <iostream>

using namespace std; 

int main(int argc, char** argv) {
	Factory fact = Factory(); 
	Base* base = fact.parse(argv, argc); 
	cout << base->evaluate() << " = " << base->stringify() << endl;  

}
