import  java.io.*;

/**
 * Test driver for class <code>AthleteScores</code>.
 *
 * @author  author name
 * @version  1.0.0
 */
public class TestAthleteScores  {

	/* Standard output stream */
	private static PrintWriter  stdOut = new  PrintWriter(System.out, true);

	/* Standard error stream */
	private static PrintWriter  stdErr = new  PrintWriter(System.err, true);

	/**
	 * Test driver for class <code>AthleteScores</code>.
	 *
	 * @param args  not used.
	 */
	public static void  main(String[] args)  {


		/* PLACE YOUR CODE HERE */
        AthleteScores scores = new AthleteScores("NurlashKO", 1, 2, 3);
        assertTrue("Wrong Name", scores.getName() == "NurlashKO");
        assertTrue("Wrong Score1", scores.getScoreOne() == 1);
        assertTrue("Wrong Score2", scores.getScoreTwo() == 2);
        assertTrue("Wrong Score3", scores.getScoreThree() == 3);

        scores.setScoreOne(5);
        assertTrue("Wrong Set1", scores.getScoreOne() == 5);

        scores.setScoreTwo(5);
        assertTrue("Wrong Set2", scores.getScoreOne() == 5);

        scores.setScoreThree(5);
        assertTrue("Wrong Set3", scores.getScoreOne() == 5);

        scores.setScoreOne(0);
        assertTrue("Wrong Min1", scores.getMinimum() == 0);

        scores.setScoreTwo(-1);
        assertTrue("Wrong Min2", scores.getMinimum() == -1);

        scores.setScoreThree(-2);
        assertTrue("Wrong Min3", scores.getMinimum() == -2);

        AthleteScores scores2 = new AthleteScores("NurlashKO", 1, 2, 3);
        assertTrue("Wrong EqualNames", scores.equals(scores2));

        AthleteScores scores3 = new AthleteScores("Nurlan", 1, 2, 3);
        assertTrue("Wrong Different Names", !scores.equals(scores3));

        assertTrue("Wrong Different Instances", !scores.equals(10));

        assertTrue("Wrong ToString", scores.toString().equals("NurlashKO,0.0,-1.0,-2.0"));
	}

	/**
	 * Displays a message in the standard error stream if the value specified
	 * by parameter <code>condition<code> is <code>false</code>.
	 *
	 * @param message  the error message.
	 * @param condition  the test condition.
	 */
	public static void assertTrue(String message, boolean condition) {

		if (! condition) {
			stdErr.print("** Test failure ");
			stdErr.println(message);
		}
	}
}
