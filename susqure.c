#include <stdio.h>
int main(void)
{
  char *s;
  size_t i;
  unsigned ctr = 0;
  size_t n = 1000000;
  const unsigned target_val = 1001;
  s = calloc(n, sizeof *s);
  for (i = 2; i < n; i++) {
    if (!s[i]) {
      size_t j;
      ctr++;
      if (ctr == target_val) {
        printf("%lu\n", i);
        break;
      }
      for (j = i*2; j < n; j += i) {
        s[j] = 1;
      }
    }
  }
  free(s);
  return 0;
}