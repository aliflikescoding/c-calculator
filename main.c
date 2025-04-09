#include <stdio.h>
#include <stdlib.h>

void calculate(float a, float b, char operator, float *result)
{
  if (operator== '*')
  {
    *result = a * b;
  }
  else if (operator== '+')
  {
    *result = a + b;
  }
  else if (operator== '/')
  {
    *result = a / b;
  }
  else if (operator== '-')
  {
    *result = a - b;
  }
  else
  {
    printf("Not a valid operator :(\n");
  }

  printf("your result is: %f\n", *result);
}

int main()
{
  float a, b, result;
  char operator;
  // booleans
  int isRunning, isVal;
  // actual integers
  int cnt;

  isRunning = 1, isVal = 0;
  cnt = 0;
  while (isRunning) 
  {
    cnt++;
    if (cnt < 1)
    {
      printf("Hi welcome to c basic calculator!\n");
    }
    if (isVal == 0)
    {
      printf("Please enter in your first number:\n");
      scanf("%f", &a);
      printf("Options:\nstandard inputs: */+-\ns it to stop\n");
      printf("Enter in your operator:\n");
      scanf(" %c", &operator);
      if (operator== 's')
      {
        printf("Thank you for playing!\n");
        break;
      }
      else if (operator != '*' && operator != '+' && operator != '-' && operator != '/') {
        printf("Not a valid operator\n");
        continue;
      }
      printf("Enter in your second number:\n");
      scanf("%f", &b);
      calculate(a, b, operator, &result);
      isVal = 1;
    }
    else {
      printf("Your last result was: %f\n", result);
      printf("Options:\nstandard inputs: */+-\ns it to stop\nc is to clear your results\n");
      printf("Enter in your operator:\n");
      scanf(" %c", &operator);
      if (operator == 's')
      {
        printf("Thank you for playing!\n");
        break;
      }
      else if (operator == 'c') {
        result = 0;
        isVal = 0;
        printf("Results cleared\n");
        continue;
      }
      else if (operator != '*' && operator != '+' && operator != '-' && operator != '/') {
        printf("Not a valid operator\n");
        continue;
      }
      printf("Please enter in your number:\n");
      scanf("%f", &a);
      calculate(result, a, operator, &result);
    }
  }
  return 0;
}