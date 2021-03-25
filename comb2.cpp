#include <iostream>
#include <vector>
#include <time.h>

int main()
{
    int i = 0;
    int b = 0;
    int numOfFam = 1000;
    srand((unsigned)time(NULL));
    for (int j = 0; j < numOfFam; ++j) {
        while (b != 1)
        {
            b = rand() % 2;
            i++;
        }
        b = 0;
    }
    double res = (((double)numOfFam) / (double)i)*100;
    std::cout <<"Out of selection of " << numOfFam <<" families - "<< res<<"% will be boys ";
    std::cout << "and "<< 100-res << "% will be girls\n";
    
}
