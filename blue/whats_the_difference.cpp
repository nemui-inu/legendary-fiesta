#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

class difference {
public:
  std::vector<int> n;
  std::vector<int> m;

  std::set<int> find_diff(std::vector<int> x, std::vector<int> y){
    std::set<int> sx (x.begin(), x.end());
    std::set<int> sy (x.begin(), x.end());
    std::set<int> res;
    std::set_difference(sx.begin(), sx.end(), sy.begin(), sy.end(), 
      std::inserter(res, res.end()));
    return res;
  }

  std::vector<int> get_input(){
    std::vector<int> v;
    std::string in;
    int t_int;
    std::getline(std::cin, in);
    std::istringstream is( in );
    while(is >> t_int){
      v.push_back(t_int);
    }
    return v;
  }
};

int main(){
  difference input;

  std::cout << "Enter first set of data separated by space: ";

  input.n = input.get_input();

  for(int x: input.n){
    std::cout << x << " ";
  }

  std::cout << "Enter second set of data separated by space: ";

  input.m = input.get_input();
  
  for(int x: input.m){
    std::cout << x << " ";
  }

  std::set<int> d = input.find_diff(input.n, input.m);

  for(int x: d){
    std::cout << x << " ";
  }

  return 0;
}