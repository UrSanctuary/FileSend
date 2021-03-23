#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <time.h>   // <-- ??
#include <bitset>   // <-- ??

int main(int argc, char *argv[])
{
    //get the name of file
    if(argc != 1)
    {
        std::cerr<<"You have not entered the name of file"<<std::endl;
        break;
    }
    //create file
    std::fstream myFile;
    //open file
    MyFile.open(argv[0], std::fstream::in | std::fstream::out);
    //get string
    std::string  strToBeCoded;
    std::getline(std::cin, strToBeCoded);
    
    bool flag = false;
    //generete key (don't forget to make it differetnt every time #include <ctime>)
    int key;
    /* initialize random seed: */
    srand (time(NULL));
    key = rand() % 512 + 1;
    //check if is string valid ('a-z' or '')
    for(int i = 0; i < strToBeCoded.length(); ++i)
    {
        if(isalpha(strToBeCoded[i]||strToBeCoded[i]==' ')
        {
            //return here a flag if the statements are true
            flag = true; 
        }
        else
        {
            //return a flag
            flag = false;
            std::cerr<<"String does not match to the pattern"<<std::endl;
        }

    }
    //apply key to all string
    std::string codedString;
    /*for(int i = 0; i < strToBeCoded.length(); ++i)
    {
        int bitset<8>(strToBeCoded.c_str()[i]);
    }*/
    codedString = encrypt(strToBeCoded, key);
    
    //write it in a file
    myFile << codedString;
    //close stream
    myFile.close();
}

