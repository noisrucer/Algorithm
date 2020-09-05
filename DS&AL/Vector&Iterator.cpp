vector<int> v(8);
	for (int x : v)
		cout << x << " ";
	cout << "\n";
	fill(v.begin(), v.begin()+4, 5);
	fill(v.begin()+4, v.end(),10);
	auto i = v.begin();
	for (i; i!=v.end() ;i++)
		cout << *i << " ";
	cout << "\n";
	
	for (int &i : v) {
		i = 100;
	}
	auto itr = v.begin();
	for (itr; itr != v.end(); itr++)
		cout << *itr << " ";
	cout << "\n";