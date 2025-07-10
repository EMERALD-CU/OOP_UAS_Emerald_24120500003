#include <iostream>
#include <string>
#include <vector>
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

    virtual string getFullName() {
        return firstName + " " + lastName;
    }
};

class Coach : public Person {
private:
    string role;  // Head Coach, Assistant Coach
public:
    Coach(string pid, string fn, string ln, string dob, string nat, string r)
        : Person(pid, fn, ln, dob, nat), role(r) {}

    void conductTraining() {
        cout << getFullName() << " conducting training session as " << role << "." << endl;
    }

    string getRole() {
        return role;
    }
};

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

    int getJerseyNumber() {
        return jerseyNumber;
    }
};

class Team {
private:
    string teamName;
    vector<Coach> coaches;
    vector<Player> players;
public:
    Team(string name) : teamName(name) {}

    void addCoach(Coach coach) {
        coaches.push_back(coach);
    }

    void addPlayer(Player player) {
        players.push_back(player);
    }

    void displayRoster() {
        cout << "Team " << teamName << " Roster :" << endl;
        cout << "Coaches:" << endl;
        for (auto& c : coaches) {
            cout << "- " << c.getFullName() << " (" << c.getRole() << ")" << endl;
        }
        cout << "Players:" << endl;
        for (auto& p : players) {
            cout << "- #" << p.getJerseyNumber() << " " << p.getFullName() << endl;
        }
    }
};

int main() {
    Team fcCakrawalaMuda("FC Cakrawala Muda U-23");

    // Add Coaches
    Coach headCoach("C001", "Andi", "Setiawan", "1980-05-20", "Indonesian", "Head Coach");
    Coach assistantCoach("C002", "Budi", "Santoso", "1985-08-15", "Indonesian", "Assistant Coach");

    fcCakrawalaMuda.addCoach(headCoach);
    fcCakrawalaMuda.addCoach(assistantCoach);

    // Add Players
    fcCakrawalaMuda.addPlayer(Player("P001", "Rian", "Pratama", "2002-01-10", "Indonesian", 7, "Forward"));
    fcCakrawalaMuda.addPlayer(Player("P002", "Dewi", "Lestari", "2001-07-22", "Indonesian", 10, "Midfielder"));
    fcCakrawalaMuda.addPlayer(Player("P003", "Agus", "Wijaya", "2003-03-03", "Indonesian", 1, "Goalkeeper"));
    fcCakrawalaMuda.addPlayer(Player("P004", "Sari", "Nugroho", "2002-04-05", "Indonesian", 4, "Defender"));
    fcCakrawalaMuda.addPlayer(Player("P005", "Tomi", "Haryanto", "2002-06-15", "Indonesian", 11, "Forward"));
    fcCakrawalaMuda.addPlayer(Player("P006", "Rina", "Mahesa", "2003-02-20", "Indonesian", 8, "Midfielder"));
    fcCakrawalaMuda.addPlayer(Player("P007", "Joko", "Saputra", "2002-12-12", "Indonesian", 3, "Defender"));
    fcCakrawalaMuda.addPlayer(Player("P008", "Fitri", "Wulandari", "2001-11-09", "Indonesian", 9, "Forward"));
    fcCakrawalaMuda.addPlayer(Player("P009", "Adi", "Santoso", "2003-05-17", "Indonesian", 5, "Defender"));
    fcCakrawalaMuda.addPlayer(Player("P010", "Mira", "Putri", "2002-08-23", "Indonesian", 6, "Midfielder"));
    fcCakrawalaMuda.addPlayer(Player("P011", "Bayu", "Prasetyo", "2003-01-30", "Indonesian", 2, "Defender"));
    fcCakrawalaMuda.addPlayer(Player("P012", "Lia", "Amelia", "2001-09-29", "Indonesian", 12, "Midfielder"));
    fcCakrawalaMuda.addPlayer(Player("P013", "Hadi", "Kurniawan", "2002-07-14", "Indonesian", 14, "Forward"));
    fcCakrawalaMuda.addPlayer(Player("P014", "Nina", "Susanti", "2003-10-02", "Indonesian", 13, "Midfielder"));
    fcCakrawalaMuda.addPlayer(Player("P015", "Eko", "Wibowo", "2002-11-18", "Indonesian", 15, "Forward"));

    // Display roster
    fcCakrawalaMuda.displayRoster();

    return 0;
}
