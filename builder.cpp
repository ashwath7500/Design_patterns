#include <bits/stdc++.h>
using namespace std;

class product {
public:
	vector<string> parts;
		void showprod() {
			cout<<"The parts:\n";
			for (auto it:parts) {
				cout<<it<<",";
			}
		}
};

class builder{
public:
	virtual void reset()=0;
	virtual void buildPartA()=0;
	virtual void buildPartB()=0;
	virtual void buildPartC()=0;
	virtual product* result()=0;
};

class concrete_builder : public builder {
	product* prod;
public:
	void reset() {
		delete prod;
		prod = new product();
	}
	void buildPartA() {
		prod->parts.push_back("Part A");
	}
	void buildPartB() {
		prod->parts.push_back("Part B");
	}
	void buildPartC() {
		prod->parts.push_back("Part C");
	}
	product* result() {
		return prod;
	}
};

class Director{
private:
  builder* bob;
public:
  void set_builder(builder* bob) {
    this->bob=bob;
  }
  void BuildMinimalViableProduct() {
    bob->reset();
    bob->buildPartA();
  }
  
  void BuildFullFeaturedProduct() {
  	bob->reset();
    bob->buildPartA();
    bob->buildPartB();
    bob->buildPartC();
  }
  product* result() {
  	return bob->result();
  }
};

int main () {
	builder* bob = new concrete_builder();
	Director sankar;
	sankar.set_builder(bob);
	sankar.BuildMinimalViableProduct();
	product* min = sankar.result();
	min->showprod();cout<<"\n";
	sankar.BuildFullFeaturedProduct();
	product* max = sankar.result();
	max->showprod();
	return 0;
}