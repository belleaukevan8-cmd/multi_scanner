#include "gui.h"
#include <gui/gui.h>
#include <gui/modules/widget.h>
#include <furi.h>

// Fonction pour dessiner le résultat du scan
void draw_result(Canvas* canvas, void* ctx, const char* message) {
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 15, "Scan Result:");
    canvas_draw_str(canvas, 10, 35, message);
}