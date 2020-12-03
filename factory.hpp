#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "sub.hpp"
#include "add.hpp"  
#include "div.hpp"
#include "pow.hpp"
#include "mult.hpp" 
#include <string> 
#include <ctype.h>
#include <cctype>
#include <cstring>
#include "op.hpp"
#include <iostream>

using namespace std;

class Factory{

private: 
	
        Base* operandOne; 
	Base* operandTwo;
 	Base* combination; 
	Base* combinationTwo;  
	char op; 
public: 

	Factory(){};
	Base* parse(char** input, int length){
	     bool change = false;
	     int i = 0;
     	     operandOne = new Op(*input[0] - '0');
	     op = *input[1];
	     operandTwo = new Op(*input[2] - '0');
	     if(op == '+'){
                    combination = new Add(operandOne, operandTwo);
             }

              if(op == '-'){
                     combination = new Sub(operandOne, operandTwo); 
             } 

               if(op == '/'){
                      combination = new Div(operandOne, operandTwo); 
             }

	     if(op == '*'){
                   if(*input[2] == '*'){
                       combination = new Pow(operandOne, new Op(*input[3] - '0'));
		       change = true; 
                   }
                   else
                       combination = new Mult(operandOne, operandTwo);
              }
	      if(change == true) {i = 1;}
  
             if(length > 3){    
		for(i = i + 3; i < length; i+=2){
			   op = *input[i];
		  	   if(op == '+'){
				combinationTwo = new Add(combination, new Op(*input[i+1] - '0')); 	
			   }

			   if(op == '-'){
				combinationTwo = new Sub(combination, new Op(*input[i+1] - '0'));
			   } 

			   if(op == '/'){
			        combinationTwo = new Div(combination, new Op(*input[i+1] - '0')); 
			   }

			   if(op == '*'){
				if(*input[i+1] == '*'){
				  ++i; 
				  combinationTwo = new Pow(combination, new Op(*input[i+1] - '0'));   
				}
				else
                                   combinationTwo = new Mult(combination, new Op(*input[i+1] - '0'));
			   }
			   combination = combinationTwo; 
			}
		}
	        return combination; 
       	}
};


#endif	
