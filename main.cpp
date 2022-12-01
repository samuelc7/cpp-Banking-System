//
//  main.cpp
//  Week5 Smart Pointers
//
//  Created by Samuel Cummings on 11/21/22.
//

#include <iostream>
#include "Account.hpp"
#include "Contact.hpp"
#include <list>
#include <algorithm>
#include <numeric>

void display_accounts(std::list<Account>& account_list);
std::list<Account>::iterator find_account_by_id(std::list<Account>& account_list);
void remove_account_by_id(std::list<Account>& account_list);
void show_total_balance(std::list<Account>& account_list);
void add_dividend_to_all(std::list<Account>& account_list);
void add_contact_info_to_account(std::list<Account>& account_list);

int main(int argc, const char * argv[]) {
    // Create list of accounts
    std::list<Account> accounts;

    // Loop until user wants out
    while (true) {
       // Show Account Menu
        std::cout << "\nAcount Menu:\n0. Quit Program\n1. Display Account Information\n2. Add a deposit to an account\n3. Withdraw from an account\n4. Add new account\n5. Find account by ID\n6. Remove account\n7. Show total balance for all accounts\n8. Add a dividend to all accounts\n9. Add contact information to an account\nYour choice: ";
        int user_choice;
        std::cin >> user_choice;
        switch (user_choice) {
            // Quit
            case 0:
                std::cout << "Bye Bye.\n";
                return 0;
                break;
            // Display Account Info
            case 1:
                display_accounts(accounts);
                break;
            // Add deposit
            case 2: {
                std::list<Account>::iterator it = find_account_by_id(accounts);
                if (it == accounts.end()) {
                    std::cout << "Could not find account.\n";
                } else {
                    float deposit_amount;
                    std::cout << "Found account: ";
                    it->show_info();
                    std::cout << "Amount to deposit: ";
                    std::cin >> deposit_amount;
                    it->deposit(deposit_amount);
                }
                break;
            }
            // Withdraw
            case 3: {
                std::list<Account>::iterator it = find_account_by_id(accounts);
                if (it == accounts.end()) {
                    std::cout << "Could not find account.\n";
                } else {
                    float withdraw_amount;
                    std::cout << "Found account: ";
                    it->show_info();
                    std::cout << "Amount to withdraw: ";
                    std::cin >> withdraw_amount;
                    it->withdraw(withdraw_amount);
                }
                break;
            }
            // Add new account
            case 4: {
                std::string name;
                double balance_amount;
                std::cout << "Enter the name: ";
                std::cin >> name;
                std::cout << "Enter the initial balance: ";
                std::cin >> balance_amount;
                accounts.push_back(Account{name, balance_amount});
                break;
            }
            // Find account by ID
            case 5: {
                std::list<Account>::iterator it = find_account_by_id(accounts);
                if (it == accounts.end()) {
                    std::cout << "Could not find account.\n";
                } else {
                    std::cout << "Found account: ";
                    it->show_info();
                }
                break;
            }
            // Remove account
            case 6:
                remove_account_by_id(accounts);
                break;
            // Show total balance
            case 7:
                show_total_balance(accounts);
                break;
            // Add a dividend to all accounts
            case 8:
                add_dividend_to_all(accounts);
                break;
            // Add contact info to account
            case 9:
                add_contact_info_to_account(accounts);
                break;
            default:
                std::cout << "Not a valid option. Please try again.\n";
                break;
        }
    }
    return 0;
}

/**
 This will display all of the accounts in the passed in list of Accounts
 */
void display_accounts(std::list<Account>& account_list) {
    for_each(account_list.begin(), account_list.end(),
        [](auto& account) {
            account.show_info();
        }
    );
}

/**
 This will find an account within the passed in list of accounts that matches the id
 that the user inputs.
 Returns the iterator of the Account that was found or the end iterator of the list if
 no Account was found.
 */
std::list<Account>::iterator find_account_by_id(std::list<Account>& account_list) {
    int id;
    std::cout << "Enter the ID of the account to find: ";
    std::cin >> id;
    
    std::list<Account>::iterator it;
    for (it = account_list.begin(); it != account_list.end(); it++) {
        if (it->get_id() == id) {
            return it;
        }
    }
    return it;
}

/**
 This will find an account based off of the inputed id and will remove it
 from the account_list
 */
void remove_account_by_id(std::list<Account>& account_list) {
    int id;
    std::cout << "Enter account ID to remove: ";
    std::cin >> id;
    auto end = remove_if(account_list.begin(), account_list.end(),
        [id](auto& account) {
            return id == account.get_id();
        }
    );
    account_list.erase(end, account_list.end());
}

/**
 This will show the total balance of the deposits in the system.
 */
void show_total_balance(std::list<Account>& account_list) {
    auto total = accumulate(account_list.begin(), account_list.end(), 0.0f,
        [](auto accumulator, auto& account) {
            return accumulator + account.get_balance();
        }
    );
    std::cout << "Total in all accounts: $" << total << std::endl;
}

/**
 This will add a dividend to all accounts
 */
void add_dividend_to_all(std::list<Account>& account_list) {
    float percentage;
    std::cout << "Enter the dividend as a percentage: ";
    std::cin >> percentage;
    auto accounts_end = transform(account_list.begin(), account_list.end(), account_list.begin(), [percentage] (auto& account) {
        account.deposit(account.get_balance() * (percentage / 100.0f));
        return account;
    });
    account_list.erase(accounts_end, account_list.end());
}

/**
 This will add contact information to an account.
 */
void add_contact_info_to_account(std::list<Account>& account_list) {
    std::list<Account>::iterator it = find_account_by_id(account_list);
    if (it == account_list.end()) {
        std::cout << "Could not find account.\n";
    } else {
        std::cout << "Found account: ";
        it->show_info();
        it->add_contact_info();
    }    
}
