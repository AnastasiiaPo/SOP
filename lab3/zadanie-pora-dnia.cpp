#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

enum class Time_of_day {
    RANO,
    DZIEN,
    WIECZOR,
    NOC,
};

struct Czas {
    using value_type = unsigned int;
    value_type godzina;
    value_type minuta;
    value_type sekunda;
    
    Czas(value_type, value_type, value_type);
    auto to_String() const -> std::string;
};

Czas::Czas(value_type g, value_type m, value_type s)
    : godzina{g}
    , minuta{m}
    , sekunda{s}
{}

auto Czas::time_of_day() const -> Time_of_day {
    if (hour_ < 3) {
        return TimeOfDay::NOC;
    }
    if (hour_ < 6) {
        return TimeOfDay::RANO;
    }
    if (hour_ < 18) {
        return TimeOfDay::DZIEN;
    }
    if (hour_ < 22) {
        return TimeOfDay::WIECZOR;
    }
    return Time_of_day::NOC;
}

auto to_String(time_of_day x) -> std::string {
    switch(x) {
        case Time_of_day::NOC: return "NOC";
        case Time_of_day::RANO: return "RANO";
        case Time_of_day::DZIEN: return "DZIEN";
        case Time_of_day::WIECZOR: return "WIECZOR";
    }
}

auto Czas::to_String() const -> std::string {
    return std::to_String(godzina) + ":" + std::to_String(minuta) + ":" + std::to_String(sekunda);
}

auto main() -> int {
    auto czas = Czas(23, 59, 59);
    std::cout << to_String(czas.time_of_day()) << "\n";
    return 0;
}

void Czas::next_hour() {
    godzina++;
    
    if (godzina == 24) {
        godzina = 0;
    }
}

void Czas::next_minute() {
    minuta++;
    
    if (minuta == 60) {
        minuta = 0;
        next_hour();
    }
}

void Czas::next_second() {
    sekunda++;
    
    if (sekunda == 60) {
        sekunda = 0;
        next_minute();
    }
}
