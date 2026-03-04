#include <iostream>
#include <string>
#include "bai1/Town.hpp"
#include "InputUtils.hpp"
#include "bai2/Hotel.hpp"

// ===== MENU FOR TOWN =====
static void menuTown() {
    Town town;

    while (true) {
        std::cout << "\n=== TOWN MASNAGEMENT ===\n"
                  << "1. Input households\n"
                  << "2. Search by name (keyword)\n"
                  << "3. Search by house number\n"
                  << "4. Display all households\n"
                  << "0. Back\n"
                  << "Choose: ";

        int choice = readInt("Choose: ", 0, 4);

        if (choice == 0) break;

        if (choice == 1) {
            town.input(std::cin);
        }
        else if (choice == 2) {
            std::string keyword = readLine("Enter name keyword: ");
            town.searchByName(keyword, std::cout);
        }
        else if (choice == 3) {
            int houseNumber = readInt("Enter house number: ", 0);
            town.searchByHouseNumber(houseNumber, std::cout);
        }
        else if (choice == 4) {
            town.displayAll(std::cout);
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }
}

// ===== MENU FOR HOTEL =====
static void menuHotel() {
    Hotel hotel;

    while (true) {
        std::cout << "\n=== HOTEL MANAGEMENT ===\n"
                  << "1. Input renters\n"
                  << "2. Display all renters\n"
                  << "3. Search by name (keyword)\n"
                  << "4. Checkout by name (keyword)\n"
                  << "0. Back\n"
                  << "Choose: ";

        int choice = readInt("Choose: ", 0, 4);

        if (choice == 0) break;

        if (choice == 1) {
            hotel.input(std::cin);
        }
        else if (choice == 2) {
            hotel.displayAll(std::cout);
        }
        else if (choice == 3) {
            std::string keyword = readLine("Enter name keyword: ");
            hotel.searchByName(keyword, std::cout);
        }
        else if (choice == 4) {
            std::string keyword = readLine("Enter name keyword for checkout: ");
            hotel.checkoutByName(keyword, std::cout);
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }
}

int main() {
    while (true) {
        std::cout << "\n===== ASSIGNMENT 10 =====\n"
                  << "1. Town management\n"
                  << "2. Hotel management\n"
                  << "0. Exit\n"
                  << "Choose: ";

        int choice = readInt("Choose: ", 0, 2);

        if (choice == 0) break;

        if (choice == 1) menuTown();
        else if (choice == 2) menuHotel();
        else std::cout << "Invalid choice!\n";
    }

    return 0;
}