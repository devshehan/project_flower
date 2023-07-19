#include <iostream>
#include <fstream>

using namespace std;

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
    }
    ip.close();
}

int main(){

    // 1. read csv file
    readCsvFile();

    return 0;
}