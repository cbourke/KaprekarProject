package unl.cse.kaprekar;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

import org.junit.Assert;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

/**
 * This is a test suite that tests the {@link unl.cse.kaprekar.KaprekarUtils#isKaprekar isKaprekar} 
 * method on all integers in the range [-10, {@link #UPPER_BOUND}].  Test cases are 
 * generated based on a static list ({@link #KAPREKAR_NUMBERS}) of known Kaprekar 
 * numbers up to {@link #MAX_UPPER_BOUND}.
 * 
 * This suite uses JUnit's {@link Parameterized} class to generate and execute multiple
 * test cases.  Why they call it "parameterized" when it clearly uses incorrectly uses raw
 * types is beyond me...
 * 
 * @author cbourke
 *
 */
@RunWith(Parameterized.class)
public class TestKaprekarUtils {

	/**
	 * Array of all Kaprekar Numbers up to 100,000
	 */
	public static final List<Integer> KAPREKAR_NUMBERS = Arrays.asList(1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962, 77778, 82656, 95121, 99999);
	/**
	 * The maximum value supported by this test suite
	 */
	public static final int MAX_UPPER_BOUND = 100000;
	/**
	 * The upper bound of the actual tests run
	 */
	public static final int UPPER_BOUND = 10000;

	private final int value;
	private final boolean isKaprekar;
	
	public TestKaprekarUtils(int value, boolean isKaprekar) {
		this.value = value;
		this.isKaprekar = isKaprekar;
	}
	
	//this static method returns a collection of test data
	@Parameters
	public static Collection<Object[]> generateData() {
		Collection<Object[]> data = new ArrayList<Object[]>();
		for(int i=-10; i<=Math.min(UPPER_BOUND, MAX_UPPER_BOUND); i++) {			
			Object[] testData;
			if(KAPREKAR_NUMBERS.contains(i)) {
				testData = new Object[]{i, true};
			} else {
				testData = new Object[]{i, false};
			}
			data.add(testData);
		}
		return data;
	}
	
	@Test
	public void test() {
		Assert.assertEquals("Test value: " + this.value + " failed",
				            this.isKaprekar,
				            KaprekarUtils.isKaprekar(this.value));
	}

}
