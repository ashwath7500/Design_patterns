#include <bits/stdc++.h>
using namespace std;

class chair{
public:
	virtual void sit() {
		cout<<"Normal sitting chair.";
	}
};
class victorian_chair : public chair{
	void sit() {
		cout<<"Victorian sitting char.";
	}
};
class modern_chair : public chair{
	void sit() {
		cout<<"Modern sitting char.";
	}
};

class sofa{
public:
	virtual void sleep() {
		cout<<"Normal sleeping sofa.";
	}
};
class victorian_sofa : public sofa{
	void sleep() {
		cout<<"Victorian sleeping sofa.";
	}
};
class modern_sofa : public sofa{
	void sleep() {
		cout<<"Modern sleping sofa.";
	}
};

class factory{
public:
	virtual chair* getChair() {
		return new chair();
	}
	virtual sofa* getSofa() {
		return new sofa();
	}
};
class victorian_factory : public factory {
	chair* getChair() {
		return new victorian_chair();
	}
	sofa* getSofa() {
		return new victorian_sofa();
	}
};
class modern_factory : public factory {
	chair* getChair() {
		return new modern_chair();
	}
	sofa* getSofa() {
		return new modern_sofa();
	}
};

int main () {
	factory* fact;
	cout<<"1 for Victorian factory, 2 for modern_factory";
	int input;
	cin>>input;
	switch(input) {
		case 1:
			fact = new victorian_factory();
			break;
		case 2:
			fact = new modern_factory();
			break;
		default:
			fact = new factory();
	}
	sofa* sof = fact->getSofa();
	chair* cha = fact->getChair();
	sof->sleep();cout<<"\n";
	cha->sit();
	return 0;
}