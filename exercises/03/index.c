#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>



// typedef struct row_struct {
//   int *data;
//   int front;
//   int back;
// } row;


// int front, back;


// void constructor() {
//   front = 0;
//   back = -1;
// }

// int rowEmpty(int front, int back) {
//   if (front > back) {
//     return 1;
//   } else {
//     return 0;
//   }
// }

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

// int addItem(int val) {
//   if (rowFull()) {
//     return 0;
//   } else {
//     back++;
//     row[back] = val;
//     return 1;
//   }
// }

// int removeItem(int *val) {
//   if (rowEmpty()) {
//     return 0;
//   } else {
//     val = row[front];
//     front++;
//     return 1;
//   }
// }



int main() {

  int number_of_pages, frame_length;
  int page_faults, front, back;

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

  }

  return 0;
}

