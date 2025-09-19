#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: could not open file " << filename << endl;
        return 1;
    }

    // Input variables
    string firstName, lastName;
    double baseSalary, commissionPercent, totalSales, expenses;

    // Read data from file
    infile >> firstName >> lastName;
    infile >> baseSalary >> commissionPercent;
    infile >> totalSales;
    infile >> expenses;

    infile.close();

    // Calculations
    double commission = (commissionPercent / 100.0) * totalSales;
    double totalPay = baseSalary + commission - expenses;

    // Output results
    cout << fixed << setprecision(2);
    cout << "\nPayroll data for " << firstName << " " << lastName << "\n\n";

    cout << setw(15) << left << "Base Salary:" 
         << setw(10) << right << baseSalary << "\n";

    cout << setw(15) << left << "Commission:" 
         << setw(10) << right << commission << " (" 
         << setprecision(1) << commissionPercent << "% of " 
         << fixed << setprecision(2) << totalSales << ")\n";

    cout << setw(15) << left << "Expenses:" 
         << setw(10) << right << expenses << "\n";

    cout << setw(15) << left << " " << "----------\n";

    cout << setw(15) << left << "Total:" 
         << setw(10) << right << totalPay << "\n";

    return 0;
}
