#include <stdio.h>

int ternary_search(
  int * arr, 
  int size,
  int target
){
  int mid_a = (0 + (size / 3)) - 1;
  int mid_b = (size - (size / 3)) - 1;

  while(mid_a <= mid_b){
    if(arr[mid_a] == target){
      return mid_a;
    }
    if(arr[mid_b] == target){
      return mid_b;
    }

    if(target < arr[mid_a]){
      mid_a--;
    } else if (target > arr[mid_b]) {
      mid_b++;
    } else {
      mid_a++;
      mid_b--;
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

  int index_at = ternary_search(arr_input, arr_size, target);
  if(index_at == -1){
    printf("Target value not found in the array.");
  } else {
    printf("Target value found at index %d.", index_at);
  }

  return 0;
}