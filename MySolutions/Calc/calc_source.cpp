
#include <iostream>
#include <string>
#include <cstdlib>

int isInt(char* op)
{
	for (int i = 0; i < sizeof(op); i++) {
		if (op[i] != '\0' && (op[i] < '0' || op[i] > '9')) {
			// operator
			if (op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/') {
				return -1;
			}
			std::cout << op[i] << std::endl;
			// invalid string
			return 0;
		}
	}

	// is a number
	return 1;
}

int operate(int carry, char* num, char* op)
{
	if (isInt(num) != 1 || isInt(op) != -1) {
		std::cout << "Error" << std::endl;
	}
	else {
		switch (op[0])
		{
		case '+':
			carry += atoi(num);
			break;
		case '-':
			carry -= atoi(num);
			break;
		case '*':
			carry *= atoi(num);
			break;
		case '/':
			carry /= atoi(num);
			break;
		}
	}

	return carry;
}

int main(int argc, char* argv[])
{
	int result = 0,
		isnum = 0;

	if (argc > 1)
	{
		if (strcmp(argv[1], "-help") == 0)
		{
			std::cout << std::endl << "Usage:" << std::endl << std::endl;
			std::cout << "\tThis is a simple calculator that does integer arithmatic "
				"calculations by using Polish Notation." << std::endl << std::endl;
			std::cout << "\tFor example:\n\n"
				"\t\tCalc int1 int2 operation (int3 op int4 op ...)"
				<< std::endl << std::endl;
		}
		else
		{
			isnum = isInt(argv[1]);
			std::cout << isnum << std::endl;

			if (isnum == 1)
			{
				result = std::atoi(argv[1]);

				for (int i = 2; i < argc; i += 2) {
					result = operate(result, argv[i], argv[i + 1]);
				}
			}
			else
			{
				std::cout << "Invalid notation! Please, utilize Polish Notation "
					"for arguments (-help for correct usage).\n";
			}
		}
	}

	//getchar();
	getchar();
	return 0;
}