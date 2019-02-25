#include <cstdlib>
#include <thread>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
#include <mutex>   

struct padded_int
{
   int value;
   char padding[60];
};

std::mutex mtx;
int threesCount = 0;
const int processors = 8;
padded_int privatecounts [processors]; 
std::vector<std::string> numbers = {};
int size = 0;

void countThrees(int thIndex)
{
    int startPoint = (size / processors) * thIndex;
    int endpoint;
    
    if (thIndex == processors - 1) 
    {
        endpoint = size - 1;
    }
    else 
    {
        endpoint = (size / processors) * (thIndex + 1) - 1;
    }
    for(int i = startPoint; i < endpoint; i++) 
    {
        if (numbers[i] == "3") 
        {
            privatecounts[thIndex].value++;
        }
    }
            mtx.lock();
            threesCount += privatecounts[thIndex].value;
            mtx.unlock();
}

int main() 
{
    
    std::ifstream iFile;
    iFile.open("array-values.txt");
    std::string line = "";
    
    while (getline(iFile, line)) 
    {
        std::istringstream fileLine(line);
        std::string number;
    
        while (fileLine >> number) 
        {
            numbers.push_back(number);
        }
    }
    
    size = numbers.size();
    
    auto start = std::chrono::high_resolution_clock::now();
    
    std::thread threads[processors];
    
     for (int i = 0; i < processors; i++)
    {
        threads[i] = std::thread(countThrees, i);
    }
    
    for (int j = 0; j < processors; ++j) 
    {
        threads[j].join();
    }
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << duration.count() << std::endl;
    std::cout << threesCount << std::endl;

    return EXIT_SUCCESS;
}


    
