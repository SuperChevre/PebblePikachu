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
switch(pika_happiness) {
  case 3 :
      switch(current_hour) {
	     case 4 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 9 :
		   switch( genrand()%15) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 13 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 14 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 17 :
		   switch( genrand()%13) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 21 :
		   switch( genrand()%9) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 6 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 13 :
		   switch( genrand()%6) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 14 :
		   switch( genrand()%4) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 12 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 8 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
}
	     	break;
	     case 20 :
		   switch( genrand()%9) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 23 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 0 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 22 :
		   switch( genrand()%9) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 19 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 7 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 16 :
		   switch( genrand()%13) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 1 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 3 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 2 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 11 :
		   switch( genrand()%12) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 10 :
		   switch( genrand()%15) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 13 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 14 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 15 :
		   switch( genrand()%14) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA28;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 13 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 18 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA16;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 5 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
      }
      break;
  case 2 :
      switch(current_hour) {
	     case 4 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 9 :
		   switch( genrand()%13) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 17 :
		   switch( genrand()%11) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 21 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 6 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 13 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 14 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 12 :
		   switch( genrand()%4) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 8 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
}
	     	break;
	     case 20 :
		   switch( genrand()%8) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 23 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 0 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 22 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA65;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 19 :
		   switch( genrand()%4) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 7 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 16 :
		   switch( genrand()%11) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 1 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 3 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 2 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 11 :
		   switch( genrand()%10) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 10 :
		   switch( genrand()%13) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 12 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 15 :
		   switch( genrand()%12) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA05;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA02;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA03;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA06;
				    break;
				case 10 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 11 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 18 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA14;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA13;
				    break;
}
	     	break;
	     case 5 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
      }
      break;
  case 1 :
      switch(current_hour) {
	     case 4 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 9 :
		   switch( genrand()%10) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 17 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 21 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 6 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 13 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 14 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 12 :
		   switch( genrand()%4) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 8 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
}
	     	break;
	     case 20 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 23 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 0 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 22 :
		   switch( genrand()%5) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 19 :
		   switch( genrand()%4) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA64;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA04;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 7 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 5 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 1 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 16 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 3 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 2 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 11 :
		   switch( genrand()%7) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 10 :
		   switch( genrand()%10) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA07;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA12;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 8 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 9 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 15 :
		   switch( genrand()%8) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA15;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA30;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA20;
				    break;
				case 3 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA21;
				    break;
				case 4 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA19;
				    break;
				case 5 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA84;
				    break;
				case 6 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 7 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
	     case 18 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA34;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA01;
				    break;
}
	     	break;
      }
      break;
  case 0 :
      switch(current_hour) {
	     case 9 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 4 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 6 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 17 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 8 :
		   switch( genrand()%1) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
}
	     	break;
	     case 21 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 13 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 14 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 12 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 16 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 20 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 23 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 0 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 22 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 19 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 7 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 5 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 1 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 3 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 2 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA08;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA09;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA10;
				    break;
}
	     	break;
	     case 11 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 10 :
		   switch( genrand()%3) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA11;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 2 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 15 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
	     case 18 :
		   switch( genrand()%2) {
				case 0 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA17;
				    break;
				case 1 :
				    pika_image=RESOURCE_ID_IMAGE_PIKA18;
				    break;
}
	     	break;
      }
      break;
}
}
