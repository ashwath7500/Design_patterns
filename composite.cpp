#include <bits/stdc++.h>
using namespace std;

class Component {
 protected:
  Component *parent_;
 public:
  void SetParent(Component *parent) {
    this->parent_ = parent;
  }
  Component *GetParent() {
    return this->parent_;
  }
  virtual void Add(Component *component) {}
  virtual void Remove(Component *component) {}
  virtual bool IsComposite() {
    return false;
  }
  virtual void Operation() = 0;
};

class Leaf : public Component {
 public:
  void Operation() {
    cout<<"Leaf component";
  }
};

class Composite : public Component {
 protected:
  std::list<Component *> children_;

 public:
  void Add(Component *component) {
    this->children_.push_back(component);
    component->SetParent(this);
  }
  void Remove(Component *component) {
    children_.remove(component);
    component->SetParent(nullptr);
  }
  bool IsComposite() {
    return true;
  }
  void Operation() {
    string result;
    cout<<"Branch(";
    for (Component *c : children_) {
      if (c == children_.back()) {
        c->Operation();
      } else {
        c->Operation();
        cout<<"+";
      }
    }
    cout<<")";
  }
};

int main() {
  Component *tree = new Composite;
  Component *branch1 = new Composite;

  Component *leaf_1 = new Leaf;
  Component *leaf_2 = new Leaf;
  Component *leaf_3 = new Leaf;
  tree->Add(branch1);
  tree->Add(leaf_1);
  branch1->Add(leaf_2);
  branch1->Add(leaf_3);
  tree->Operation();

  delete tree;
  delete branch1;
  delete leaf_1;
  delete leaf_2;
  delete leaf_3;

  return 0;
}