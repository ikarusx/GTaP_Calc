
#include <iostream>
//#include <string>
#include <cstdlib>

int main(int argc, char* argv[])
{
	//std::cout << "test" << std::endl;
	std::cout << argv[0] << " is running";
	
	if (argc >= 2) {
		std::cout << " by " << argv[1] << std::endl;

		if (argc >= 3) {

			int count = std::atoi(argv[2]);

			std::cout << "Converted number is: " << count << std::endl;

			std::cout << "How many times? " << std::endl;

			for (int i = 0; i < count; i++) {
				std::cout << i + 1 << " " << std::endl;
			}
		}
	}

	//getchar();
	getchar();
	return 0;
}