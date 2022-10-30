#include <bits/stdc++.h>
using namespace std;

class Target {
 public:
  virtual void Request() {
    cout<<"Target class";
  }
};

class Adaptee {
 public:
  void SpecificRequest() {
    cout<<"Adaptee class";
  }
};

class Adapter : public Target {
 private:
  Adaptee *adaptee_;

 public:
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
  void Request() {
    cout<<"Adapter calling adaptee class\n";
    adaptee_->SpecificRequest();
  }
};

int main() {
  Target target;
  Adaptee adaptee;
  Adapter adapter(&adaptee);
  adapter.Request();

  return 0;
}
