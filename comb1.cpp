#include <iostream>
#include <time.h>

int main()
{
    int count = 0;
    int i = 0;
    int a,b;
    srand((unsigned)time(NULL));
    a = rand() % 2;
    while (count < 11)
    {
        b = rand() % 2;
        std::cout << i << ": " << b << std::endl;
        if (a == b)
        {
            count++;
            if (count == 11)
            {
                break;
            }
           
        }
        else {
            count = 0;
        }
        a = b;
        i++;
    }
    std::cout << "\nAfter " << i << " times you will get 11 times of " << b << std::endl;
}
