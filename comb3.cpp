#include <iostream>
#include <vector>
#include <time.h>

int countOccurrences(std::vector<int> vec, int n, int x)
{
    int result = 0;
    for (int i = 0; i < n; i++)
        if (x == vec[i])
            result++;
    return result;
}

int main()
{
    std::vector<int> randNum;
    int i = 0;
    int num = 0;
    int count = 0;
    srand(time(NULL));
    //girls = i-1; 
    //boy = 1;
    while (i != 1000)
    {
        num = rand() % 10;
        randNum.push_back(num);
        i++;
    }
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "\nNumber of occurrences of "<<i<<" : " << countOccurrences(randNum, randNum.size(),i);
    }
   
}

