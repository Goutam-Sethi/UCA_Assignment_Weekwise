#include <stdbool.h>
#include <stdio.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
  int frames[num_frames];
  int last_used[num_frames];
  int page_faults = 0;

  for (int i = 0; i < num_frames; i++) {
    frames[i] = -1;
    last_used[i] = -1;
  }

  for (int time = 0; time < num_requests; time++) {
    int page = page_requests[time];
    bool hit = false;

    int i;
    for (i=0; i<num_frames; i++) {
      if (page == frames[i]) {
        hit = true;
        break;
      }
    }

    if (hit) {
      last_used[i] = time;
    } 
    else {
      page_faults++;
      bool emptySlotFound = false;

      for (int j=0; j<num_frames; j++) {
        if (frames[j] == -1) {
          frames[j] = page;
          last_used[j] = time;
          emptySlotFound = true;
          break;
        }
      }
      
      if (!emptySlotFound) {
        int leastRecentlyIdx = 0;

        for (int j=1; j<num_frames; j++) {
          if (last_used[j] < last_used[leastRecentlyIdx]) 
            leastRecentlyIdx = j;
        }

        last_used[leastRecentlyIdx] = time;
        frames[leastRecentlyIdx] = page;
      }
    }
  }

  printf("Total Page Faults: %d\n", page_faults);
}

int main() {
  int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
  int num_requests = sizeof(requests) / sizeof(requests[0]);

  simulate_lru(requests, num_requests, 3);
  return 0;
}