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
    void next_godzina();
    void next_minuta();
    void next_sekunda();
    
    auto time_of_day() const -> Time_of_day;
};

Czas::Czas(value_type g, value_type m, value_type s)
    : godzina{g}
    , minuta{m}
    , sekunda{s}
{}

auto Czas::time_of_day() const -> Time_of_day {
    if (godzina < 3) {
        return Time_of_day::NOC;
    }
    if (godzina < 6) {
        return Time_of_day::RANO;
    }
    if (godzina < 18) {
        return Time_of_day::DZIEN;
    }
    if (godzina < 22) {
        return Time_of_day::WIECZOR;
    }
    return Time_of_day::NOC;
}

auto to_string(Time_of_day x) -> std::string {
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
    std::cout << to_string(czas.time_of_day()) << "\n";
    return 0;
}

void Czas::next_godzina() {
    godzina++;
    
    if (godzina == 24) {
        godzina = 0;
    }
}

void Czas::next_minuta() {
    minuta++;
    
    if (minuta == 60) {
        minuta = 0;
        next_godzina();
    }
}

void Czas::next_sekunda() {
    sekunda++;
    
    if (sekunda == 60) {
        sekunda = 0;
        next_minuta();
    }
}
