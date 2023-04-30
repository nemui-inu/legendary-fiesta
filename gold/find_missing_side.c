#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
const char * find_s_mside(char * seg_1, char * seg_2) {    
    if((!strcmp(seg_1, "AB") && !strcmp(seg_2, "BC")) || (!strcmp(seg_2, "AB") && !strcmp(seg_1, "BC"))){
        // solve for AC
        return "AC";
    } 
    else if((!strcmp(seg_1, "AB") && !strcmp(seg_2, "AC")) || (!strcmp(seg_2, "AB") && !strcmp(seg_1, "AC"))){
        // solve for BC
        return "BC";
    } 
    else if((!strcmp(seg_1, "BC") && !strcmp(seg_2, "AC")) ||(!strcmp(seg_2, "BC") && !strcmp(seg_1, "AC"))){
        // solve for AB
        return "AB";
    } else {
        return "";
    }
}
 
float find_v_mside(char * seg_c, char * seg_a, int s_val_a, char * seg_b, int s_val_b) {
    float s_val_c = 0;
    
    if(strcmp(seg_c,"AC") == 0){
        s_val_c = sqrt(pow(s_val_a, 2) + pow(s_val_b, 2));
    }
    else{
        if(strcmp(seg_a,"AC") == 0){
            s_val_c = sqrt(pow(s_val_a, 2) - pow(s_val_b, 2));
        }
        else if(strcmp(seg_b,"AC") == 0){
            s_val_c = sqrt(pow(s_val_b, 2) - pow(s_val_a, 2));
        }
    }

    return s_val_c;
}
 
int main(){
    system("cls");
    printf("Assume a right triangle with sides: AB, BC, and AC.\n");
    printf("Wheras: AC is always hypothenuse\n");
    printf("\n");
    printf("(!) WARNING: Segment input is case-sensitive.\n");
    printf("\n");
    
    char seg_a[3];
    printf("Enter first segment: ");
    //fflush(stdin);
    //fgets(seg_a, sizeof seg_a, stdin);
    gets(seg_a);
    
    int v_seg_a;
    printf("Enter first length: ");
    scanf("%d", &v_seg_a);
    fflush(stdin);

    if(v_seg_a <= 0){
        printf("(!) Error: Length must be greater than zero (0).");
        exit(1);
    }

    char seg_b[3];
    printf("Enter second segment: ");
    //fflush(stdin);
    //fgets(seg_b, sizeof seg_b, stdin);
    gets(seg_b);
   
    
    int v_seg_b;
    printf("Enter second length: ");
    scanf("%d", &v_seg_b);
    fflush(stdin);

    if(v_seg_b <= 0){
        printf("(!) Error: Length must be greater than zero (0).");
        exit(1);
    }

    //AC always hypotenuse
    if(strcmp(seg_a,"AC") == 0){
        if(v_seg_a < v_seg_b){
            printf("(!) Error: AC must always be hypotenuse.");
            exit(1);
        }
    }
    else if(strcmp(seg_b,"AC") == 0){
        if(v_seg_b < v_seg_a){
            printf("(!) Error: AC must always be hypotenuse.");
            exit(1);
        }
    }
    
    printf("\n");

    char seg_c[3] = "";
    strcpy(seg_c, find_s_mside(seg_a, seg_b));
    
    seg_c[2] = '\0';
    
    fflush(stdin);

    if(strcmp(seg_c,"") == 0) {
        printf("(!) Error: Invalid segment input.\n");
        exit(1);
    }

    float v_seg_c = find_v_mside(seg_c, seg_a, v_seg_a, seg_b, v_seg_b);

    printf("Missing side is %s\n", seg_c);
    printf("Length is %.2f\n", v_seg_c);
    
    return 0;
}