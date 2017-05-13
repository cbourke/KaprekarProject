#include<stdlib.h>
#include<stdio.h>

#include "kaprekarUtils.h"

/**
 * Utility function to test if the given key is the given array.
 */
static int contains(int arr[], int n, int key);

/**                                                                                                                       
 * A class to demonstrated automated, but ad-hoc testing                                                                  
 * without a testing framework.  Much of the "heavy lifting"                                                              
 * falls to the developer.                                                                                                
 *                                                                                                                        
 * @author cbourke                                                                                                        
 *                                                                                                                        
 */
int main(int argc, char **argv) {

  //number of Kaprekar Numbers between [1, 100,000]
  int numKaprekarNumbers = 24;
  int kaprekarNumbers[] = {1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962, 77778, 82656, 95121, 99999};
  
  int numCorrect = 0;
  int numWrong   = 0;
  int i;
    
  for(i=-10; i<=100000; i++) {
    if(contains(kaprekarNumbers, numKaprekarNumbers, i) != isKaprekar(i)) {
      numWrong++;
      if(contains(kaprekarNumbers, numKaprekarNumbers, i)) {
	fprintf(stderr, "i = %d: is a known Kaprekar number, but the method returned false\n", i);
      } else {
	fprintf(stderr, "i = %d: is known NOT to be a Kaprekar number, but the method returned true\n", i);
      }
    } else {
      numCorrect++;
    }
  }
  printf("Number of tests passed: %d\n", numCorrect);
  printf("Number of tests failed: %d\n", numWrong);
  double percentCorrect = (double) numCorrect / (numCorrect + numWrong) * 100.0;
  printf("Percentage Test Cases passed: %.2f\n", percentCorrect);

  return 0;      
}

static int contains(int arr[], int n, int key) {
  int i;
  for(i=0; i<n; i++) {
    if(arr[i] == key) {
      return 1;
    }
  }
  return 0;
}
