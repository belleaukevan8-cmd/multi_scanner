#include "multi_scanner.h"
#include "scanner.h"
#include "classifier.h"
#include "gui.h"

#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/widget.h>
#include <furi_hal.h>

static void draw_callback(Canvas* canvas, void* ctx) {
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 10, 15, "Multi Scanner");
    canvas_draw_str(canvas, 10, 35, "Press OK to scan");
}

static bool input_callback(InputEvent* event, void* ctx) {
    if(event->type == InputTypePress && event->key == InputKeyOk) {
        ScanResult result;
        scanner_start(&result);
        ObjectType type = classify_object(&result);

        Canvas* canvas = furi_record_open(RECORD_GUI);
        canvas_clear(canvas);
        const char* message =
            type == OBJECT_BLE_DEVICE ? "BLE Device Found" :
            type == OBJECT_RFID_TAG   ? "RFID Tag Found" :
            type == OBJECT_REMOTE     ? "IR Remote Found" :
                                        "Unknown Object";
        canvas_draw_str(canvas, 10, 15, message);
    }
    return true;
}

int32_t multi_scanner_app(void* p) {
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewDispatcher* vd = view_dispatcher_alloc();

    View* view = view_alloc(draw_callback, input_callback, NULL);
    view_dispatcher_add_view(vd, 0, view);
    view_dispatcher_attach_to_gui(vd, gui, ViewDispatcherTypeFullscreen);
    view_dispatcher_switch_to_view(vd, 0);
    view_dispatcher_run(vd);

    view_dispatcher_free(vd);
    furi_record_close(RECORD_GUI);
    return 0;
}