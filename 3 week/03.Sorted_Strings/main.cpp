class SortedStrings{
	public:
		void AddString(const string& s){
			strings.push_back(s);
			sort(strings.begin(), strings.end());
		}
		vector<string> GetSortedStrings(){
			return strings;
		}
	private:
		vector<string> strings;
};
