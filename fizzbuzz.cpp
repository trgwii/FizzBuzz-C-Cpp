#include <iostream>
#include <ranges>
#include <sstream>

auto main(int argc, char **argv) -> int {
  uint64_t limit = 100;
  if (argc >= 2) {
    uint64_t parsed;
    ((std::istringstream)argv[1]) >> parsed;
    if (parsed)
      limit = parsed;
  }
  for (uint64_t i = 0; i <= limit; i++) {
    if (i % 15 == 0)
      std::cout << "FizzBuzz";
    else if (i % 5 == 0)
      std::cout << "Buzz";
    else if (i % 3 == 0)
      std::cout << "Fizz";
    else
      std::cout << i;
    std::cout << std::endl;
  }
}
