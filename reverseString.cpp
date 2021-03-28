#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> SplitBySpaceWithRev( std::string str)
{
    std::vector<std::string> words;
    std::string word = "";
    std::string revStr = "";
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i]==' ')
        {
            revStr = std::string(word.rbegin(),word.rend());
            words.push_back(std::string(revStr));
            word="";
            revStr = "";
        }
        else
        {
            word.push_back(str[i]);
        }
        
    }
    std::reverse(word.begin(), word.end());
    words.push_back(word);
    std::reverse(words.begin(),words.end());
    return words;
}
void PrintVector(std::vector<std::string> v){
	for(int i=0;i<v.size();++i)
		std::cout<<v[i]<<" ";
    std::cout<<"\n";
}
int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);
    PrintVector(SplitBySpaceWithRev(sentence));
}
