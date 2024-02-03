#include <bits/stdc++.h>

using namespace std;

template<typename Numeric>
bool is_Number(const string &s){
    istringstream iss(s);
    Numeric n;
    iss >> noskipws >> n;
    return (iss.eof() && !iss.fail() && n >= 0);
}


void forceExit() {
    cout << "Please Press any key then Enter and check your input again or press Q then Enter to exit:\n";
    string s;
    cin >> s;
    if (s == "Q" || s == "q") exit(0);
    cin.ignore(); // Delete the newline character in the buffer
}

template<typename Numeric>
Numeric getUserInput(const string& prompt) {
    int attempts = 0;
    while (true) {
        string input;
        cout << prompt;
        getline(cin, input);
        if (is_Number<Numeric>(input)) {
            return stod(input);
        } else {
            cout << "\nWrong input format! ";
            if (++attempts > 5) {
                forceExit();
            }
        }
    }
}

void process(const double& totalIncome, const double& numDependent, const double& basisSalary) {
    const int dutyFree = 11000000;
    const int npFree = 4400000;

    // Calculate Social insurance tax
    double maxSocialInsurance1 = basisSalary;
    double maxSocialInsurance2 = basisSalary;

    if (basisSalary >= 29800000) maxSocialInsurance1 = 29800000;
    if (basisSalary >= 93600000) maxSocialInsurance2 = 93600000;

    double socialInsurance = (maxSocialInsurance1 * 9.5) / 100 + (maxSocialInsurance2 * 1) / 100;

    double tax = 0;
    double initMoney = totalIncome - socialInsurance - dutyFree - npFree * numDependent;

    if (initMoney <= 5000000) {
        tax = initMoney * 0.05;
    } else if (initMoney > 5000000 && initMoney < 10000000) {
        tax = initMoney * 0.1 - 250000;
    } else if (initMoney > 10000000 && initMoney < 18000000) {
        tax = initMoney * 0.15 - 750000;
    } else if (initMoney > 18000000 && initMoney < 32000000) {
        tax = initMoney * 0.2 - 1650000;
    } else if (initMoney > 32000000 && initMoney < 52000000) {
        tax = initMoney * 0.25 - 3250000;
    } else if (initMoney > 52000000 && initMoney < 80000000) {
        tax = initMoney * 0.3 - 5850000;
    } else {
        tax = initMoney * 0.35 - 9850000;
    }

    if (tax < 0) tax = 0;

    cout << "\nYour Social Insurance Tax is: " << fixed << setprecision(3) << socialInsurance << " VND" << endl;
    cout << "\nYour tax is: " << fixed << setprecision(3) << tax << " VND";
}

int main() {
    cout << "WELCOME TO TAX CALCULATOR\n///////////////////////////\n";
    cout << "Please enter values as:\n- Total Income as a number\n- Number of Dependents as an integer\n- Basis Salary as a number\n";
    cout << "**Every value must be greater than 0**\n";

    double totalIncome = getUserInput<double>("Please input the total income (VND): ");
    double numDependent = getUserInput<int>("Please input the number of dependents (Person): ");
    double basisSalary = getUserInput<double>("Please input the basis salary (VND): ");

    process(totalIncome, numDependent, basisSalary);

    cin.ignore(); // Pause screen
    return 0;
}