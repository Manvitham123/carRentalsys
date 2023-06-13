#include <iostream>
#include <vector>
#include "userInteraction.h"

using namespace std;

userInteraction::userInteraction(string userFile, string carFile) : verifiedUser("0", "0"), chosen(0.0, 0.0, 0, 0, "none"), h(userFile), c(carFile)
{
}
bool userInteraction::getVerifiedUser()
{
    if (verifiedUser.getUsername() == "0")
    {
        return false;
    }
    return true;
}

bool userInteraction::getChosenNumber()
{
    if (chosen.getNumber() == 0)
    {
        return false;
    }
    return true;
}
bool userInteraction::getChosenType()
{
    if (chosen.getType() == "none")
    {
        return false;
    }
    return true;
}

void userInteraction::login()
{
    string username;
    string password;
    cout << "Enter username:" << endl;
    cin >> username;
    cout << "Enter password:" << endl;
    cin >> password;
    if (h.verify(username, password))
    {
        cout << "log in successful" << endl;
        verifiedUser = h.getUser(username);
    }
    else
    {
        cout << "log in unsuccessful try again" << endl;
    }
}
void userInteraction::LoadUserData()
{
    h.load();
}
void userInteraction::LoadCarData()
{
    c.load();
}

vector<car> userInteraction::displayCarOptions()
{
    string carType;
    cout << " " << endl;
    cout << "Available car type options: " << endl;
    for (auto types : c.typeList)
    {
        cout << types << endl;
    }
    cout << " " << endl;

    cout << "what car type would you like?:" << endl;
    cin >> carType;
    vector<car> filteredCars;
    for (auto cars : c.carList)
    {
        if (cars->getType() == carType)
        {
            filteredCars.push_back(*cars);
            cout << "Car Id: " << cars->getNumber();
            cout << " Car type: " << cars->getType();
            cout << " Mileage: " << cars->getMileage();
            cout << " Rent price: " << cars->getrentPrice();
            cout << " Max power: " << cars->getMaxpower() << endl;
            chosen.setType(carType);
        }
    }

    if (filteredCars.size() == 0)
    {
        cout << "car type unavailable" << endl;
    }
    return filteredCars;
}
// vector<string> userInteraction::carRentalDetails(double number){

//}
void userInteraction::chooseCar()
{
    int number;
    string num;
    cout << "which car would you like? enter car number:" << endl;
    cin >> num;

    try
    {
        number = stoi(num);
        int count = 0;

        for (auto cars : c.carList)
        {
            if (cars->getNumber() == number && number != 0)
            {
                this->chosen = *cars;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "car number does not exsist please try again:" << endl;
        }
    }
    catch (...)
    {
        cout << "Incorrect input please try again" << endl;
    }
}
void userInteraction::setNumberOfDays()
{
    int days1;
    cout << "how many days would you like to rent the car:" << endl;
    cin >> days1;
    days = days1;
    invoice();
}

void userInteraction::invoice()
{
    cout << "Invoice for user: " << verifiedUser.getUsername() << endl;
    cout << endl;
    cout << "Car details: " << endl;
    cout << "   Car Id: " << chosen.getNumber() << endl;
    cout << "   Car type: " << chosen.getType() << endl;
    cout << "   Mileage: " << chosen.getMileage() << endl;
    cout << "   Rent price: " << chosen.getrentPrice() << endl;
    cout << "   Max power: " << chosen.getMaxpower() << endl;
    cout << endl;
    cout << "days to be rented: " << days << endl;
    cout << endl;
    cout << "Total: " <<"$" <<chosen.getrentPrice() * days  <<endl;
}
