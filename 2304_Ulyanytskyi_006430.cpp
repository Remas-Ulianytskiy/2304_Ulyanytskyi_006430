#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Ukrainian_Letter {
private:
    string letter;

public:
    Ukrainian_Letter() : letter("É") {}
    Ukrainian_Letter(const string& letter) : letter(letter) {}
    string get_symbol() const { return letter; }
};

class English_Letter {
private:
    string letter;

public:
    English_Letter() : letter("Q") {}
    English_Letter(const string& letter) : letter(letter) {}
    string get_symbol() const { return letter; }
};

class Number {
private:
    int number;

public:
    Number() : number(0) {}
    Number(int number) : number(number) {}
    int getNumber() const { return number; }
};

class Composition {
private:
    Ukrainian_Letter passport_letter_1;
    Ukrainian_Letter passport_letter_2;
    Ukrainian_Letter car_letters_1;
    Ukrainian_Letter car_letters_2;
    English_Letter iban_letters;
    Number passport_number[6];
    Number iban_number[27];
    Number car_number[4];

public:
    Composition() : 
        passport_letter_1("Ì"),
        passport_letter_2("Å"), 
        car_letters_1("ÊÀ"),
        car_letters_2("ĞÎ"),
        iban_letters("UA")
    {}

    void set_passport_number(const Number(&num_array)[6])
    {
        for (int i = 0; i < 6; ++i)
            passport_number[i] = num_array[i];
    }

    void set_iban_number(const string& iban)
    {
        for (int i = 0; i < 14; ++i)
            iban_number[i] = iban[i];
    }

    void set_car_number(const Number(&num_array)[4])
    {
        for (int i = 0; i < 4; i++)
            car_number[i] = num_array[i];
    }

    string get_passport_string() const
    {
        string result = passport_letter_1.get_symbol() + passport_letter_2.get_symbol();
        for (int i = 0; i < 6; i++)
            result += to_string(passport_number[i].getNumber());
        return result;
    }

    string get_iban_string() const
    {
        string result = iban_letters.get_symbol() + "35" + "377090";
        for (int i = 0; i < 5; ++i)
            result += "0";
        for (int i = 0; i < 14; ++i)
            result += to_string(iban_number[i].getNumber());
        return result;
    }

    string get_car_number_String() const
    {
        string result = car_letters_1.get_symbol();
        for (int i = 0; i < 4; i++)
            result += to_string(car_number[i].getNumber());
        result += car_letters_2.get_symbol();
        return result;
    }

    void display()
    {
        cout << "Ukrainian Passport: " << get_passport_string() << endl;
        cout << "IBAN Number: " << get_iban_string() << endl;
        cout << "Car Number: " << get_car_number_String() << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Number passport_numbers[6] = { 7, 4, 3, 6, 9, 1 };    
    Number car_numbers[4] = { 4, 2, 7, 1 };
    string iban = "45819100265137";

    Composition composition;

    composition.set_passport_number(passport_numbers);
    composition.set_iban_number(iban);
    composition.set_car_number(car_numbers);

    composition.display();

    return 0;
}
