#include <stdio.h>

int main(void) {
  for (int i = 0; i < 100; i++) {
    printf("This should print 4? times.\n");
    if (i == 3) {
      break;
    }
  }
  return 0;
}
