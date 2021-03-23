#include <istream>
#include <vector>

int main()
{
    std::vector<int> binVector;
    int count = 0;
    int i = 0;
    int num = 0;
    while(count < 11)
    {
        srand(time(NULL));
        binVector[i] = rand()%1;
        //int ones = 1;
        if((binVector[i] == 1 || binVector[i] == 0)&& (binVector[i+1] == 1 || binVector[i+1] == 0))
        {
            count++;
        }
        else{
            count = 0;
        }
        num = binVector[i];
        i++;
    }
    std::cout<<"After "<< i << "times of ___ you will get 11 times of "<< num << std::endl;
}
