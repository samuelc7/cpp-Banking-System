//
//  Account.cpp
//  Week5 Smart Pointers
//
//  Created by Samuel Cummings on 11/29/22.
//

#include "Account.hpp"

Account::Account():name{""}, balance{-1.0}, contact{nullptr} {
    id = Account::next_id++;
}
Account::Account(std::string name, double balance) {
    contact = nullptr;
    this->name = name;
    this->balance = balance;
    id = Account::next_id++;
}

int Account::next_id = 0;

std::string Account::get_name() {
    return name;
}

void Account::deposit(float amount) {
    balance += amount;
}

void Account::withdraw(float amount) {
    balance -= amount;
}

float Account::get_balance() {
    return balance;
}

int Account::get_id() {
    return id;
}

void Account::show_info() {
    std::cout << "Acount ID: " << Account::get_id() << " Name: " << Account::get_name() << " Balance: $" << Account::get_balance() << std::endl;
    if (contact != nullptr) {
        contact->display();
    }
}

void Account::add_contact_info() {
    contact = std::make_shared<Contact>();
    contact->initialize();
}

//std::ostream& Account::display(std::ostream &out) const {
//    out << "Acount ID: " << Account::get_id() << " Name: " << Account::get_name() << " Balance: $" << Account::get_balance() << std::endl;
//    return out;
//}
