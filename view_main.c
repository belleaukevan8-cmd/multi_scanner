#include "gui.h"
#include <gui/gui.h>
#include <gui/modules/widget.h>
#include <furi.h>
#include <furi_hal.h>

// Fonction pour dessiner l'écran principal
void draw_main(Canvas* canvas, void* ctx) {
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 15, "Multi Scanner");
    canvas_draw_str(canvas, 10, 35, "Press OK to start scanning");
}