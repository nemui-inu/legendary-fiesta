#include <stdio.h>
#include <string.h>
#include <math.h>

char * find_s_mside(
  char * seg_1,
  char * seg_2
) {
  char * mside_n_seg;

  char AC[2] = "AC";
  char BC[2] = "BC";
  char AB[2] = "AB";

  if(
    (!strcmp(seg_1, "AB") && !strcmp(seg_2, "BC")) ||
    (!strcmp(seg_2, "AB") && !strcmp(seg_1, "BC"))
    ){
    // solve for AC
    mside_n_seg = AC;
  } else if(
    (!strcmp(seg_1, "AB") && !strcmp(seg_2, "AC")) ||
    (!strcmp(seg_2, "AB") && !strcmp(seg_1, "AC"))
    ){
    // solve for BC
    mside_n_seg = BC;
  } else if(
    (!strcmp(seg_1, "BC") && !strcmp(seg_2, "AC")) ||
    (!strcmp(seg_1, "BC") && !strcmp(seg_2, "AC"))
    ){
    // solve for AB
    mside_n_seg = AB;
  } else {
    return NULL;
  }
}

float find_v_mside(
  int s_val_a,
  int s_val_b
) {
  float s_val_c;
  
  // b not read
  printf("a = %d, b = %d, c = %d\n", s_val_a, s_val_b, s_val_c);

  // debug for pow
  printf("a^2 = %d, b^2 = %d, c = %d\n", (s_val_a * s_val_a), (s_val_b & s_val_b), s_val_c);

  if(s_val_a > 0 && s_val_b > 0){
    if(s_val_c = sqrt(pow(s_val_a, 2) + pow(s_val_b, 2))){
      return s_val_c;
    } else {
      return -1;
    }
  } else {
    return -1;
  }
}

int main(){
  printf("Assume a right triangle with sides: AB, BC, and AC.\n");
  printf("Wheras: AC is always hypothenuse\n");
  printf("\n");
  printf("(!) WARNING: Segment input is case-sensitive.\n");
  printf("\n");

  char seg_a[3];
  printf("Enter first segment: ");
  fflush(stdin);
  fgets(seg_a, sizeof seg_a, stdin);

  int v_seg_a;
  printf("Enter first length: ");
  scanf("%d", &v_seg_a);

  char seg_b[3];
  printf("Enter second segment: ");
  fflush(stdin);
  fgets(seg_b, sizeof seg_b, stdin);
  
  int v_seg_b;
  printf("Enter second length: ");
  scanf("%d", &v_seg_b);
  printf("v_seg_b: %d\n", v_seg_b);

  printf("\n");
  char seg_c[3];
  strcpy(
    seg_c, find_s_mside(
      seg_a, seg_b
    )
  );

  seg_c[2] = '\0';

  fflush(stdin);

  float v_seg_c = find_v_mside(v_seg_a, v_seg_b);

  if(seg_c == NULL) {
    printf("(!) Error: Invalid segment input.\n");
    return -1;
  } else {
    printf("Missing side is %s.\n", seg_c);
  }

  if(v_seg_c == -1){
    printf("(!) Error: Invalid length input.\n");
    return -1;
  } else {
    printf("Length is %f.\n", v_seg_c);
  }

  return 0;
}