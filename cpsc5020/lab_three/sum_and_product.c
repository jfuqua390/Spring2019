#include <stdio.h>

int main() {
  int x, y;
  printf("Enter two integers: ");
  scanf("%d %d", &x, &y);

  int s = x+y;
  int p = x*y;
  printf("The sum of the two numbers is: %d, and the product is: %d \n", s, p);
}
