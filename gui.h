#pragma once
#include <gui/gui.h>

typedef struct View View;

typedef void (*ViewDrawCallback)(Canvas*, void*);
typedef bool (*ViewInputCallback)(InputEvent*, void*);

View* view_alloc(ViewDrawCallback draw_callback, ViewInputCallback input_callback, void* ctx);