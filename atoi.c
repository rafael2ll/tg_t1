#include<stdio.h>

int main(int argc, char const *argv[])
{

char * str = "123";
int result= 0;	
  while ((*str >= '0') && (*str <= '9'))
  {
      result = (result * 10) + ((*str) - '0');
      str++;
  }
  printf("%d\n", result);
	return 0;
}