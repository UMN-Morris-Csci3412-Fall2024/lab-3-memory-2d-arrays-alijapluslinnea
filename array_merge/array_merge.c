#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdio.h>


int* array_merge(int num_arrays, int* sizes, int** values) {
   int total_size = 0;
   for (int i = 0; i < num_arrays; i++) {
       total_size += sizes[i];
   }


   int* temp_array = (int*)malloc(total_size * sizeof(int));
   if (!temp_array) {
       fprintf(stderr, "Memory allocation failed for temp_array\n");
       return NULL;
   }


   int index = 0;
   for (int i = 0; i < num_arrays; i++) {
       for (int j = 0; j < sizes[i]; j++) {
           temp_array[index++] = values[i][j];
       }
   }


   // Correctly calling mergesort with both size and array
   mergesort(total_size, temp_array);


   int unique_count = 0;
   if (total_size > 0) {
       unique_count = 1;
       for (int i = 1; i < total_size; i++) {
           if (temp_array[i] != temp_array[i - 1]) {
               unique_count++;
           }
       }
   }


   int* result = (int*)malloc((unique_count + 1) * sizeof(int));
   if (!result) {
       fprintf(stderr, "Memory allocation failed for result\n");
       free(temp_array);
       return NULL;
   }
   result[0] = unique_count;


   index = 1;
   if (total_size > 0) {
       result[index++] = temp_array[0];
       for (int i = 1; i < total_size; i++) {
           if (temp_array[i] != temp_array[i - 1]) {
               result[index++] = temp_array[i];
           }
       }
   }


   free(temp_array);
   return result;
}


