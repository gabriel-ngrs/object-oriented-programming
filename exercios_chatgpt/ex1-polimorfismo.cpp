#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void falar() = 0;
};

class Cachorro : public Animal {
    public:
        void falar() override {
            cout << "Au au" << endl;
        }
};

class Gato : public Animal{
    public:
        void falar() override {
            cout << "Miau" << endl;
        }
};

class Vaca : public Animal {
    public:
        void falar() override {
            cout << "Muuuu" << endl;
        }
};

int main() {
    Animal* a1 = new Cachorro();
    Animal* a2 = new Gato();
    Animal* a3 = new Vaca();
    a1->falar();
    a2->falar();
    a3->falar();

    delete a1;
    delete a2;
    delete a3;
    return 0;
}