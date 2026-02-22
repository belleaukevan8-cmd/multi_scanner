#include "classifier.h"

// Classifie selon le résultat du scan
ObjectType classify_object(ScanResult* result) {
    if(result->ble_detected) return OBJECT_BLE_DEVICE;
    if(result->rfid_detected) return OBJECT_RFID_TAG;
    if(result->ir_detected) return OBJECT_REMOTE;
    return OBJECT_UNKNOWN;
}