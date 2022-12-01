//
//  Contact.hpp
//  Smart Pointers
//
//  Created by Samuel Cummings on 11/29/22.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <iostream>
#include <memory>

using std::string;

class Contact {
    private:
        string street_address;
        string city;
        string state;
        string zip_code;
        string phone_number;
    public:
        Contact();
        Contact(string street_address, string city, string state, string zip_code, string phone_number);
        void initialize();
        void display();
    };
#endif /* Contact_hpp */
