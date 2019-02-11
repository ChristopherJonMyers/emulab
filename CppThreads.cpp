//Chris Myers
// I wrote all my code.
// I did not show my code

#include <iostream> 
#include <thread> 
#include <fstream>
#include <string>
#include <chrono>
using namespace std; 
using namespace std::chrono;

string getNumbers()
{
    ifstream ifs("inputnum.txt");
    string content((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));
    return content;
}
    const int cores = 8;
    const string mainString = getNumbers();
    const int size = mainString.length();
    const int partSize = size/cores;
    const int th0Index = 0;
    const int th1Index = 1;
    const int th2Index = 2;
    const int th3Index = 3;
    const int th4Index = 4;
    const int th5Index = 5;
    const int th6Index = 6;
    const int th7Index = 7; 
    int totalThrees;

void pairWise(int thIndex)
{
    int begining = thIndex * partSize;
    string partition = mainString.substr(begining,partSize);
    int numOfThrees = 0;
    for (int i = 0; i < partSize; i ++)
    {
        if((partition[i] == '3'))
        {
            numOfThrees++;
        }
    }
    totalThrees += numOfThrees;
}

int main()
{ 
    auto start = high_resolution_clock::now();
    
    thread th0(pairWise,th0Index);
    thread th1(pairWise,th1Index);
    thread th2(pairWise,th2Index);
    thread th3(pairWise,th3Index);
    thread th4(pairWise,th4Index);
    thread th5(pairWise,th5Index);
    thread th6(pairWise,th6Index);
    thread th7(pairWise,th7Index);
    
    th0.join();
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    
    cout << "Total Number of 3's: " << totalThrees << "\n";
    cout << "Exicution time: " << duration.count() << " microseconds\n";
    
    
    return EXIT_SUCCESS;
}
