#include <iostream>
#include <string>
#include <sstream>

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
    int count_sekundy();
    int count_minuty();
    Czas czas_do_polnocy();
};

Czas::Czas(value_type g, value_type m, value_type s)
    : godzina{g}
    , minuta{m}
    , sekunda{s}
{}

auto Czas::to_String() const -> std::string {
    return std::to_String(godzina) + ":" + std::to_String(minuta) + ":" + std::to_String(sekunda);
}

auto main() -> int {
    auto czas = Czas(23, 59, 59);
    //czas.next_godzina();
    //czas.next_minuta();
    //czas.next_sekunda();
    std::cout << czas.to_String() << "\n";
    
    std::cout << czas.count_minuty() << "\n";
    std::cout << czas.count_sekundy() << "\n";
  
    czas = czas.czas_do_polnocy();
    std::cout << czas.to_String() << "\n";
    
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

int Czas::count_sekundy() {
	return (godzina * 3600) + (minuta * 60) + sekunda;
}

int Czas::count_minuty() {
	return (godzina * 60) + minuta;
}

Czas Czas::czas_do_polnocy() {
	if (count_sekundy() == 0) {
		return Czas(0, 0, 0);
	}
	
	auto iloscSekund = 86400 - count_sekundy();
	
	auto g = iloscSekund/3600;
	iloscSekund = iloscSekund % 3600;
	
	auto m = iloscSekund / 60;
	auto s = iloscSekund % 60;
	
	return Czas(g, m, s);
}
