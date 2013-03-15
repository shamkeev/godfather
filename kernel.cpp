Kernel::Kernel
	: machine(), processes(),
	_last_issed_process_id(0),
	_last_ram_position(0),
	_current_process_index(0),
	_cycle_passed_after_preemption(0)
{
	pic.irq_0 = []() 
	{
		//ToDo: Unload the cyrrebt process
		
		std::cout << "Caught the hardware interruption 1 " << std::endl;
	}
	
	CreateProcess("change_register.vmexe");
	CreateProcess("change_register_in_loop.vmexe");
	CreateProcess("Change_register.vmexe");
	
	machine.pic_isr_0 = [&]()
	{
		if( _cycle_passed_after_preemption > Kernel::MAX_CYCLE)
		{
			// Preempt
			// Save registers from cpu to current process
			// Change the state of the current process from running to ready
			//_cycle_passed_after_preemption = (_cycle_passed_after_preemption + 1 ) process.size()
			
			// Set the register state for the processor to the state of the current process
			// CPU & IS change 
			// Change the state of the curent process to running
			_cycle_passed_after_preemption = 0;
		}
		else
		{
			_cycle_passed_after_preemption++;
		}
	}
	machine.pic.isr_3 = [&]()
	{
		// todo sytscall exit, ,unload the ucdrrent process
		//  Remove the current process from the process list
		 // Perform  the context switch
	}
	pic.isr_1 = []() 
	{
		//ToDo: Unload the cyrrebt process
		
		std::cout << "Caught the software interruption 1 " << std::endl;
	}
	
	machine.Start();
}

Kernel::CreateProcess(std::string name)
{
	if(_last_issed_process_id == std::numeric_limists<Process:process_id_type>::max())
		std::cerr<< << std::endl;
	else
		std::ifstream input_stream(name, std::ios::in | std::ios::binary);
		if(!input_stream)
			std::cerr << "failed: to open the program file. "<< std::endl;
		else
			Memory::ram_type ops;
			// —читывает файл с диска помещает в пам€ть и добавл€ет его в €дре
			
			input_stream.seekg(0,std::ios::end);
			auto file_size = intput_stream.tellg();
			input_stream.seekg(0,std:ios::beg);
			ops.resize(file)size /4);
			
			input_stream.read(reinterpret_cast<char *> (&ops[0]), file_size);
			
			if(input_stream.bad())
				std::cerr<< "incorrect input" << endl;
			else{
				std::copy(ops.begin(),ops.end(),(machine.memory.ram.begin() + _last_ram_position))
				
				Process process(_last_issued_process_id++, _last_ram_position, _last_ram_position + ops.size())
				
				_last_ram_position += ops.size();
				
				processes.push_back(processs);
			}
}

Kernel::Kernel() {

}