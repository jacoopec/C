#include "../CHeaders.h"

typedef struct {
  int count;
  int * elements;
} int_list;

int_list reverse_list(int_list input_list) {
  // Write your code here
  int_list return_value = {
    .count = 0,
    .elements = NULL,
  };
  int_list temp = input_list;
  int_list array[20];
  int i = 0;
  while(temp.elements != NULL){
    i++;
  int size = i;
  for(;i > 0; i--){
    return_value.count = size-i;
    return_value.elements = array[i-1].elements;
  }
  return return_value;
}
}

int main(){
    int_list e1 = {.count = 1, .elements = NULL};
    int_list e2 = {.count = 2, .elements = &e1 };
    int_list e3 = {.count = 3, .elements = &e2 };
    int_list r = reverse_list(e3);
}