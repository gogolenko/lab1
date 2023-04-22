#include <iostream>
class Lamp {
    bool state;
public:
    static int count;
    static int size;
    Lamp();
    ~Lamp();
    void turnOn();
    void turnOff();
    bool isTurned();
};

int Lamp::count = 0;
int Lamp::size = 0;

Lamp::Lamp() {
    state = false;

    if (count == 0)
        std::cout << "First object has been created\n";
    count++;
    size += sizeof(Lamp);
    std::cout << "count = " << count << std::endl;
    std::cout << "size = " << size << "\n\n";
}

Lamp::~Lamp() {
    count--;
    size -= sizeof(Lamp);
    if (count == 0)
        std::cout << "Last element has been deleted\n";
    std::cout << "count = " << count << std::endl;
    std::cout << "size = " << size << "\n\n";
}

void Lamp::turnOn() {
    state = true;
}

void Lamp::turnOff() {
    state = false;
}

bool Lamp::isTurned() {
    return state;
}

int main() {
    Lamp* l;
    l = new Lamp[2];
    delete[] l;
    return 0;
}
