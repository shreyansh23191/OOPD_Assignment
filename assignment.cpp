#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
int main() {
    ifstream Myfile("india_data.csv");
    if (!Myfile.is_open()) {
        cerr << "Failed to open the Myfile." << endl;
        return 1;
    }

    double amount, amount1, amount2,amount3,amount4;
    int year;

    cout << "Enter amount invested: " << endl;
    cin >> amount2;
    cout << "Enter the year in which amount is invested: " << endl;
    cin >> year;
    if(year<2002){
        amount2 = amount2/166;
    }
    amount1 = amount2;
    amount3 = amount2;
    amount4 = amount2;
    string line;
    int serialnum, fileYear;
    long double interestRate, inflationRate;
    while (getline(Myfile, line)) {
        istringstream iss(line);
        char comma;
        
        if (iss >> serialnum >> comma >> fileYear >> comma >> interestRate >> comma >> inflationRate) {
            if (fileYear < 1978){ 
                amount3 = (amount3 * (1 + (interestRate - inflationRate) / 100))/18;
            }
            if (fileYear >= 1978){
                amount4 = amount4 * ((1 + (interestRate - inflationRate) / 100));
            }
            
            if (fileYear >= year) {
                amount1 = amount1 * (1 + (interestRate) / 100); 
                

                amount2 = amount2 * (1 + (interestRate - inflationRate) / 100);
                
                }
                
        } else {
            cerr << "Failed to parse line: " << line << endl;
        }

    }
    cout<<fixed<<setprecision(2);
    cout << "Year: " << fileYear << " - Money received: " << amount1 << " - Value of money received: " << amount2 << std::endl;
    if(amount3<amount4){
        cout<<"Dictatorship wins";
            }   

    Myfile.close();

    return 0;
}
