
using namespace std;

struct person {
    string name = "";
    int age = 0;
};

person getPerson() {
    person newPerson;
    cout << "Enter new person's name: " << endl;
    cin >> newPerson.name;
    cout << "Enter new person's age: " << endl;
    cin >> newPerson.age;

    return newPerson;
}

void changePerson(person currentPerson) {
    currentPerson.name = "Andrew Cencini";
    currentPerson.age = 100;
    cout << currentPerson.name << " " << currentPerson.age << endl;
}