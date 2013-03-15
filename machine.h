#pragma once
#include "CPU.h"
#include "Memory.h"
#include "PIC.h"

namespace vm
{

	class Machine
	{
	public:
		Memory memory;
		PIC pic;
		CPU cpu;
		Machine();
		void Start();
		
		virtual ~Machine();
	private:
	};
}