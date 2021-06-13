#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

struct Student {
    std::string imie;
    std::string nazwisko;
    std::string indeks;
    int aktualny_semestr;
    float srednia_ocen;
    
    Student(std::string imie, std::string nazwisko, std::string indeks, int aktualny_semestr, 
    float srednia_ocen);
    
    std::string toString();
}

Student::Student(std::string im, std::string na, std::string in, int as, float so) {
    imie = im;
    nazwisko = na;
    indeks = in;
    aktualny_semestr = as; 
    srednia_ocen = so;
}

auto main() -> int {
    auto student = Student("Anastasiia", "Ponkratova", "s12345", 3, 3.5);
    std::cout << student.toString();
    
    return 0;
}

std::string Student::toString() {
	std::string aktualny_semestr_str = std::to_string(aktualny_semestr);
	std::string srednia_ocen_str = std::to_string(srednia_ocen);
	
    return imie + " " + nazwisko + " " + indeks + " " + aktualny_semestr_str + " " + srednia_ocen_str;
}
