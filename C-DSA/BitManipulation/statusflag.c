#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Initialize the status register to zero
void initStatus(uint8_t *status){
    *status = 0;
}

// Set the bit at a given position (0-7)
void setStatus(uint8_t *status, int position){
    *status |=1U << position; 
}

// Clear the bit at a given position (0-7)
void clearStatus(uint8_t *status, int position){
    *status &=~(1U << position);
}

// Check if the bit at a given position is set
bool isStatusSet(uint8_t status, int position){
    return status & (1U << position);
}

// Count total number of error bits set
int countErrors(uint8_t status){
    int count =0;
    while(status)
    {
        count++;
        status &= (status -1);
    }
    return count;
}


int main(){
uint8_t status;
initStatus(&status);

setStatus(&status, 2);     // set bit 2
setStatus(&status, 5);     // set bit 5

printf("%d\n", isStatusSet(status, 2)); // 1
printf("%d\n", countErrors(status));    // 2

clearStatus(&status, 2);
printf("%d\n", isStatusSet(status, 2)); // 0
return 0;

}