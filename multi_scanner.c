#include "multi_scanner.h"
#include <furi.h>
#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/widget.h>

#include "scanner/scanner.h"
#include "classifier/classifier.h"

typedef struct {
    Gui* gui;
    ViewDispatcher* view_dispatcher;
    Widget* widget;
    ScanResult result;
} MultiScannerApp;

static void draw_callback(Canvas* canvas, void* ctx) {
    MultiScannerApp* app = ctx;

    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);

    canvas_draw_str(canvas, 10, 15, "Multi Scanner");
    canvas_draw_str(canvas, 10, 35, "Press OK to Scan");
}

static bool input_callback(InputEvent* event, void* ctx) {
    MultiScannerApp* app = ctx;

    if(event->type == InputTypePress && event->key == InputKeyOk) {
        scanner_start(&app->result);
        ObjectType type = classify_object(&app->result);

        canvas_clear(app->widget->canvas);

        widget_reset(app->widget);

        widget_add_string_element(
            app->widget,
            10,
            20,
            AlignLeft,
            AlignTop,
            FontPrimary,
            type == OBJECT_BLE_DEVICE   ? "BLE Device Found" :
            type == OBJECT_RFID_TAG     ? "RFID Tag Found" :
            type == OBJECT_REMOTE       ? "IR Remote Found" :
                                          "Unknown Object"
        );
    }

    return true;
}

int32_t multi_scanner_app(void* p) {
    UNUSED(p);

    MultiScannerApp* app = malloc(sizeof(MultiScannerApp));

    app->gui = furi_record_open(RECORD_GUI);
    app->view_dispatcher = view_dispatcher_alloc();
    app->widget = widget_alloc();

    widget_set_draw_callback(app->widget, draw_callback, app);
    widget_set_input_callback(app->widget, input_callback, app);

    view_dispatcher_add_view(app->view_dispatcher, 0, widget_get_view(app->widget));
    view_dispatcher_attach_to_gui(app->view_dispatcher, app->gui, ViewDispatcherTypeFullscreen);

    view_dispatcher_switch_to_view(app->view_dispatcher, 0);
    view_dispatcher_run(app->view_dispatcher);

    widget_free(app->widget);
    view_dispatcher_free(app->view_dispatcher);
    furi_record_close(RECORD_GUI);

    free(app);

    return 0;
}