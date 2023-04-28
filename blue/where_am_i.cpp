#include <iostream>

class location{
public:
  int q;
  int which_q(int x, int y){
    if(x > 0 && y > 0) return 1;
    if(x < 0 && y > 0) return 2;
    if(x < 0 && y < 0) return 3;
    if(x > 0 && y < 0) return 4;
    return -1;
  }
};

int main(){
  int pos_x, pos_y;

  std::cout << "Enter X and Y seperated by a space: "; 
  std::cin >> pos_x >> pos_y;

  location input;
  input.q = input.which_q(pos_x, pos_y);
  if(input.q == -1){
    std::cout << "Input must not be zero" << std::endl;
  } else {
    std::cout << "Q" << input.q << std::endl;
  }

  return 0;
}