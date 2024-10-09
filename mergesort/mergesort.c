#include "mergesort.h"
#include <stdlib.h>  // For malloc, calloc, and free


void merge(int* values, int* left, int leftSize, int* right, int rightSize) {
   int i = 0, j = 0, k = 0;


   while (i < leftSize && j < rightSize) {
       if (left[i] <= right[j]) {
           values[k++] = left[i++];
       } else {
           values[k++] = right[j++];
       }
   }
   while (i < leftSize) {
       values[k++] = left[i++];
   }
   while (j < rightSize) {
       values[k++] = right[j++];
   }
}


void mergesort(int size, int values[]) {
   if (size < 2) {
       return; // Base case: array is already sorted
   }


   int mid = size / 2;
   int* left = (int*)calloc(mid, sizeof(int));
   int* right = (int*)calloc(size - mid, sizeof(int));


   for (int i = 0; i < mid; i++) {
       left[i] = values[i];
   }
   for (int i = mid; i < size; i++) {
       right[i - mid] = values[i];
   }


   mergesort(mid, left);
   mergesort(size - mid, right);
   merge(values, left, mid, right, size - mid);


   free(left);
   free(right);
}
