/**
 * Sample output on the website is incorrect.
 * 
 * Charge for above 100 KwH = $0.09259
 * Sample Input: $1500 ; Sample Output: $122.65
 * Whereas: 122.65 / 1500 = 0.08175 
 * 
*/

#include <iostream>

class bill {
public:
  float under_1000 = 0.07633;
  float over_1000 = 0.09259;

  float get_charge(int usage){
    float charge = (usage < 1000) ? usage * under_1000 : 
      usage * over_1000;
    return charge;
  }
};

int main(){
  int kw_hours;
  std::cout << "Enter the KW hours used: ";
  std::cin >> kw_hours;

  if(kw_hours < 0){
    std::cout << "Invalid input." << std::endl;
    return -1;
  }

  bill electric;
  float e_bill = electric.get_charge(kw_hours);

  std::cout << "Amount owed is $" << e_bill << "." << std::endl;

  return 0;
}
