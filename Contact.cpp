//
//  Contact.cpp
//  Smart Pointers
//
//  Created by Samuel Cummings on 11/29/22.
//

#include "Contact.hpp"
using std::cout;
using std::cin;

Contact::Contact():street_address{""}, city{""}, state{""}, zip_code{""}, phone_number{""}{};

Contact::Contact(string street_address, string city, string state, string zip_code, string phone_number) {
    this->street_address = street_address;
    this->city = city;
    this->state = state;
    this->zip_code = zip_code;
    this->phone_number = phone_number;
}

void Contact::initialize() {
    string street_address, city, state, zip_code, phone_number;
    cout << "Please enter the following contact information:\nStreet address: ";
    cin.ignore();
    std::getline(cin, street_address);
    cout << "City: ";
    std::getline(cin, city);
    cout << "State: ";
    std::getline(cin, state);
    cout << "Zip code: ";
    std::getline(cin, zip_code);
    cout << "Phone number: ";
    std::getline(cin, phone_number);
    
    this->street_address = street_address;
    this->city = city;
    this->state = state;
    this->zip_code = zip_code;
    this->phone_number = phone_number;
}

void Contact::display() {
    cout << "+ Contact Information: Address: " << street_address <<
        ", " << city << ", " << state << ", " <<
        zip_code << "\nPhone: " << phone_number << std::endl;
}
