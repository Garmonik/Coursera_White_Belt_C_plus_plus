set<string> BuildMapValuesSet(const map<int, string>& m){
  set<string> val;

  for (const auto& i : m)
    val.insert(i.second);
  return val;
}
