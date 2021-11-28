#include "cpu.h"
#include <iostream>
#include <string>
#include <fstream>

void RAM::translate() 
{
    this->memory.emplace(0,std::vector<std::string>{"cr_mov" ,"cr_ebx" , "4"}) ;
    this->memory.emplace(1,std::vector<std::string>{"cr_mov" ,"cr_eax" , "10"}) ;
    this->memory.emplace(2,std::vector<std::string>{"cr_add" ,"cr_ebx", "cr_eax"}) ;
    this->memory.emplace(3,std::vector<std::string>{"cr_print" ,"cr_ebx"}) ;
    this->memory.emplace(4,std::vector<std::string>{"cr_jmp_g" ,"cr_ebx" , "cr_eax" , "2"}) ;
}

int CPU::get_register(std::string reg)
{
	if (reg == "cr_eax") {
		return CR_EAX;
	} else if (reg == "cr_ebx") {
		return CR_EBX;
	} else if (reg == "cr_ecx") {
		return CR_ECX;
	} else if (reg == "cr_edx") {
		return CR_EDX;
	} else {
		std::cout << "incorrect register name" << std::endl;
		std::exit(-1);
	}
}
void CPU::move_register(std::string reg, int val)
{
	if (reg == "cr_eax") {
		CR_EAX = val;
	} else if (reg == "cr_ebx") {
		CR_EBX = val;
	} else if (reg == "cr_ecx") {
		CR_ECX = val;
	} else if (reg == "cr_edx") {
		CR_EDX = val;
	} else {
		std::cout << "incorrect register name" << std::endl;
		std::exit(-1);
	}
}
void CPU::print_register(std::string reg)
{	
    std::ofstream ofile("hard_disk",std::ofstream::app) ;
	if (reg == "cr_eax") {
		std::cout << CR_EAX << std::endl;
        ofile << CR_EAX << std::endl;
	} else if (reg == "cr_ebx") {
		std::cout << CR_EBX << std::endl;
        ofile << CR_EBX << std::endl;
	} else if (reg == "cr_ecx") {
		std::cout << CR_ECX << std::endl;
        ofile << CR_ECX << std::endl;
	} else if (reg == "cr_edx") {
		std::cout << CR_EDX << std::endl;
        ofile << CR_EDX << std::endl;
	} else {
		std::cout << "incorrect register name" << std::endl;
		std::exit(-1);
	}
    ofile.close() ;
}

void CPU::CU::analize_info(RAM& ob_ram,CPU& ob_cpu)
{
    int end = (--ob_ram.memory.end())->first ;
    for (;SP <= end; ++SP)
    {
        if (ob_ram.memory[SP][0] == "cr_mov")
        {
            ob_cpu.move_register(ob_ram.memory[SP][1],std::stoi (ob_ram.memory[SP][2]));
        }
        else if (ob_ram.memory[SP][0] == "cr_add")
        {
            ob_cpu.alu.add(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_mul")
        {
            ob_cpu.alu.mul(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
            
        }
        else if (ob_ram.memory[SP][0] == "cr_div")
        {
            ob_cpu.alu.div(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_sub")
        {
            ob_cpu.alu.sub(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_modul")
        {
            ob_cpu.alu.modul(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_and")
        {
            ob_cpu.alu.and_(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_or")
        {
            ob_cpu.alu.or_(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_xor")
        {
            ob_cpu.alu.xor_(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_add")
        {
            ob_cpu.alu.add(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_not")
        {
            ob_cpu.alu.not_(ob_ram.memory[SP][1],ob_cpu);
        }
        else if (ob_ram.memory[SP][0] == "cr_jmp_l")
        {
            if(ob_cpu.alu.jmp_l(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu)) 
            {
                int tmp = std::stoi(ob_ram.memory[SP][3]) ;
                SP -= tmp ;       
            }
        }
        else if (ob_ram.memory[SP][0] == "cr_jmp_g")
        {
            if(ob_cpu.alu.jmp_g(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu)) 
            {
                int tmp = std::stoi(ob_ram.memory[SP][3]) ;
                SP -= tmp ;       
            }
        }
        else if (ob_ram.memory[SP][0] == "cr_jmp_e")
        {
            if(ob_cpu.alu.jmp_e(ob_ram.memory[SP][1],ob_ram.memory[SP][2],ob_cpu)) 
            {
                int tmp = std::stoi(ob_ram.memory[SP][3]) ;
                SP -= tmp ;       
            }
        }
        else if(ob_ram.memory[SP][0] == "cr_print") 
        {
            ob_cpu.print_register(ob_ram.memory[SP][1]) ;
        }
    }
}

int CPU::ALU::add(std::string num1, std::string num2, CPU& obj)
{
	int tmp = obj.get_register(num1) + obj.get_register(num2);
	obj.move_register(num1,tmp);
	return tmp;
}
int CPU::ALU::sub(std::string num1, std::string num2, CPU& obj)
{
	int tmp = obj.get_register(num1) - obj.get_register(num2);
	obj.move_register(num1, tmp);
	return tmp;
}
int CPU::ALU::mul(std::string num1, std::string num2, CPU& obj)
{
	int tmp = obj.get_register(num1) * obj.get_register(num2);
	obj.move_register(num1, tmp);
	return tmp;
}
int CPU::ALU::div(std::string num1, std::string num2, CPU& obj)
{
	int tmp = obj.get_register(num1) / obj.get_register(num2);
	obj.move_register(num1, tmp);
	return tmp;
}
int CPU::ALU::modul(std::string num1, std::string num2, CPU& obj)
{
	int tmp = obj.get_register(num1) % obj.get_register(num2);
	obj.move_register(num1, tmp);
	return tmp;
}
bool CPU::ALU::and_(std::string num1, std::string num2, CPU& obj)
{
	bool tmp = (obj.get_register(num1)) && (obj.get_register(num2));
	obj.move_register(num1, tmp);
	return tmp;
}
bool CPU::ALU::or_(std::string num1, std::string num2, CPU& obj)
{
	bool tmp = (obj.get_register(num1)) || (obj.get_register(num2));
	obj.move_register(num1, tmp);
	return tmp;
}
bool CPU::ALU::xor_(std::string num1, std::string num2, CPU& obj)
{
	bool tmp = (obj.get_register(num1)) ^ (obj.get_register(num2));
	obj.move_register(num1, tmp);
	return tmp;
}
bool CPU::ALU::not_(std::string num1, CPU& obj)
{
	bool tmp = ~(obj.get_register(num1));
	obj.move_register(num1, tmp);
	return tmp;
}
bool CPU::ALU::jmp_g(std::string num1, std::string num2, CPU& obj)
{
	int tmp1 = obj.get_register(num1);
	int tmp2 = obj.get_register(num2);
	if (tmp1 > tmp2) { return true; }
	return false;
}
bool CPU::ALU::jmp_l(std::string num1, std::string num2, CPU& obj)
{
	int tmp1 = obj.get_register(num1);
	int tmp2 = obj.get_register(num2);
	if (tmp1 < tmp2) { return true; }
	return false;
}
bool CPU::ALU::jmp_e(std::string num1, std::string num2, CPU& obj)
{
	int tmp1 = obj.get_register(num1);
	int tmp2 = obj.get_register(num2);
	if (tmp1 == tmp2) { return true; }
	return false;
}

void CPU::go()
{
	RAM memory;
	memory.translate();
	cu.analize_info(memory, *this);
}