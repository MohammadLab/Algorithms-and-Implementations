import java.io.*;
import java.util.*;

public class StudentMarks {
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
			this.average = Math.round((marks1 + marks2 + marks3) / 3.0 * 100.0) / 100.0;
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

	public static List<Student> readAndDisplayFile(String filename) {
		List<Student> students = new ArrayList<>();
		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			String line;
			boolean firstLine = true;
			while ((line = reader.readLine()) != null) {
				if (firstLine) {
					firstLine = false;
					System.out.println(line);
					continue;
				}
				System.out.println(line);
				String[] parts = line.split(", ");
				int marks1 = validateMarks(Integer.parseInt(parts[2].trim()));
				int marks2 = validateMarks(Integer.parseInt(parts[3].trim()));
				int marks3 = validateMarks(Integer.parseInt(parts[4].trim()));

				students.add(new Student(parts[0].trim(), parts[1].trim(), marks1, marks2, marks3));
			}
		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		}
		return students;
	}

	private static int validateMarks(int marks) {
		if (marks < 0 || marks > 100) {
			throw new IllegalArgumentException("Marks must be between 0 and 100");
		}
		return marks;
	}

	public static void writeStudentsToFile(List<Student> students, String filename) {
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
			System.out.println("Error writing to file: " + e.getMessage());
		}
	}

	public static Student findTopScorer(List<Student> students) {
		return students.stream().max(Comparator.comparingDouble(s -> s.average))
				.orElseThrow(() -> new RuntimeException("No students found"));
	}

	public static void main(String[] args) {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter("students.txt"))) {
			writer.write("ID, Name, Marks1, Marks2, Marks3\n");
			writer.write("101, Alice, 85, 78, 92\n");
			writer.write("102, Bob, 90, 88, 84\n");
			writer.write("103, Carol, 75, 72, 70\n");
			writer.write("104, David, 95, 92, 96\n");
			writer.write("105, Eve, 60, 65, 62\n");
		} catch (IOException e) {
			System.out.println("Error creating initial file: " + e.getMessage());
			return;
		}

		List<Student> students = readAndDisplayFile("students.txt");
		writeStudentsToFile(students, "students_with_avg.txt");
	}
}