#include "CPU.h"

namespace vm
{
	Registers::Registers(): 
		: a(0), b(0), c(0), flags(0), ip(0), sp(0){}
	CPU::CPU(Memory &memory, PIC &pic)
		: memory(memory), pic(pic) {}
		
	CPU::~CPU(){}
	
	void CPU::Step()
	{
		int instruction = memory.ram[registers.ip];
		int data = memory.ram[registers.ip];
		
		if (instruction == CPU::MOVA_BASE_OPCODE)
		{
			registers.a = data;
			register.ip += 2;
		}
		else if ( instruciton == CPU::MOVA_BASE_OPCODE)
		{
			registers.b = data;
			register.ip += 2;
		}
		else if (instruction = CPU::INT_BASE_OPCODE)
		{
			pic.isr_1();
			register.ip += 2;
		}
		else if (instruction = CPU::JMP_BASE_OPCODE)
		{
			registers.ip += data;
		}
	}
}