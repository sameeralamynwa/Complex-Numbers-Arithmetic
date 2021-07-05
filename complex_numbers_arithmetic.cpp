					#include <bits/stdc++.h>
					
					const double pi = M_PI;
					
					using namespace std;
					
					class Complex{
						
						double x, y;
						
						public:
						
						Complex(){
							
						}
						
						Complex(double X, double Y){
							x = X;
							y = Y;
						}
						
						
						void print(void){
							cout << x; (y > 0 ? cout << " + " : cout << " - ") << abs(y) << "i" << endl;
						}
						
						Complex operator +(Complex c){
							Complex store;
							store.x = x + c.x;
							store.y = y + c.y;
							return store;
						}
						
						Complex operator -(Complex c){
							Complex store;
							store.x = x - c.x;
							store.y = y - c.y;
							return store;
						}
						
						Complex operator *(Complex c){
							Complex store;
							store.x = x * c.x - y * c.y;
							store.y = x * c.y + y * c.x;
							return store;
						}

						Complex operator /(Complex c){
							Complex store;
							store.x = (x * c.x + y * c.y) / (c.x * c.x + c.y * c.y);
							store.y = (y * c.x - x * c.y) / (c.x * c.x + c.y * c.y);
							return store;
						}
						
						Complex operator -(void){
							Complex store;
							store.x = -x;
							store.y = -y;
							return store;
						}
						
						int quadrant(void){
							if(x == 0 and y == 0){
								cout << "The complex number is the origin and quadrant isn't defined'" << endl;
								return -1;								
							}
							
							if(x == 0){
								cout << "The complex number lies on the imaginary axis and quadrant isn't defined'" << endl;
								return -1;
							}

							if(y == 0){
								cout << "The complex number lies on the real axis and quadrant isn't defined'" << endl;
								return -1;
							}

							if(x > 0 and y > 0){
								return 1;
							}
							
							else if(x < 0 and y > 0){
								return 2;
							}
							
							else if(x < 0 and y < 0){
								return 3;
							}
							
							else if(x > 0 and y < 0){
								return 4;
							}
							else{
								assert(false);
							}
						}

						double mod(void){
							return sqrt(x * x + y * y);
						}

						double arg(void){
							if(x == 0){
								if(y > 0){
									return 90;
								}
								
								else if(y < 0){
									return 270;
								}
								
								else{
									cout << "Argument of zero complex number is not defined" << endl;
									assert(false);
								}
							}

							if(y == 0){
								if(x > 0){
									return 0;
								}
								
								else if(x < 0){
									return 180;
								}
								
								else{
									cout << "Argument of zero complex number is not defined" << endl;
									assert(false);
								}
							}
							
							double theta = atan(abs(y) / abs(x)) * 180 / pi;
							
							Complex store = Complex(x, y);
							
							if(store.quadrant() == 1){
								return theta;
							}
							
							else if(store.quadrant() == 2){
								return 180 - theta;
							}
							
							else if(store.quadrant() == 3){
								return 180 + theta;
							}
							
							else if(store.quadrant() == 4){
								return 180 * 2 - theta;
							}
							
							else{
								assert(false);
							}
						}
						
						Complex conjugate(void){
							Complex store;
							store.x = x;
							store.y = -y;
							return store;
						}		
						
						double real(void){
							return x;
						}

						double img(void){
							return y;
						}	
						
						int precedence(char op){
						    if(op == '+' or op == '-'){
						    	return 1;
						    }
						    if(op == '*' or op == '/'){
						    	return 2;
						    }
						    return 0;
						}

						Complex evaluate(string expression){						     
						    stack <Complex> values;
						     
						    stack <char> operators;
						     
						    for(int i = 0; i < expression.length(); i++){
						        if(expression[i] == ' '){
						            continue;
						        }
						            
						        else if(expression[i] == '('){
						            operators.push(expression[i]);
						        }

						        else if(isdigit(expression[i]) or expression[i] == 'i'){
						            
						            int value = 0;
						            
						            Complex store;
						            
						            if(expression[i] == 'i'){
						            	store = Complex(0, 1);
						            }
						            
						            else{
							            while(i < expression.length() && isdigit(expression[i])){
							                value = (value * 10) + (expression[i] - '0');
							                i++;
							            }
							             
							            if(expression[i] == 'i'){
							            	store = Complex(0, value);
							            }
							            
							            else{
							            	store = Complex(value, 0);
								            i--;
							            }
							        }
						            values.push(store);
						        }
						         
						        else if(expression[i] == ')'){
						        	
						            while(!operators.empty() && operators.top() != '('){
						                Complex a = values.top();
						                values.pop();
						                 
						                Complex b = values.top();
						                values.pop();
						                 
						                char op = operators.top();
						                operators.pop();
						                 
						                if(op == '+'){
						                	values.push(a + b);
						                }

						                if(op == '-'){
						                	values.push(a - b);
						                }

						                if(op == '*'){
						                	values.push(a * b);
						                }

						                if(op == '/'){
						                	values.push(a / b);
						                }
						            }
						             
						            if(!operators.empty()){
						               operators.pop();
						            }
						        }
						         
						        else if(expression[i] == '+' or expression[i] == '-' or expression[i] == '*' or expression[i] == '/'){
						            while(!operators.empty() && precedence(operators.top()) >= precedence(expression[i])){
						                Complex b = values.top();
						                values.pop();
						                 
						                Complex a = values.top();
						                values.pop();
						                 
						                char op = operators.top();
						                operators.pop();
						                 
						                if(op == '+'){
						                	values.push(a + b);
						                }

						                if(op == '-'){
						                	values.push(a - b);
						                }

						                if(op == '*'){
						                	values.push(a * b);
						                }

						                if(op == '/'){
						                	values.push(a / b);
						                }
						            }
						             
						            operators.push(expression[i]);
						        }
						    }
						     

						    while(!operators.empty()){
						        Complex b = values.top();
						        values.pop();
						                 
						        Complex a = values.top();
						        values.pop();
						                 
						        char op = operators.top();
						        operators.pop();
						                 
						        if(op == '+'){
						        	values.push(a + b);
						        }

						        if(op == '-'){
						        	values.push(a - b);
						        }

						        if(op == '*'){
						        	values.push(a * b);
						        }

						        if(op == '/'){
						        	values.push(a / b);
						        }
						    }
						     
						    return values.top();
						}		
						
					};
					
					void solve(void){
						Complex a(3, 4);
						Complex b(8, -2);
						Complex c = a / b;
						c.print();
						cout << c.real() << " " << c.img() << endl;
						c.conjugate().print();
						Complex d (3, 7);
						cout << d.mod() << endl;
						Complex e(2, -2);
						cout << e.arg() << endl;
						Complex f (0, 0);
						cout << f.quadrant() << endl;
						Complex g = -d;
						g.print();
						g.evaluate("(1 + 5i) * (5 + i) * (4i + 5) / (25 + 14 * 5 * 2 + 5) * i").print();
					}
					
					signed main() {
					int t = 1; 
					while(t--){
					    solve();
					}	
					
					    return 0;
					}
