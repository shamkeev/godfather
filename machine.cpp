#include "machine.h"
namespace vm
{
	Machine::Machine()
		: memory(), pic(), cpu(memory, pic){}

	Machine::~Machine() {}
		
	void Machine::Start()
	{
		for(;;)
		{
			cpu.Step();
			
			pic.irq_0();
			//General the Timer Interrupt
		}
	}	
}