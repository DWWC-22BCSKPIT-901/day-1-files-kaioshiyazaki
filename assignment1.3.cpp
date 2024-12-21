// Q5. Hierarchical Inheritance for Employee Management System. (V Hard)

#include <iostream>
#include <string>
#include <memory>

class Employee {
protected:
    std::string name;
    int id;
    int salary;

public:
    Employee(const std::string &n, int i, int s) : name(n), id(i), salary(s) {}
    virtual ~Employee() = default;

    virtual void displayEarnings() const = 0; // pure virtual function
};

class Manager : public Employee {
private:
    int rating; // 1 to 5
public:
    Manager(const std::string &n, int i, int s, int r)
        : Employee(n, i, s), rating(r) {}

    void displayEarnings() const override {
        // Bonus per rating point = 10% of salary
        // total bonus = rating * 10% * salary = rating * (0.1 * salary)
        int bonus = static_cast<int>(rating * (0.1 * salary));
        int totalEarnings = salary + bonus;

        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
        std::cout << "Role: Manager\n";
        std::cout << "Base Salary: " << salary << "\n";
        std::cout << "Bonus: " << bonus << "\n";
        std::cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

class Developer : public Employee {
private:
    int extraHours; // 0 to 100
public:
    Developer(const std::string &n, int i, int s, int hours)
        : Employee(n, i, s), extraHours(hours) {}

    void displayEarnings() const override {
        // Overtime rate = $500 per hour
        int overtimeCompensation = extraHours * 500;
        int totalEarnings = salary + overtimeCompensation;

        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
        std::cout << "Role: Developer\n";
        std::cout << "Base Salary: " << salary << "\n";
        std::cout << "Overtime Compensation: " << overtimeCompensation << "\n";
        std::cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int employeeType;
    if (!(std::cin >> employeeType) || employeeType < 1 || employeeType > 2) {
        std::cout << "Invalid employee type.\n";
        return 0;
    }

    std::string name;
    int id;
    int salary;
    if (!(std::cin >> name >> id >> salary)) {
        std::cout << "Invalid input.\n";
        return 0;
    }

    // Validate common constraints
    if (salary < 10000 || salary > 1000000) {
        std::cout << "Invalid input.\n";
        return 0;
    }

    std::unique_ptr<Employee> emp;

    if (employeeType == 1) {
        // Manager
        int rating;
        if (!(std::cin >> rating)) {
            std::cout << "Invalid input.\n";
            return 0;
        }

        // Validate constraints
        if (rating < 1 || rating > 5) {
            std::cout << "Invalid input.\n";
            return 0;
        }

        emp = std::make_unique<Manager>(name, id, salary, rating);

    } else if (employeeType == 2) {
        // Developer
        int extraHours;
        if (!(std::cin >> extraHours)) {
            std::cout << "Invalid input.\n";
            return 0;
        }

        // Validate constraints
        if (extraHours < 0 || extraHours > 100) {
            std::cout << "Invalid input.\n";
            return 0;
        }

        emp = std::make_unique<Developer>(name, id, salary, extraHours);
    }

    if (emp) {
        emp->displayEarnings();
    } else {
        // This case should not be reached due to earlier checks,
        // but we include it for completeness.
        std::cout << "Invalid input.\n";
    }

    return 0;
}
