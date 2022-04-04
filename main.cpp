/*
*	CS 219 Section 1001
*
*	This file will read ARM version 7 ISA instructions in a textfile and
*	display the instruction, registers affected by the instruction, and
*	the new value for that register after the instruction has been executed
*
*	@file main.cpp
*	@author Austin Ah Mau
*	@version 1.1 4/4/2022
*
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "converter.h"

/*
*	@brief Initializes register R0 - R7, reads through my textfile,
*	determines which instruction to execute and which registers are
*	being affected, and displays answers to the screen.
*
*	@return 0
*
*/
int main(){
	uint32_t R0 = 0x0, R1 = 0x0, R2 = 0x0, R3 = 0x0, R4 = 0x0, R5 = 0x0, R6 = 0x0, R7 = 0x0;

	std::string line;
	std::string instructions[50];
	int i = 0;

	std::ifstream file("input.txt");
	//checks if file is open
	if(file.is_open()){
		while(getline(file, line)){
			std::istringstream ss(line);
			std::string instruction;

			getline(ss, instruction, ' ');
			instructions[i] = instruction;
			i++;

			while(getline(ss, instruction, ',')){
				ss.ignore();
				instructions[i] = instruction;
				i++;
			}
		}			
	}
	file.close();

	int count = 0;
	std::string destOperand;
	std::string operand1;
	std::string operand2;
	
	//scan through instructions array until it reaches the end		
	while(instructions[count] != "\0"){
		//initializes the specified register to a specified immediate operand
		if(instructions[count] == "MOV"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				destOperand = instructions[count+2];

				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: MOV R0, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R0 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				destOperand = instructions[count+2];

				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: MOV R1, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R1 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				destOperand = instructions[count+2];

				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: MOV R2, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R2 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				destOperand = instructions[count+2];

				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: MOV R3, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R3 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				destOperand = instructions[count+2];

				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: MOV R4, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R4 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				destOperand = instructions[count+2];

				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: MOV R5, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R5 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				destOperand = instructions[count+2];

				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: MOV R6, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R6 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				destOperand = instructions[count+2];

				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: MOV R7, " << destOperand << std::endl;

				destOperand.erase(0,1);
				R7 = std::stoul(destOperand, 0, 16);

				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//Adds the values of specified registers and stores the new value into the destination register
		else if(instructions[count] == "ADD"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R0 = R0 + R1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: ADD R0, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R1 = R0 + R1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: ADD R1, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R2 = R0 + R1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: ADD R2, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R3 = R0 + R1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: ADD R3, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R4 = R0 + R1;
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: ADD R4, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R5 = R0 + R1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: ADD R5, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R6 = R0 + R1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: ADD R6, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R7 = R0 + R1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: ADD R7, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}

		}
		//Subtracts the values of specified registers and stores the new value into the destination register
		else if(instructions[count] == "SUB"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R0 = R0 - R1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: SUB R0, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R1 = R0 - R1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: SUB R1, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R2 = R0 - R1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: SUB R2, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R3 = R0 - R1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: SUB R3, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R4 = R0 - R1;
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: SUB R4, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R5 = R0 - R1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: SUB R5, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R6 = R0 - R1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: SUB R6, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R7 = R0 - R1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: SUB R7, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//ANDs the values of specified registers and stores the new value into the destination register
		else if(instructions[count] == "AND"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R0 = R0 & R1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: AND R0, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R1 = R0 & R1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: AND R1, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R2 = R0 & R1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: AND R2, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R3 = R0 & R1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: AND R3, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R4 = R0 & R1;
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: AND R4, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R5 = R0 & R1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: AND R5, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R6 = R0 & R1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: AND R6, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R7 = R0 & R1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: AND R7, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//ORs the values of specified registers and stores the new value into the destination register
		else if(instructions[count] == "ORR"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R0 = R0 | R1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: ORR R0, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R1 = R0 | R1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: ORR R1, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R2 = R0 | R1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: ORR R2, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R3 = R0 | R1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: ORR R3, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R4 = R0 | R1;
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: ORR R4, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R5 = R0 | R1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: ORR R5, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R6 = R0 | R1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: ORR R6, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R7 = R0 | R1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: ORR R7, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//XORs the values of specified registers and stores the new value into the destination register
		else if(instructions[count] == "XOR"){
			//determines which register is being updated
			if(instructions[count + 1] == "R0"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R0 = R0 ^ R1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: XOR R0, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R1"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R1 = R0 ^ R1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: XOR R1, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R2"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R2 = R0 ^ R1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: XOR R2, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R3"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R3 = R0 ^ R1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: XOR R3, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R4"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R4 = R0 ^ R1;
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: XOR R4, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R5"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R5 = R0 ^ R1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: XOR R5, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R6"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R6 = R0 ^ R1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: XOR R6, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(instructions[count + 1] == "R7"){
				operand1 = instructions[count + 2];
				operand2 = instructions[count + 3];
				R7 = R0 ^ R1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: XOR R7, " << operand1 << ", " << operand2 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//Shifts each bit to the right by 1 then shifts a zero int the MSB
		else if(instructions[count] == "LSR"){
			destOperand = instructions[count + 1];
			operand1 = instructions[count + 2];
			//determines which register is being updated
			if(destOperand == "R0"){
				R0 = R1 >> 1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: LSR R0, " << operand1 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(destOperand == "R1"){
				R1 = R1 >> 1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: LSR R1, " << operand1 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(destOperand == "R2"){
				R2 = R1 >> 1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: LSR R2, " << operand1 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(destOperand == "R3"){
				R3 = R1 >> 1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: LSR R3, " << operand1 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(destOperand == "R4"){
				R4 = R1 >> 1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: LSR R4, " << operand1 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(destOperand == "R5"){
				R5 = R1 >> 1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: LSR R5, " << operand1 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(destOperand == "R6"){
				R6 = R1 >> 1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: LSR R6, " << operand1 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(destOperand == "R7"){
				R7 = R1 >> 1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: LSR R7, " << operand1 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//Shifts each bit to the left by 1 then shifts a zero int the LSB
		else if(instructions[count] == "LSL"){
			destOperand = instructions[count + 1];
			operand1 = instructions[count + 2];
			//determines which register is being updated
			if(destOperand == "R0"){
				R0 = R1 << 1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: LSL R0, " << operand1 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl << std::endl;
			}
			else if(destOperand == "R1"){
				R1 = R1 << 1;
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: LSL R1, " << operand1 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl << std::endl;
			}
			else if(destOperand == "R2"){
				R2 = R1 << 1;
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: LSL R2, " << operand1 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl << std::endl;
			}
			else if(destOperand == "R3"){
				R3 = R1 << 1;
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: LSL R3, " << operand1 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl << std::endl;
			}
			else if(destOperand == "R4"){
				R4 = R1 << 1;
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: LSL R4, " << operand1 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl << std::endl;
			}
			else if(destOperand == "R5"){
				R5 = R1 << 1;
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: LSL R5, " << operand1 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl << std::endl;
			}
			else if(destOperand == "R6"){
				R6 = R1 << 1;
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: LSL R6, " << operand1 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl << std::endl;
			}
			else if(destOperand == "R7"){
				R7 = R1 << 1;
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: LSL R7, " << operand1 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl << std::endl;
			}
		}
		//Shifts each bit to the right by 1 and preserves the MSB when shifted
		else if(instructions[count] == "ASR"){
			destOperand = instructions[count + 1];
			operand1 = instructions[count + 2];
			
			std::string operandString = std::to_string(R1);
			Converter convert;
			std::string getMSB = convert.hexToBinary(operandString);
			char msb = getMSB[0];

			std::string answerASR = "";
			answerASR += msb;

			//determines which register is being updated
			if(destOperand == "R0"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R0 = finalASR;
				
				std::cout << "Register R0 updated" << std::endl;
				std::cout << "Instruction: ASR R0, " << operand1 << std::endl;
				std::cout << "Register R0 = 0x" << std::hex << std::uppercase << R0 << std::endl;
			}
			else if(destOperand == "R1"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R1 = finalASR;
				
				std::cout << "Register R1 updated" << std::endl;
				std::cout << "Instruction: ASR R1, " << operand1 << std::endl;
				std::cout << "Register R1 = 0x" << std::hex << std::uppercase << R1 << std::endl;
			}
			else if(destOperand == "R2"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R2 = finalASR;
				
				std::cout << "Register R2 updated" << std::endl;
				std::cout << "Instruction: ASR R2, " << operand1 << std::endl;
				std::cout << "Register R2 = 0x" << std::hex << std::uppercase << R2 << std::endl;
			}
			else if(destOperand == "R3"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R3 = finalASR;
				
				std::cout << "Register R3 updated" << std::endl;
				std::cout << "Instruction: ASR R3, " << operand1 << std::endl;
				std::cout << "Register R3 = 0x" << std::hex << std::uppercase << R3 << std::endl;
			}
			else if(destOperand == "R4"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R4 = finalASR;
				
				std::cout << "Register R4 updated" << std::endl;
				std::cout << "Instruction: ASR R4, " << operand1 << std::endl;
				std::cout << "Register R4 = 0x" << std::hex << std::uppercase << R4 << std::endl;
			}
			else if(destOperand == "R5"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R5 = finalASR;
				
				std::cout << "Register R5 updated" << std::endl;
				std::cout << "Instruction: ASR R5, " << operand1 << std::endl;
				std::cout << "Register R5 = 0x" << std::hex << std::uppercase << R5 << std::endl;
			}
			else if(destOperand == "R6"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R6 = finalASR;
				
				std::cout << "Register R6 updated" << std::endl;
				std::cout << "Instruction: ASR R6, " << operand1 << std::endl;
				std::cout << "Register R6 = 0x" << std::hex << std::uppercase << R6 << std::endl;
			}
			else if(destOperand == "R7"){
				for(int i = 0; i < getMSB.length() - 1; i++){
					answerASR += getMSB[i];
				}
				uint32_t finalASR = std::stoul(answerASR, 0, 2);
				R7 = finalASR;
				
				std::cout << "Register R7 updated" << std::endl;
				std::cout << "Instruction: ASR R7, " << operand1 << std::endl;
				std::cout << "Register R7 = 0x" << std::hex << std::uppercase << R7 << std::endl;
			}	
		}
		count++;
	}
return 0;
}
