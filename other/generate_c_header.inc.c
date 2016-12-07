#include <pebble.h>
#include <time.h>


static int getWeekSteps(){

  // Get last week steps
  time_t start = time(NULL)-604800;
  time_t end = time(NULL);
  HealthMetric metric = HealthMetricStepCount;
  // Check the metric has data available for today
  HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric,
  start, end);
  int steps=0;

  if(mask & HealthServiceAccessibilityMaskAvailable) {
    // Data is available!
    steps=(int)health_service_sum(metric, start, end);
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Steps of the last 7days %d",steps);

  } else {
    // No data recorded yet today
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Data unavailable!");
  }
  return steps;
}

static int getPikachuHappiness(){



int steps = getWeekSteps();


  // HERE ARE THE VALUES...
  if (  steps > 17000 ){
    return 1;
  }
  else if (  steps > 38000 ){
    return 2;
  }
  else if (  steps > 70000 ){
    return 3;
  }
  else {
    return 0;
  }

}

static int getpikaanim( int pika_happiness, int current_hour ){
  if ( current_hour<8 || current_hour>=23 ){
    return NULL;
  }
  else {
    if (pika_happiness == 0){
      return RESOURCE_ID_IMAGE_ANIM_1;
    }
    else if (pika_happiness == 1){
      return RESOURCE_ID_IMAGE_ANIM_2;
    }
    else if (pika_happiness == 2){
      return RESOURCE_ID_IMAGE_ANIM_2;
    }
    else if (pika_happiness == 3){
      return RESOURCE_ID_IMAGE_ANIM_2;
    }
  }

}

static int getpikaimage( int pika_happiness, int current_hour ){

srand( time(NULL)/1200 ); // Change random every 20 minutes
int pika_image = RESOURCE_ID_IMAGE_PIKA65;
