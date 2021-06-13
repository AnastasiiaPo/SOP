#include <iostream>
#include <stdlib.h>

auto main(int argc, char *argv[]) -> int {
  auto zmienna = argv[1];
  
  auto resoult = getenv(zmienna);
  
  if (resoult != nullptr) {
    std::cout << resoult << '\n';
  }
  
  return 0;
}
