#include <stdio.h>
#include <stdlib.h>

#define max 32

int conv_int_arr(int * o_int_arr, unsigned int i_input){
  int arr_size = 0;
  int n = i_input;
  for(int i = 0; i_input > 0; i++){
    if(i > 0){
      for(int j = arr_size - 1; j >= 0; j--){
        if((j + 1) >= max){
          printf("(!) Error: Buffer overflow.\n");
          exit(1);
        }
        o_int_arr[j + 1] = o_int_arr[j];
      }
    }
    o_int_arr[0] = i_input % 10;
    i_input /= 10;
    arr_size++;
  }
  return arr_size;
}

int main(){
  int input;
  printf("Enter the number: ");
  scanf("%d", &input); 

  if(input < 1){
    printf("(!) Error: Input should be an integer greater than 0.");
    exit(1);
  } else if(input < 10){
    printf("%d", input);
    exit(0);
  }

  int i_arr[max];
  int i_arr_len = conv_int_arr(i_arr, input);

  while(i_arr[1] != -1){
    // array has preceding zeroes?: adjust array.
    if(i_arr[0] == 0){
      int z_count = 0;
      for(int i = 0; i_arr[i] == 0; i++){
        z_count++;
      }
      for(int i = 0; z_count < i_arr_len; i++, z_count++){
        i_arr[i] = i_arr[z_count]; 
      }
    }
    
    int ir = i_arr_len;
    i_arr_len = 0;
    for(int i = 0; i < ir - 1; i++){
      // printf("%d :: %d - %d\n", abs(i_arr[i] - i_arr[i + 1]), i_arr[i], i_arr[i + 1]);
      i_arr[i] = abs(i_arr[i] - i_arr[i + 1]);
      i_arr_len++;
    }
    // printf("\n***\n\n");
    i_arr[i_arr_len] = -1;
  }

  printf("%d", * i_arr);
  
}
  
  