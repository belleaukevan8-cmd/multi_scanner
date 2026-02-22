#include "scanner.h"

void scanner_start(ScanResult* result) {
    result->ble_detected = true;
    result->rfid_detected = false;
    result->ir_detected = false;
}