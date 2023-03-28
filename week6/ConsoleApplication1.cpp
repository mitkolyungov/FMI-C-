#include <iostream>
#include<fstream>
using namespace::std;

const int CAR_NUMBER = 2;

class F1Car {
public:
    string name;
    int year;
    int wins;
    double engineCapcity;

    F1Car(string n, int y, int w, double eC) { // Constructor with parameters
        name = n;
        year = y;
        wins = w;
        engineCapcity = eC;
    };

    F1Car() {

    };


};

class F1Team {
public:
    string name;
    F1Car cars[CAR_NUMBER];
    ofstream oFile;
    ifstream iFile;

    F1Team(string n, F1Car c[CAR_NUMBER]) {
        name = n;
        for (int i = 0; i < CAR_NUMBER; i++)
        {
            cars[i] = c[i];
        };
        oFile.open("team.bin", std::ios::binary);
        iFile.open("team.bin", std::ios::binary);
    };

    ~F1Team()
    {
        oFile.close();
    }


    
    void writeTeamInFile(F1Car car, ofstream oFile);
    void readTeamFromFile(F1Car car, ifstream iFile);
};

void F1Team::writeTeamInFile(F1Car car, ofstream oFile)
{
    
    if (!oFile.is_open()) {
        throw std::exception ("Error opening file!\n");
    }

    oFile.write((char*)&car, sizeof(car));
}

void F1Team::readTeamFromFile(F1Car car, ifstream iFile)
{
     iFile.read((char*)&car, sizeof(F1Car));
     iFile.close();
}

int main()
{   
}
