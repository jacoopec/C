#include "CHeaders.h"

const char * reverse_string(const char * input_string) {
  char* result;
  char next;
  int i = 0;
  while(next != '%'){
    next = input_string[i];
    // result += next;
    printf("%c",(char)next);
    // result[i] = next;
    i++;
  }
  const char* result2 = result;
  return result2;
}

int popular_size() {
  int nPeople = 6;
  int array[nPeople][2];
  int api_get_size[6] = {39,40,41,42,43};
  int temp = 0;
  int num = 1; 
  bool existing = false;

  for(int i = 0; i < nPeople; i++){
    temp = api_get_size[i];

    for(int j = 0; j < num; j++){
      if(temp == array[j][0]){
        array[j][1]++;
        existing = true;
      } else {continue;}
    }
    if(!existing){
      num++;
      array[num][0] = temp;
      array[num][1] =1;
    }
  }
  for(int y = 0; y < 6; y++){
    for(int u = 0; u < 2; u++){
        printf("%i ",array[y][u]);
    }
    printf("\n");
  }
  int result=0;
  int current = 0;
  for(int k = 0; k < nPeople; k++){
    if(array[k][1] > current){ result =array[k][0];}
  }
    bool correct = false;
  for(int k = 0; k < nPeople; k++){
    if(array[k][1] > 1){ correct = true;} else{continue;}
  }
  if(!correct){result = -1;}
  
  return result;
}


// const char * popular_name() {
//     for(int i = 0; i < nPeople; i++){
//     temp = api_get_size[i];

//   return "foo";
// }

int main(){
    // printf("%s", reverse_string("uicji"));
    // // char * u = "d";
    // int matrix[3][2] = {{1,2},{6,5},{9,8}};
    // for(int i = 0; i< 3; i++){
    //     for(int j = 0; j <2; j++){
    //         printf("%i",matrix[i][j]);
    //     }
        printf("%i", popular_size());
    // }
}