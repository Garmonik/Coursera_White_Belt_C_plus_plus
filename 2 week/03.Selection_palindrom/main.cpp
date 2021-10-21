vector<string> PalindromFilter(vector<string> words, int min_length){
	vector<string> out_vector;

	for (auto w : words){
		int n = w.size() / 2;

		bool flag = true;

		for (int i = 0; i <= n; ++i)
			flag *= (w[i] == w[(w.size() - 1) - i]);

		if (flag && w.size() >= min_length)
			out_vector.push_back(w);
	}

	return out_vector;
}
