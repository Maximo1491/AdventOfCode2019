#include <iostream>
#include <fstream>
#include <string>
#include <vector>

constexpr int STORAGE_INDEX = 3;
constexpr int FIRST_INDEX = 1;
constexpr int SECOND_INDEX = 2;
constexpr int INPUT_STRIDE = 4;
constexpr int ADD_COMMAND = 1;
constexpr int MULTIPLY_COMMAND = 2;
constexpr int END_COMMAND = 99;
constexpr int MINIMUM_INPUT = 0;
constexpr int MAXIMUM_INPUT = 99;
constexpr int MAGIC_OUTPUT = 19690720;

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

		input_vector[FIRST_INDEX] = 12;
		input_vector[SECOND_INDEX] = 2;

		auto add_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + STORAGE_INDEX]] = input_vector[input_vector[value + FIRST_INDEX]] + input_vector[input_vector[value + SECOND_INDEX]];
		};

		auto multiply_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + STORAGE_INDEX]] = input_vector[input_vector[value + FIRST_INDEX]] * input_vector[input_vector[value + SECOND_INDEX]];
		};

		for ( size_t i = 0; i < input_vector.size(); i += INPUT_STRIDE )
		{
			if ( i + INPUT_STRIDE > input_vector.size() )
			{
				std::cout << "We've run out of array! Abort!";
				return;
			}

			switch ( input_vector[i] )
			{
			case ADD_COMMAND:
				{
					add_vector( i );
				}
				break;
			case MULTIPLY_COMMAND:
				{
					multiply_vector( i );
				}
				break;
			case END_COMMAND:
				{
					std::cout << "We finished ya'll, position 0 is " << input_vector[0] << "\n";
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

void part2()
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

		auto add_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + STORAGE_INDEX]] = input_vector[input_vector[value + FIRST_INDEX]] + input_vector[input_vector[value + SECOND_INDEX]];
		};

		auto multiply_vector = [&input_vector]( size_t value )
		{
			input_vector[input_vector[value + STORAGE_INDEX]] = input_vector[input_vector[value + FIRST_INDEX]] * input_vector[input_vector[value + SECOND_INDEX]];
		};

		std::vector<int> reset_vector = input_vector;

		//Bruteforce the inputs to find the magic output
		for ( int noun = MINIMUM_INPUT; noun < MAXIMUM_INPUT; noun++ )
		{
			for ( int verb = MINIMUM_INPUT; verb < MAXIMUM_INPUT; verb++ )
			{
				input_vector = reset_vector;
				input_vector[FIRST_INDEX] = noun;
				input_vector[SECOND_INDEX] = verb;

				for ( size_t i = 0; i < input_vector.size(); i += INPUT_STRIDE )
				{
					if ( i + INPUT_STRIDE > input_vector.size() )
					{
						std::cout << "We've run out of array! Abort!";
						return;
					}

					switch ( input_vector[i] )
					{
					case ADD_COMMAND:
						{
							add_vector( i );
						}
						break;
					case MULTIPLY_COMMAND:
						{
							multiply_vector( i );
						}
						break;
					case END_COMMAND:
						{
							//Output will be stored at the start of the array
							if ( input_vector[0] == MAGIC_OUTPUT )
							{
								std::cout << "We've found 19690720 lads, noun = " << noun << " verb = " << verb << " answer = " << 100 * noun + verb << "\n";
							}
						}
						break;
					default:
						{

						}
						break;
					}

					if ( input_vector[i] == END_COMMAND )
					{
						break;
					}
				}
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
	part2();

	return 1;
}