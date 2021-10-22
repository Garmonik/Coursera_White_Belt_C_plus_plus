#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(){
	int n;
	cin >> n;

	set<string> string_set;

	for(int i = 0; i < n; i++){
		string tmp_str;
		cin >> tmp_str;
		string_set.insert(tmp_str);
	}
	cout << string_set.size();
}
