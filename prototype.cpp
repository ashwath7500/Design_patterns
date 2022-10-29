#include <bits/stdc++.h>
using namespace std;

class Prototype {
 protected:
  string prototype_name_;

 public:
  virtual Prototype *Clone() const = 0;
  virtual void Method() {
    cout << "Call Method from " << prototype_name_ <<"\n";
  }
};

class ConcretePrototype1 : public Prototype {
 public:
  ConcretePrototype1() {
    prototype_name_ = "Type 1";
  }
  Prototype *Clone() const override {
    return new ConcretePrototype1();
  }
};

class ConcretePrototype2 : public Prototype {
 public:
  ConcretePrototype2() {
    prototype_name_ = "Type 2";
  }
  Prototype *Clone() const override {
    return new ConcretePrototype2();
  }
};

int main() {
  unique_ptr<Prototype> prot(new ConcretePrototype1);
  unique_ptr<Prototype> clone1(prot->Clone());
  unique_ptr<Prototype> prot2(new ConcretePrototype2);
  unique_ptr<Prototype> clone2(prot2->Clone());
  prot->Method();
  prot2->Method();
  clone1->Method();
  clone2->Method();
  return 0;
}