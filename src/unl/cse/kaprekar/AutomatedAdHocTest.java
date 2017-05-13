package unl.cse.kaprekar;

import java.util.Arrays;
import java.util.List;

/**
 * A class to demonstrated automated, but ad-hoc testing
 * without a testing framework.  Much of the "heavy lifting" 
 * falls to the developer.
 * 
 * @author cbourke
 *
 */
public class AutomatedAdHocTest {

	/**
	 * Array of all Kaprekar Numbers up to 100,000
	 */
	public static final List<Integer> KAPREKAR_NUMBERS = Arrays.asList(1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962, 77778, 82656, 95121, 99999);
	
	public static void testAll() {
		int numCorrect = 0;
		int numWrong   = 0;
		
		for(int i=-10; i<=100000; i++) {
			if(KAPREKAR_NUMBERS.contains(i) != KaprekarUtils.isKaprekar(i)) {
				numWrong++;
				if(KAPREKAR_NUMBERS.contains(i)) {
					System.err.printf("i = %d: is a known Kaprekar number, but the method returned false\n", i);
				} else {
					System.err.printf("i = %d: is known NOT to be a Kaprekar number, but the method returned true\n", i);
				}
			} else {
				numCorrect++;
			}
		}
		System.out.println("Number of tests passed: " + numCorrect);
		System.out.println("Number of tests failed: " + numWrong);
		double percentCorrect = (double) numCorrect / (numCorrect + numWrong) * 100.0;
		System.out.println("Percentage Test Cases passed: " + percentCorrect);
		
	}
	
	public static void main(String args[]) {
		testAll();
	}
}
