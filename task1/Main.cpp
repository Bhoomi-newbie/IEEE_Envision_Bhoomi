#include<iostream>
#include<string>
#include<vector>
#include<fstream>



class Student {
public:
	std::string name;
	int rollNumber;
	std::vector<float> grades = { 0,0,0 };

	Student(int roll,const std::string& name):name(name),rollNumber(roll){}
	float avg() {
		return ((grades[0] + grades[1] + grades[2]) / 3);
	}
};

std::vector<Student> studentList;

void add(int roll, const std::string& name) {
	studentList.emplace_back(roll, name);
}

void rm(int roll) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].rollNumber == roll) {
			studentList.erase(studentList.begin() + i);
			//delete *studentList[i];
		}
	}
}

void view() {
	for (int i = 0; i < studentList.size(); i++) {
		std::cout <<"Roll number: "<< studentList[i].rollNumber << ", Name: " << studentList[i].name << ", Marks: ";
		for (int j = 0; j < 3; j++) {
			std::cout << studentList[i].grades[j] << " " ;
		}
		std::cout<<std::endl;
	}
	    
}

void average(int roll) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].rollNumber == roll) {
			std::cout << studentList[i].avg() << std::endl;
		}
	}
}

void addMarks(int roll, const std::vector<float>& marks){
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].rollNumber == roll) {
			studentList[i].grades = marks;
		}
	}
}

void update(int roll,int sub,float marks) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].rollNumber == roll) {
			studentList[i].grades[sub]=marks;
		}
	}
}

void save(std::ofstream& file) {
	for (const auto& student : studentList) {
		file << student.rollNumber << " " << student.name << " ";
		for (float g : student.grades) {
			file << g << " ";
		}
		file << "\n";
	}
}

void load(std::ifstream& file) {
	std::string strInput{};
	while (std::getline(file, strInput))
		std::cout << strInput << '\n';
}

int main() {
	add(1, "ananya");
	add(2, "bhavy");
	add(3, "danny");
	addMarks(2, { 80,68,65 });
	addMarks(1, { 89,78,65 });
	addMarks(3, { 76,74,92 });
	//average(2);
	update(2, 0, 82);
	view();
	std::ofstream file{ "students.txt" };
	save(file);
	file.close();
	std::ifstream infile{ "students.txt" };
	load(infile);

}