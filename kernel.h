#include "cpu.h"
#include "pic.h"
#include "machine.h"

namespace vm
{

public :
	Machine machine;
	Kernel();
	std::vecotr(Process> processes;
	void CreateProcess(std::string name);
private:
	static const unsgigned int MAX_CYCLES_BEFORE_PREEMTION = 100;
	
	Process::process_id type _last_issed_rpcess_id;
	Memory:ram_type::size_type _last_ram_position;
	
	unsigned int _cycles_passed_after_preemption;
	std::vector<Process>::size_type _current_process_index;
}