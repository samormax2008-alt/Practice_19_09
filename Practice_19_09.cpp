#include <iostream>
#include <cstring>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 2000)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() const
    {
        return day;
    }

    int getMonth() const
    {
        return month;
    }

    int getYear() const
    {
        return year;
    }
};


class Person
{
private:
    char* id;
    char* surname;
    char* name;
    char* patronymic;
    Date birthDate;

    static int count;

public:
    Person(const char* id, const char* surname, const char* name,
        const char* patronymic, Date birthDate)
        : birthDate(birthDate)
    {
        this->id = new char[strlen(id) + 1];
        strcpy_s(this->id, strlen(id) + 1, id);

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);

        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);

        count++;
    }

    Person() : Person("000000", "Unknown", "Unknown", "Unknown", Date())
    {
    }

    ~Person()
    {
        delete[] id;
        delete[] surname;
        delete[] name;
        delete[] patronymic;

        count--;
    }

    static int getCount()
    {
        return count;
    }

    const char* getId() const
    {
        return id;
    }

    const char* getSurname() const
    {
        return surname;
    }

    const char* getName() const
    {
        return name;
    }

    const char* getPatronymic() const
    {
        return patronymic;
    }

    Date getBirthDate() const
    {
        return birthDate;
    }

    Person& setId(const char* id)
    {
        delete[] this->id;

        this->id = new char[strlen(id) + 1];
        strcpy_s(this->id, strlen(id) + 1, id);

        return *this;
    }

    Person& setSurname(const char* surname)
    {
        delete[] this->surname;

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);

        return *this;
    }

    Person& setName(const char* name)
    {
        delete[] this->name;

        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        return *this;
    }

    Person& setPatronymic(const char* patronymic)
    {
        delete[] this->patronymic;

        this->patronymic = new char[strlen(patronymic) + 1];
        strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);

        return *this;
    }

    void show() const
    {
        cout << "ID: " << id << endl;
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Patronymic: " << patronymic << endl;

        cout << "Date of birth: "
            << birthDate.getDay() << "."
            << birthDate.getMonth() << "."
            << birthDate.getYear() << endl;
    }
};

int Person::count = 0;


int main()
{
    Person person1(
        "123456",
        "Ivanov",
        "Ivan",
        "Ivanovich",
        Date(15, 5, 2005)
    );

    Person person2;

    person2
        .setId("654321")
        .setSurname("Petrov")
        .setName("Petr")
        .setPatronymic("Petrovich");

    cout << "----- Person 1 -----" << endl;
    person1.show();

    cout << endl;

    cout << "----- Person 2 -----" << endl;
    person2.show();

    cout << endl;

    cout << "Number of objects: "
        << Person::getCount() << endl;

    return 0;
}