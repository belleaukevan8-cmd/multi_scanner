#include "storage.h"
#include <stdio.h>
#include <furi.h>

// Sauvegarde simulée dans fichier texte (pour l'instant)
void save_scan_result(ScanResult* result) {
    // Exemple : sauvegarde fictive
    printf("Saving ScanResult: BLE=%d, RFID=%d, IR=%d\n",
        result->ble_detected,
        result->rfid_detected,
        result->ir_detected
    );
}