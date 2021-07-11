#include <iostream>

using namespace std;

//====Exercise 1=====================================================================================

class Figure {
public: 
    virtual double area() = 0;
};

class Circle : virtual public Figure {
private:
    double rad, pi = 3.14;
public:
    Circle(double r) : rad(r) {

    }
    double area() override {
        return (pi * rad * rad);
    }
};

class Parallelogram : virtual public Figure {
protected: 
    double a, b, alpha;
public:
    Parallelogram(double a1, double b1, double al) : a(a1), b(b1), alpha(al) {}
    double area() override {
        return (a * b * sin(alpha));
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a1, double b1, double al = 90) : Parallelogram(a1, b1, al) {}
    double area() override {
        return (a * b);
    }
};

class Square : public Parallelogram {
public:
    Square(double a1, double b1 = 0, double al = 90) : Parallelogram(a1, b1, al) {}
    double area() override {
        return (a * a);
    }
}; 

class Rhombus : public Parallelogram {
public:
    Rhombus(double a1, double al, double b1 = 0) : Parallelogram(a1, b1, al) {}
    double area() override {
        return (a * a * sin(alpha));
    }
};

//====Exercise 2=====================================================================================

class Car{
protected:
    string company, model;
public:
    Car(string comp, string mod) : company(comp), model(mod) {
        cout << " Company: " << company << "   Model: " << model << endl;
    }
};
class PassengerCar : virtual public Car {
public:
    PassengerCar(string comp, string mod) : Car(comp, mod) {
        cout << " Company: " << company << "   Model: " << model << endl;
    }
};
class Bus : virtual public Car {
public:
    Bus(string comp, string mod) : Car(comp, mod) {
        cout << " Company: " << company << "   Model: " << model << endl;
    }
};
class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string comp, string mod) : PassengerCar(comp, mod), Bus(comp, mod), Car(comp, mod) {
        cout << " Company: " << company << "   Model: " << model << endl;
    }
};

//====Exercise 3=====================================================================================

class Fraction {
private:
    int num = 1, den = 1;
public:
    Fraction(){}

    Fraction(int n2, int d2) {
        if (d2 != 0) {
            num = n2;
            den = d2;
        }
        else cout << " Denominator can't equal 0" << endl;
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1);
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);

    void Reduction() {
        while (num % 2 == 0 && den % 2 == 0) {
            num = num / 2;
            den = den / 2;
        }
        while (num % 3 == 0 && den % 3 == 0) {
            num = num / 3;
            den = den / 3;
        }
        while (num % 5 == 0 && den % 5 == 0) {
            num = num / 5;
            den = den / 5;
        }
        while (num % 7 == 0 && den % 7 == 0) {
            num = num / 7;
            den = den / 7;
        }
    }
    void print() const {
        cout << " " << num << "/" << den << endl;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int rezN, rezD = f1.den;
    if (f1.den == f2.den) rezN = f1.num + f2.num;
    else {
        rezN = f1.num * f2.den + f2.num * f1.den;
        rezD = f1.den * f2.den;
    }
    Fraction f3(rezN, rezD);
    f3.Reduction();
    return f3;
};
Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int rezN, rezD = f1.den;
    if (f1.den == f2.den) rezN = f1.num - f2.num;
    else {
        rezN = f1.num * f2.den - f2.num * f1.den;
        rezD = f1.den * f2.den;
    }
    Fraction f3(rezN, rezD);
    f3.Reduction();
    return f3;
};
Fraction operator*(const Fraction& f1, const Fraction& f2) {    
    Fraction f3(f1.num*f2.num,f1.den*f2.den);
    f3.Reduction();
    return f3;
};
Fraction operator/(const Fraction& f1, const Fraction& f2) {
    Fraction f3(f1.num*f2.den,f1.den*f2.num);
    f3.Reduction();
    return f3;
};
Fraction operator-(const Fraction& f1) { return Fraction(-f1.num,f1.den); };
bool operator==(const Fraction& f1, const Fraction& f2) { return (f1.num == f2.num && f1.den == f2.den); };
bool operator!=(const Fraction& f1, const Fraction& f2) { return !(f1 == f2); };
bool operator>(const Fraction& f1, const Fraction& f2) { return (f1.num*f2.den > f2.num*f1.den); };
bool operator<(const Fraction& f1, const Fraction& f2) { return (f1.num * f2.den < f2.num* f1.den); };
bool operator>=(const Fraction& f1, const Fraction& f2) { return !(f1 < f2); };
bool operator<=(const Fraction& f1, const Fraction& f2) { return !(f1 > f2); };

//====Exercise 4=====================================================================================

enum cardtype { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };
enum suit { diamonds, clubs, heart, spades};

class Card {
private:
    cardtype type;
    suit suit;
    bool position = false;
    
public:
    void Flip() {
        if (position == false) position = true; else position = false;
    }

    int GetValue() {
        if (type == ace) return 1;
        if (type == two) return 2;
        if (type == three) return 3;
        if (type == four) return 4;
        if (type == five) return 5;
        if (type == six) return 6;
        if (type == seven) return 7;
        if (type == eight) return 8;
        if (type == nine) return 9;
        if (type == ten || type == jack || type == queen || type == king) return 10;
    }
};

//===================================================================================================

int main()
{
    cout << " Ex 1" << endl;
    Circle c1(3);
    cout << " Circle area:" << c1.area() << endl;
    Parallelogram par1(3, 4, 120);
    cout << " Parallelogram area:" << par1.area() << endl;
    Square s1(3);
    cout << " Square area:" << s1.area() << endl;
    Rectangle rec1(3, 5);
    cout << " Rectangle area:" << rec1.area() << endl;
    Rhombus rh1(3, 120);
    cout << " Rhombus area:" << rh1.area() << endl;
    //===================================================================================================

    cout << " Ex 2" << endl;
    Car car("mazra","RX-7");
    cout << endl;
    PassengerCar pascar("Reno","Logan");
    cout << endl;
    Bus bus("Man","Midibus");
    cout << endl;
    Minivan min("BMW","Grand Tourer");
    cout << endl;

    //===================================================================================================
    
    cout << " Ex 3" << endl;
    Fraction f1(7, 10), f2(1, 5), frez;

    frez = f1 + f2;
    frez.Reduction();
    frez.print();
    frez = f1 - f2;
    frez.Reduction();
    frez.print();
    frez = f1 * f2;
    frez.Reduction();
    frez.print();
    frez = f1 / f2;
    frez.Reduction();
    frez.print();
    frez = -frez;
    frez.Reduction();
    frez.print();
    if (f1 > f2) cout << " True" << endl; else cout << " False" << endl;
    if (f1 < f2) cout << " True" << endl; else cout << " False" << endl;
    if (f1 >= f2) cout << " True" << endl; else cout << " False" << endl;
    if (f1 <= f2) cout << " True" << endl; else cout << " False" << endl;   

    return 0;
}


