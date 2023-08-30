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
    
    Myfile.close();

    return 0;
}
