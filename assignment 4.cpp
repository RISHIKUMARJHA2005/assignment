#include <iostream>
using namespace std;

class computation {
public:
    int compute(int a, int b) {
        return a + b;
    }

    float compute(int a, float b) {
        return a + b;
    }

    double compute(int a, double b) {
        return a + b;
    }

    int compute(char a, char b) {
        return int(a) + int(b);
    }

    int compute(char a, int b) {
        return int(a) + b;
    }

    int compute() {
        return 0;
    }
};

int main() {
    computation obj;

    cout << "1 + 2 = " << obj.compute(1, 2) << endl;
    cout << "1 + 2.5 = " << obj.compute(1, 2.5f) << endl;
    cout << "1 + 2.5 = " << obj.compute(1, 2.5) << endl;
    cout << "ASCII value of 'A' + 'B' = " << obj.compute('A', 'B') << endl;
    cout << "ASCII value of 'A' + 5 = " << obj.compute('A', 5) << endl;
    cout << "Default value = " << obj.compute() << endl;

    return 0;
}
