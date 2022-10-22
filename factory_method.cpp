#include<bits/stdc++.h>
using namespace std;

class transport {
public:
	virtual void deliver() {
		cout<<"Delivery in generic transport";
	}
};
class airtransport : public transport {
	void deliver() {
		cout<<"Delivery in air transport";
	}
};
class watertransport : public transport {
	void deliver() {
		cout<<"Delivery in water transport";
	}
};

class creator {
public:
	virtual transport* create() {
		return new transport();
	}
};
class aircreator : public creator {
	transport* create() {
		return new airtransport();
	}
};
class watercreator : public creator {
	transport* create() {
		return new watertransport();
	}
};

int main () {
	int input;
	transport* t;
	creator* cr;
	cout<<"Input: 0 for generic transport, 1 for airtransport and 2 for watertransport";
	cin>>input;
	switch(input) {
		case 0:
			cr = new creator();
			break;
		case 1:
			cr = new aircreator();
			break;
		case 2:
			cr = new watercreator;
			break;
		default:
			cout<<"Incorrect input";
			return 0;
	}
	t = cr->create();
	t->deliver();
	delete t;
	delete cr;
}