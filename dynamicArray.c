#include <stdio.h>
#include <stdlib.h>

int main(){
  // ints are 4 bytes in the heap, while int pointers are 8 bytes
  // int pointers are 8 bytes because my system has a 64-bit memory address
  // so you need 8 bytes to represent the entire memory address
  printf("%lu, %lu\n", sizeof(int), sizeof(int*));

  // allocate space for array in the heap
  int* ptrArr = (int*)(malloc(10*sizeof(int)));
  // printf("%ld\n", ((ptrArr+(10*sizeof(int))) - ptrArr)/4);
  // populate the array

  // how much memory do you want to allocate for your pointer?
  int* ptr = (int*)(malloc(10*sizeof(int)));
  int j = 11;

  // you cant add two memory addresses but
  // if you add a memory address and a primitive type,
  // the memory address adds the size of that variable plus
  // its value
  // the second argument evaluates to 16 because sizeof(j) == 4
  // and ptr + 4 is adding 4 integers, each of size 4 bytes
  // to the memory address. 2nd arg == ptr + 16
  printf("%p\t%p\n", ptr, ptr+sizeof(j));

  // you can access more memory than you malloc, but then
  // you will have a memory leak, or you can overwrite memory
  for (int i = 0; i < 10; i++){

    // populate array using bracket notation
    // ptrArr[i] = i;
    // printf("%d\t%p\n", ptrArr[i], &ptrArr[i]);

    // populate array using pointer arithmetic
    *ptrArr = i;
    printf("%d\t%p\n", *ptrArr, ptrArr);
    ptrArr++;

    // printf("%p %d\n", ptrArr+i, ptrArr+i);
  }

  return 0;
}


