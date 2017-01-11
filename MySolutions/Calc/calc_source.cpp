
#include <iostream>
#include <cstdlib>
#include <string>

#define NOTIF_ERROR "\nInvalid notation!\nPlease, utilize Polish Notation for arguments (-help for correct usage).\n"

/**
*
* @author Matheus Depra Gudergues
*
* @brief This program emulates a simple calculator (works with float) (Assignment 1).
*
* @return 0 if everything executed correctly
*
*/

bool isOperator(char* op)
{
	if ((sizeof(op) >= 2) && (op[1] == '\0')
		&& (op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/'))
	{
		return true;
	}

	return false;
}

bool isInteger(char* op)
{
	// empty string (shouldn't be possible)
	if (sizeof(op) == 0)
	{
		return false;
	}
	for (int i = 0; op[i] != '\0'; i++)
	{
		if (op[i] < '0' || op[i] > '9')
		{
			return false;
		}
	}

	return true;
}

bool isFloatingPoint(char* op)
{
	bool fpoint = false;

	// empty string (shouldn't be possible)
	if (sizeof(op) == 0)
	{
		return false;
	}
	for (int i = 0; op[i] != '\0'; i++)
	{
		if (op[i] == '.')
		{
			if (fpoint)
			{
				return false;
			}
			
			fpoint = true;
		}
		else if (op[i] < '0' || op[i] > '9')
		{
			return false;
		}
	}

	return fpoint;
}

int operate(int carry, char* num, char* op)
{
	if (!isInteger(num) || !isOperator(op))
	{
		std::cout << NOTIF_ERROR << "(Error message: invalid character/order reached)\n";

		getchar();
		exit(0);
	}
	else
	{
		switch (op[0])
		{
		case '+':
			std::cout << carry << " " << op[0] << " " << num;
			carry += atoi(num);
			std::cout << " = " << carry << std::endl;
			break;
		case '-':
			std::cout << carry << " " << op[0] << " " << num;
			carry -= atoi(num);
			std::cout << " = " << carry << std::endl;
			break;
		case '*':
			std::cout << carry << " " << op[0] << " " << num;
			carry *= atoi(num);
			std::cout << " = " << carry << std::endl;
			break;
		case '/':
			std::cout << carry << " " << op[0] << " " << num;
			carry /= atoi(num);
			std::cout << " = " << carry << std::endl;
			break;
		}
	}

	return carry;
}

double operate(double carry, char* num, char* op)
{
	if ((!isInteger(num) && !isFloatingPoint(num)) || !isOperator(op))
	{
		std::cout << NOTIF_ERROR << "(Error message: invalid character/order reached)\n";

		getchar();
		exit(0);
	}
	else
	{
		switch (op[0])
		{
		case '+':
			std::cout << carry << " " << op[0] << " " << num;
			carry += atof(num);
			std::cout << " = " << carry << std::endl;
			break;
		case '-':
			std::cout << carry << " " << op[0] << " " << num;
			carry -= atof(num);
			std::cout << " = " << carry << std::endl;
			break;
		case '*':
			carry *= atof(num);
			std::cout << carry << " " << op[0] << " " << num;
			std::cout << " = " << carry << std::endl;
			break;
		case '/':
			std::cout << carry << " " << op[0] << " " << num;
			carry /= atof(num);
			std::cout << " = " << carry << std::endl;
			break;
		}
	}

	return carry;
}

void printHelp(void)
{
	std::cout << std::endl << "Usage:" << std::endl << std::endl;
	std::cout << "\tThis is a simple calculator that evaluates integer and floating point "
		"arithmatic calculations by using Polish Notation for its arguments." << std::endl << std::endl;
	std::cout << "\tFor example, execute the program as:\n\n"
		"\t\tCalc.exe int1 int2 operation (int3 op int4 op ...)\n"
		"\t\tCalc.exe float1 float2 operation (float3 op float4 op ...)\n"
		"\t\tCalc.exe int1 float2 operation (float3 op int4 op ...)"
		<< std::endl << std::endl;
}

void parseAndCalculate(int argc, char* argv[])
{
	bool float_flag = false;
	int iresult = 0;
	double fresult = 0.0f;

	if (isInteger(argv[1]))
	{
		iresult = std::atoi(argv[1]);
	}
	else if (isFloatingPoint(argv[1]))
	{
		fresult = std::atof(argv[1]);
		float_flag = true;
	}
	else
	{
		std::cout << NOTIF_ERROR << "(Error message: invalid character / order reached)\n";

		return;
	}

	for (int i = 2; i < argc; i += 2)
	{
		if (i + 1 < argc)
		{
			if (float_flag)
			{
				fresult = operate(fresult, argv[i], argv[i + 1]);
			}
			else if (isFloatingPoint(argv[i]))
			{
				float_flag = true;
				fresult = static_cast<double>(iresult);
				fresult = operate(fresult, argv[i], argv[i + 1]);
			}
			else
			{
				iresult = operate(iresult, argv[i], argv[i + 1]);
			}
		}
		else
		{
			std::cout << NOTIF_ERROR << "(Error message: invalid length of arguments)\n";

			return;
		}
	}

	if (float_flag)
	{
		std::cout << std::showpoint << "Result: " << fresult << std::endl;
	}
	else
	{
		std::cout << "Result: " << iresult << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-help") == 0)
		{
			printHelp();
		}
		else
		{
			parseAndCalculate(argc, argv);
		}
	}
	else
	{
		std::cout << NOTIF_ERROR << "(Error message: no arguments)\n";
	}

	//getchar();
	getchar();
	return 0;
}
