#include "../headers/Order.h"

using namespace std;

Order::Order(string clientOrder_ID, string instrument_name, int side_type, double price_of_instrument, int total_quantity) {
    clientOrderID = clientOrder_ID;
    instrument = instrument_name;
    side = side_type;
    price = price_of_instrument;
    quantity = total_quantity;
}

string Order::getClientOrderID() {
    return clientOrderID;
}

string Order::getInstrument() {
    return instrument;
}

int Order::getSide() {
    return side;
}

double Order::getPrice() {
    return price;
}

int Order::getQuantity() {
    return quantity;
}
