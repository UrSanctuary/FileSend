#include <iostream>
#include <time.h>

int main()
{
    int count = 0;
    int i = 0;
    int a, b;
    srand((unsigned)time(NULL));
    a = rand() % 2;
    while (count < 11)
    {
        b = rand() % 2;
        if (a == b)
        {
            count++;
        }
        else {
            count = 0;
        }
        a = b;
        i++;
    }
    std::cout << "After " << i << " times you will get 11 times of " << b << std::endl;
}
