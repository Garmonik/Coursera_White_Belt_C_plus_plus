#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	map<string, vector<string>> bus_dict;

	vector<string> busses;

	int q;

	cin >> q;

	for(int i = 0; i < q; i++){
		string command;

		cin >> command;

		if(command == "NEW_BUS"){
			string bus;
			int stop_count;

			cin >> bus >> stop_count;

			busses.push_back(bus);
			bus_dict[bus].resize(stop_count);

			for(string& stop : bus_dict[bus])
				cin >> stop;
		}

		if(command == "BUSES_FOR_STOP"){
			string stop;

			cin >> stop;

			bool search_flag = false;
			string out_str = "";

			for(const auto& bus : busses){
				if(count(bus_dict[bus].begin(), bus_dict[bus].end(), stop) != 0){
					search_flag += true;
					out_str += bus + " ";
				}
			}

			if(search_flag)
				cout << out_str << endl;
			else
				cout << "No stop" << endl;
		}

		if(command == "STOPS_FOR_BUS"){
			string bus;

			cin >> bus;

			if(count(busses.begin(), busses.end(), bus) != 0){
				for(const auto& stop : bus_dict[bus]){
					bool search_flag = false;
					string out_str = "";

					for(const auto& other_bus : busses){
						if(count(bus_dict[other_bus].begin(), bus_dict[other_bus].end(), stop) != 0 && other_bus != bus){
							search_flag += true;
							out_str += other_bus + " ";
						}
					}

					if(search_flag)
						cout << "Stop " << stop << ": " << out_str << endl;
					else
						cout << "Stop " << stop << ": no interchange" << endl;
				}
			}
			else
				cout << "No bus" << endl;
		}

		if(command == "ALL_BUSES"){
			if(bus_dict.size() != 0){
				for(const auto& bus : bus_dict){
					string out_str = "";

					for(const auto& stop : bus_dict[bus.first])
						out_str += stop + " ";

					cout << "Bus " << bus.first << ": " << out_str << endl;
				}
			}
			else
				cout << "No buses" << endl;
		}
	}
}
