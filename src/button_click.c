#include <pebble.h>
  
static Window *window;
static TextLayer *t1_layer;
static TextLayer *t2_layer;
static TextLayer *t3_layer;
static TextLayer *t4_layer;
static TextLayer *t5_layer;
static TextLayer *t6_layer;
static TextLayer *t7_layer;
static TextLayer *t8_layer;
static TextLayer *t9_layer;
static TextLayer *t10_layer;
static TextLayer *t11_layer;
static TextLayer *t12_layer;
static TextLayer *t13_layer;
static TextLayer *t14_layer;
static TextLayer *t15_layer;
static TextLayer *t16_layer;
static TextLayer *lButton_layer;
static TextLayer *win_layer;
static char *winBoard[]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
static char *curBoard[]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
static int select =4;
static int level= 1;
static bool won=true;
 const char *temp;
static char *ctemp;
static char *ctem;
  const char *tem;
  static int intT;
  static int intt;
static void initLayers();


static void loadsetting(){

  if (persist_exists(99) ){

    level =persist_read_int(99);

    }
  else
    {
    level = 1;
  }
    
 }
  


static void savesetting(){


  persist_write_int(99, level);
}
  
static void didWin(){

  
  if (atoi(text_layer_get_text(t1_layer))==1 &&
    atoi(text_layer_get_text(t2_layer))==2 &&
     atoi(text_layer_get_text(t3_layer))==3 &&
    atoi(text_layer_get_text(t4_layer))==4 &&
     atoi(text_layer_get_text(t5_layer))==5 &&
    atoi(text_layer_get_text(t6_layer))==6 &&
     atoi(text_layer_get_text(t7_layer))==7 &&
    atoi(text_layer_get_text(t8_layer))==8 && 
     atoi(text_layer_get_text(t9_layer))==9 &&
    atoi(text_layer_get_text(t10_layer))==10 &&
     atoi(text_layer_get_text(t11_layer))==11 &&
    atoi(text_layer_get_text(t12_layer))==12 &&
     atoi(text_layer_get_text(t13_layer))==13 &&
    atoi(text_layer_get_text(t14_layer))==14 &&
     atoi(text_layer_get_text(t15_layer))==15 &&
    atoi(text_layer_get_text(t16_layer))==16  &&
     !won)
  {
   // APP_LOG(APP_LOG_LEVEL_INFO, "Won = true");
    won=true;
    char *ttemp=""; 
    char *cat="";
    char *catt="";
    int t=level;
    level=t+1;
  
 //APP_LOG(APP_LOG_LEVEL_INFO, ttemp);
    snprintf(ttemp, sizeof(ttemp), "%d", level);
  
//    APP_LOG(APP_LOG_LEVEL_INFO, ttemp);
    cat = strcat("SortFlip\nLevel\n", ttemp); 
   text_layer_set_text(win_layer, cat);
 // APP_LOG(APP_LOG_LEVEL_INFO, cat); 
    vibes_double_pulse();
   for (int l=1;l<10000;l++)
     {
     
   }

    
   layer_set_hidden((Layer *)win_layer, false);
    
  initLayers();
 
} // did win YES
  
}

static void updateButs(){
  switch (select)
    {
    case 1:
        layer_set_frame( text_layer_get_layer(lButton_layer), GRect (1,92, 24,24 ));
       text_layer_set_text(lButton_layer, ">");
    break;
    case 2:
        layer_set_frame( text_layer_get_layer(lButton_layer), GRect (1,68, 24,24 ));
  text_layer_set_text(lButton_layer, ">");
    break;
      case 3:
      layer_set_frame( text_layer_get_layer(lButton_layer), GRect (1,44, 24,24 ));
  text_layer_set_text(lButton_layer, ">");
    break;
    case 4:
       layer_set_frame( text_layer_get_layer(lButton_layer), GRect (1,20, 24,24 ));
  text_layer_set_text(lButton_layer, ">");
    break;
     case 5:
        layer_set_frame( text_layer_get_layer(lButton_layer), GRect (20,1, 24,24 ));
  text_layer_set_text(lButton_layer, "v");
    break;
    case 6:
    layer_set_frame( text_layer_get_layer(lButton_layer), GRect (44,1, 24,24 ));
  text_layer_set_text(lButton_layer, "v");
    break;
      case 7:
      layer_set_frame( text_layer_get_layer(lButton_layer), GRect (68,1, 24,24 ));
  text_layer_set_text(lButton_layer, "v");
    break;
    case 8:
         layer_set_frame( text_layer_get_layer(lButton_layer), GRect (90,1, 24,24 ));
  text_layer_set_text(lButton_layer, "v");
    break;
  }

  
}  


static void swapTiles(){
 
  
  switch (select)
    {
    case 1:
    
     temp=text_layer_get_text(t13_layer);
     tem =text_layer_get_text(t16_layer);
     text_layer_set_text(t13_layer, tem);
     text_layer_set_text(t16_layer, temp);
    
      temp=text_layer_get_text(t14_layer);
     tem =text_layer_get_text(t15_layer);

     text_layer_set_text(t14_layer, tem);
     text_layer_set_text(t15_layer, temp);
 
    break;
    case 2:
     temp=text_layer_get_text(t9_layer);
     tem=text_layer_get_text(t12_layer);
     text_layer_set_text(t9_layer,tem );
     text_layer_set_text(t12_layer, temp);
    
     temp=text_layer_get_text(t10_layer);
     tem =text_layer_get_text(t11_layer);
     text_layer_set_text(t10_layer, tem);
     text_layer_set_text(t11_layer, temp);
   
    break;
      case 3:
     temp=text_layer_get_text(t5_layer);
     tem =text_layer_get_text(t8_layer);
     text_layer_set_text(t5_layer, tem);
     text_layer_set_text(t8_layer, temp);
    
      temp=text_layer_get_text(t6_layer);
     tem =text_layer_get_text(t7_layer);
     text_layer_set_text(t6_layer, tem);
     text_layer_set_text(t7_layer, temp);
    
    break;
    case 4:
         temp=text_layer_get_text(t1_layer);
     tem =text_layer_get_text(t4_layer);

     text_layer_set_text(t1_layer, tem);
     text_layer_set_text(t4_layer, temp);
      temp=text_layer_get_text(t2_layer);
     tem =text_layer_get_text(t3_layer);

     text_layer_set_text(t2_layer, tem);
     text_layer_set_text(t3_layer, temp);
    break;
     case 5:
       temp=text_layer_get_text(t1_layer);
     tem =text_layer_get_text(t13_layer);
   
     text_layer_set_text(t1_layer, tem);
     text_layer_set_text(t13_layer, temp);
      temp=text_layer_get_text(t5_layer);
     tem =text_layer_get_text(t9_layer);
 
     text_layer_set_text(t5_layer, tem);
     text_layer_set_text(t9_layer, temp);
    break;
    case 6:
     temp=text_layer_get_text(t2_layer);
     tem =text_layer_get_text(t14_layer);

     text_layer_set_text(t2_layer, tem);
     text_layer_set_text(t14_layer, temp);
      temp=text_layer_get_text(t6_layer);
     tem =text_layer_get_text(t10_layer);

     text_layer_set_text(t6_layer, tem);
     text_layer_set_text(t10_layer, temp);
    break;
      case 7:
     temp=text_layer_get_text(t3_layer);
     tem =text_layer_get_text(t15_layer);
     text_layer_set_text(t3_layer, tem);
     text_layer_set_text(t15_layer, temp);

      temp=text_layer_get_text(t7_layer);
     tem =text_layer_get_text(t11_layer);
     text_layer_set_text(t7_layer, tem);
     text_layer_set_text(t11_layer, temp);
    break;
    case 8:
     temp=text_layer_get_text(t4_layer);
     tem =text_layer_get_text(t16_layer);
     text_layer_set_text(t4_layer, tem);
     text_layer_set_text(t16_layer, temp);
  
      temp=text_layer_get_text(t8_layer);
     tem =text_layer_get_text(t12_layer);
     text_layer_set_text(t8_layer, tem);
     text_layer_set_text(t12_layer, temp);
   break;
  }
  didWin();
}
static void initLayers(){
 // APP_LOG(APP_LOG_LEVEL_INFO, "Init");
int prevS=0;
  srand(time(NULL));

  for (int i=0;i<level;i++)
   {  
    select = (rand()%7)+1;

      while (prevS == select)
      {
       select = (rand()%7)+1;
       }
    prevS=select;
    swapTiles();
  }  
  
  select=4;
  updateButs();
  
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (!won) {
     //   APP_LOG(APP_LOG_LEVEL_INFO, "click  not won");
 swapTiles();
didWin();
  }
  else 
    {
   // APP_LOG(APP_LOG_LEVEL_INFO, "click won");
     layer_set_hidden((Layer *)win_layer, true);
    won=false;
  }
  
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
 if (select<8){
  select++;
 }
  else
    {
  select=1;
 }
updateButs();
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
 if (select >1){
  select--;
 }
  else
    {
  select=8;
 }
  updateButs();
}
static void back_click_handler(ClickRecognizerRef recognizer, void *context) {
  window_stack_remove(window, true);
}

void select_long_click_handler(ClickRecognizerRef recognizer, void *context) {
 level=1;
  won=false;

  
    text_layer_set_text(t1_layer,"1");
    text_layer_set_text(t2_layer,"2");
    text_layer_set_text(t3_layer,"3");
    text_layer_set_text(t4_layer,"4");
    text_layer_set_text(t5_layer,"5");
    text_layer_set_text(t6_layer,"6");
    text_layer_set_text(t7_layer,"7");
    text_layer_set_text(t8_layer,"8"); 
    text_layer_set_text(t9_layer,"9");
    text_layer_set_text(t10_layer,"10");
    text_layer_set_text(t11_layer,"11");
    text_layer_set_text(t12_layer,"12");
    text_layer_set_text(t13_layer,"13");
    text_layer_set_text(t14_layer,"14");
    text_layer_set_text(t15_layer,"15");
    text_layer_set_text(t16_layer,"16");  
  won=true;
    char *ttemp=""; 
    char *cat="";
  
 APP_LOG(APP_LOG_LEVEL_INFO, ttemp);
    snprintf(ttemp, sizeof(ttemp), "%d", level);
  
 //   APP_LOG(APP_LOG_LEVEL_INFO, ttemp);
    cat = strcat("SortFlip\nLevel\n", ttemp); 
   text_layer_set_text(win_layer, cat);
 //   APP_LOG(APP_LOG_LEVEL_INFO, cat);
   layer_set_hidden((Layer *)win_layer, false);
    
  initLayers();
}
void select_long_click_release_handler(ClickRecognizerRef recognizer, void *context) {
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_long_click_subscribe(BUTTON_ID_SELECT, 700, select_long_click_handler, select_long_click_release_handler);
  //  window_single_click_subscribe(BUTTON_ID_BACK, back_click_handler);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
 // GRect bounds = layer_get_bounds(window_layer);

  
  
  t1_layer = text_layer_create((GRect) { .origin = { 24, 20 }, .size = { 30, 30 } });
  text_layer_set_font(t1_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t1_layer,curBoard[0]);
  text_layer_set_text_alignment(t1_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t1_layer));
  
  
  t2_layer = text_layer_create((GRect) { .origin = { 50, 20 }, .size = { 30, 30 } });
  text_layer_set_font(t2_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t2_layer,curBoard[1]);
  text_layer_set_text_alignment(t2_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t2_layer));
  
   t3_layer = text_layer_create((GRect) { .origin = { 75, 20 }, .size = { 30, 30 } });
  text_layer_set_font(t3_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t3_layer,curBoard[2]);
  text_layer_set_text_alignment(t3_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t3_layer));
  
  
  t4_layer = text_layer_create((GRect) { .origin = { 100, 20 }, .size = { 30, 30 } });
  text_layer_set_font(t4_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t4_layer,curBoard[3]);
  text_layer_set_text_alignment(t4_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t4_layer));
  
    t5_layer = text_layer_create((GRect) { .origin = { 25, 44 }, .size = { 30, 30 } });
  text_layer_set_font(t5_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t5_layer,curBoard[4]);
  text_layer_set_text_alignment(t5_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t5_layer));
  
  
  t6_layer = text_layer_create((GRect) { .origin = { 50, 44 }, .size = { 30, 30 } });
  text_layer_set_font(t6_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t6_layer,curBoard[5]);
  text_layer_set_text_alignment(t6_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t6_layer));
  
   t7_layer = text_layer_create((GRect) { .origin = { 75, 44 }, .size = { 30, 30 } });
  text_layer_set_font(t7_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t7_layer,curBoard[6]);
  text_layer_set_text_alignment(t7_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t7_layer));
  
  
  t8_layer = text_layer_create((GRect) { .origin = { 100, 44 }, .size = { 30, 30 } });
  text_layer_set_font(t8_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t8_layer,curBoard[7]);
  text_layer_set_text_alignment(t8_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t8_layer));
  
  t9_layer = text_layer_create((GRect) { .origin = { 25, 68 }, .size = { 30, 30 } });
  text_layer_set_font(t9_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t9_layer,curBoard[8]);
  text_layer_set_text_alignment(t9_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t9_layer));
  
  
  t10_layer = text_layer_create((GRect) { .origin = { 50, 68 }, .size = { 30, 30 } });
  text_layer_set_font(t10_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t10_layer,curBoard[9]);
  text_layer_set_text_alignment(t10_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t10_layer));
  
   t11_layer = text_layer_create((GRect) { .origin = { 75, 68 }, .size = { 30, 30 } });
  text_layer_set_font(t11_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t11_layer,curBoard[10]);
  text_layer_set_text_alignment(t11_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t11_layer));
  
  
  t12_layer = text_layer_create((GRect) { .origin = { 100, 68 }, .size = { 30, 30 } });
  text_layer_set_font(t12_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t12_layer,curBoard[11]);
  text_layer_set_text_alignment(t12_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t12_layer));
  
    t13_layer = text_layer_create((GRect) { .origin = { 25, 92 }, .size = { 30, 30 } });
  text_layer_set_font(t13_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t13_layer,curBoard[12]);
  text_layer_set_text_alignment(t13_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t13_layer));
  
  
  t14_layer = text_layer_create((GRect) { .origin = { 50, 92 }, .size = { 30, 30 } });
  text_layer_set_font(t14_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t14_layer,curBoard[13]);
  text_layer_set_text_alignment(t4_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t14_layer));
  
   t15_layer = text_layer_create((GRect) { .origin = { 75, 92 }, .size = { 30, 30 } });
  text_layer_set_font(t15_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t15_layer,curBoard[14]);
  text_layer_set_text_alignment(t15_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t15_layer));
  
  
  t16_layer = text_layer_create((GRect) { .origin = { 100, 92 }, .size = { 30, 30 } });
  text_layer_set_font(t16_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(t16_layer,curBoard[15]);
  text_layer_set_text_alignment(t16_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(t16_layer));
  
  
 lButton_layer = text_layer_create((GRect) { .origin = { 1, 20}, .size = { 20, 120 } });
  text_layer_set_font(lButton_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text(lButton_layer,">");
  text_layer_set_text_alignment(lButton_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(lButton_layer));
  layer_set_frame( text_layer_get_layer(lButton_layer), GRect (1,90, 24,24 ));

   loadsetting();
   win_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { 144, 168} });
  text_layer_set_font(win_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
  char *ttemp="";
  char * cat ="";
     snprintf(ttemp, sizeof(ttemp), "%d", level);
  cat = strcat("SortFlip\nLevel\n", ttemp); 
  text_layer_set_text(win_layer,cat);
  text_layer_set_text_alignment(win_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(win_layer));
  layer_set_hidden((Layer *)win_layer, false);

  select=4;
   initLayers();
  
    updateButs();

  
}

static void window_unload(Window *window) {
  text_layer_destroy(t1_layer);
  text_layer_destroy(t2_layer);
    text_layer_destroy(t3_layer);
  text_layer_destroy(t4_layer);
    text_layer_destroy(t5_layer);
  text_layer_destroy(t6_layer);
    text_layer_destroy(t7_layer);
  text_layer_destroy(t8_layer);
   text_layer_destroy(t9_layer);
  text_layer_destroy(t10_layer);
    text_layer_destroy(t11_layer);
  text_layer_destroy(t12_layer);
    text_layer_destroy(t13_layer);
  text_layer_destroy(t14_layer);
    text_layer_destroy(t15_layer);
  text_layer_destroy(t16_layer);
  
  text_layer_destroy(lButton_layer);
 
}

static void init(void) {

  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
 window_set_window_handlers(window, (WindowHandlers) {
	.load = window_load,
    .unload = window_unload,
  });
  
  
   
  
  
    
 
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  savesetting();
  
  window_destroy(window);
  
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}