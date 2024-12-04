// #include <bits/stdc++.h> - assuming you don't know bits

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

void vectorExamples() {
	vector<int> a;

	a.push_back(1); 
	a.push_back(2);
	a.pop_back();
	a.push_back(0);
	a.push_back(-1);

	// sort(a.begin(), a.begin() + a.size());
	sort(a.begin(), a.end());

	// a.erase(a.begin(), a.end()); // delete range
	// a.erase(a.begin() + 1); // delete pos

										    // 2  3 
	// vector<int> add = {1, 2, 3, 4, 6, 7, 8};
	// a.insert(a.begin(), add.begin() + 2, add.begin() + 4);

	int pos = lower_bound(a.begin(), a.end(), 0) - a.begin();
	cout << pos << endl;

	for (int i = 0; i < (int)a.size(); i++) {
		cout << a[i] << ' ';
	}

	cout << endl;

	/*
		vector<int> a = {1, 2, 3, 4};
		a.capacity() = 4

		a.push_back(5);
	*/
}

void stackExamples() {
	stack<int> st;
	st.push(5);
	st.push(3);
	st.push(10);
	// st.size()
	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	// FILO -> First in Last out

	/*
		Problem:

		())() -> incorrect
		))(( -> incorrect
		(())() -> correct

		       v
		[{]} -> incorrect

		stack = 
	     

	*/

	string s;
	stack<char> b;
	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (c == '(') b.push(c);
		else {
			if (b.size() == 0) {
				cout << "BAD SEQUENCE!";
				return;
			}
			b.pop();
		}
	}
	if (b.size() == 0) {
		cout << "GOOD SEQUENCE!";
	}
	else {
		cout << "BAD SEQUENCE!";
	}
}

string s;
void rec(int v = 1) {
	if (v > 10) {
		int bal = 0;
		bool bad = 0;
		for (char i : s) {
			if (i == '(') bal++;
			else bal--;
			if (bal < 0) bad = 1;
		}
		if (!bad && bal == 0) cout << s << endl;
		return;
	}
	s += "(";
	rec(v + 1);
	s.pop_back();
	s += ")";
	rec(v + 1);
	s.pop_back();
}

void queueExamples() {
	queue<int> q;
	q.push(10);
	q.push(2);
	q.push(5);

	while (q.size() > 0) {
		cout << q.front() << endl;
		q.pop();
	}
	// FIFO -> First in First out
}

void dequeExamples() {
	deque<int> d;
	d.push_front(1);
	d.push_back(2);
	d.push_front(3);
	d.push_back(4);
	// push_back, push_front -> O(1)
	// front(), back() -> O(1)
	// d[i] -> O(1)
}

void mapExamples() {
	//  key     value
	map<string, string> mp;

	mp["Semyon"] = "Overthinkers";
	mp["Asylbek"] = "Overthinkers";
	mp["Dima"] = "Tancy s Bubnami";
	mp.insert({"Zhan", "Coach"});

	// accessing element that doesn't exist -> you create new element
	
	// cout << " -> " << mp.count("Zhan") << endl;
	

	// for (map<string,string>::iterator i = mp.begin(); 
	// 	i != mp.end(); i++) {
	// 		cout << i->first << " from " << i->second << endl;
	// 	}
	mp["Zhan"] = "Coach";
	mp.erase("Coach");
	for (auto i : mp) { // for (map<string,string>::iterator i = mp.begin(); i != mp.end(); i++)
		cout << i.first << " from " << i.second << endl;
	}
	
	// insert, erase -> O(log(n))

	unordered_map<string, string> mp1;

	// insert, erase -> O(1) on average, O(N) in worst case
	// unordered_map is not sorted
}

void setExamples() {
	set<int> st;
	st.insert(10);
	st.insert(15);
	// st.insert(30);
	st.erase(15);
	// insert, erase -> O(log(N))

	auto it = st.lower_bound(10); // >= 10
	if (it != st.end()) {
		cout << *it << endl;
	}

	it = st.upper_bound(10); // > 10
	if (it != st.end()) {
		cout << *it << endl;
	}
	// O(log(N))
}
int main() {
	vectorExamples();
	// stackExamples();
	// queueExamples();
	// rec();
	// dequeExamples();
	// mapExamples();
	// setExamples();
	return 0;
}
/*
	abcd < abcda
*/
