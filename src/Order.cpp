#include "../headers/Order.h"
#include <sstream>
#include <iomanip>

using namespace std;

Order::Order(string clientOrder_ID, string instrument_name, int side_type, double price_of_instrument, int total_quantity) {
    clientOrderID = clientOrder_ID;
    instrument = instrument_name;
    side = side_type;
    price = price_of_instrument;
    quantity = total_quantity;

    //generate order id
    orderID = generateSystemOrderID();
    status = 0; // 0-new 1-rejected 2-fill 3-partially fill
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

string Order::getOrderID(){
    return orderID;
}

string Order::generateSystemOrderID(){
    
    static int systemIDCounter = 1;

    // Generate a unique system ID
    std::stringstream ss;
    ss << "ord" << std::setw(4) << std::setfill('0') << systemIDCounter++;
    string orderIDString = ss.str();
    return orderIDString;
}
