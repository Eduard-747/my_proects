#include <iostream>

int reverse(int num);
bool isPalindrome(int num);
int PalindromesCount(int digit);

int main()
{
  const int digit = 4;
  std::cout << "Palindromes count: " << PalindromesCount(digit) << std::endl;
  
  return 0;
}

int reverse(int num) 
{
  int tmp = 0;
  while (num > 0) {
    tmp = tmp * 10 + num % 10;
    num = num / 10;
  }
  return tmp;
}

bool isPalindrome(int num)
{
  if (num == reverse(num))
    return true;
 
  return false;
}

int PalindromesCount(int digit)
{
  int smallest = pow(10, digit - 1) + 1;
  int largest = pow(10, digit) - 1;
  int count {};

  for (int i = smallest; i < largest; i += smallest) 
  {
    for(int j = i; j < i + smallest; j += 10)
      if (isPalindrome(j))
      {
        ++count;
      }
  }

  return count;
}
