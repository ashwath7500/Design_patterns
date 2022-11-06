#include <bits/stdc++.h>
using namespace std;
class shared_state{
private:
	string model, color;
public:
	shared_state(string mod, string col) : model(mod), color(col) {}
	void show() {
		cout<<model<<" "<<color;
	}
};

map<string, shared_ptr<shared_state> > ma;

class car {
private:
	shared_ptr<shared_state> srd;
	int number_plate;
public:
	car(string model, string color, int num) : number_plate(num) {
		if (!ma[model+","+color]) {
			ma[model+","+color] = make_shared<shared_state>(model,color);
		}
		srd = ma[model+","+color];
	}
	void show() {
		srd->show();
		cout<<" "<<number_plate<<" "<<srd;
	}
};
int main() {
	car c1("toyo", "black", 54);
	car c2("toyo", "black", 25);
	c1.show();
	cout<<"\n";
	c2.show();
	return 0;
}