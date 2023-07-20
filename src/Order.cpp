#include <bits/stdc++.h>
#include "../headers/Order.h"

using namespace std;

class Order{
private:
    string clientOrderID;
    string instrument;
    int side;
    double price;
    int quantity;

public:
    Order(string clientOrder_ID, string instrument_name, int side_type, double price_of_instrument, int total_quantity){
        clientOrderID = clientOrder_ID;
        instrument = instrument_name;
        side = side_type;
        price = price_of_instrument;
        quantity = total_quantity;
    }
};