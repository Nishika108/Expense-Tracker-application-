#include <iostream>
#include <vector>
#include <string>
using namespace std;
double total_spending = 0; // total spending in a month.
// defining expences using class
class Expense
{
private:
string name;
double amount;
string category;
public:
// defining constructor
Expense(string n, double a, string c)
{
name = n;
amount = a;
category = c;
}
string getName() const { return name; }
double getAmount() const { return amount; }
string getCategory() const { return category; }
};
// Tracking the expenses
class ExpenseTracker
{
private:
vector<Expense> expenses;
public:
void addExpense(const Expense &expense)
{
expenses.push_back(expense);
}

// function to display expenses of the month.
void displayExpenses() const
{
if (expenses.empty())
{
cout << "No recorded yet." << endl;
return;
}
cout << "Expense List:" << endl;
cout << "-----------------------------------------" << endl;
cout << "Name\t\tAmount\t\tCategory" << endl;
cout << "-----------------------------------------" << endl;
for (const auto &expense : expenses)
{
cout << expense.getName() << "\t\tRs. " << expense.getAmount() <<

"\t\t" << expense.getCategory() << endl;
}
cout << "-----------------------------------------" << endl;
}
// displaying the expenses
void displaySpendingTrends() const
{
cout << "**Spending Trends**" << endl;
cout << "-----------------------------------------" << endl;
cout << "Category\tTotal Amount" << endl;
cout << "-----------------------------------------" << endl;
vector<std::string> categories;
vector<double> categoryTotals;
for (const auto &expense : expenses)
{
bool found = false;
for (size_t i = 0; i < categories.size(); ++i)
{
if (categories[i] == expense.getCategory())
{
categoryTotals[i] += expense.getAmount();
found = true;
break;
}
}
if (!found)
{
categories.push_back(expense.getCategory());
categoryTotals.push_back(expense.getAmount());
}
}

for (size_t i = 0; i < categories.size(); ++i)
{
cout << categories[i] << "\t\tRs. " << categoryTotals[i] << endl;
}
cout << "-----------------------------------------" << endl;
// calculating the total spendings for the month.
total_spending = 0;
for (size_t i = 0; i < categories.size(); i++)
{
total_spending += categoryTotals[i];
}
cout << "Total Expences this month: Rs." << total_spending << endl;
cout << "-----------------------------------------" << endl;
if (total_spending > 35000)
{
cout << "Expenses this month has exceeded your monthly budget!!!"

<< endl;

cout << "-----------------------------------------" << endl;
}
else
{
cout << "Happy Month :) " << endl;
cout << "-----------------------------------------" << endl;
}
}
};
int main()
{
ExpenseTracker tracker;
string category;
string Name;
double amount;
// getting the choice from the user what task to perform
int choice;
do
{
// displaying choices
cout << endl;
cout << "APPLICATION Menu:" << endl;
cout << "1. Add Expenses" << endl;
cout << "2. Display Expenses" << endl;
cout << "3. Exit" << endl;

cout << "Enter your choice: ";
cin >> choice;
switch (choice)
{
case 1:
cout << "Enter Your Expenses Here!!" << endl;
cout << "Name ";
cin >> Name;
cout << "Category ";
cin >> category;
cout << "Amount ";
cin >> amount;
cout << endl;
// calling function to add expenses.
tracker.addExpense(Expense(Name, amount, category));
break;
case 2:
tracker.displayExpenses();
tracker.displaySpendingTrends();
break;
case 3:
cout << "Exiting Application. Goodbye!" << endl;
break;
default:
cout << "Invalid choice. Please enter a valid option." << endl;
break;
}
} while (choice != 3);
return 0;
}