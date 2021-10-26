#include<iostream>
#include<vector>
#include<string>
using namespace std;

string GetPositivity(int x) {
    return x > 0 ? "positive"
                 : (x == 0 ? "zero" : "negative");
}

int main(){

cout << GetPositivity(-5);
}
