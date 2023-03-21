#include <iostream>
using namespace::std;
#include <fstream>;
int main()
{   
    ifstream myFile;

    myFile.open("C:\\Users\\grade\\Desktop\\myFile.txt" , ios::binary);

    if (!myFile.is_open())
    {
        throw  std::exception("File not opened");
    }

    const int buffer_size = 1024;
    char line[buffer_size];
    long length = 0;

    while (myFile.getline(line, buffer_size))
     {
            length += strlen(line) + 1;
     }
    
    std::cout << length - 1;
    myFile.close();
    return 0;
};
