#include <iostream>
#include <fstream>
#include <vector>

#include "headers/ValidateOrder.h"
#include "headers/Order.h"

using namespace std;

// If orders are valid store them in vector
vector<Order> ordersVector;

// read file variables
void readCsvFile(){
    ifstream ip("input.csv");

    if(!ip.is_open()){
        cout << "[ERROR] : file open" << endl;
    }

    //read the first line
    string header;
    getline(ip,header);

    string Client_Order_ID,Instrument,Side,Price,Quantity;

    while(ip.good()){
        getline(ip,Client_Order_ID,',');
        getline(ip,Instrument,',');
        getline(ip,Side,',');
        getline(ip,Price,',');
        getline(ip,Quantity,'\n');

        bool isInputesAreValid = validateOrder(Client_Order_ID, Instrument, Side, Price, Quantity);
        
        if(!isInputesAreValid){
            // need to write in the execution report
        }else{
            // continue the process
            Order orderCreate = Order(Client_Order_ID,Instrument,stoi(Side),stod(Price),stoi(Quantity));

            //add user into the list
            ordersVector.push_back(orderCreate);
        }
    }
    ip.close();
}


int main(){

    readCsvFile();
 

    return 0;
}