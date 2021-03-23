#include <iostream>
#include <vector>

int main()
{
    std::vector<int> sexOfShip;
    int i = 0;
    //girls = i-1; 
    //boy = 1;
    while(sexOfShip[i]!=1)
    {
        srand(time(NULL));
        sexOfShip[i] = rand()%1;
        i++;
    }
    int pers = ((i-1)/i)*100;
    std::cout<<"Girls in this family "<< rers<< "/nBoys in this family "<<100-pers<<std::endl;
}
// 0 1 - 50/50
// 0 0 1 75/25
// ... 
