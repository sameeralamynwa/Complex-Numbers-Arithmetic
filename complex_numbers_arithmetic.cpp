#include <iostream>

using namespace std;

namespace Maths{
  const int mod = 998244353;
  
  template <typename T>
  T max(T a, T b){
    return a > b ? a : b;
  }

  template <typename T>
  T min(T x, T y){
    return x < y ? x : y;
  }
  
  template <typename T>
  T abs(T x){
    return x < 0 ? -x : x;
  }
  
  template <typename T>
  T power(T x, T y){
    T res = 1;
    while(y > 0){
      if(y & 1){
        res *= x;
      }
      x *= x;
      y >>= 1;
    }
    return res;
  }
  
  template <typename T>
  T modularPower(T x, T y){
    T res = 1;
    while(y > 0){
      if(y & 1){
        res = res * x % Maths :: mod;
      }
      x = x * x % Maths :: mod;
      y >>= 1;
    }
    return res;
  }
  
  template <typename T>
  T modularInverse(T x){
    return Maths :: modularPower(x, mod - 2);
  }
  
  template <typename T>
  T gcd(T x, T y){
    return !x ? y : Maths :: gcd(y % x, x);
  }
  
  template <typename T>
  T lcm(T x, T y){
    return x * y / Maths :: gcd(x, y);
  }
  
}

template <typename T>
class Fraction{
  T n, d;
  
  public:
  Fraction(){
    
  }
  
  Fraction(T n, T d){
    T gcd = Maths :: gcd(n, d);
    this -> n = n / gcd;
    this -> d = d / gcd;
  }
  
  void print(){
    cout << (n < 0) ^ (d < 0) ? "-" : "" << abs(n) << "/" << abs(d) << endl;
  }
  
};

template <typename T>
class ComplexNumbers{
  T r, i;
  
  public:
  Complex(){
    
  }
  
  Complex(T r, T i){
    this -> r = r;
    this -> i = i;
  }
  
  void print(){
    
  }
  
};

int main(){
  cout << Maths :: power(3, 5) << endl;
}
