#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream Myfile("india_data.csv");
    if (!Myfile.is_open()) {
        cerr << "Failed to open the Myfile." << std::endl;
        return 1;
    }

    double amount, amount1, amount2,amount3;
    int year;

    cout << "Enter amount invested: " << std::endl;
    cin >> amount2;
    cout << "Enter the year in which amount is invested: " << std::endl;
    cin >> year;
    amount = amount2;
    string line;
    int serialnum, fileYear;
    long double interestRate, inflationRate;
    while (getline(Myfile, line)) {
        istringstream iss(line);
        char comma;

        if (iss >> serialnum >> comma >> fileYear >> comma >> interestRate >> comma >> inflationRate) {
            if (fileYear >= year) {
                amount1 = amount * (1 + (interestRate) / 100);
                amount = amount1;
                

                amount3 = amount2 * (1 + (interestRate - inflationRate) / 100);
                amount2 = amount3;

                }
                
        } else {
            cerr << "Failed to parse line: " << line << endl;
        }

    }
            

    Myfile.close();

    return 0;
}
