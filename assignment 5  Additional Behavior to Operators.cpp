#include <iostream>
#include <string>

class User {
private:
    std::string z;
    int y;
    int x;
    int w;
    double v;

public:
    User(std::string z, int y, int x, int w, double v) :
        z(z), y(y), x(x), w(w), v(v) {}

    int operator==(const User& other) const {
        if (y < other.y)
            return -1;
        else if (y > other.y)
            return 1;
        else {
            if (x < other.x)
                return -1;
            else if (x > other.x)
                return 1;
            else {
                if (w < other.w)
                    return -1;
                else if (w > other.w)
                    return 1;
                else
                    return 0;
            }
        }
    }

    double operator+(const User& other) const {
        return (v + other.v) / 2.0;
    }

    double operator+(double increment) const {
        return v + (v * increment / 100);
    }

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "Name: " << user.z << ", Birth Year: " << user.y << ", Salary: " << user.v;
        return os;
    }
};

int main() {
    User z("John", 1990, 5, 15, 50000);
    User y("Alice", 1985, 8, 25, 60000);

    int x = z == y;
    double w = z + y;

    std::cout << "Result of comparison: " << x << std::endl;
    std::cout << "Average salary: " << w << std::endl;

  double v = z + 5;
double u = y + 10;


    std::cout << "New salary of user1 after 5% increment: " << v << std::endl;
    std::cout << "New salary of user2 after 10% increment: " << u << std::endl;

    return 0;
}
