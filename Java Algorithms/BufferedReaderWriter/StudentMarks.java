import java.io.*;
import java.util.*;

public class StudfentMarks {
	static class Student {
		String id;
		String name;
		int marks1, marks2, marks3;
		double average;
		char grade;

		Student(String id, String name, int marks1, int marks2, int marks3) {
			this.id = id;
			this.name = name;
			this.marks1 = marks1;
			this.marks2 = marks2;
			this.marks3 = marks3;
			calculateAverage();
			assignGrade();
		}

		void calculateAverage() {
			this.average = (marks1 + marks2 + marks3) / 3.0;
		}

		void assignGrade() {
			if (average >= 90)
				grade = 'A';
			else if (average >= 80)
				grade = 'B';
			else if (average >= 70)
				grade = 'C';
			else if (average >= 60)
				grade = 'D';
			else
				grade = 'F';
		}
	}

	public static List<Student> readStudent(String filename) {
		List<Student> students = new ArrayList<>();
		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			String line;
			System.out.println("ID, Name, Marks1, Marks2, Marks3");

			reader.readLine();

			while ((line = reader.readLine()) != null) {
				String[] parts = line.split(", ");
				String id = parts[0];
				String name = parts[1];
				int marks1 = validateMarks(Integer.parseInt(parts[2].trim()));
				int marks2 = validateMarks(Integer.parseInt(parts[3].trim()));
				int marks3 = validateMarks(Integer.parseInt(parts[4].trim()));

				students.add(new Student(id, name, marks1, marks2, marks3));
				System.out.println(id + ", " + name + ", " + marks1 + ", " + marks2 + ", " + marks3);
			}
		} catch (IOException e) {
			System.out.println("Error: " + e);
		}
		return students;
	}

	static int validateMarks(int marks) {
		if (marks < 0 || marks > 100) {
			System.out.println("Marks must be between 0 and 100");
			return -1;
		}
		return marks;
	}

	public static void writeStudent(List<Student> students, String filename) {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
			writer.write("ID, Name, Marks1, Marks2, Marks3, Average, Grade\n");

			for (Student student : students) {
				writer.write(String.format("%s, %s, %d, %d, %d, %.2f, %c\n", student.id, student.name, student.marks1,
						student.marks2, student.marks3, student.average, student.grade));
			}

			Student topScorer = findTopScorer(students);
			writer.write(String.format("\nTop Scorer: %s, Average: %.2f, Grade: %c", topScorer.name, topScorer.average,
					topScorer.grade));

		} catch (IOException e) {
			System.out.println("Error: " + e);
		}
	}

	public static Student findTopScorer(List<Student> students) {
		Student topStudent = students.get(0);
		for (Student student : students) {
			if (student.average > topStudent.average) {
				topStudent = student;
			}
		}
		return topStudent;
	}

	public static void main(String[] args) {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter("students.txt"))) {
			writer.write("ID, Name, Marks1, Marks2, Marks3\n");
			writer.write("101, Alice, 85, 78, 92\n");
			writer.write("102, Bob, 90, 88, 84\n");
			writer.write("103, Carol, 75, 72, 70\n");
			writer.write("104, David, 95, 92, 96\n");
			writer.write("105, Eve, 1111, 65, 62\n");
		} catch (IOException e) {
			System.out.println("Eror:" + e);
			return;
		}

		List<Student> students = readStudent("students.txt");
		writeStudent(students, "students_with_avg.txt");
	}
}