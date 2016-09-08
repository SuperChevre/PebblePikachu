#include <pebble.h>
#include <time.h>
#include "pseudorandomgen.c"

static int getPikachuHappiness(){

  // Get last week steps
  HealthMetric metric = HealthMetricStepCount;
time_t start = time(NULL)-604800;
time_t end = time(NULL);

int steps = 0;

// Check the metric has data available for today
HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric,
  start, end);

if(mask & HealthServiceAccessibilityMaskAvailable) {
  // Data is available!
  steps=(int)health_service_sum(metric, start, end);
  APP_LOG(APP_LOG_LEVEL_INFO, "Steps today: %d", steps);
} else {
  // No data recorded yet today
  APP_LOG(APP_LOG_LEVEL_ERROR, "Data unavailable!");
}


  // HERE ARE THE VALUES...
  if (  steps > 14000 ){
    return 1;
  }
  else if (  steps > 28000 ){
    return 2;
  }
  else if (  steps > 49000 ){
    return 3;
  }
  else {
    return 0;
  }

}

static int getpikaimage( int pika_happiness, int current_hour ){

getPikachuHappiness();
int pika_image = RESOURCE_ID_IMAGE_PIKA65;
