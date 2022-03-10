#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address in memory of the string : " << (void*)&str[0] << std::endl;
    std::cout << "address of the string using stringPTR : " << stringPTR << std::endl;
    std::cout << "address of the string using stringREF : " << &stringREF << std::endl;

    std::cout << "string data using stringPTR : " << *stringPTR << std::endl;
    std::cout << "string data using stringREF : " << stringREF << std::endl;
}