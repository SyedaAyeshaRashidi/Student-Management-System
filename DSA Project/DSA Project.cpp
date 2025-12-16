//#include <iostream>
//#include <string>
//using namespace std;
//
//// -------------------- Structures --------------------
//struct Student {
//    int roll;
//    string name;
//    string dept;
//    float cgpa;
//    Student* next;
//};
//
//struct Stack {
//    int roll;
//    Stack* next;
//};
//
//struct Queue {
//    int roll;
//    Queue* next;
//};
//
//// -------------------- Global Pointers --------------------
//Student* head = NULL;
//Stack* top = NULL;
//Queue* frontQ = NULL;
//Queue* rearQ = NULL;
//
//// -------------------- Prototypes --------------------
//void addStudent();
//void displayStudents();
//void deleteStudent();
//void updateStudent();
//void searchByNameAll();
//void searchByRollBinary();
//void pushStack(int roll);
//void showStack();
//void enqueue(int roll);
//void dequeue();
//void removeFromQueue(int roll);
//void sortBubble();
//void sortSelection();
//int countStudents();
//bool rollExists(int roll);
//
//// -------------------- Check Duplicate Roll --------------------
//bool rollExists(int roll) {
//    Student* temp = head;
//    while (temp != NULL) {
//        if (temp->roll == roll) return true;
//        temp = temp->next;
//    }
//    return false;
//}
//
//// -------------------- Add Student --------------------
//void addStudent() {
//    Student* newNode = new Student();
//
//    cout << "Enter Roll: ";
//    cin >> newNode->roll;
//
//    // ✅ Duplicate roll check
//    if (rollExists(newNode->roll)) {
//        cout << "Error: Student with this roll number already exists!\n";
//        delete newNode;
//        return;
//    }
//
//    cout << "Enter Name: ";
//    cin >> newNode->name;
//
//    cout << "Enter Department: ";
//    cin >> newNode->dept;
//
//    cout << "Enter CGPA: ";
//    cin >> newNode->cgpa;
//
//    newNode->next = NULL;
//
//    if (head == NULL) head = newNode;
//    else {
//        Student* temp = head;
//        while (temp->next != NULL)
//            temp = temp->next;
//        temp->next = newNode;
//    }
//
//    enqueue(newNode->roll);
//    cout << "Student added successfully.\n";
//}
//
//// -------------------- Display Students --------------------
//void displayStudents() {
//    Student* temp = head;
//    if (temp == NULL) {
//        cout << "No records found.\n";
//        return;
//    }
//
//    while (temp != NULL) {
//        cout << "\nRoll: " << temp->roll
//            << "\nName: " << temp->name
//            << "\nDepartment: " << temp->dept
//            << "\nCGPA: " << temp->cgpa << endl;
//        pushStack(temp->roll);
//        temp = temp->next;
//    }
//}
//
//// -------------------- Delete Student --------------------
//void deleteStudent() {
//    int r;
//    cout << "Enter roll no to delete: ";
//    cin >> r;
//
//    Student* temp = head;
//    Student* prev = NULL;
//
//    while (temp != NULL && temp->roll != r) {
//        prev = temp;
//        temp = temp->next;
//    }
//
//    if (temp == NULL) {
//        cout << "Student not found.\n";
//        return;
//    }
//
//    if (prev == NULL) head = temp->next;
//    else prev->next = temp->next;
//
//    delete temp;
//    removeFromQueue(r);
//
//    cout << "Student deleted.\n";
//}
//
//// -------------------- Update Student --------------------
//void updateStudent() {
//    int r;
//    cout << "Enter roll to update: ";
//    cin >> r;
//
//    Student* temp = head;
//    while (temp != NULL && temp->roll != r)
//        temp = temp->next;
//
//    if (temp == NULL) {
//        cout << "Student not found.\n";
//        return;
//    }
//
//    cout << "Enter new name: ";
//    cin >> temp->name;
//    cout << "Enter new department: ";
//    cin >> temp->dept;
//    cout << "Enter new CGPA: ";
//    cin >> temp->cgpa;
//
//    cout << "Record updated.\n";
//}
//
//// -------------------- Search by Name --------------------
//void searchByNameAll() {
//    string name;
//    cout << "Enter name: ";
//    cin >> name;
//
//    Student* temp = head;
//    bool found = false;
//
//    while (temp != NULL) {
//        if (temp->name == name) {
//            found = true;
//            cout << "\nRoll: " << temp->roll
//                << "\nDepartment: " << temp->dept
//                << "\nCGPA: " << temp->cgpa << endl;
//            pushStack(temp->roll);
//        }
//        temp = temp->next;
//    }
//
//    if (!found) cout << "No student found.\n";
//}
//
//// -------------------- Count Students --------------------
//int countStudents() {
//    int c = 0;
//    Student* temp = head;
//    while (temp != NULL) {
//        c++;
//        temp = temp->next;
//    }
//    return c;
//}
//
//// -------------------- Bubble Sort --------------------
//void sortBubble() {
//    int n = countStudents();
//    if (n == 0) return;
//
//    Student* arr[100];
//    Student* temp = head;
//    int i = 0;
//
//    while (temp != NULL) {
//        arr[i++] = temp;
//        temp = temp->next;
//    }
//
//    for (i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j]->roll > arr[j + 1]->roll) {
//                Student* t = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = t;
//            }
//        }
//    }
//
//    cout << "\nSorted by Roll no.\n";
//    for (i = 0; i < n; i++)
//        cout << arr[i]->roll << " - " << arr[i]->name << endl;
//}
//
//// -------------------- Selection Sort --------------------
//void sortSelection() {
//    int n = countStudents();
//    if (n == 0) return;
//
//    Student* arr[100];
//    Student* temp = head;
//    int i = 0;
//
//    while (temp != NULL) {
//        arr[i++] = temp;
//        temp = temp->next;
//    }
//
//    for (i = 0; i < n - 1; i++) {
//        int min = i;
//        for (int j = i + 1; j < n; j++) {
//            if (arr[j]->name < arr[min]->name)
//                min = j;
//        }
//        Student* t = arr[i];
//        arr[i] = arr[min];
//        arr[min] = t;
//    }
//
//    cout << "\nSorted by Name:\n";
//    for (i = 0; i < n; i++)
//        cout << arr[i]->name << " - " << arr[i]->roll << endl;
//}
//
//// -------------------- Binary Search --------------------
//void searchByRollBinary() {
//    int n = countStudents();
//    if (n == 0) return;
//
//    Student* arr[100];
//    Student* temp = head;
//    int i = 0;
//
//    while (temp != NULL) {
//        arr[i++] = temp;
//        temp = temp->next;
//    }
//
//    for (i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j]->roll > arr[j + 1]->roll) {
//                Student* t = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = t;
//            }
//        }
//    }
//
//    int key;
//    cout << "Enter roll: ";
//    cin >> key;
//
//    int low = 0, high = n - 1;
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if (arr[mid]->roll == key) {
//            cout << "Found: " << arr[mid]->name << endl;
//            return;
//        }
//        else if (arr[mid]->roll < key) low = mid + 1;
//        else high = mid - 1;
//    }
//
//    cout << "Not found.\n";
//}
//
//// -------------------- Stack --------------------
//void pushStack(int roll) {
//    Stack* node = new Stack();
//    node->roll = roll;
//    node->next = top;
//    top = node;
//}
//
//void showStack() {
//    Stack* temp = top;
//    if (!temp) {
//        cout << "No recently viewed records.\n";
//        return;
//    }
//    while (temp != NULL) {
//        cout << "Roll: " << temp->roll << endl;
//        temp = temp->next;
//    }
//}
//
//// -------------------- Queue --------------------
//void enqueue(int roll) {
//    Queue* node = new Queue();
//    node->roll = roll;
//    node->next = NULL;
//
//    if (rearQ == NULL) frontQ = rearQ = node;
//    else {
//        rearQ->next = node;
//        rearQ = node;
//    }
//}
//
//void removeFromQueue(int roll) {
//    Queue* temp = frontQ;
//    Queue* prev = NULL;
//
//    while (temp != NULL && temp->roll != roll) {
//        prev = temp;
//        temp = temp->next;
//    }
//
//    if (!temp) return;
//
//    if (!prev) {
//        frontQ = temp->next;
//        if (!frontQ) rearQ = NULL;
//    }
//    else {
//        prev->next = temp->next;
//        if (temp == rearQ) rearQ = prev;
//    }
//    delete temp;
//}
//
//void dequeue() {
//    if (!frontQ) {
//        cout << "No pending requests.\n";
//        return;
//    }
//    cout << "Processed roll: " << frontQ->roll << endl;
//    Queue* temp = frontQ;
//    frontQ = frontQ->next;
//    if (!frontQ) rearQ = NULL;
//    delete temp;
//}
//
//// -------------------- Main --------------------
//int main() {
//    int choice;
//
//    do {
//        cout << "\n---- Student Record Management System ----\n";
//        cout << "1. Add Student\n2. Delete Student\n3. Update Student\n4. Display All Students \n";
//        cout << "5. Search by Name\n6. Search by Roll no.\n";
//        cout << "7. Sort by Roll\n8. Sort by Name\n9. View History\n10. Handle Pending Requests\n0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: addStudent(); break;
//        case 2: deleteStudent(); break;
//        case 3: updateStudent(); break;
//        case 4: displayStudents(); break;
//        case 5: searchByNameAll(); break;
//        case 6: searchByRollBinary(); break;
//        case 7: sortBubble(); break;
//        case 8: sortSelection(); break;
//        case 9: showStack(); break;
//        case 10: dequeue(); break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Node
{
public:
    string Name;
    int rollNo;
    float cgpa;
    int attendance;
    // string feeStatus;
    Node* next = nullptr;

    Node(string n, int r, float c, int a)
    {
        Name = n;
        rollNo = r;
        cgpa = c;
        attendance = a;
        // feeStatus = fee;
    }
};

class StudentList
{
public:
    Node* head;
    StudentList()
    {
        head = nullptr;
    }
    int countstudents()
    {
        int n = 0;
        Node* temp = head;
        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }
    void insertStudent() // Node *&head
    {
        string name;
        int rollNo;
        float cgpa;
        // string feeStatus;
        float attendedClasses;
        const int totalClasses = 48;

        cout << "-----------------------------" << endl;
        cout << "         NEW STUDENT         " << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Roll Number: ";
        cin >> rollNo;

        if (isRollExist(rollNo))
        {
            cout << "This Roll Number already exists! Roll Number must be UNIQUE.\n";
            return;
        }

        cout << "CGPA (0.0 - 4.0): ";
        cin >> cgpa;
        while (cgpa < 0.0 || cgpa > 4.0)
        {
            cout << "Invalid CGPA. Enter again: ";
            cin >> cgpa;
        }

        cout << "Enter Attended Classes: ";
        cin >> attendedClasses;
        cin.ignore();
        if (attendedClasses > totalClasses)
        {
            cout << "You have entered more classes than total!\n";
            return;
        }

        /*  cout << "Enter Fee Status (Paid/Pending): ";
          getline(cin, feeStatus);*/

        float attendancePercent = (attendedClasses / (float)totalClasses) * 100;

        Node* new_node = new Node(name, rollNo, cgpa, attendancePercent);

        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        cout << "Student added successfully! " << endl;
    }

    void displayStudents(Node* head)
    {
        if (head == nullptr)
        {
            cout << "\n----------------------No Record Found-------------------------\n";
            return;
        }

        cout << "\n---------------------------Student List------------------------\n";

        cout << left
            << "| " << setw(20) << "Name"
            << "| " << setw(10) << "Roll No"
            << "| " << setw(10) << "CGPA"
            << "| " << setw(12) << "Attendance" << " |\n";

        cout << "-----------------------------------------------------------------\n";

        Node* temp = head;
        while (temp != nullptr)
        {
            cout << left
                << "| " << setw(20) << temp->Name
                << "| " << setw(10) << temp->rollNo
                << "| " << setw(10) << temp->cgpa
                << "| " << setw(12) << temp->attendance << " |\n";

            temp = temp->next;
        }
    }

    void showAttendance()
    {
        int rollNo;
        cout << "Enter rollno:" << endl;
        cin >> rollNo;
        if (head == nullptr)
        {
            cout << "No students in the list!\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->rollNo == rollNo)
            {
                cout << "Attendance: " << temp->attendance << "%\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Student with Roll Number " << rollNo << " not found.\n";
    }
    //=================================== Update Student ====================================

    void updateStudent() {
        int roll;
        cout << "Enter Roll No to update: ";
        cin >> roll;

        Node* temp = head; 
        while (temp != nullptr && temp->rollNo != roll)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        cout << "Enter new Name: ";
        cin.ignore();
        getline(cin, temp->Name);
        cout << "Enter new CGPA: ";
        cin >> temp->cgpa;
       /* cout << "Enter new Attended Classes (0-48): ";
        int attended;
        cin >> attended;
        temp->attendance = (attended / 48.0f) * 100;

        cout << "Student record updated successfully!\n";*/
    }

    //====================================================================================================
    void searchStudent_ByGPA()
    {
        int choice;
        cout << "\n1) Search Student By CGPA Range";
        cout << "\n2) Search Student By Exact CGPA\n";
        cout << "Enter your choice" << " ";
        cin >> choice;

        // --------- RANGE SEARCH -------------------
        if (choice == 1)
        {
            float low;
            float high;
            cout << "Enter Lower Range: ";
            cin >> low;
            cout << "Enter Upper Range: ";
            cin >> high;

            if (low > high)
            {
                cout << "Invalid range! Lower limit cannot be greater than upper limit.\n";
                return;
            }

            Node* temp = head;
            bool found = false;

            while (temp != nullptr)
            {
                if (temp->cgpa >= low && temp->cgpa <= high)
                {
                    cout << "Name: " << temp->Name
                        << " | Roll No: " << temp->rollNo
                        << " | CGPA: " << temp->cgpa << endl;
                    found = true;
                }
                temp = temp->next;
            }

            if (!found)
                cout << "No students found in this CGPA range.\n";
        }

        // -------EXACT CGPA SEARCH -------------------
        else if (choice == 2)
        {
            float targetGpa;
            cout << "Enter Exact CGPA: ";
            cin >> targetGpa;

            Node* temp = head;
            bool found = false;

            while (temp != nullptr)
            {
                if (temp->cgpa == targetGpa)
                {
                    cout << "Name: " << temp->Name
                        << " | Roll No: " << temp->rollNo
                        << " | CGPA: " << temp->cgpa << endl;
                    found = true;
                }
                temp = temp->next;
            }

            if (!found)
                cout << "No student found with this CGPA.\n";
        }

        else
        {
            cout << "Invalid choice!\n";
        }
    }

    // search by name

    void searchStudent_ByName()
    {
        string search_Name;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, search_Name);
        /*       cin >> search_Name;*/

        bool found = false;

        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->Name == search_Name)
            {
                cout << "\nName: " << temp->Name
                    << "\nRoll No: " << temp->rollNo
                    << "\nCGPA: " << temp->cgpa
                    << "\nAttendance: " << temp->attendance << "%";
                //<< "\nFee status: " << temp->feeStatus << "\n";

                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "No student found with this name." << endl;
        }
    }

    // search by roll#
    void searchStudent_ByRollno()
    {
        int search_roll;
        cout << "Enter Student Roll No: ";
        cin >> search_roll;
        cin.ignore();

        Node* temp = head;
        bool found = false;
        while (temp != nullptr)
        {
            if (temp->rollNo == search_roll)
            {
                cout << "\nRoll No: " << temp->rollNo
                    << "\nName: " << temp->Name
                    << "\nCGPA: " << temp->cgpa
                    << "\nAttendance: " << temp->attendance << "%";
                //<< "\nFee status: " << temp->feeStatus << "\n";
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "No student found with Roll Number " << search_roll << endl;
        }
    }

    bool isRollExist(int r)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->rollNo == r)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void SortBy_RollNo()
    {
        int n = countstudents();
        if (n < 2)
            return;
        Node* temp;
        Node* current;

        for (int i = 0; i < n - 1; i++)
        {
            current = head;

            for (int j = 0; j < n - 1 - i; j++)
            {
                if (current->rollNo > current->next->rollNo)
                {

                    int tRoll = current->rollNo;
                    current->rollNo = current->next->rollNo;
                    current->next->rollNo = tRoll;

                    string tName = current->Name;
                    current->Name = current->next->Name;
                    current->next->Name = tName;

                    float tCgpa = current->cgpa;
                    current->cgpa = current->next->cgpa;
                    current->next->cgpa = tCgpa;

                    int tAttendance = current->attendance;
                    current->attendance = current->next->attendance;
                    current->next->attendance = tAttendance;
                }
                current = current->next;
            }
        }

        cout << "\nStudents sorted by Roll Number!\n";
    }

    //____________________________ Delete Student _________________________________

    void deleteStudent_ByRollNo()
    {
        int roll;
        cout << "Enter Roll Number to delete: ";
        cin >> roll;
        if (head == nullptr)
        {
            cout << "No students to delete!\n";
            return;
        }
        if (head->rollNo == roll)
        {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "Student deleted successfully!\n";
            return;
        }
        Node* current = head;

        while (current->next != nullptr)
        {
            if (current->next->rollNo == roll)
            {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;

                cout << "Student deleted successfully!\n";
                return;
            }
            current = current->next;
        }

        cout << "Student with Roll Number " << roll << " not found!\n";
    }

};

// ---------------- MAIN OUTSIDE CLASS ------------------

int main()
{
    StudentList obj;
    // Node* head = nullptr;

    int id;

    while (true)
    {
        cout << "\n===== Student Record Management System =====";
        cout << "\n1) Add Student";
        cout << "\n2) Display All Students";
        cout << "\n3) Update Student";
        cout << "\n4) Search Student by Name";
        cout << "\n5) Search Student by Roll No";
        cout << "\n6) Search Student by CGPA";
        cout << "\n7) Sort by Roll No";
        cout << "\n8) Show Attendance";
        cout << "\n9) Delete Student \n";
        cout << "-----------------------------------------------------------------\n";

        cout << "Enter id: ";
        cin >> id;

        if (id == 1)
        {
            obj.insertStudent();
        }
        else if (id == 2)
        {
            obj.displayStudents(obj.head);
        }
        else if (id == 3)
        {
            obj.updateStudent();
            obj.displayStudents(obj.head);
        }
        else if (id == 4)
        {
            obj.searchStudent_ByName();
        }
        else if (id == 5)
        {
            obj.searchStudent_ByRollno();
        }
        else if (id == 6)
        {
            obj.searchStudent_ByGPA();
        }
        else if (id == 7)
        {
            obj.SortBy_RollNo();
            obj.displayStudents(obj.head);
        }
        else if (id == 8)
        {
            obj.showAttendance();
        }
        else if (id == 9)
        {
            obj.deleteStudent_ByRollNo();
        }
    }
}
