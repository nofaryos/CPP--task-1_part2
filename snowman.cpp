#include "snowman.hpp"
#include <stdexcept>
#include <array>


namespace ariel{
	const int partion_num = 10;
	const int options = 4;
	const int smallest_option = 11111111;
	const int biggest_option = 44444444;
	const int iteams = 8;
	const int first_option = 1;
	const int last_option = 4;
	const int h = 0;
	const int n = 1;
	const int l_e = 2;
	const int r_e = 3;
	const int l_a = 4;
	const int r_a = 5;
	const int t = 6;
	const int b = 7;
	
	
	string snowman(int input){
		//input tests
		if(input < smallest_option || biggest_option < input){
			throw std:: logic_error{"invalid number"};
		}
		int input_check = input;
		int digit = 0;
		for(int i = 0 ; i < iteams; i++){
			digit = input_check % partion_num;
			if(digit < first_option || last_option < digit){
				throw std:: logic_error{"invalid number"};
			}
			input_check = input_check/partion_num;
		}
				
		//Assign an array for each item 
		std::array<std::string, options> hat_array = {" _===_","  ___ \n .....","   _  \n  /_\\ ","  ___ \n (_*_)"};
		std::array<std::string, options> nose_array = {",",".","_"," "};
		std::array<std::string, options> eye_array = {".", "o", "O","-"}; 
		std::array<std::string, options> leftArm_array = {"<", "\\", "/", " "};
		std::array<std::string, options> rightArm_array = {">", "/", "\\", " "};
		std::array<std::string, options> torso_array = {"( : )", "(] [)","(> <)","(   )"};
		std::array<std::string, options> base_array = {" ( : )", " (\" \")"," (___)", " (   )"};
		
		//The iteams chosen by the user 
		std::array<int, iteams> iteams_array= {};
		for(int i = iteams - 1; 0 <= i; i--){
			iteams_array.at(i) = (input % partion_num) -1;
			input = input/partion_num;
		}
		
		//Creating each of the four parts of the snowman's body
		std:: string base = base_array.at(iteams_array.at(b));
		std::string face = "("+eye_array.at(iteams_array.at(l_e)) + nose_array.at(iteams_array.at(n)) + eye_array.at(iteams_array.at(r_e))+")";
		std::string torso = torso_array.at(iteams_array.at(t));
		std::string hat = hat_array.at(iteams_array.at(h));
		
		
		//Adjust the left arm to the appropriate area of the body - face or torso
		if(iteams_array.at(l_a) == 3){
		    torso = leftArm_array.at(iteams_array.at(l_a)) + torso;
			face = leftArm_array.at(iteams_array.at(l_a)) + face;
			
		    
		}
		else if(iteams_array.at(l_a) == 1){
		  face = leftArm_array.at(iteams_array.at(l_a))+ face;
		   torso = " " + torso;
	   }
		
		else{
			torso = leftArm_array.at(iteams_array.at(l_a)) + torso;
			face = " " + face;
		}
	
		//Adjust the right arm to the appropriate area of the body - face or torso
		if(iteams_array.at(r_a) == 1){
			face = face + rightArm_array.at(iteams_array.at(r_a));
		}
		else{
			torso = torso + rightArm_array.at(iteams_array.at(r_a));
		}
		
		return  hat + "\n" + face + "\n" + torso + "\n" + base;	

	
	}
}

