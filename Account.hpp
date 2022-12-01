//
//  Account.hpp
//  Week5 Smart Pointers
//
//  Created by Samuel Cummings on 11/29/22.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <iostream>
#include "Contact.hpp"

class Account {
    private:
        int id;
        std::string name;
        float balance;
        static int next_id;
        std::shared_ptr<Contact> contact;
    public:
        Account();
        Account(std::string name, double balance);
        std::string get_name();
        void deposit(float amount);
        void withdraw(float amount);
        float get_balance();
        int get_id();
        void show_info();
        void add_contact_info();
        // std::ostream& display(std::ostream& out) const;
};

#endif /* Account_hpp */
