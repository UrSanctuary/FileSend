#include <iostream>
#include <vector>
#include <time.h>
int main()
{
    std::vector<int> sexOfShip;
    int i = 0;
    int b = 0;
    srand(time(NULL));
    //girls = i-1; 
    //boy = 1;
    while (b != 1)
    {
        b = rand() % 2;
        sexOfShip.push_back(b);
        std::cout << sexOfShip[i] << std::endl;
        i++;
    }
    double pers = (((double)i - 1) / (double)i)*100 ;
    std::cout << "Girls in this family " << pers << "%\nBoys in this family " << (100 - pers) << "%"<<std::endl;
}

