#include <iostream>
#include <vector>
 
using namespace std;

int main() {
    int dec = 0;
    vector<int> bin;

    cin >> dec;

    while (dec > 0){
        auto i = bin.cbegin();
        bin.insert(i, dec % 2);
        dec /= 2;
    }

    for (int n : bin){
        cout << n;
    }

    return 0;
}

