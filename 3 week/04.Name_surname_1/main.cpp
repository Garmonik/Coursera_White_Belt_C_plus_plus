#include<map>
#include<string>


class Person{
public:
    void ChangeFirstName(int year, const string& first_name){
        first_names[year] = first_name;
        // добавить факт изменения имени на first_name в год year
    }
    void ChangeLastName(int year, const string& last_name){
        last_names[year] = last_name;
        // добавить факт изменения фамилии на last_name в год year
    }
    string GetFullName(int year){
        string first_name;
        string last_name;
        for(const auto& i : first_names){
            if(year >= i.first){
                first_name = i.second;
            } 
            else{
                break;
            }
        } // получили имя на момент этого года
        for(const auto& j : last_names){
            if(year >= j.first){
                last_name = j.second;
            }
            else{
                break;
            }
        } // получили фамилию на момент этого года
        if(first_name.empty() && last_name.empty()){
            return "Incognito";
        }
        else if(first_name.empty()){
            return last_name + " with unknown first name";
        }
        else if(last_name.empty()){
            return first_name + " with unknown last name";
        }
        else{
            return first_name + " " + last_name;
        }
        // получить имя и фамилию по состоянию на конец года year
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};
