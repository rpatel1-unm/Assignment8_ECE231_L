#include <iostream>
#include <cmath>

const double PI = 3.14159265358979;
const double EPS0 = 8.854e-12;
const double MU0 = 4e-7 * PI;

class Field {
protected:
    double *value;

public:
    Field() {
        value = new double[3];
        for (int i = 0; i < 3; i++)
            value[i] = 0;
    }

    Field(double x, double y, double z) {
        value = new double[3];
        value[0] = x;
        value[1] = y;
        value[2] = z;
    }

    Field(const Field &f) {
        value = new double[3];
        for (int i = 0; i < 3; i++)
            value[i] = f.value[i];
    }

    Field &operator=(const Field &f) {
        if (this != &f) {
            for (int i = 0; i < 3; i++)
                value[i] = f.value[i];
        }
        return *this;
    }

    ~Field() {
        delete[] value;
    }

    void printMagnitude() {
        std::cout << "x = " << value[0] << ", y = " << value[1]
                  << ", z = " << value[2] << std::endl;
    }
};

class Electric_Field : public Field {
private:
    double calcE;

public:
    Electric_Field() : Field() {
        calcE = 0;
    }

    Electric_Field(double x, double y, double z) : Field(x, y, z) {
        calcE = 0;
    }

    Electric_Field(const Electric_Field &e) : Field(e) {
        calcE = e.calcE;
    }

    Electric_Field &operator=(const Electric_Field &e) {
        Field::operator=(e);
        calcE = e.calcE;
        return *this;
    }

    void calculateE(double Q, double r) {
        calcE = Q / (4 * PI * r * r * EPS0);
    }

    double getE() {
        return calcE;
    }

    Electric_Field operator+(const Electric_Field &e) {
        Electric_Field temp(value[0] + e.value[0],
                            value[1] + e.value[1],
                            value[2] + e.value[2]);
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &out, const Electric_Field &e) {
        out << "(" << e.value[0] << ", " << e.value[1] << ", "
            << e.value[2] << ")";
        return out;
    }
};

class Magnetic_Field : public Field {
private:
    double calcB;

public:
    Magnetic_Field() : Field() {
        calcB = 0;
    }

    Magnetic_Field(double x, double y, double z) : Field(x, y, z) {
        calcB = 0;
    }

    Magnetic_Field(const Magnetic_Field &b) : Field(b) {
        calcB = b.calcB;
    }

    Magnetic_Field &operator=(const Magnetic_Field &b) {
        Field::operator=(b);
        calcB = b.calcB;
        return *this;
    }

    void calculateB(double I, double r) {
        calcB = MU0 * I / (2 * PI * r);
    }

    double getB() {
        return calcB;
    }

    Magnetic_Field operator+(const Magnetic_Field &b) {
        Magnetic_Field temp(value[0] + b.value[0],
                            value[1] + b.value[1],
                            value[2] + b.value[2]);
        return temp;
    }

    friend std::ostream &operator<<(std::ostream &out, const Magnetic_Field &b) {
        out << "(" << b.value[0] << ", " << b.value[1] << ", "
            << b.value[2] << ")";
        return out;
    }
};

int main() {
    Electric_Field E1(0, 1e5, 1e3);
    Magnetic_Field B1(2e-5, 0, 3e-5);

    std::cout << "Electric field components:" << std::endl;
    E1.printMagnitude();
    std::cout << "Magnetic field components:" << std::endl;
    B1.printMagnitude();

    E1.calculateE(1e-6, 0.5);
    std::cout << "\nElectric field from Gauss' law (Q = 1e-6 C, r = 0.5 m): "
              << E1.getE() << " N/C" << std::endl;

    B1.calculateB(10, 0.05);
    std::cout << "Magnetic field from Ampere's law (I = 10 A, r = 0.05 m): "
              << B1.getB() << " T" << std::endl;

    Electric_Field e2(1, 2, 3), e3(4, 5, 6), e4;
    e4 = e2 + e3;
    std::cout << "\ne2 = " << e2 << std::endl;
    std::cout << "e3 = " << e3 << std::endl;
    std::cout << "e2 + e3 = " << e4 << std::endl;

    Magnetic_Field b2(1e-5, 2e-5, 3e-5), b3(4e-5, 5e-5, 6e-5), b4;
    b4 = b2 + b3;
    std::cout << "\nb2 = " << b2 << std::endl;
    std::cout << "b3 = " << b3 << std::endl;
    std::cout << "b2 + b3 = " << b4 << std::endl;

    return 0;
}
