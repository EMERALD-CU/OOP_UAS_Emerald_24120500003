#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
protected:
    string personId;
    string firstName;
    string lastName;
    string dateOfBirth;
    string nationality;
public:
    Person(string pid, string fn, string ln, string dob, string nat)
        : personId(pid), firstName(fn), lastName(ln), dateOfBirth(dob), nationality(nat) {}

    virtual ~Person() = default;
    
    virtual string getFullName() const {
        return firstName + " " + lastName;
    }
    
    virtual void displayRole() const = 0;
};

// Concrete class Coach
class Coach : public Person {
private:
    string role;  // Head Coach, Assistant Coach
public:
    Coach(string pid, string fn, string ln, string dob, string nat, string r)
        : Person(pid, fn, ln, dob, nat), role(r) {}

    void conductTraining() {
        cout << getFullName() << " conducting training session as " << role << "." << endl;
    }

    string getRole() const {
        return role;
    }

    void displayRole() const override {
        cout << "Coach role: " << role << endl;
    }
};

// Concrete class Player
class Player : public Person {
private:
    int jerseyNumber;
    string position; // Forward, Midfield, Defender, Goalkeeper
    string status;
public:
    Player(string pid, string fn, string ln, string dob, string nat, int jersey, string pos)
        : Person(pid, fn, ln, dob, nat), jerseyNumber(jersey), position(pos), status("Active") {}

    void playMatch() {
        cout << "Player " << getFullName() << " is playing in position " << position << "." << endl;
    }

    int getJerseyNumber() const {
        return jerseyNumber;
    }

    void displayRole() const override {
        cout << "Player position: " << position << ", Jersey Number: " << jerseyNumber << endl;
    }
};

// Concrete class Staff
class Staff : public Person {
private:
    string department;
    string role;
public:
    Staff(string pid, string fn, string ln, string dob, string nat, string dept, string r)
        : Person(pid, fn, ln, dob, nat), department(dept), role(r) {}

    void performDuties() {
        cout << getFullName() << " performing duties as " << role << " in " << department << " department." << endl;
    }

    void displayRole() const override {
        cout << "Staff role: " << role << " (Department: " << department << ")" << endl;
    }
};

// Interface factory PersonFactory
class PersonFactory {
public:
    virtual ~PersonFactory() = default;
    virtual shared_ptr<Person> createPerson() const = 0;
};

// Concrete Factory CoachFactory
class CoachFactory : public PersonFactory {
private:
    string pid, fn, ln, dob, nat, role;
public:
    CoachFactory(string pid_, string fn_, string ln_, string dob_, string nat_, string role_)
        : pid(pid_), fn(fn_), ln(ln_), dob(dob_), nat(nat_), role(role_) {}

    shared_ptr<Person> createPerson() const override {
        return make_shared<Coach>(pid, fn, ln, dob, nat, role);
    }
};

// Concrete Factory PlayerFactory
class PlayerFactory : public PersonFactory {
private:
    string pid, fn, ln, dob, nat, position;
    int jerseyNumber;
public:
    PlayerFactory(string pid_, string fn_, string ln_, string dob_, string nat_, int jersey_, string pos_)
        : pid(pid_), fn(fn_), ln(ln_), dob(dob_), nat(nat_), jerseyNumber(jersey_), position(pos_) {}

    shared_ptr<Person> createPerson() const override {
        return make_shared<Player>(pid, fn, ln, dob, nat, jerseyNumber, position);
    }
};

// Concrete Factory StaffFactory
class StaffFactory : public PersonFactory {
private:
    string pid, fn, ln, dob, nat, department, role;
public:
    StaffFactory(string pid_, string fn_, string ln_, string dob_, string nat_, string dept_, string role_)
        : pid(pid_), fn(fn_), ln(ln_), dob(dob_), nat(nat_), department(dept_), role(role_) {}

    shared_ptr<Person> createPerson() const override {
        return make_shared<Staff>(pid, fn, ln, dob, nat, department, role);
    }
};

class Team {
private:
    string teamName;
    vector<shared_ptr<Person>> members;
public:
    Team(string name) : teamName(name) {}

    void addMember(shared_ptr<Person> person) {
        members.push_back(person);
    }

    void displayRoster() const {
        cout << "Team " << teamName << " Roster:" << endl;
        for (const auto& member : members) {
            cout << "- " << member->getFullName() << " | ";
            member->displayRole();
        }
    }
};

int main() {
    Team fcCakrawalaMuda("FC Cakrawala Muda U-23");

    // Add Coaches using factory
    CoachFactory headCoachFactory("C001", "Andi", "Setiawan", "1980-05-20", "Indonesian", "Head Coach");
    CoachFactory assistantCoachFactory("C002", "Budi", "Santoso", "1985-08-15", "Indonesian", "Assistant Coach");

    fcCakrawalaMuda.addMember(headCoachFactory.createPerson());
    fcCakrawalaMuda.addMember(assistantCoachFactory.createPerson());

    // Add Players using factory
    PlayerFactory player1Factory("P001", "Rian", "Pratama", "2002-01-10", "Indonesian", 7, "Forward");
    PlayerFactory player2Factory("P002", "Dewi", "Lestari", "2001-07-22", "Indonesian", 10, "Midfielder");
    PlayerFactory player3Factory("P003", "Agus", "Wijaya", "2003-03-03", "Indonesian", 1, "Goalkeeper");
    PlayerFactory player4Factory("P004", "Sari", "Nugroho", "2002-04-05", "Indonesian", 4, "Defender");
    PlayerFactory player5Factory("P005", "Tomi", "Haryanto", "2002-06-15", "Indonesian", 11, "Forward");
    PlayerFactory player6Factory("P006", "Rina", "Mahesa", "2003-02-20", "Indonesian", 8, "Midfielder");
    PlayerFactory player7Factory("P007", "Joko", "Saputra", "2002-12-12", "Indonesian", 3, "Defender");
    PlayerFactory player8Factory("P008", "Fitri", "Wulandari", "2001-11-09", "Indonesian", 9, "Forward");
    PlayerFactory player9Factory("P009", "Adi", "Santoso", "2003-05-17", "Indonesian", 5, "Defender");
    PlayerFactory player10Factory("P010", "Mira", "Putri", "2002-08-23", "Indonesian", 6, "Midfielder");
    PlayerFactory player11Factory("P011", "Bayu", "Prasetyo", "2003-01-30", "Indonesian", 2, "Defender");
    PlayerFactory player12Factory("P012", "Lia", "Amelia", "2001-09-29", "Indonesian", 12, "Midfielder");
    PlayerFactory player13Factory("P013", "Hadi", "Kurniawan", "2002-07-14", "Indonesian", 14, "Forward");
    PlayerFactory player14Factory("P014", "Nina", "Susanti", "2003-10-02", "Indonesian", 13, "Midfielder");
    PlayerFactory player15Factory("P015", "Eko", "Wibowo", "2002-11-18", "Indonesian", 15, "Forward");


    fcCakrawalaMuda.addMember(player1Factory.createPerson());
    fcCakrawalaMuda.addMember(player2Factory.createPerson());
    fcCakrawalaMuda.addMember(player3Factory.createPerson());
    fcCakrawalaMuda.addMember(player4Factory.createPerson());
    fcCakrawalaMuda.addMember(player5Factory.createPerson());
    fcCakrawalaMuda.addMember(player6Factory.createPerson());
    fcCakrawalaMuda.addMember(player7Factory.createPerson());
    fcCakrawalaMuda.addMember(player8Factory.createPerson());
    fcCakrawalaMuda.addMember(player9Factory.createPerson());
    fcCakrawalaMuda.addMember(player10Factory.createPerson());
    fcCakrawalaMuda.addMember(player11Factory.createPerson());
    fcCakrawalaMuda.addMember(player12Factory.createPerson());
    fcCakrawalaMuda.addMember(player13Factory.createPerson());
    fcCakrawalaMuda.addMember(player14Factory.createPerson());
    fcCakrawalaMuda.addMember(player15Factory.createPerson());

    // Add Staff using factory
    StaffFactory staffFactory("S001", "Eko", "Widodo", "1975-11-11", "Indonesian", "Medical", "Physiotherapist");
    fcCakrawalaMuda.addMember(staffFactory.createPerson());

    // Display roster
    fcCakrawalaMuda.displayRoster();

    return 0;
}
