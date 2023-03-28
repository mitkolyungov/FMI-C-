#include <iostream>
#include<fstream>
#include<iostream>
using namespace::std;


class SimpleVector {
public:

    int data[10];
    int size;
    ofstream oFile;
    ifstream iFile;
    ofstream oText;
    ifstream iText;

    SimpleVector() {
        size = 0;
        oFile.open("vector.bin", std::ios::binary);
        iFile.open("vector.bin", std::ios::binary);
        oText.open("example.txt");
        iText.open("example.txt");
    };

    ~SimpleVector()
    {
        oFile.close();
        iFile.close();
        oText.close();
        iText.close();
    }



    SimpleVector operator+(const SimpleVector& other) const;
    SimpleVector operator-(const SimpleVector& other) const;
    SimpleVector operator*(const int scalar) const;
    SimpleVector operator/(const int scalar) const;
    SimpleVector(const SimpleVector& other) {
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
    };

    void printVector();
    void writeVectorInFile(ofstream oFile);
    void readVectorFromFile(ifstream iFile);
    void writeVectorInTextFile(ofstream oText);
    void readVectorFromTextFile(ifstream iText);
};

void SimpleVector::writeVectorInFile(ofstream oFile) {
    
    if (!oFile.is_open()) {
        throw std::exception("file must be open");
    };

    oFile.write((char*)this, sizeof(this));
};

void SimpleVector::writeVectorInTextFile(ofstream oText) {

    if (!oText.is_open()) {
        throw std::exception("file must be open");
    };

    for (int i = 0; i < size; i++)
    {
        oText << data[i];
    }
};

void SimpleVector::readVectorFromTextFile(ifstream iText) {
    const int buffer_size = 1024;
    char line[buffer_size];
    
    if (iText.is_open())
    {
        while ( iText.getline(line, buffer_size))
        {
            cout << line << '\n';
        }
    }

    else throw std::exception("Unable to open file");
};

void SimpleVector::readVectorFromFile(ifstream iFile) {

    iFile.read((char*)this, sizeof(this));
};

SimpleVector SimpleVector::operator+(const SimpleVector& other) const {

    if (size != other.size) {
        throw std::exception("Vectors must be with the same size");
    }

    SimpleVector result;

    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i] + other.data[i];
    }

    result.size = size;

    return result;
};

SimpleVector SimpleVector::operator-(const SimpleVector& other) const {
    if (size != other.size) {
        throw std::exception("Vectors must be with the same size");
    }

    SimpleVector result;

    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i] - other.data[i];
    }

    result.size = size;

    return result;
};

SimpleVector SimpleVector::operator*(const int scalar) const {
    SimpleVector result;

    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i] * scalar;
    }

    result.size = size;

    return result;
};

SimpleVector SimpleVector::operator/(const int scalar) const {
    SimpleVector result;

    for (int i = 0; i < size; i++)
    {
        result.data[i] = data[i] / scalar;
    }

    result.size = size;

    return result;
};

void SimpleVector::printVector() {
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
};

int main()
{
    std::cout << "Hello World!\n";
}

