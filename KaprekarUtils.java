package unl.cse.kaprekar;

public class KaprekarUtils {
	
	/**
	 * <p>This method tests whether the given input <code>n</code>
	 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
	 * integer n whose square can be split into two positive integers 
	 * whose sum is equal to the original number.  For the purposes of 
	 * this method, we restrict our consideration to base-10 representations.</p>
	 * 
	 * For example, 45 is a Kaprekar number, because 
	 *   45<sup>2</sup> = 2025 
	 * and 
	 *   20 + 25 = 45. 
	 * 
	 * <p>See Wikipedia's 
	 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
	 * article for more information.</p>
	 * 
	 * @param n
	 * @return <code>true</code> if <code>n</code> is a Kaprekar Number, 
	 * <code>false</code> otherwise.
	 */
	public static boolean isKaprekar(int n) {
		if(n < 1) {
			return false;
		} 
		else {
			//we use a long to accommodate larger squares
			long square = n * n;
			int numDigits = (int) Math.log10(n) + 1;
			long modulus = 1;
			long first, second;
			for(int i=1; i<=numDigits; i++) {
				modulus *= 10;
				first = square / modulus;
				second = square % modulus;
				if(first > 0 &&
					first + second == n) {
					return true;
				}
			}
		}
		return false;
	}
}