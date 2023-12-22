#include <iostream>
#include <vector>
#include <string>

class Faculty {
protected:
    std::string name;
    std::string qualification;
    std::vector<std::string> subjects;

public:
    Faculty(const std::string& fName, const std::string& fQualification, const std::vector<std::string>& fSubjects)
        : name(fName), qualification(fQualification), subjects(fSubjects) {}

    virtual ~Faculty() {}

    virtual void readData() {
        std::cout << "Enter Name: ";
        std::cin >> name;

        std::cout << "Enter Qualification: ";
        std::cin >> qualification;

        std::cout << "Enter the number of subjects: ";
        int numSubjects;
        std::cin >> numSubjects;

        subjects.clear();
        std::cout << "Enter Subjects (separated by space): ";
        for (int i = 0; i < numSubjects; ++i) {
            std::string subject;
            std::cin >> subject;
            subjects.push_back(subject);
        }
    }

    virtual void displayData() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Qualification: " << qualification << std::endl;
        std::cout << "Subjects: ";
        for (const auto& subject : subjects) {
            std::cout << subject << " ";
        }
        std::cout << std::endl;
    }
};

class RegularFaculty : public Faculty {
public:
    RegularFaculty(const std::string& name, const std::string& qualification, const std::vector<std::string>& subjects)
        : Faculty(name, qualification, subjects) {}

    void readData() override {
        Faculty::readData();
        // Additional specific input for Regular Faculty (if needed)
    }

    void displayData() const override {
        std::cout << "Regular Faculty Details\n";
        Faculty::displayData();
        // Additional specific display for Regular Faculty (if needed)
    }
};

class VisitingFaculty : public Faculty {
private:
    std::string consultingTime;

public:
    VisitingFaculty(const std::string& name, const std::string& qualification, const std::vector<std::string>& subjects)
        : Faculty(name, qualification, subjects) {}

    void readData() override {
        Faculty::readData();
        
        std::cout << "Enter Consulting Time: ";
        std::cin >> consultingTime;
    }

    void displayData() const override {
        std::cout << "Visiting Faculty Details\n";
        Faculty::displayData();
        std::cout << "Consulting Time: " << consultingTime << std::endl;
    }
};

int main() {
    RegularFaculty regularFaculty("John Doe", "Ph.D.", {"Math", "Physics", "Chemistry"});
    VisitingFaculty visitingFaculty("Alice Smith", "M.Sc.", {"Computer Science"});

    regularFaculty.displayData();
    std::cout << "------------------------\n";
    visitingFaculty.displayData();

    return 0;
}
