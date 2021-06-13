#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>

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
    
    Czas dodawanie(const Czas czas);
    Czas odejmowanie(const Czas czas);
    bool mniej(const Czas czas);
    bool wiecej(const Czas czas);
    bool rowno(const Czas czas);
    bool nie_rowno(const Czas czas);
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
    auto czas1 = Czas(23, 59, 59);
    auto czas2 = Czas(10, 30, 30);
    //czas.next_godzina();
    //czas.next_minuta();
    //czas.next_sekunda();
    std::cout << czas1.to_String() << "\n";
    
    std::cout << czas1.mniej(czas2) << "\n";
    std::cout << czas1.wiecej(czas2) << "\n";
    std::cout << czas1.rowno(czas2) << "\n";
    std::cout << czas1.nie_rowno(czas2) << "\n";
    
    czas2 = czas1.dodawanie(czas1);
    std::cout << czas2.to_String();
    
    czas2 = czas1.odejmowanie(czas1);
    std::cout << czas2.to_String();
    
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

Czas Czas::dodawanie(Czas czas) {
	int g;
	int m;
	int s;
	
	g = godzina + czas.godzina;
	m = minuta + czas.minuta;
	s = sekunda + czas.sekunda;
	
	if (g >= 60) {
		g -= 24;
	}
	
	if (m >= 60) {
		m -= 60;
		g++;
	}
	
	if (s >= 60) {
		s -= 60;
		m++;
	}
	
	Czas c = Czas(g, m, s);
	return c;
}

Czas Czas::odejmowanie(Czas czas) {
	int g;
	int m;
	int s;
	
	g = godzina - czas.godzina;
	m = minuta - czas.minuta;
	s = sekunda - czas.sekunda;
	
	if (g < 0) {
		g += 24;
	}
	
	if (m < 0) {
		m += 60;
		g--;
	}
	
	if (s < 0) {
		s += 60;
		m--;
	}
	
	Czas c = Czas(g, m, s);
	return c;
}

bool Czas::mniej(Czas czas) {
	if (godzina < czas.godzina) {
		return true;
	} else if (godzina == czas.godzina) {
		if (minuta < czas.minuta) {
			return true;
	} else if (minuta == czas.minuta) {
		if (sekunda < czas.sekunda) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
    } else {
		return false;
	}
}

bool Czas::rowno(Czas czas) {
	if (godzina == czas.godzina && minuta == czas.minuta && sekunda == czas.sekunda) {
		return true;
	} else {
		return false;
	}
}

bool Czas::nie_rowno(Czas czas) {
	if (godzina == czas.godzina && minuta == czas.minuta && sekunda == czas.sekunda) {
		return false;
	} else {
		return true;
	}
}
