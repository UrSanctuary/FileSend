#include <iostream>

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int number;
    std::cin>>number;
    std::cout << countSetBits(number);
    return 0;
}
 
