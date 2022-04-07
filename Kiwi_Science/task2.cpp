#include <iostream>

bool isPrime(int num);
int returnPrime(int n);

int main()
{
  
  std::cout << "Enter N - ";
  int N;
  std::cin >> N;
  std::cout << "N - th prime number is: " << returnPrime(N) << std::endl;

  return 0;
}

bool isPrime(int num)
{
  for (int i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0) return false;
  }
  return true;
}

int returnPrime(int n)
{
  int count = 2;
  for (int i = 5; ; i = i+2)
  {
    if(isPrime(i))
    {
      ++count;
    }
    if(count == n)
    {
      return i;
    }
  }
  return 0;
}
