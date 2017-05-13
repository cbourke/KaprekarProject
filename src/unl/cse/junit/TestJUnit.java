package unl.cse.junit;

import org.junit.Test;

import unl.cse.kaprekar.KaprekarUtils;

import static org.junit.Assert.assertEquals;
public class TestJUnit {
	
	@Test
	public void testAdd() {
		String str= "Junit is working fine";
		assertEquals("Junit is working fine",str);
	}
}