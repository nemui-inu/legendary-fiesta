/**
 * Sample output on the website is incorrect.
 * 
 * Charge for above 100 KwH = $0.09259
 * Sample Input: $1500 ; Sample Output: $122.65
 * Whereas: 122.65 / 1500 = 0.08175 
 * 
*/

#include <iostream>

float charge(int usage);

int main(){
  int kw_hours;
  std::cout << "Enter the KW hours used: ";
  std::cin >> kw_hours;

  if(kw_hours < 0){
    std::cout << "Invalid input." << std::endl;
    return -1;
  }

  float amount_owed = charge(kw_hours);
  std::cout << "Amount owed: $" << amount_owed;

  return 0;
}

float charge(int usage){
  float rate[] = {00.07633, 00.09259};
  float to_pay;
  to_pay = (usage <= 1000) ? usage * rate[0] : 
    usage * rate[1];
  return to_pay;
}