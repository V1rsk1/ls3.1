#include <iostream>
#include<Windows.h>
using namespace std;


class Date {
public:
    int day, month, year;

    Date() : day(0), month(0), year(0) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void print() const {
        cout << day << "." << month << "." << year;
    }
};

class Human {
public:
    int id;
    string surname;
    string name;
    string fatherName;
    Date birthDate;

    Human() : id(0), surname(""), name(""), fatherName(""), birthDate() {}

    Human(int i, string s, string n, string f, int d, int m, int y)
        : id(i), surname(s), name(n), fatherName(f), birthDate(d, m, y) {}

    void print() const {
        cout << id << " - " << surname << " " << name << " " << fatherName << ", ";
        birthDate.print();
        cout << endl;
    }
};

class Flat {
public:
    Human people[10];
    int count;

    Flat() : count(0) {}

    Flat(Human humans[], int c) : count(c) {
        for (int i = 0; i < count; i++) {
            people[i] = humans[i];
        }
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            people[i].print();
        }
    }
};

class Building {
public:
    Flat flats[10];
    int count;

    Building() : count(0) {}

    Building(Flat flatsList[], int c) : count(c) {
        for (int i = 0; i < count; i++) {
            flats[i] = flatsList[i];
        }
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            cout << "Квартира " << i + 1 << ":" << endl;
            flats[i].print();
            cout << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);




    Human flat1[] = { {1, "Иванов", "Иван", "Петрович", 28, 1, 1978} };
    Human flat2[] = { {2, "Сидоров", "Дмитрий", "Алексеевич", 2, 3, 1996},
                      {3, "Петров", "Алексей", "Игоревич", 6, 9, 1992} };
    Human flat3[] = { {4, "Кузнецова", "Ольга", "Владимировна", 4, 6, 2001},
                      {5, "Кузнецов", "Антон", "Владимирович", 15, 10, 2000},
                      {6, "Кузнецова", "Анна", "Антоновна", 25, 7, 2021} };
    Human flat4[] = { {7, "Михайлова", "Мария", "Геннадьевна", 17, 8, 1967},
                      {8, "Михайлов", "Сергей", "Александрович", 21, 4, 1958},
                      {9, "Михайлов", "Артем", "Сергеевич", 25, 7, 1988},
                      {10, "Михайлова", "Елена", "Сергеевна", 25, 7, 1995} };
    Human flat5[] = { {11, "Николаева", "Светлана", "Ивановна", 3, 2, 1998},
                      {12, "Николаев", "Владислав", "Михайлович", 21, 4, 1993},
                      {13, "Николаев", "Александр", "Владиславович", 4, 12, 2018},
                      {14, "Николаева", "Дарья", "Владиславовна", 13, 11, 2020},
                      {15, "Николаев", "Павел", "Владиславович", 13, 11, 2020} };

    Flat flats[] = { Flat(flat1, 1), Flat(flat2, 2), Flat(flat3, 3), Flat(flat4, 4), Flat(flat5, 5) };

    Building building(flats, 5);
    building.print();

    return 0;
}
