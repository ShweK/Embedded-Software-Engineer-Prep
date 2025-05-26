// Ring buffer implementation for CAN Rx PDUs with overflow diagnostics
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CAN_RX_BUF_SIZE 8

typedef struct {
    uint32_t id;
    uint8_t data[8];
    uint8_t dlc;
} CanPdu;

CanPdu canRxBuffer[CAN_RX_BUF_SIZE];

uint8_t head = 0;
uint8_t tail = 0;
uint8_t count = 0;
uint32_t overflowCounter = 0;  // Diagnostic counter for dropped messages

// Simulated callback from CAN driver or ISR
void Can_RxIndication(uint32_t id, uint8_t* data, uint8_t dlc) {
    if (count == CAN_RX_BUF_SIZE) {
        overflowCounter++;
        printf("[WARN] CAN Rx buffer overflow! Total dropped: %lu\n", (unsigned long)overflowCounter);
        return;
    }

    canRxBuffer[head].id = id;
    canRxBuffer[head].dlc = dlc;
    memcpy(canRxBuffer[head].data, data, dlc);

    head = (head + 1) % CAN_RX_BUF_SIZE;
    count++;
}

// Simulated application layer poller
void Process_CanMessages(void) {
    while (count > 0) {
        CanPdu* pdu = &canRxBuffer[tail];

        printf("[INFO] Processing CAN PDU ID: 0x%03X, DLC: %d, Data:", pdu->id, pdu->dlc);
        for (int i = 0; i < pdu->dlc; i++) {
            printf(" %02X", pdu->data[i]);
        }
        printf("\n");

        tail = (tail + 1) % CAN_RX_BUF_SIZE;
        count--;
    }
}

// Mock CAN message simulation
void simulate_can_input() {
    for (int i = 0; i < 10; i++) {
        uint8_t data[8] = {i, i+1, i+2, i+3, i+4, i+5, i+6, i+7};
        Can_RxIndication(0x100 + i, data, 8);
    }
}

int main() {
    simulate_can_input();
    Process_CanMessages();
    return 0;
}