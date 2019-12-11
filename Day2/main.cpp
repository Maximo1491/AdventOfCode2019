#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part1()
{
	std::ifstream input_file;
	input_file.open( "input.txt", std::ios::in );

	if ( input_file.is_open() )
	{
		std::string line;
		std::vector<int> input_vector;
		while ( getline( input_file, line, ',' ) )
		{
			input_vector.push_back( std::stoi( line ) );
		}

		input_vector[1] = 12;
		input_vector[2] = 2;

		auto add_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + 3]] = input_vector[input_vector[value + 1]] + input_vector[input_vector[value + 2]];
		};

		auto multiply_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + 3]] = input_vector[input_vector[value + 1]] * input_vector[input_vector[value + 2]];
		};

		for ( size_t i = 0; i < input_vector.size(); i += 4 )
		{
			if ( i + 4 > input_vector.size() )
			{
				std::cout << "We've run out of array! Abort!";
				return;
			}

			switch ( input_vector[i] )
			{
			case 1:
				{
					add_vector( i );
				}
				break;
			case 2:
				{
					multiply_vector( i );
				}
				break;
			case 99:
				{
					std::cout << "We finished ya'll, position 0 is " << input_vector[0];
					return;
				}
				break;
			default:
				{

				}
				break;
			}
		}
	}
	else
	{
		std::cout << "Couldn't open file.";
	}
}

int main()
{
	part1();

	return 1;
}