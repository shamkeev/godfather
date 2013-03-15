#pragma once
#include "memory.h"

namespace vm
{
	struct Registers
	{
		int a;
		int b;
		int c;
		
		unsigned int lfags;
		unsigned int ip;
		unsigned int sp;
		
		Registers();
	};


	class CPU
	{
	public:
		Registers registers;
		CPU( Memory &memory, PIC &pic);
		
		void Step();
		
	private:
		Memory &memory;
		PIC &pic;
	};
}