#include <bits/stdc++.h>
using namespace std;

class Handler {
 public:
  virtual shared_ptr<Handler> SetNext(shared_ptr<Handler> handler) = 0;
  virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public Handler {
 private:
  shared_ptr<Handler> next_handler_;

 public:
  AbstractHandler() : next_handler_(nullptr) {
  }
  shared_ptr<Handler> SetNext(shared_ptr<Handler> handler) override {
    this->next_handler_ = handler;
    return handler;
  }
  std::string Handle(std::string request) override {
    if (this->next_handler_) {
      return this->next_handler_->Handle(request);
    }

    return {};
  }
};

class MonkeyHandler : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "Banana") {
      return "Monkey: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class SquirrelHandler : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "Nut") {
      return "Squirrel: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class DogHandler : public AbstractHandler {
 public:
  std::string Handle(std::string request) override {
    if (request == "MeatBall") {
      return "Dog: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};

void ClientCode(Handler &handler) {
  vector<string> food = {"Nut", "Banana", "Cup of coffee"};
  for (const string &f : food) {
    cout << "Client: Who wants a " << f << "?\n";
    const std::string result = handler.Handle(f);
    if (!result.empty()) {
      cout << "  " << result;
    } else {
      cout << "  " << f << " was left untouched.\n";
    }
  }
}

int main() {
  shared_ptr<AbstractHandler> monkey = make_shared<MonkeyHandler>();
  shared_ptr<AbstractHandler> squirrel = make_shared<SquirrelHandler>();
  shared_ptr<AbstractHandler> dog = make_shared<DogHandler>();
  monkey->SetNext(squirrel)->SetNext(dog);

  cout << "Chain: Monkey > Squirrel > Dog\n\n";
  ClientCode(*monkey);
  cout << "\n";
  cout << "Subchain: Squirrel > Dog\n\n";
  ClientCode(*squirrel);

  return 0;
}