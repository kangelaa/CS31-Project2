//
//  duty.cpp
//  Project 2
//
//  Created by Angela Kan on 10/20/20.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //Ask user to input cheese type
    cout << "Cheese type: ";
    string cheese;
    getline(cin, cheese);
    
    //Ask user to input value
    cout << "Value: ";
    double value;
    cin >> value;
    cin.ignore(10000, '\n');
    
    //Ask user to input cheese importer
    cout << "Importer: ";
    string importer;
    getline(cin, importer);
    
    cout << "---" << endl;
    
    //Check for empty strings and non-positive values. If none, calculuate duty and print it as output
    double amount;
    cout.setf(ios::fixed);                  //fix amount output to 2 decimal places
    cout.precision(2);

    if (cheese == ""){                      // Checks for empty cheese string
        cout << "You must enter a cheese type" << endl;
    } else if (value <= 0){                // Checks for negative/zero value
        cout << "The value must be positive" << endl;
    } else if (importer == ""){            // Checks for empty importer string
        cout << "You must enter an importer" << endl;
    } else {                            //Entire next section calculates duty amount based on input value and outputs it
        if (value <= 1000){
            amount = value * .011;
        } else if (value <= 13000 && (cheese == "cheshire" || cheese == "stilton") ){
            amount = ( (value - 1000) * .014) + (1000 * .011);
        } else if (value <= 13000){
            amount = ( (value - 1000) * .02) + (1000 * .011);
        } else if (value > 13000 && (cheese == "cheshire" || cheese == "stilton") ){
            amount = ( (value - 13000) * .029) + (12000 * .014) + (1000 * .011);
        } else {
            amount = ( (value - 13000) * .029) + (12000 * .02) + (1000 * .011);
        }
            
        cout << "The import duty for " << importer << " is $" << amount << endl;
    }

    return 0;
}

