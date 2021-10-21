void Reverse(vector<int>& num_vec){
	vector<int> tmp_vec;

	for (int i = num_vec.size() - 1; i >= 0; --i)
		tmp_vec.push_back(num_vec[i]);

	num_vec = tmp_vec;
}
