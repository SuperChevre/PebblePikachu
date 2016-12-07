#include <pebble.h>
#include "getimage.c"
#include "constants.h"

static Window *s_main_window;

static TextLayer *s_time_layer;
static TextLayer *s_step_layer;

static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;


static BitmapLayer *s_pokemon_layer;
static GBitmap *s_pokemon_bitmap;

static BitmapLayer *s_battery_layer;
static GBitmap *s_battery_bitmap;

static Layer *s_hapiness_progress;

static GFont s_font;
static GFont s_font2;

static GColor8 getHappyProgressColor( int steps ){

  return GColorMelon;
}

//////////////////////////////////////////////////////////////////////////
// Draw Pikachu
static GBitmapSequence *s_sequence;
static GBitmap *s_bitmap;



static void draw_pokemon( int currenthour ) {
  Layer *window_layer = window_get_root_layer(s_main_window);

  int pikahapiness = getPikachuHappiness();

  int resource_id = getpikaimage(pikahapiness,currenthour);
  s_pokemon_bitmap = gbitmap_create_with_resource(resource_id);

  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_pokemon_layer, s_pokemon_bitmap);
  layer_mark_dirty(bitmap_layer_get_layer(s_pokemon_layer));
}


static void pika_timer_handler(void *context) {
  uint32_t next_delay;

  // Advance to the next APNG frame, and get the delay for this frame
  if(gbitmap_sequence_update_bitmap_next_frame(s_sequence, s_bitmap, &next_delay)) {
    // Set the new frame into the BitmapLayer
    bitmap_layer_set_bitmap(s_pokemon_layer, s_bitmap);
    layer_mark_dirty(bitmap_layer_get_layer(s_pokemon_layer));

    // Timer for that frame's delay
    app_timer_register(next_delay, pika_timer_handler, NULL);
    APP_LOG(APP_LOG_LEVEL_DEBUG, "ANIM NEXT DELAY %d",next_delay);
  }
  else {
    // draw pikachu usual
    // draw the initial pokemon
    time_t temp = time(NULL);
    struct tm *tick_time = localtime(&temp);
    draw_pokemon( tick_time->tm_hour);
  }
}

static void draw_pika_animated( int currenthour ) {
    int pikahapiness = getPikachuHappiness();


    int resource_anim = getpikaanim( currenthour, pikahapiness );
    if ( resource_anim == NULL ){
      draw_pokemon(current_hour);
    }
    else {
      s_sequence = gbitmap_sequence_create_with_resource(RESOURCE_ID_IMAGE_ANIM_1 );
      // Create blank GBitmap using APNG frame size
      GSize frame_size = gbitmap_sequence_get_bitmap_size(s_sequence);

      s_bitmap = gbitmap_create_blank(frame_size, GBitmapFormat8Bit);
      gbitmap_sequence_set_play_count(s_sequence, 10);
      app_timer_register(10, pika_timer_handler, NULL);
      APP_LOG(APP_LOG_LEVEL_DEBUG, "ANIM FRAME SIZE %d %d",frame_size.w, frame_size.h);
    }
}

static void draw_hapiness_progress_proc( Layer *layer, GContext *ctx ) {
  int steps=getWeekSteps();
  if (steps>PIKA_MAX_HAPPY_PROGRESS){
    steps=PIKA_MAX_HAPPY_PROGRESS;
  }
  graphics_context_set_fill_color(ctx, getHappyProgressColor(steps) );

  #if defined(PBL_ROUND)
    int hapiness_angle=(( steps * 360) /PIKA_MAX_HAPPY_PROGRESS)/4+138;

    GRect bounds = layer_get_bounds( layer );

    GRect frame = grect_inset(bounds, GEdgeInsets(7));
    graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 2, DEG_TO_TRIGANGLE(132), DEG_TO_TRIGANGLE(hapiness_angle));
  #elif defined(PBL_RECT)
    int hapiness_size=(( steps * 124) /PIKA_MAX_HAPPY_PROGRESS);
    GRect bounds = layer_get_bounds( layer );
    GRect frame = grect_inset(bounds, GEdgeInsets(1));
    frame.origin.y=164;
    frame.origin.x=10;
    frame.size.h=3;
    frame.size.w=hapiness_size;

    APP_LOG(APP_LOG_LEVEL_DEBUG, "%d %d %d %d",frame.origin.y,frame.origin.x,frame.size.h,frame.size.w);
    graphics_fill_rect(ctx, frame,0,0);
  #endif
}

//
//////////////////////////////////////////////////////////////////////////


static void draw_battery() {
  Layer *window_layer = window_get_root_layer(s_main_window);
  int resource_id;
  BatteryChargeState charge_state = battery_state_service_peek();

  if (charge_state.is_charging) {
    resource_id = RESOURCE_ID_IMAGE_BATTERY;
      // Create GBitmap
  s_battery_bitmap = gbitmap_create_with_resource(resource_id);

  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_battery_layer, s_battery_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_battery_layer));
  } else if(charge_state.charge_percent <= 10) {
    resource_id = RESOURCE_ID_IMAGE_BATTERY0;
      // Create GBitmap
  s_battery_bitmap = gbitmap_create_with_resource(resource_id);

  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_battery_layer, s_battery_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_battery_layer));
  } else if(charge_state.charge_percent <= 20) {
    resource_id = RESOURCE_ID_IMAGE_BATTERY1;
      // Create GBitmap
  s_battery_bitmap = gbitmap_create_with_resource(resource_id);

  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_battery_layer, s_battery_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_battery_layer));
  } else {
    layer_remove_from_parent(bitmap_layer_get_layer(s_battery_layer));;
  }

}


static void update_time() {
  // time buffer
  static char s_buffer[9];

  // Display time
  clock_copy_time_string(s_buffer, 9);
  text_layer_set_text(s_time_layer, s_buffer);
}

static void update_step() {
  // buffer
  static char s_buffer[8];

  // Display time and step count
  snprintf(s_buffer, sizeof(s_buffer), "%d", (int)health_service_sum_today(HealthMetricStepCount));
  text_layer_set_text(s_step_layer, s_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
  update_step();

  if ( tick_time->tm_min == 20 || tick_time->tm_min == 40 || tick_time->tm_min == 0 ){
    layer_mark_dirty(s_hapiness_progress);
    draw_pokemon( tick_time->tm_hour );

  }

}

static void tap_handler(AccelAxisType axis, int32_t direction) {
  update_step();
}

static void battery_handler(BatteryChargeState charge_state) {
  draw_battery();
}

static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Load the custom font
s_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DIGIT_28));
s_font2 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DIGIT_32));


  // BACKGROUND
  // Create GBitmap
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMG_BACKGROUND);
  // Create BitmapLayer to display the GBitmap
  s_background_layer = bitmap_layer_create(GRect(0, 0, bounds.size.w, bounds.size.h));
  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));

  // Create BitmapLayer to display the Hapiness progress
  s_hapiness_progress = layer_create(bounds);
  layer_set_update_proc(s_hapiness_progress, draw_hapiness_progress_proc);
  layer_add_child(window_layer, s_hapiness_progress);

  // Create BitmapLayer to display the Pikachu GBitmap
  s_pokemon_layer = bitmap_layer_create(GRect(PBL_IF_ROUND_ELSE(36, 19), 45, 108, 90));
  bitmap_layer_set_compositing_mode(s_pokemon_layer, GCompOpSet);
  layer_add_child(window_layer, (Layer *)s_pokemon_layer);

  // Create BitmapLayer to display the Battery GBitmap
  s_battery_layer = bitmap_layer_create(GRect(20,122, 24, 12));

  draw_pika_animated();
  draw_battery();
  layer_mark_dirty(s_hapiness_progress);

  // TIME
  // Create time layers
  s_time_layer = text_layer_create(
      GRect(PBL_IF_ROUND_ELSE(18, 0), PBL_IF_ROUND_ELSE(0, 0), 144, 33));


  // Style the text
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  text_layer_set_text(s_time_layer, "00:00");
  // Use a custom font in a TextLayer
  text_layer_set_font(s_time_layer, s_font2);


  // Add layers to the window
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));

  // STEP
  // Create step Layer
  s_step_layer = text_layer_create(
      GRect( 0, 135, PBL_IF_ROUND_ELSE(180, 144), 29));

  // Style the text
  text_layer_set_background_color(s_step_layer, GColorClear);
  text_layer_set_text_color(s_step_layer, GColorBlack);
  text_layer_set_text_alignment(s_step_layer, GTextAlignmentCenter);
  text_layer_set_text(s_step_layer, "0");
  text_layer_set_font(s_step_layer, s_font);

  // Add layer to the window
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_step_layer));
}

static void main_window_unload(Window *window) {
  // Destroy bitmap elements and layers
  gbitmap_destroy(s_background_bitmap);
  bitmap_layer_destroy(s_background_layer);

  gbitmap_destroy(s_pokemon_bitmap);
  gbitmap_sequence_destroy(s_sequence);
  bitmap_layer_destroy(s_pokemon_layer);


  gbitmap_destroy(s_battery_bitmap);
  bitmap_layer_destroy(s_battery_layer);

  layer_destroy(s_hapiness_progress);
  // Destroy text elements
  text_layer_destroy(s_step_layer);
  text_layer_destroy(s_time_layer);
}


static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set the background color
  window_set_background_color(s_main_window, GColorWhite);

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

  // Make sure the steps are displayed from the start
  update_time();
  update_step();
  draw_battery();

  // Register with TickTimerService and AccelTapService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  accel_tap_service_subscribe(tap_handler);
  battery_state_service_subscribe(battery_handler);

}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
