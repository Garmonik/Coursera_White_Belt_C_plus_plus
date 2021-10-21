#include<iostream>
#include<map>
#include<string>

using namespace std;

    int main(){

	map<string, string> capitals_map;
	int q;

	cin >> q;

	for(int i = 0; i < q; i++){
		string command;
        cin >> command;

		if(command == "CHANGE_CAPITAL"){
			string country;
			string new_capital;

			cin >> country >> new_capital;

			if(capitals_map.count(country) == 0){
				capitals_map[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else{
				if(capitals_map[country] == new_capital)
					cout << "Country " << country << " hasn't changed its capital" << endl;
				else{
					string old_capital = capitals_map[country];
					capitals_map[country] = new_capital;

					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
		}

		if(command == "RENAME"){
			string old_country_name,
                   new_country_name;

			cin >> old_country_name >> new_country_name;

			if(capitals_map.count(old_country_name) == 0 || capitals_map.count(new_country_name) == 1 || old_country_name == new_country_name)
				cout << "Incorrect rename, skip" << endl;
			
			else{
				string tmp_capital = capitals_map[old_country_name];

				capitals_map.erase(old_country_name);
				capitals_map[new_country_name] = tmp_capital;

				cout << "Country " << old_country_name << " with capital " << tmp_capital << " has been renamed to " << new_country_name << endl;
			}
		}

		if(command == "ABOUT"){
			string country;

			cin >> country;

			if(capitals_map.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital " << capitals_map[country] << endl;
		}

		if(command == "DUMP"){
			if(capitals_map.size() == 0){
				cout << endl;
                cout << "There are no countries in the world" << endl;
			}
            else{
				for(const auto& couple : capitals_map)
					cout << couple.first << "/" << couple.second << " ";
				cout << endl;
			}
		}
	}
}
