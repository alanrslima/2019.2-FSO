#include <stdio.h>
#include <stdlib.h>


int row_full(int back, int size) {
  if (back == size - 1) {
    return 1;
  } else {
    return 0;
  }
}

int page_exists_in_row(int number, int *row, int length) {
  for (int i = 0; i < length; i++){
    if (number == row[i]) {
      return 1;
    }
  }
  return 0;
}

void order(int *arr_frames, int *arr_page_fault, int size) {
  int temp_frame;
  int temp_page_fault;
  for ( int i = 0; i < size; i++ ) {
    for( int j = i+1; j < size; j++ ) {
      if (*(arr_frames + i) > *(arr_frames + j) ) {
        temp_frame = *(arr_frames + i);
        *(arr_frames + i) = *(arr_frames + j);
        *(arr_frames + j) = temp_frame;

        temp_page_fault = *(arr_page_fault + i);
        *(arr_page_fault + i) = *(arr_page_fault + j);
        *(arr_page_fault + j) = temp_page_fault;
      }
    }
  }
}

void check_belady(int *arr_page_faults, int size) {
  if (size <= 1) {
    printf("Sem anomalia\n");
    return;
  }
  for (int i = 1; i< size; i++){
    if (*(arr_page_faults + i) > (*(arr_page_faults + (i-1)))) {
      printf("Belady detectado\n");
      return;
    }
  }
  printf("Sem anomalia\n");
  return;
}


int main() {

  int number_of_pages, frame_length;
  int page_faults, front, back;
  
  int size = 2;
  int *array_page_faults, *array_frames;
  array_page_faults = (int *)malloc(size * sizeof(int));
  array_frames = (int *)malloc(size * sizeof(int));


  scanf("%d", &number_of_pages);

  int pages[number_of_pages];
    
  for(int i = 0; i < number_of_pages; i++)
    scanf("%d", &pages[i]);
  
  for(int i = 0; scanf("%d", &frame_length) != EOF; i++) {

    int frame[frame_length];
    front = 0; 
    back = -1;
    page_faults = 0;

    for (int x = 0; x < frame_length; x++) {
      frame[x] = 0;
    }
    
    for (int j = 0; j < number_of_pages; j++) {
      
      if (row_full(back, frame_length)) {
        if ( page_exists_in_row(pages[j], frame, frame_length) == 0) {
          page_faults++;
          frame[front] = pages[j];
          if (front == (frame_length - 1)) {
            front = 0;
          } else {
            front++;
          }
        }
      } else {  
        if ( page_exists_in_row(pages[j], frame, frame_length) == 0) {
          page_faults++;
          back++;
          frame[back] = pages[j];
        } 
      }

    }
    printf("%d %d\n", frame_length, page_faults);
    array_page_faults = (int *)realloc(array_page_faults, (size+1)*sizeof(int));
    array_frames = (int *)realloc(array_frames, (size+1)*sizeof(int));
    size++;
    *(array_page_faults + i) = page_faults;
    *(array_frames + i) = frame_length;
  }

  order(array_frames, array_page_faults, size-2);
  check_belady(array_page_faults, size-2);

  free(array_frames);
  free(array_page_faults);

  return 0;
}

