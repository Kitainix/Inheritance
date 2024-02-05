#include <iostream>

class Base {
private:
	int c;
protected:
	int b;
public:
	Base():Base(0, 0, 0) {}
	Base(int a, int b, int c):a(a), b(b), c(c) {}

	int a;
	int A() {
		return a;
	}
	int B() {
		return b;
	}
	int C() {
		return c;
	}
};

class Derived :public Base {
private:
	int d;
public:
	Derived() = default;
	Derived(int a, int b, int c, int d):Base(a, b, c), d(d) {}

	int M00() {
		int res{};
		res = a + b; // Свободный используем публичные и защищённые поля.
		res /= C(); // Приватные поля доступны через методы доступа внутри класса.
		return res;
	}
	int D() {
		return d;
	}
};

class Animal {
private:
	std::string name;
	int age;
public:
	int Age()const {
		return age;
	}
	void Age(int newAge) {
		age = newAge;
	}

	std::string Name()const {
		return name;
	}
	void Name(std::string newName) {
		name = newName;
	}

	// Виртуальной помечают функцию, которая должна вызываться у наследников в момент их обработки под видом родителя.
	virtual void Say()const {
		std::cout << "R.\n";
	}
};

class Cat :public Animal {
public:
	void Say()const override {
		std::cout << "Meow.\n";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	
	Base obj(1, 2, 5);
	obj.a;
	// obj.b;
	// obj.c;
	Derived dObj(1, 2, 3, 99);
	dObj.B();

	Animal abs;
	abs.Name("Dog");
	abs.Age(1);
	abs.Say();
	Cat cat;
	cat.Name("Fluffy");
	cat.Age(3);
	cat.Say(); // По умолчанию вызовёт свою реализацию.
	cat.Animal::Say(); // Принудительно вызвали реализацию родителя.

	Animal* p = &abs;
	p = &cat;
	p->Say();

	return 0;
}

// Наследование - механизм расширения функционала класса путём сужения его специализации, при котором открывается дорога для полиморфизма.