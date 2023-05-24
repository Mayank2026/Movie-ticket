#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
public:
    string title;
    int ticketPrice;
    int totalTickets;
    int ticketsBooked;
    vector<string> bookingRecords;

    Movie(string title, int ticketPrice, int totalTickets) {
        this->title = title;
        this->ticketPrice = ticketPrice;
        this->totalTickets = totalTickets;
        this->ticketsBooked = 0;
    }

    void bookTicket() {
        if (this->ticketsBooked < this->totalTickets) {
            this->ticketsBooked++;
            int ticketNumber = this->ticketsBooked;
            int totalPrice = this->ticketPrice;
            string record = "Ticket #" + to_string(ticketNumber) + " - " + this->title + " - $" + to_string(totalPrice);
            this->bookingRecords.push_back(record);
            cout << "Ticket booked successfully! Ticket #" << ticketNumber << endl;
        } else {
            cout << "Sorry, no tickets available." << endl;
        }
    }

    void cancelTicket(int ticketNumber) {
        if (ticketNumber <= this->ticketsBooked) {
            this->ticketsBooked--;
            int refundAmount = this->ticketPrice;
            string record = "Cancelled Ticket #" + to_string(ticketNumber) + " - " + this->title + " - $" + to_string(refundAmount);
            this->bookingRecords.push_back(record);
            cout << "Ticket #" << ticketNumber << " cancelled successfully. Refund: $" << refundAmount << endl;
        } else {
            cout << "Invalid ticket number." << endl;
        }
    }

    void changeTicketPrice(int newPrice) {
        this->ticketPrice = newPrice;
        cout << "Ticket price changed to $" << newPrice << " for " << this->title << endl;
    }

    void viewAllBookingRecords() {
        cout << "Booking records for " << this->title << ":" << endl;
        for (int i = 0; i < this->bookingRecords.size(); i++) {
            cout << this->bookingRecords[i] << endl;
        }
    }
};

int main() {
    Movie movie("The Avengers", 10, 5);

    while (true) {
        cout << endl << "What would you like to do?" << endl;
        cout << "1. Book a ticket" << endl;
        cout << "2. Cancel a ticket" << endl;
        cout << "3. Change ticket price" << endl;
        cout << "4. View all booking records" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            movie.bookTicket();
        } else if (choice == 2) {
            int ticketNumber;
            cout << "Enter ticket number to cancel: ";
            cin >> ticketNumber;
            movie.cancelTicket(ticketNumber);
        } else if (choice == 3) {
            int newPrice;
            cout << "Enter new ticket price: ";
            cin >> newPrice;
            movie.changeTicketPrice(newPrice);
        } else if (choice == 4) {
            movie.viewAllBookingRecords();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." <<endl;
            }
        }
        return 0;
}