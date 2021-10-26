#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

class Person{
public:
	Person(const string& first_name, const string& last_name, const int& birthday){
		birthday_first_name = first_name;
		birthday_last_name = last_name;
		this->birthday = birthday;

		first_names[birthday] = first_name;
		last_names[birthday] = last_name;
	}

	void ChangeFirstName(int year, const string& first_name){
		if(year >= birthday)
			first_names[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name){
		if(year >= birthday)
			last_names[year] = last_name;
	}

	string GetFullName(int year) const{
		if(year < birthday)
			return "No person";

		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		if(first_name.empty() && last_name.empty())
			return "Incognito";
		else if(first_name.empty())
			return last_name + " with unknown first name";
		else if(last_name.empty())
			return first_name + " with unknown last name";
		else
			return first_name + " " + last_name;
	}

	string GetFullNameWithHistory(int year) const{
		if (year < birthday)
			return "No person";

		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		const string first_name_story = FindNamesByYear(first_names, year);
		const string last_name_story = FindNamesByYear(last_names, year);

		if(first_name.empty() && last_name.empty())
			return "Incognito";
		else if(first_name.empty())
			return last_name + last_name_story + " with unknown first name";
		else if(last_name.empty())
			return first_name + first_name_story + " with unknown last name";
		else
			return first_name + first_name_story + " " + last_name + last_name_story;
	}

private:
	string birthday_first_name;
	string birthday_last_name;
	int birthday;

	map<int, string> first_names;
	map<int, string> last_names;

	string FindNameByYear(const map<int, string>& names, int year) const{
		string name;

		for(const auto& item : names){
			if(item.first <= year)
				name = item.second;
			else
				break;
		}

		return name;
	}

	string FindNamesByYear(const map<int, string>& names, int year) const{
		string result = "";
		vector<string> names_vec;
		int nearest_year;

		for(const auto& item : names){
			if(item.first <= year){
				nearest_year = item.first;

				if(count(names_vec.begin(), names_vec.end(), item.second) == 0)
					names_vec.insert(names_vec.begin() + 0, item.second);
			}
			else
			    break;
		}

		for(int i = 0; i < names_vec.size(); ++i){
			if(i == 0 && names_vec[i] != names.at(nearest_year) || i != 0){
				if (!result.empty())
					result += ", " + names_vec[i];
				else
					result = names_vec[i];
			}
		}

		if (!result.empty())
			result = " (" + result + ")";
		return result;
	}
};
