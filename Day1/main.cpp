#include <iostream>
#include <fstream>
#include <string>

int calculate_fuel( int input )
{
	input /= 3;
	input -= 2;			
	
	return input;
}

void part1()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		int total = 0;
		while ( getline( input_file, line ) )
		{
			total += calculate_fuel( std::stoi( line ) );
		}

		std::cout << "Total Fuel Requirements for part 1: " << total;
	}
	else
	{
		std::cout << "Couldn't open file.";
	}
}

void part2()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		int total = 0;
		while ( getline( input_file, line ) )
		{
			int input = calculate_fuel( std::stoi( line ) );
			total += input;
			while ( input > 2 )
			{
				input = calculate_fuel( input );
				if ( input > 0 )
				{
					total += input;
				}
			}
		}

		std::cout << "\nTotal Fuel Requirements for part 2: " << total;
	}
	else
	{
		std::cout << "Couldn't open file.";
	}
}

int main()
{
	part1();
	part2();

	return 1;
}