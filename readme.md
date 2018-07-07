
## Computer Science I - GitHub Assignment

This repo contains code and tests for a simple GitHub assignment in used in Computer Science I at the University of Nebraska-Lincoln.  It contains code to compute whether or not a given integer is a Kaprekar number.  It contains both Java and C versions.  Both versions contain both ad-hoc testing suites as well as examples of formal testing frameworks (junit and cmocka respectively).

Both versions contain intentional syntax errors and bugs that will fail a number of test cases.  The assignment is to fix these errors, commit and document each change and to push it to your own repository.

When working with GitHub, you should *fork* the project first to your own GitHub profile.  *Then* clone *your* repository to your local machine, make and commit changes, then push them to your repository.


### C Version

C code is available in `c_version/`.  A `makefile` is provided that specifies how to build the various parts of the project.  You can build the demo using:

`make kaprekarDemo`

and then run it from the command line using

`./kaprekarDemo 297`

An ad-hoc testing program has been provided as well which can be built using

`make kaprekarTest`

and then run it from the command line using

`./kaprekarTest`

An alternative version, `kaprekarTestCmocka.c` has been provided that uses a formal unit testing framework called cmocka (https://cmocka.org/).  It can be built using:

`make kaprekarTestCmocka`

which produces an executable, `kaprekarTestCmocka`.  This will only work if you have cmocka installed on your system.  The necessary files have already been installed on the CSE server, so you should build and test there.

Only after you have corrected all of the problems (both syntax errors as well as logic errors) will everything compile and the test suite reach 100%

### Java Version

Code for the Java version is in `src` directory.  However, the project is setup as an Eclipse project so you should clone the repo via Eclipse if you want the build to work.

Files provided:
  * `KaprekarUtils.java` - contains the method used to determine if an integer is a Kaprekar number or not
  * `KaprekarDemo.java` - contains a `main` method that you can run ad-hoc tests with
  * `AutomatedAdHocTest.java` - an ad-hoc automated test suite
  * `TestKaprekarUtils.java` - an automated test suite that uses JUnit

Once you've fixed all issues, run either `AutomatedAdHocTest` or `TestKaprekarUtils` to verify that your code is correct.
