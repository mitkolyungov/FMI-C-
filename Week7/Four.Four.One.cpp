#include<iostream>
#include "Power.h"
#include "Student.h"
#include "School.h"

void fightHouses(School& school, const string& house1, const string& house2) {
	std::cout << "Fight between " << house1 << " and " << house2 << std::endl;

	for (int i = 0; i < school.getSize(); i++) {
		
		const Student *student = school.getStudents();

		// no time
	}
}

int main() {
	Power spell("Expelliarmus", 10);
	Power curse("Cruciatus", 20);
	Power charm("Lumos", 5);

	School school;

	// Add some students
	school.addStudent(Student("Harry Potter"));
	school.addStudent(Student("Ron Weasley"));
	school.addStudent(Student("Hermione Granger"));
	school.addStudent(Student("Draco Malfoy"));
	school.addStudent(Student("Luna Lovegood"));

	// Assign them to houses
	school.assignHouse("Harry Potter", "Gryffindor");
	school.assignHouse("Ron Weasley", "Gryffindor");
	school.assignHouse("Hermione Granger", "Gryffindor");
	school.assignHouse("Draco Malfoy", "Slytherin");
	school.assignHouse("Luna Lovegood", "Ravenclaw");

	// Give them powers
	school.givePower("Harry Potter", spell);
	school.givePower("Ron Weasley", spell);
	school.givePower("Hermione Granger", curse);
	school.givePower("Draco Malfoy", curse);
	school.givePower("Luna Lovegood", charm);

	fightHouses(school, "Gryffindor", "Slytherin");
	return 0;
}