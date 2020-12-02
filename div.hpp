#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string> 

class Div : public Base{
	public: 
		Div(Base* one, Base* two){
			val_1 = one; 
			val_2 = two; 
			div = 0; 
		}

		virtual double evaluate(){
			double val = val_1->evaluate(); 
			double val2 = val_2->evaluate(); 
			if(val2 == 0) {
			   //std::cout << "Cannot divide by zero"; 
			   //return 0;
			}
			div = val/val2;
			return div;  
		}

		virtual std::string stringify(){
			str += val_1->stringify(); 
			str += "/"; 
			str += val_2->stringify(); 
			return str; 
		}
	private:
		Base* val_1; 
		Base* val_2; 
		double div;
		std::string str;  
};

#endif
