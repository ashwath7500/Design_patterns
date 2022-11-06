#include<bits/stdc++.h>
using namespace std;

class Implementation {
 public:
  void OperationImplementation() {
    cout<<"Implementation being done in backend.";
  }
};

class Abstraction {
 private:
  Implementation* implementation_;

 public:
  Abstraction(Implementation* implementation) : implementation_(implementation) {
  }

  void Operation() {
    cout<<"Front-end layer being called";
    implementation_->OperationImplementation();
  }
};

int main() {
  Implementation back_end;
  Abstraction front_end(&back_end);
  front_end.Operation();

  return 0;
}