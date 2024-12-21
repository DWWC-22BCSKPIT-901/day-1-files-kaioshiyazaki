#include <iostream>
#include <memory>
#include <stdexcept>

class Account {
public:
    virtual ~Account() = default;
    virtual void calculateInterest() = 0; // Pure virtual method
};

class SavingsAccount : public Account {
private:
    int balance;
    double interestRate;
    int time; // in years
public:
    SavingsAccount(int bal, double rate, int t) : balance(bal), interestRate(rate), time(t) {}
    void calculateInterest() override {
        // Interest = Balance × (Rate/100) × Time
        double interest = balance * (interestRate / 100.0) * time;
        std::cout << "Savings Account Interest: " << static_cast<int>(interest) << std::endl;
    }
};

class CurrentAccount : public Account {
private:
    int balance;
    int maintenanceFee;
public:
    CurrentAccount(int bal, int fee) : balance(bal), maintenanceFee(fee) {}
    void calculateInterest() override {
        // No interest for Current Account; Deduct maintenance fee.
        int finalBalance = balance - maintenanceFee;
        std::cout << "Balance after fee deduction: " << finalBalance << std::endl;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int accountType;
    if (!(std::cin >> accountType) || accountType < 1 || accountType > 2) {
        std::cout << "Invalid account type." << std::endl;
        return 0;
    }

    try {
        std::unique_ptr<Account> account;

        if (accountType == 1) {
            // Savings Account
            int balance;
            double interestRate;
            int time;
            if (!(std::cin >> balance >> interestRate >> time)) {
                std::cout << "Invalid input." << std::endl;
                return 0;
            }
            // Validate constraints
            if (balance < 1000 || balance > 1000000 
                || interestRate < 1 || interestRate > 15 
                || time < 1 || time > 10) {
                std::cout << "Invalid input." << std::endl;
                return 0;
            }

            account = std::make_unique<SavingsAccount>(balance, interestRate, time);
        } else {
            // Current Account
            int balance;
            int fee;
            if (!(std::cin >> balance >> fee)) {
                std::cout << "Invalid input." << std::endl;
                return 0;
            }
            // Validate constraints
            if (balance < 1000 || balance > 1000000 
                || fee < 50 || fee > 500) {
                std::cout << "Invalid input." << std::endl;
                return 0;
            }

            account = std::make_unique<CurrentAccount>(balance, fee);
        }

        account->calculateInterest();

    } catch (...) {
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}
