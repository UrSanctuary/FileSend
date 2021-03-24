#include <iostream>
#include <time.h>

int main()
{
   
    int count = 0;
    int i = 0;
    int b;
    srand(time(NULL));
    while (count < 11)
    {   
        b = rand() % 2;
        if (b=rand() % 2 == b)
        {
            count++;
        }
        else {
            count = 0;
        }
        std::cout << b << std::endl;
        i++;
    }
    std::cout << "After " << i << " times of you will get 11 times of " << b << std::endl;
}
