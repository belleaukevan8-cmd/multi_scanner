#include "gui.h"
#include <stdlib.h>

// Crée une vue simple pour FZOC
View* view_alloc(ViewDrawCallback draw_callback, ViewInputCallback input_callback, void* ctx) {
    View* view = malloc(sizeof(View));
    view->draw_callback = draw_callback;
    view->input_callback = input_callback;
    view->ctx = ctx;
    return view;
}