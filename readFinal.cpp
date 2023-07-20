#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_set>

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
bool validateInput(string clientOrderID, string instrument, string side, string price, string quantity){

    bool isClientOrderIDValid;
    bool isInstrumentValid;
    bool isSideValid;
    bool isPriceValid;
    bool isQuantityValid;
    
    // client order id
    if(clientOrderID.length() <=7 && isAlphaNumeric(clientOrderID)){
        // pass
        isClientOrderIDValid = true;
    }else{
        isClientOrderIDValid = false;
    }

    // instruments 
    // search -> O(1)
    unordered_set<string> instrumentSet = {"Rose", "Lavender", "Lotus", "Tulip", "Orchid"};
    // Capitalize first
    transform (instrument.begin(), instrument.begin()+1, instrument.begin(),  ::toupper);
    transform (instrument.begin()+1, instrument.end(),   instrument.begin()+1,::tolower);

    //check instrument input is valid or not
    if(instrumentSet.find(instrument) != instrumentSet.end()){
        isInstrumentValid = true;
    }else{
        isInstrumentValid = false;
    }

    //Side
    // convert string to integer (s to i)
    int intSide = stoi(side);
    if(intSide == 1 || intSide == 2){
        isSideValid = true;
    }else{
        isSideValid = false;
    }

    //Price
    double doublePrice = stod(price);
    if(doublePrice > 0.0){
        isPriceValid = true;
    }else{
        isPriceValid = false;
    }

    //Quantity
    int intQuantity = stoi(quantity);
    if( (intQuantity % 10 == 0) && intQuantity >= 10 && intQuantity <= 1000){
        isQuantityValid = true;
    }else{
        isQuantityValid = false;
    }

    if(isClientOrderIDValid == true && isInstrumentValid == true && isSideValid == true && isPriceValid == true && isQuantityValid ==true){
        return true;
    }else{
        return false;
    }
    
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

        bool isInputesAreValid = validateInput(Client_Order_ID, Instrument, Side, Price, Quantity);

        cout << Client_Order_ID << " -> " << isInputesAreValid << endl;
    }
    ip.close();
}


int main(){

    readCsvFile();

    return 0;
}