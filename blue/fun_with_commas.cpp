#include <iostream>
#include <string>
#include <vector>

class commas{
public:
  void print_with_commas(std::vector<std::string> p_input){
    std::cout << std::endl << "You entered: ";
    for(int i = 0; i < p_input.size(); i++){
      if(i == 0){
        std::cout << p_input.at(i);
      } else if((i + 1) == p_input.size()){
          std::cout << " and " << p_input.at(i) << "." << std::endl;
      } else{
          std::cout << ", " << p_input.at(i);
      }
    }
  }
};

int main(){
  std::vector<std::string> input;

  for(int i = 0; i < 50; i++){
    std::string t;
    std::cout << "Enter next word or \"quit\": ";
    std::cin >> t;

    if(t.compare("quit")){
      input.push_back(t);
    } else {
      break;
    } 
  }

  commas output;
  output.print_with_commas(input);

  return 0;
}