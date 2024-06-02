 
#include <iostream>
#include <string>
using namespace std;

// Structure for storing reservation information
struct Reservation {
    string name;
    int roomNumber;
    string checkInDate;
    string checkOutDate;
    bool hasDStv;
    bool hasSwimmingPoolAccess;
    bool hasParking;
    double totalCost;
};

// Structure for storing food item information
struct FoodItem {
    string name;
    double price;
};

// Array of structures for storing reservations
Reservation reservations[100];
int numReservations = 0;

// Array of structures for storing food items
FoodItem foodItems[10];
int numFoodItems = 0;

// Function for adding a new reservation
void addReservation() {
    // Get reservation information from user
    cout << "Enter guest name: ";
    getline(cin, reservations[numReservations].name);
    cout << "Enter room number: ";
    cin >> reservations[numReservations].roomNumber;
    cout << "Enter check-in date (MM/DD/YYYY): ";
    cin >> reservations[numReservations].checkInDate;
    cout << "Enter check-out date (MM/DD/YYYY): ";
    cin >> reservations[numReservations].checkOutDate;
    cout << "Does the guest want DStv service? (1 for yes, 0 for no): ";
    cin >> reservations[numReservations].hasDStv;
    cout << "Does the guest want swimming pool access? (1 for yes, 0 for no): ";
    cin >> reservations[numReservations].hasSwimmingPoolAccess;
    cout << "Does the guest want parking? (1 for yes, 0 for no): ";
    cin >> reservations[numReservations].hasParking;

    // Calculate total cost based on selected services
    double baseCost = 100.0; // Base cost for a room
    if (reservations[numReservations].hasDStv) {
        baseCost += 10.0;
    }
    if (reservations[numReservations].hasSwimmingPoolAccess) {
        baseCost += 20.0;
    }
    if (reservations[numReservations].hasParking) {
        baseCost += 5.0;
    }
    reservations[numReservations].totalCost = baseCost;

    // Increment number of reservations
    numReservations++;

    // Display confirmation message
    cout << "Reservation added successfully." << endl;
}

// Function for searching for a reservation by guest name
void searchReservation() {
    // Get guest name from user
    string guestName;
    cout << "Enter guest name to search for: ";
    getline(cin, guestName);

    // Search for reservation with matching guest name
    bool found = false;
    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].name == guestName) {
            // Display reservation information
            cout << "Guest name: " << reservations[i].name << endl;
            cout << "Room number: " << reservations[i].roomNumber << endl;
            cout << "Check-in date: " << reservations[i].checkInDate << endl;
            cout << "Check-out date: " << reservations[i].checkOutDate << endl;
            cout << "DStv service: " << (reservations[i].hasDStv ? "Yes" : "No") << endl;
            cout << "Swimming pool access: " << (reservations[i].hasSwimmingPoolAccess ? "Yes" : "No") << endl;
            cout << "Parking: " << (reservations[i].hasParking ? "Yes" : "No") << endl;
            cout << "Total cost: $" << reservations[i].totalCost << endl;
            found = true;
            break;
        }
    }

    // Display message if reservation not found
    if (!found) {
        cout << "Reservation not found." << endl;
    }
}

// Function for editing a reservation
void editReservation() {
    // Get guest name from user
    string guestName;
    cout << "Enter guest name to edit reservation: ";
    getline(cin, guestName);

    // Search for reservation with matching guest name
    bool found = false;
    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].name == guestName) {
            // Display current reservation information
            cout << "Current reservation information:" << endl;
            cout << "Guest name: " << reservations[i].name << endl;
            cout << "Room number: " << reservations[i].roomNumber << endl;
            cout << "Check-in date: " << reservations[i].checkInDate << endl;
            cout << "Check-out date: " << reservations[i].checkOutDate << endl;
            cout << "DStv service: " << (reservations[i].hasDStv ? "Yes" : "No") << endl;
            cout << "Swimming pool access: " << (reservations[i].hasSwimmingPoolAccess ? "Yes" : "No") << endl;
            cout << "Parking: " << (reservations[i].hasParking ? "Yes" : "No") << endl;
            cout << "Total cost: $" << reservations[i].totalCost << endl;

            // Get new reservation information from user
            cout << "Enter new guest name (or leave blank to keep current): ";
            getline(cin, reservations[i].name);
            cout << "Enter new room number (or 0 to keep current): ";
            cin >> reservations[i].roomNumber;
            cout << "Enter new check-in date (MM/DD/YYYY) (or leave blank to keep current): ";
            getline(cin, reservations[i].checkInDate);
            cout << "Enter new check-out date (MM/DD/YYYY) (or leave blank to keep current): ";
            getline(cin, reservations[i].checkOutDate);
            cout << "Does the guest want DStv service? (1 for yes, 0 for no): ";
            cin >> reservations[i].hasDStv;
            cout << "Does the guest want swimming pool access? (1 for yes, 0 for no): ";
            cin >> reservations[i].hasSwimmingPoolAccess;
            cout << "Does the guest want parking? (1 for yes, 0 for no): ";
            cin >> reservations[i].hasParking;

            // Calculate new total cost based on selected services
            double baseCost = 100.0; // Base cost for a room
            if (reservations[i].hasDStv) {
                baseCost += 10.0;
            }
            if (reservations[i].hasSwimmingPoolAccess) {
                baseCost += 20.0;
            }
            if (reservations[i].hasParking) {
                baseCost += 5.0;
            }
            reservations[i].totalCost = baseCost;

            // Display confirmation message
            cout << "Reservation updated successfully." << endl;
            found = true;
            break;
        }
    }

    // Display message if reservation not found
    if (!found) {
        cout << "Reservation not found." << endl;
    }
}

// Function for deleting a reservation
void deleteReservation() {
    // Get guest name from user
    string guestName;
    cout << "Enter guest name to delete reservation: ";
    getline(cin, guestName);

    // Search for reservation with matching guest name
    bool found = false;
    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].name == guestName) {
            // Shift all reservations after deleted reservation back by one index
            for (int j = i; j < numReservations - 1; j++) {
                reservations[j] = reservations[j+1];
            }
            numReservations--;

            // Display confirmation message
            cout << "Reservation deleted successfully." << endl;
            found = true;
            break;
        }
    }

    // Display message if reservation not found
    if (!found) {
        cout<< "Reservation not found." << endl;
    }
}

// Function for adding a new food item
void addFoodItem() {
    // Get food item information from user
    cout << "Enter food item name: ";
    getline(cin, foodItems[numFoodItems].name);
    cout << "Enter food item price: $";
    cin >> foodItems[numFoodItems].price;

    // Increment number of food items
    numFoodItems++;

    // Display confirmation message
    cout << "Food item added successfully." << endl;
}

// Function for displaying all reservations
void displayReservations() {
    // Display header
    cout << "Guest Name\tRoom Number\tCheck-in Date\tCheck-out Date\tDStv\tSwimming Pool\tParking\tTotal Cost" << endl;

    // Display each reservation
    for (int i = 0; i < numReservations; i++) {
        cout << reservations[i].name << "\t\t" << reservations[i].roomNumber << "\t\t" << reservations[i].checkInDate << "\t\t" << reservations[i].checkOutDate << "\t\t" << (reservations[i].hasDStv ? "Yes" : "No") << "\t" << (reservations[i].hasSwimmingPoolAccess ? "Yes" : "No") << "\t\t" << (reservations[i].hasParking ? "Yes" : "No") << "\t" << "R" << reservations[i].totalCost << endl;
    }
}

// Function for displaying all food items
void displayFoodItems() {
    // Display header
    cout << "Food Item Name\tPrice" << endl;

    // Display each food item
    for (int i = 0; i < numFoodItems; i++) {
        cout << foodItems[i].name << "\t\t$" << foodItems[i].price << endl;
    }
}

// Function for calculating and displaying receipt
void generateReceipt() {
    // Get guest name from user
    string guestName;
    cout << "Enter guest name to generate receipt: ";
    getline(cin, guestName);

    // Search for reservation with matching guest name
    bool found = false;
    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].name == guestName) {
            // Display receipt header
            cout << "-----------------------" << endl;
            cout << "Hotel Receipt" << endl;
            cout << "-----------------------" << endl;

            // Display reservation information
            cout << "Guest name: " << reservations[i].name << endl;
            cout << "Room number: " << reservations[i].roomNumber << endl;
            cout << "Check-in date: " << reservations[i].checkInDate << endl;
            cout << "Check-out date: " << reservations[i].checkOutDate << endl;
            cout << "DStv service: " << (reservations[i].hasDStv ? "Yes" : "No") << endl;
            cout << "Swimming pool access: " << (reservations[i].hasSwimmingPoolAccess ? "Yes" : "No") << endl;
            cout << "Parking: " << (reservations[i].hasParking ? "Yes" : "No") << endl;

            // Calculate and display room cost
            double roomCost = 100.0;
            cout << "Room cost: $" << roomCost << endl;

            // Calculate and display service costs
            double serviceCost = 0.0;
            if (reservations[i].hasDStv) {
                serviceCost += 10.0;
            }
            if (reservations[i].hasSwimmingPoolAccess) {
                serviceCost += 20.0;
            }
            if (reservations[i].hasParking) {
                serviceCost += 5.0;
            }
            cout << "Service cost: $" << serviceCost << endl;

            // Calculate and display food item costs
            double foodCost = 0.0;
            char choice;
            do {
                // Display food items and prices
                displayFoodItems();

                // Get food item choice from user
                cout << "Enter food item number to add to bill (or 0 to finish): ";
                cin >> choice;

                // Addselected food item cost to total cost
                if (choice >= '1' && choice <= '9') {
                    int index = choice - '1';
                    foodCost += foodItems[index].price;
                }
            } while (choice != '0');
            cout << "Food cost: $" << foodCost << endl;

            // Calculate and display total cost
            double totalCost = roomCost + serviceCost + foodCost;
            cout << "Total cost: $" << totalCost << endl;

            // Display receipt footer
            cout << "-----------------------" << endl;
            found = true;
            break;
        }
    }

    // Display message if reservation not found
    if (!found) {
        cout << "Reservation not found." << endl;
    }
}

// Main function
int main() {
    // Display welcome message
    cout << "----------------------------------------" << endl;
    cout << "Welcome to the hotel reservation system." << endl;
    cout << "----------------------------------------" << endl;
    // Display menu options
    char choice;
    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add reservation" << endl;
        cout << "2. Search for reservation" << endl;
        cout << "3. Edit reservation" << endl;
        cout << "4. Delete reservation" << endl;
        cout << "5. Display all reservations" << endl;
        cout << "6. Add food item" << endl;
        cout << "7. Display all food items" << endl;
        cout << "8. Generate receipt" << endl;
        cout << "0. Exit" << endl;

        // Get user choice
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character left in input buffer

        // Perform selected action
        switch (choice) {
            case '1':
                addReservation();
                break;
            case '2':
                searchReservation();
                break;
            case '3':
                editReservation();
                break;
            case '4':
                deleteReservation();
                break;
            case '5':
                displayReservations();
                break;
            case '6':
                addFoodItem();
                break;
            case '7':
                displayFoodItems();
                break;
            case '8':
                generateReceipt();
                break;
            case '0':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '0');

    return 0;
}