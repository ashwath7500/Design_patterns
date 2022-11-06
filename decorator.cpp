#include <bits/stdc++.h>
using namespace std;

class component {
private:
	vector<string> vec;
public:
	void addString(string st) {
		vec.push_back(st);
	}
	void show_all() {
		for (auto it:vec) {
			cout<<it<<" ";
		}
	}
};

class wrapper : public component {
public:
	void addInt(int a) {
		addString(to_string(a));
	}
};
int main() {
	wrapper wrap;
	wrap.addString("hello");
	wrap.addString("world");
	wrap.addInt(3456);
	wrap.show_all();
	return 0;
}