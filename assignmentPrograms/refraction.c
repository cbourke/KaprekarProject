/*
* Author: Chase Prochow
* Date:   9/4/2018
*
* This programs is desgined to take the incidence angle and the
* index refraction of the medium to calculate the angle of refraction
*
*/
#include "stdlib.h"
#include "stdio.h"
#include "math.h"


int main(void){

double incidenceAngle;
double refractionIndex;
double incidenceRadian;

printf("Please enter the angle of incidence: ");
scanf("%lf", &incidenceAngle);

printf("Please enter the index of refraction: ");
scanf("%lf", &refractionIndex);

if(refractionIndex < 1){
  printf("error: refraction index cannot be less than 1\n");
  exit(0);
}

if(incidenceAngle < 0 || incidenceAngle > 180){
  printf("error: the angle of incidence cannot be less than 0 or greater than 180\n");
  exit(0);
}


// turns incidenceAngle into radians

incidenceRadian = (incidenceAngle / 180) * M_PI;

// calc the angle fo refration

double refractionRadian = asin((sin(incidenceRadian)) / refractionIndex);

// tunrs refractionRadian in degrees

double refractionAngle = (refractionRadian / M_PI) * 180;

printf("Angle of incidence:    %.4f degrees\n", incidenceAngle);
printf("Index of refraction:   %.4f\n", refractionIndex);
printf("Angle of refraction:   %.2f degrees\n", refractionAngle);

}
