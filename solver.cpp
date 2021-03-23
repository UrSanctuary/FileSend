#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* [])
{
    std::fstream myFile = argc[0];
    //open file
    myFile.open();
    //getline from file
    std::string strEncoded;
    getline(myFile,strEncoded);
    //decode it
    std::vector<std::string> varOfEncStr;
    varOfEncStr.append(decode(strEncoded));
    //cout vars of string 
    for(auto iter: varOfEncStr)
    {
        std::cout<<iter<<std::endl;
    }
    //close file
    myFile.close();
}

// 010111^011 = 10100
