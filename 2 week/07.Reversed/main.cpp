vector<int> Reversed(const vector<int>& v){
	vector<int> tmp_vec;

	for (int i = v.size() - 1; i >= 0; --i)
		tmp_vec.push_back(v[i]);

	return tmp_vec;
}
