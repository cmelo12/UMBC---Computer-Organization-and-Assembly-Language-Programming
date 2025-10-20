/**
 * @brief This file contains the main function and function prototypes for managing and displaying art pieces.
 *
 * This program provides functionality for reading art pieces from a file, displaying them, and performing
 * various operations based on user input. The program relies on the `ArtWork` class defined in "ArtWork.h".
 * 
 * @file main.cpp
 * @author Caua Melo
 * @date 08/2024
 */

#include "ArtWork.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

//Prototypes of the functions in the driver
void readFile(vector<ArtWork>& artPieces);
void displayArt(const vector<ArtWork>& artPieces);
void getRange(vector<ArtWork>& artPieces);
void getOldest(vector<ArtWork>& artPieces);
void displayByYear(const vector<ArtWork>& artPieces);
void menu(vector<ArtWork>& artPieces);

/**
 * @brief The entry point of the program.
 *
 * Initializes a vector of `ArtWork` objects and populates it by reading data from a file using the `readFile` function.
 * Then, it displays the main menu and handles user interactions using the `menu` function.
 */
int main(){

    vector<ArtWork> artPieces;
    
    readFile(artPieces);
    menu(artPieces);

}//end main

/**
 * @brief Reads art pieces from a CSV file and populates a vector with the data.
 *
 * This function opens the file "artwork.csv" and reads its contents line by line. Each line is used to
 * create an `ArtWork` object, which is then added to the `artPieces` vector. If the file cannot be opened,
 * the program outputs an error message and terminates.
 *
 * @param artPieces A reference to a vector of `ArtWork` objects that will be populated with data read from the file.
 */
void readFile(vector<ArtWork>& artPieces) {
    ifstream infile("artwork.csv");
    string line;
    istringstream iss("");

    if (!infile) {
        cout << "File not found. Terminating program" << endl;
        exit(0);
    }//end if

    getline(infile, line);

    while (getline(infile, line)) {
        ArtWork art(line);
        artPieces.push_back(art);
    }//end while

    infile.close();
}//end readFile

/**
 * @brief Displays art pieces from a specified year.
 *
 * Prompts the user to enter a four-digit year and then searches the `artPieces` vector for artworks
 * from that year. For each artwork found, it prints detailed information including the name, type,
 * and artist. If no artworks are found for the specified year, it outputs a corresponding message.
 *
 * @param artPieces A reference to a vector of `ArtWork` objects that are searched for artworks from the specified year.
 */
void displayByYear(vector<ArtWork>& artPieces) {
    int userYear;
    bool found = false;

    cout << "Enter a four digit year: ";
    cin >> userYear;
    
    cout << "\nArtwork(s) found from that year: " << endl;

    for (ArtWork aw : artPieces) {
        if (aw.getYear() == userYear) {
            cout << "\n" << "\t" << "-> \"" << aw.getName() << "\"" << " (" << aw.getType() << ")" << " by " << aw.getArtist() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No artworks found from " << userYear << endl;
    }

}//end displayYear

/**
 * @brief Finds and displays the oldest and most recent artworks from the vector.
 *
 * This function identifies the oldest and newest artworks based on their year from the `artPieces` vector.
 * It then prints details of both artworks, including their type, name, year, and artist. If the vector is empty,
 * it outputs an error message and terminates the program.
 *
 * @param artPieces A reference to a vector of `ArtWork` objects from which the oldest and newest artworks are determined.
 */
void getRange(vector<ArtWork>& artPieces) {
    int oldest = artPieces[0].getYear();
    int oldestIndex = 0;
    int newest = artPieces[0].getYear();
    int newIndex = 0;

    if (artPieces.empty()) {
        cout << "No artworks available" << endl;
        exit(0);
    }

    for (int i = 0; i < artPieces.size(); ++i) {
        if (artPieces.at(i).getYear() < oldest) {
            oldest = artPieces[i].getYear();
            oldestIndex = i;
        }//if
    }//for
    
    for (int i = 0; i < artPieces.size(); ++i) {
        if (artPieces.at(i).getYear() > newest) {
            newest = artPieces[i].getYear();
            newIndex = i;
        }//if
    }//for

    cout << "The oldest artwork in file is the " << artPieces[oldestIndex].getType() << " \"" << artPieces[oldestIndex].getName() << "\"" <<
             " (" << artPieces[oldestIndex].getYear() << ")" << " by " << artPieces[oldestIndex].getArtist() << endl;

    cout << "The most recent artwork in file is the " << artPieces[newIndex].getType() << " \"" << artPieces[newIndex].getName() << "\"" <<
        " (" << artPieces[newIndex].getYear() << ")" << " by " << artPieces[newIndex].getArtist() << endl;

}//end getRange

/**
 * @brief Finds and displays the oldest artwork from the vector.
 *
 * This function identifies the oldest artwork based on its year from the `artPieces` vector and prints its details,
 * including the type, name, year, and artist. If the vector is empty, it outputs an error message and terminates the program.
 *
 * @param artPieces A reference to a vector of `ArtWork` objects from which the oldest artwork is determined.
 */
void getOldest(vector<ArtWork>& artPieces) {
    int oldest = artPieces[0].getYear();
    int oldestIndex = 0;

    if (artPieces.empty()) {
        cout << "No artworks available" << endl; 
        exit(0);
    }

    for (int i = 0; i < artPieces.size(); ++i) {
        if (artPieces.at(i).getYear() < oldest) {
            oldest = artPieces[i].getYear();
            oldestIndex = i;
        }//if
    }//for

   // cout << "The oldest piece is " << artPieces[oldestIndex].getName() << " by " << artPieces[oldestIndex].getArtist() << endl;
    cout << "The oldest piece is the " << artPieces[oldestIndex].getType() << " \"" << artPieces[oldestIndex].getName() << "\""
        << " (" << artPieces[oldestIndex].getYear() << ") " << " by " << artPieces[oldestIndex].getArtist() << endl;

}//end getOldest

/**
 * @brief Displays detailed information about all artworks in the vector.
 *
 * This function prints a header row with column titles, followed by detailed information for each artwork
 * in the `artPieces` vector. The information is displayed in a tabular format with columns for the name,
 * artist, year, and type of the artwork. The `displayAll` method of the `ArtWork` class is used to output
 * the details of each artwork.
 *
 * @param artPieces A constant reference to a vector of `ArtWork` objects that are displayed.
 */
void displayArt(const vector<ArtWork>& artPieces) {
    cout << setw(30) << left << "Name" << setw(36) << "Artist" << setw(48) << "Year" << setw(37) << "Type" << endl;

    for (ArtWork a : artPieces) {
        a.displayAll();
    }//end for

}//end display

/**
 * @brief Displays a menu for user interaction and processes user choices.
 *
 * This function presents a menu with options for the user to choose from, including displaying all artworks,
 * getting a range of artworks, displaying the oldest artwork, finding artworks by year, or exiting the program.
 * It processes the user's choice and calls the corresponding functions based on the input. The menu continues to
 * be displayed until the user chooses to exit.
 *
 * @param artPieces A reference to a vector of `ArtWork` objects that are manipulated based on user input.
 */
void menu(vector<ArtWork>& artPieces) {
    int userChoice = -1;

    do {
        cout << "Art Work Menu" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter a number from the menu:" << endl;
        cout << "1. Display all the art works in file." << endl;
        cout << "2. Get range of the works." << endl;
        cout << "3. Display oldest piece." << endl;
        cout << "4. Enter a year to find an artwork." << endl;
        cout << "5. Exit." << endl;
        
        cin >> userChoice;
        
        cout << "\n";

        switch (userChoice) {
        case 1: displayArt(artPieces);
            break;
        case 2: getRange(artPieces);
            break;
        case 3: getOldest(artPieces);
            break;
        case 4: displayByYear(artPieces);
            break;
        case 5: exit(0);
        default: cout << "Invalid input. Try again." << endl;
            break;
        }//end switch

        cout << "\n";
    } while (userChoice != 5);

}//end menu
