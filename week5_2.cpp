#include <iostream>
using namespace::std;
#include <fstream>;

int main()
{
    ifstream myFile;

    myFile.open("week5_2.cpp");

    if (!myFile.is_open())
    {
        throw  std::exception("File not opened");
    }

    const int buffer_size = 1024;
    char line[buffer_size];

    while (myFile.getline(line, buffer_size))
    {
        std::cout << line << endl;
    }

    myFile.close();
    return 0;
};