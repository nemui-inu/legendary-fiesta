#include <stdio.h>

int binary_search(
  int * b_arr,
  int b_size,
  int b_target
) {
  int mid = b_size / 2;
  while(mid != 0 && mid <= b_size){
    if(b_arr[mid] == b_target){
      return mid;
    }
    if (b_arr[mid] > b_target){
      mid--;
    } else {
      mid++;
    }
  }
  return -1;
}

int main(){
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  
  int arr[100];
  printf("Enter the array elements: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }

  if(size <= 0 || size > 100){
    printf("Error: Invalid size. Max = 100, Min = 1");
    return -1;
  }

  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  int ouput_index = binary_search(arr, size, target);
  if(ouput_index == -1){
    printf("Target value not found in the array.");
  } else {
    printf("Target value found at index %d.", ouput_index);
  }
}