#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
using namespace::std;
#include "Student.h"
#include "Power.h"
#include <iostream>

class School {
private:
	Student *students;
	int size;
	int capacity;
	void resize() {
		Student* newStudentsSize = new Student[size];
		for (int i = 0; i < size; i++)
		{
			newStudentsSize[i] = students[i];
		};

		students = new Student[2 * size];
		for (int i = 0; i < size; i++)
		{
			students[i] = newStudentsSize[i];
		};

		delete[] newStudentsSize;
	};

public:
	School() {
		students = new Student[8];
		capacity = 8;
		size = 0;
	};

	int getSize() {
		return size;
	}
	School(const School& other) {
				students = new Student[other.capacity];

		for (int i = 0; i < other.size; i++)
		{
			students[i] = other.students[i];
		}
		size = other.size;
		capacity = other.capacity;
	};

	School(School&& other) {
		students = other.students;
		size = other.size;
		capacity = other.capacity;
		other.students = nullptr;
		other.capacity = 0;
		other.size = 0;
	};

	School& operator=(const School& other) {
		if (this != &other)
		{
			delete [] students;
			copy(other);
		}
		return *this;
	};

	School& operator=(School&& other) {
		if (this != &other)
		{
			delete[] students;
			students = other.students;
			capacity = other.capacity;
			size = other.size;
			other.students = nullptr;
			other.capacity = 0;
			other.size = 0;
		}
		return *this;
	};

	~School() {
		delete[] students;
	};
	void copy(const School& other) {
		size = other.size;
		capacity = other.capacity;
		if (other.size)
			students = nullptr;
		else
		{
			students = new Student[other.size];
			for (int i = 0; i < size; i++)
				students[i] = other.students[i];
		}
	};
	void addStudent(const Student& student) {
		if (size == capacity) {
			resize();
		};

		students[size++] = student;
	};

	void assignHouse(const string& studentName, const string& house) {
		for (int i = 0; i < size; i++)
		{
			Student student = students[i];
			if (student.getName() == studentName) {
				student.setHouse(house);
			};
		};
	};
	void givePower(const string& name, const Power& power) {
		for (int i = 0; i < size; i++)
		{
			Student student = students[i];
			if (student.getName() == name) {
				student.setPower(&power);
			};
		};
	};


	int getHouseStudentsCount(const string& house) {
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			Student student = students[i];
			if (student.getHouse() == house) {
				counter++;
			};
		};

		return counter;
	};


	Student* getFirstStudent(const std::string& house) {
		for (int i = 0; i < size; i++)
		{
			if (students[i].getHouse() == house) {
				return &students[i];
			}
		}
	};
	const Student* getStudents() {
		return students;
	};

	bool removeStudent(const string& name) {
		int indexFound = -1;
		for (int i = 0; i < size; i++)
		{
			if (students[i].getName() == name) {
				indexFound = i;
				break;
			}
		};

		for (int i = indexFound; i < size - 1; i++)
		{
			students[i] = students[i + 1];
		}

		size--;
	};
};

#endif // SCHOOL_H 
