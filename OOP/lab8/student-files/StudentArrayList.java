import java.util.*;

/**
 * This class contains methods to process array lists of {@link Student}
 * objects.
 *
 * @author  autor name
 * @version  1.0.0
 * @see  Student
 * @see  ArrayList
 */
public class  StudentArrayList  {

	/**
	 * Returns an array list with three elements.
	 *
	 * @param first  a <code>Student</code> object.
	 * @param second  a <code>Student</code> object.
	 * @param third  a <code>Student</code> object.
	 * @return an array list with the objects <code>first</code>,
	 *           <code>second</code>, and <code>third</code>
	 */
	public static ArrayList<Student> makeArrayList(
		Student  first,
		Student  second,
		Student  third)  {

        return new ArrayList<Student> (Arrays.asList(first, second, third));
	}

	/**
	 * Returns an array list with the same elements of the specified array
	 * arranged in the same order.
	 *
	 * @param array  an array with <code>Student</code> objects .
	 * @return an array list with the same elements of the specified array
	 *         arranged in the same order
	 */
	public static ArrayList<Student> makeArrayListFromArray(Student[] array) {

        return new ArrayList<Student>(Arrays.asList(array));
	}

	/**
	 * Returns <code>true</code> if the specified array list contains a
	 * student whose id matches the specified ID.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param id  a student ID.
	 * @return  <code>true</code> if the specified array list contains a
	 *          student whose ID matches the specified ID;
	 *          <code>false</code> otherwise.
	 */
	public static boolean hasStudent(
		ArrayList<Student>  arrayList,
		int  id)  {

        for (Student student : arrayList)
            if (student.getId() == id) return true;
        return false;
	}

	/**
	 * Returns the number of students in the specified array list whose
	 * grade is greater than or equal to the specified grade.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param grade  a grade.
	 * @return  the number of students in the specified array list whose
	 *          grade is greater than or equal to the specified grade.
	 */
	public static int countGradeGreaterOrEqual(
		ArrayList<Student> arrayList,
		int grade)  {

        int cnt = 0;
        for (Student s : arrayList)
        {
            if (s.getGrade() >= grade)
                cnt++;
        }
        return cnt;
	}

	/**
	 * Returns the smallest grade of the students in the specified array list.
	 * <p>
	 * This method assumes that the array list is not empty.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the smallest grade of the students in the specified array list.
	 */
	public static int getMinGrade(ArrayList<Student> arrayList)  {

        int m = 100;
        for (Student s : arrayList)
            if (s.getGrade() < m) m = s.getGrade();
        return m;
	}

	/**
	 * Returns the average grade of the students in the specified array list.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the average grade of the students in the specified array list.
	 */
	public static double getGradeAverage(ArrayList<Student>  arrayList)  {
        int cnt = 0, sum = 0;
        for (Student s : arrayList)
        {
            cnt++;
            sum += s.getGrade();
        }
        return sum / (cnt + 0.0);

	}

	/**
	 * Removes all students in the specified array list whose grade
	 * is less than the specified grade.
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @param grade  a grade.
	 */
	public static void removeGradeLess(
		ArrayList<Student>  arrayList,
		int  grade)  {

        ArrayList<Student> v = new ArrayList<Student>();
        for (int i = (int)arrayList.size() - 1; i >= 0; i--)
        {
            if (arrayList.get(i).getGrade() < grade)
                arrayList.remove(i);
        }

        return ;
	}

	/**
	 * Returns the string representation of the objects in the specified
	 * array list.
	 * <p>
	 * A new line character ( \n ) should separate the string
	 * representations of the objects. For example:
	 * </p>
	 * <pre>
	 * Student[328,Galileo Galilei,80]\nStudent[123,Albert Einstein,100]
	 * </pre>
	 * <p>
	 * Note that the string does <i>not</i> end with a new line character ( \n )
	 * </p>
	 *
	 * @param arrayList  an array list of <code>Student</code> objects.
	 * @return  the string representation of the objects in the specified
	 *          array list.
	 */
	public static String displayAll(ArrayList<Student>  arrayList)  {

        String s = "";
        for (int i = 0; i < arrayList.size(); i++)
        {
            if (i > 0)
                s += "\n";
            s += arrayList.get(i);
        }
        return s;
	}
}
