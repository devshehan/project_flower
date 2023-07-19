#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

bool isAlphaNumeric(string clientOrderID){
    // Regex to check valid  alphanumeric String.
    const regex pattern("^(?=.*[a-zA-Z])(?=.*[0-9])[A-Za-z0-9]+$");

    if(clientOrderID.empty()){
        return false;
    }

    if(regex_match(clientOrderID,pattern)){
        return true;
    }else{
        return false;
    }
}

// validate file input
void validateInput(string clientOrderID, string instrument, string side, string price, string quantity){
    
    // client order id
    if(clientOrderID.length() <=7 && isAlphaNumeric(clientOrderID)){
        // pass
        cout << clientOrderID << " pass" << endl;
    }else{
        cout << clientOrderID << "fail" << endl;
    }

    // instruments
}

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

        validateInput(Client_Order_ID, Instrument, Side, Price, Quantity);
    }
    ip.close();
}


int main(){

    readCsvFile();

    return 0;
}