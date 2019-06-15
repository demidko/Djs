#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void TestJson()
{
    std::locale::global(std::locale("ru"));
    std::ifstream jsonFile("Test.json");
    std::stringstream jsonText;
    std::cout << "Before:" << std::endl;
    for (std::string i; std::getline(jsonFile, i);)
    {
        std::cout << i << std::endl;
        jsonText << i << std::endl;
    }
    std::cout << "\nAfter:" << std::endl;
}

#include<optional>

std::optional<int> Null() {
    return ;
}

int main()
{
    std::cout << (Null() == std::nullopt);
}

