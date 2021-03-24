#include <iostream>
#include <vector>

int main()
{
    std::vector<int> sexOfShip;
    int i = 0;
    int b = 0;
    //girls = i-1; 
    //boy = 1;
    while(b != 1)
    {
        b = rand() % 2;
        sexOfShip.push_back(b);
        std::cout<<sexOfShip[i]<<std::endl;
        i++;
    }
    int pers = ((i-1)/i)*100;
    std::cout<<"Girls in this family "<< pers<< "\nBoys in this family "<<100-pers<<std::endl;
}
// 0 1 - 50/50
// 0 0 1 75/25
// ... 
