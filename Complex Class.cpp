#include <iostream>

using namespace std;

namespace Maths{
  const int mod = 998244353;
  
  template <typename T>
  T max(T x, T y){
    return x > y ? x : y;
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
  double nthRoot(T x, int n, double error = 1e-6){
    double low = 0, high = x;
    while(high - low > error){
      cout << low << " " << high << endl;
      double mid = (low + high) / 2, result = 1;
      for(int i = 0; i < n; ++i){
        result *= mid;
      }
      if(result > x){
        high = mid;
      }
      else{
        low = mid;
      }
    }
    return (low + high) / 2;
  }
  
  template <typename T>
  T power(T x, int y){
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
  T modularPower(T x, int y){
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
class Complex{
  T r, i;
  
  public:
  Complex(){
    
  }
  
  Complex(T r, T i){
    this -> r = r;
    this -> i = i;
  }
  
  static void print(Complex c){
    cout << c.r << (!c.i ? "" : c.i < 0 ? " - " : " + ") << Maths :: abs(c.i) << endl;
  }
  
  void print(){
    cout << r << (!i ? "" : i < 0 ? " - " : " + ") << Maths :: abs(i) << endl;
  }

	Complex operator +(Complex c){
		Complex store;
		store.r = r + c.r;
		store.i = i + c.i;
		return store;
	}

	Complex operator -(Complex c){
		Complex store;
		store.r = r - c.r;
		store.i = i - c.i;
		return store;
	}

	Complex operator *(Complex c){
		Complex store;
		store.r = r * c.r - i * c.i;
		store.i = r * c.i + i * c.r;
		return store;
	}

	Complex operator /(Complex c){
		Complex store;
		store.r = (r * c.r + i * c.i) / (c.r * c.r + c.i * c.i);
		store.i = (i * c.r - r * c.i) / (c.r * c.r + c.i * c.i);
		return store;
	}

	Complex operator -(void){
		Complex store;
		store.r = -r;
		store.i = -i;
		return store;
	}
	
	double modulus(void){
	  return Maths :: nthRoot(r * r + i * i, 2);
	}
  
};

int main(){
  cout << Maths :: power(3, 5) << endl;
  Complex <float> c(4, -5);
  c.print();
  
  Complex <float> f(4, 5.6);
  f.print();
  
  Complex <float> r = f + c;
  r.print();
  Complex <float> :: print(c + f);
  
  cout << Maths :: nthRoot(25, 2+5);
  
}
