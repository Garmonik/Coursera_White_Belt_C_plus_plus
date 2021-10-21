#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
	map<vector<string>,int> stations_dict;

	int q;
	cin >> q;

	for(int i = 0; i < q; i++){
		int num;
		cin >> num;

		vector<string> tmp_vec(num);

		for(auto& station : tmp_vec)
			cin >> station;

		if (stations_dict.count(tmp_vec) != 0)
			cout << "Already exists for " << stations_dict[tmp_vec] << endl;
		else{
			int tmp_val = stations_dict.size() + 1;
			stations_dict[tmp_vec] = tmp_val;

			cout << "New bus " << tmp_val << endl;
		}
	}
}
