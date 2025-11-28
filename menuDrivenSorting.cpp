#include <iostream>
using namespace std;

class Student {

    public:
    int roll;
    string name;
    double marks;

    Student(int roll, string name, double marks)
    {
        this->roll = roll;
        this->name = name;
        this->marks = marks;
    }
};

void input(vector<Student> &v) {
    int roll;
    string name;
    double marks;

    cout << "Enter student info (roll name marks). Type -1 to stop:\n";
    while (true) {
        cout << ">> ";
        cin >> roll;
        if (roll == -1) break;

        cin >> name >> marks;
        v.push_back(Student(roll,name,marks));
    }
}

void search(const vector<Student> &v) {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    bool found = false;
    for (auto &s : v) {
        if (s.roll == roll) {
            cout << "Student found: " << "Name: " << s.name << " Marks: " << s.marks << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "No student with the roll " << roll << " found.\n";
}

void display(vector<Student> v) {
    if (v.empty()) {
        cout << "No students to display.\n";
        return;
    }

    sort(v.begin(), v.end(), [](const Student &a, const Student &b){
        return a.roll > b.roll;  
    });

    cout << "Rank\tRoll\tName\tMarks\n";
    int rank = 1;
    for (auto &s : v) {
        cout << rank << "\t" << s.roll << "\t" << s.name << "\t" << s.marks << "\n";
        rank++;
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Information Menu";
        cout << "\n========================\n";
        cout << "1. Input student info\n";
        cout << "2. Search by Roll\n";
        cout << "3. Sort by Roll \n";
        cout << "4. Exit";
        cout << "\n========================\n";
        cout << "Enter choice >> ";
        cin >> choice;

        switch(choice) {
            case 1:
                input(students);
                break;
            case 2:
                search(students);
                break;
            case 3:
                display(students);
                break;
            case 4:
                cout << "Exiting.....\n\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}