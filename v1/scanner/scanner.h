#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool ble_detected;
    bool rfid_detected;
    bool ir_detected;
} ScanResult;

void scanner_start(ScanResult* result);