#include <iostream>

class largest_quotient{
public:
  int get_lq(int selection[15], int size){
    int highest_number = selection[0];
    int lowest_number = selection[0];
    for(int i = 0; i < size; i++){
      if (highest_number < selection[i]){
        highest_number = selection[i];
      } 
      if (lowest_number > selection[i]){
        lowest_number = selection[i];
      } 
    }

    int quotient = highest_number / lowest_number;

    return quotient;
  }
};

int main(){
  int arr[15], arr_size;

  std::cout << "Enter integers separated by space." << std::endl;
  std::cout << "End with zero(0): ";

  for(int i = 0; i < 15; i++){
    int t;
    std::cin >> t;

    arr_size = i;

    if(t < 0){
      std::cout << "Invalid input.";
    } else if(t == 0){
        break;
    } else{
        arr[i] = t;
    }
  }

  if(arr_size <= 1){
    std::cout << "Error: More than 1 input expected." << std::endl;
    return -1;
  }

  int lq;
  largest_quotient solution;
  lq = solution.get_lq(arr, arr_size);
  std::cout << "Highest quotient possible is " << lq <<  "." << std::endl;

  return 0;
}