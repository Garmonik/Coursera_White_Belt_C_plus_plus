bool IsPalindrom(string str){
	int n = str.size() / 2;
	bool flag = true;

	for (int i = 0; i <= n; ++i){
		flag *= (str[i] == str[(str.size() - 1) - i]);
	}
	return flag;
}
