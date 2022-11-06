#include <bits/stdc++.h>
using namespace std;

class ArrayProxy {
public:
    ArrayProxy(int& val) : elemPtr(&val) {}
    void operator = (int val) {
        if (val > 1 || val < 0) {
            throw "not 0 or 1";
        }
        *elemPtr = val;
    }
 private:
    int * elemPtr;
};

class Array {
private:
    int elemArray[10];
public:
    ArrayProxy operator[](int i) {
        return ArrayProxy(elemArray[i]);
    }
};

int main() {
    Array arr;
    arr[0] = 0;
    //arr[1] = 5;
    return 0;
}