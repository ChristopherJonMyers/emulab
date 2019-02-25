#include <cstdlib>
#include <thread>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> numbers = {};
    int threesCount = 0;

    std::ifstream iFile;
    iFile.open("array-values.txt");
    std::string line = "";
    
    while (getline(iFile, line)) {
	std::istringstream fileLine(line);
	std::string number;
	while (fileLine >> number) {
	    numbers.push_back(number);
	}
    }
    for(std::string index : numbers) {
	if (index == "3") {
	    threesCount++;
	}
    }
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << duration.count() << std::endl;
    std::cout << threesCount << std::endl;

    return EXIT_SUCCESS;
}
