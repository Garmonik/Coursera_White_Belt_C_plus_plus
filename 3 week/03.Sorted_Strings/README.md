Отсортированные строки<a name="TOP"></a>
===================

Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода: 

```C++
class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
  }
private:
  // приватные поля
};
```

***Пример***


***stdin***   | ***stdout***
------------- | -------------
2 5 2  |	-0.5 -2 
2 4 2 | -1
2 1 2 | 
0 4 10 | -2.5

***Подсказка***

**Код**
```C++
void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}
```

**Вывод**
```C++
first second third
first second second third
```
