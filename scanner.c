#include "scanner.h"

// Version V1 simulée pour test
void scanner_start(ScanResult* result) {
    result->ble_detected = true;  // Simule la détection BLE
    result->rfid_detected = false;
    result->ir_detected = false;
}