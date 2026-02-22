#pragma once
#include "../scanner/scanner.h"

typedef enum {
    OBJECT_UNKNOWN,
    OBJECT_BLE_DEVICE,
    OBJECT_RFID_TAG,
    OBJECT_REMOTE
} ObjectType;

ObjectType classify_object(ScanResult* result);