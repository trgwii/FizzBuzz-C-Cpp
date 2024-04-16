#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static const char *text_table[] = {
    NULL,
    "Buzz",
    "Fizz",
    "FizzBuzz",
};

#define FIZZBUZZ_FMT "%s\n"
#define INT_FMT "%" PRIu64 "\n"
static const char *const fmt_table[] = {INT_FMT, FIZZBUZZ_FMT, FIZZBUZZ_FMT,
                                        FIZZBUZZ_FMT};

int main(int argc, char **argv) {
  uint64_t limit = 100;
  if (argc >= 2) {
    uint64_t parsed;
    if (sscanf(argv[1], "%" SCNu64, &parsed) == 1) {
      limit = parsed;
    }
  }
  for (uint64_t i = 1; i <= limit; i++) {
    uint8_t mask = (uint8_t)((i % 3 == 0) << 1) | (uint8_t)(i % 5 == 0);
    text_table[0] = (char *)i;
    char buf[21];
    int len = snprintf(&buf, 21, fmt_table[mask], text_table[mask]);
    assert(len > 0);
    size_t bytes = fwrite(buf, 1, len, stdout);
    assert(bytes == len);
  }
  fflush(stdout);
}
