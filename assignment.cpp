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
        

    Myfile.close();

    return 0;
}
