#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int main(int args, char *argv[])
{
	if (args >= 3)
	{
		std::ifstream input_stream(argv[1]);
		if (!input_stream)
		{
			std::cerr << "Invlid arguments." << std::endl;

			return -1;
		}

		std::ofstream output_stream(argv[2], std::ios::out | std::ios::binary);
		if(!output_stream)
		{
			std::cerr << "Invalid arguments." << std::endl;
			return -1;
		}
		std::vector<int> ops;
		for(std::string  line; std::getline(input_stream,line);)
		{
			std::stringstream tokens(line);std::string token;

			
			if (tokens >> token)
			{
				if (token == "mov")
				{
					if (tokens >> token)
					{
						int opcode, data;
						if (token == "a")
						{
							opcode = 0x10;
						}
						else if ( token == "b")
						{
							opcode = 0x11;
						}
						else if (token == "c")
						{
							opcode = 0x12;
						}
						else
						{
							std::cerr << " Invalid registrer name "  << std::endl;
							return -1;
						}
						if (!(tokens >> data))
						{
							std::cerr << "invalid data " << std::endl;	
							return -1;
						}

						ops.push_back(opcode);
						ops.push_back(data);
					}
					else
					{
						std::cerr << "Invalid command syntax." << std::endl;
					}
				
				
				
				}

			else if( token == "int")
				{
					int opcode = 0x20;
					int data;
					if(!(tokens >> token))
					{
						std::cerr << "Invalid data for int." << std::endl;
						return -1;
					}
					ops.push_back(opcode);
					ops.push_back(data);

				}
			


			}
			else
			{
				std::cerr << "invalid operation mnemonic" << std::endl;
				return -1;
			}

			
		}
		if(input_stream.bad())
			{
				std::cerr << "Failed to read the file."<< std::endl;
				return -1;
			}

			output_stream.write(reinterpret_cast<const char *> (&ops[0]), ops.size() * sizeof(int));
	}
	else 
	{
		std::cerr << "Invalid arguments " << std::endl;
		return -1;

	}
	

	return 0;

}