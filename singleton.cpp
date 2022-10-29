#include <bits/stdc++.h>
using namespace std;

class singleton{
private:
	singleton(string value) : val(value){
	}
public:
	string val;
	static singleton& getinstace(string value) {
		static singleton single(value);
		return single;
	}
};

void foo() {
	singleton a = singleton::getinstace("foo");
	cout<<a.val<<"\n";
}

void bar() {
	singleton a = singleton::getinstace("bar");
	cout<<a.val<<"\n";
}

int main() {
	thread t1(foo);
	thread t2(bar);
	t1.join();
	t2.join();
}