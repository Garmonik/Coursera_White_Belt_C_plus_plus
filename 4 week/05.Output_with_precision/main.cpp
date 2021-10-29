#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    ifstream input("input.txt");
//  ifstream input("input1.txt");
//  ifstream input("input2.txt");
    double a;

    cout << fixed << setprecision(3);

    while (input >> a)
        cout << a << endl;
    return 0;
}
