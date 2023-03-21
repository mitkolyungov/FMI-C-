#include <iostream>
#include <fstream>
#include<string>
using namespace::std;

class Shoe {
private:
    std::string brand;
    std::string model;
    double price;
    double rating;
    int capacity;

public:

    string getModel() {
        return model;
    }

    int getCapacity() {
        return capacity;
    }

    double getRating() {
        return rating;
    }

    void setRating(int r) {
        rating = r;
    }

    void setCapacity(int c) {
        capacity = c;
    }
};

class Storage {
private:
    Shoe *shoes;
    int size;
    int capacity;
public:

    int getCapacity() {
        return capacity;
    }

    void setCapacity(int c) {
        capacity = c;
    };

    int getSize() {
        return size;
    }

    Storage(int countShoes);
    ~Storage();
    Storage(const Storage& other);
    Storage& operator=(const Storage& other);
    void removeModel(string model);
    void addModelCapacity(string model, int capacity);
    void changeRatingModel(string model, double newRating);
    void sellModel(string model);
};

Storage::Storage(int countShoes)
{
    shoes = new Shoe[countShoes];
    size = countShoes;
    capacity = 0;
};

Storage::~Storage()
{
    delete[] shoes;
}
Storage::Storage(const Storage& other)
{   
    this->shoes = new Shoe[other.size];
    size = other.size;
    capacity = other.capacity;

    delete[] other.shoes;
};



void Storage::removeModel(string model)
{
    for (int i = 0; i < getCapacity(); i++)
    {
        if (shoes[i].getModel() == model) {
            delete[i] shoes;
            setCapacity(getCapacity() - 1);
        };
    };
}

void Storage::addModelCapacity(string model, int capacity)
{   
    bool found = false;
    for (int i = 0; i < getSize(); i++)
    {   
        Shoe shoe = shoes[i];

        if (shoe.getModel() == model) {
            found = true;
            shoe.setCapacity(shoe.getCapacity() + capacity);
            setCapacity(getCapacity() + 1);
        };
    };

    if (!found) {
        throw std::exception("Model does not exist");
    }
}
void Storage::changeRatingModel(string model, double newRating)
{
    for (int i = 0; i < getSize(); i++)
    {
        Shoe shoe = shoes[i];

        if (shoe.getModel() == model) {
            shoe.setRating(newRating);
        };
    };
}
void Storage::sellModel(string model)
{   
    bool found = false;
    for (int i = 0; i < getSize(); i++)
    {
        Shoe shoe = shoes[i];

        if (shoe.getModel() == model) {

            if (shoe.getCapacity() == 0) {
                this->removeModel(shoe.getModel());
                break;
            }

            found = true;
            shoe.setCapacity(shoe.getCapacity() - 1);
            setCapacity(getCapacity() - 1);
        };
    };

    if (!found) {
        throw std::exception("Model not found and cannot be sold");
    }
}
;

int main()
{   
    

}

