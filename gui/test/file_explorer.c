
#include <gui.h>

window_t* wnd;
edit_t* edtPath;

void
file_explorer_on_change_dir_cb(widget_t* widget) {
  edit_set_text(edtPath,FILE_NAVIGATOR(widget)->directory);
}

// void
// file_explorer_on_choose_file(widget_t* widget, uint8_t* file) {
//   text_view(strcat(strcat(FILE_NAVIGATOR(widget)->directory,"/"),file);
// }

widget_t*
file_explorer() {
  file_navigator_t* fn;

  wnd = window_create(300,300);
  window_set_name(wnd, "File Explorer");
  edtPath = edit_create(WIDGET(wnd));
  WIDGET(edtPath)->x = 0;
  WIDGET(edtPath)->y = 0;
  WIDGET(edtPath)->w = WIDGET(wnd)->w - WIDGET(wnd)->padding_left - WIDGET(wnd)->padding_right;
  edit_set_text(edtPath,"/");
  fn = file_navigator_create("/", WIDGET(wnd));
  WIDGET(fn)->y = WIDGET(edtPath)->h;
  WIDGET(fn)->h -= WIDGET(edtPath)->h;

  fn->OnChoose_user = file_explorer_on_change_dir_cb;

  gui_set_active_window(wnd);

  return WIDGET(wnd);
}
