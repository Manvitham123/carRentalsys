#include <iostream>
#include <vector>

using namespace std;

class car{
    public:
    car();
    car(double rentPrice, double maxPower, int mileage, int number, string type);

    double getrentPrice();
     double getModel();
     double getMaxpower();
    int getMileage();
     int getNumber();
     string getType();
     void setType(string t);
    private:
    string type;
    string model;
    double rentPrice;
    double maxPower;
    int mileage;
    int number;


};


class carDatabase{
     public:
    virtual void load() = 0;
    vector<car *> carList;
    vector<string> typeList;

};

class fileCarDatabase: public carDatabase{
    public:
    fileCarDatabase(string filename);
    void load();
    private:
    vector<string> getStringTokens(string str, char delim);
    private:
    string filename;
};
