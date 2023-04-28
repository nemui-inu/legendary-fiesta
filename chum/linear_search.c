#include <stdio.h>

int linear_search(
  int * arr, 
  int size, 
  int tar
){
  for(int i = 0; i < size; i++){
    if(tar == arr[i]){
      return i;
    }
  }
  return -1;
}

int main(){
  int arr_size;
  printf("Enter the size of the array: ");
  scanf("%d", &arr_size);

  if(arr_size <= 0 || arr_size > 100){
    printf("Error: Invalid size. Max = 100, Min = 1");
    return -1;
  }

  int arr_input[100];
  printf("Enter the array elements: ");
  for(int i = 0; i < arr_size; i++){
    scanf("%d", &arr_input[i]);
  }

  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  int index_at = linear_search(arr_input, arr_size, target);
  if(index_at == -1){
    printf("Target value not found in the array.");
  } else {
    printf("Target value found at index %d.", index_at);
  }

  return 0;
}