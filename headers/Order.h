#pragma once
#include <iostream>

using namespace std;

class Order {
private:
    string clientOrderID;
    string instrument;
    int side;
    double price;
    int quantity;

public:
    Order(string clientOrder_ID, string instrument_name, int side_type, double price_of_instrument, int total_quantity);

    string getClientOrderID();
    string getInstrument();
    int getSide();
    double getPrice();
    int getQuantity();
};
