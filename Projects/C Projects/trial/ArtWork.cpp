/**
 * @file ArtWork.h
 * @brief Represents an artwork with various attributes such as name, artist, year, and type.
 *
 * The ArtWork class allows for setting and retrieving the details of a piece of artwork.
 * It includes methods to set and get the name, artist, year, and type of artwork, as well
 * as a method to display all details of the artwork.
 *
 * @author Caua Melo
 * @date 08/2024
 */

#include "ArtWork.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

/**
 * @brief Default constructor for the `ArtWork` class.
 * 
 * Initializes an `ArtWork` object with default values:
 * - `name` is set to an empty string.
 * - `artist` is set to an empty string.
 * - `year` is set to 0.
 * - `type` is set to an empty string.
 * 
 * This constructor is used to create an `ArtWork` object when no specific values are provided.
 */
ArtWork::ArtWork() {
	name = "";
	artist = "";
	year = 0;
	type = "";
}//end constructor

/**
 * @brief Parameterized constructor for the `ArtWork` class.
 *
 * Initializes an `ArtWork` object with the specified values:
 * - `name` is set to the provided `name` argument.
 * - `artist` is set to the provided `artist` argument.
 * - `year` is set to the provided `year` argument.
 * - `type` is set to the provided `type` argument.
 *
 * @param name The name of the artwork.
 * @param artist The artist of the artwork.
 * @param year The year the artwork was created.
 * @param type The type of the artwork.
 */
ArtWork::ArtWork(string name, string artist, int year, string type) {
	this->name = name;
	this->artist = artist;
	this->year = year;
	this->type = type;
}//end overloaded

/**
 * @brief Parameterized constructor for the `ArtWork` class that initializes the object from a CSV-formatted string.
 *
 * This constructor parses a single `string` containing comma-separated values to initialize the `ArtWork` object:
 * - `name` is set to the first value in the string.
 * - `artist` is set to the second value in the string.
 * - `year` is set to the third value, which is converted from a string to an integer.
 * - `type` is set to the fourth value in the string.
 *
 * The input string is expected to be in the format: "name,artist,year,type".
 *
 * @param line A `string` containing comma-separated values representing the attributes of the artwork.
 */
ArtWork::ArtWork(string line) {
	istringstream iss(line);
	string temp = "";

	getline(iss, name, ',');
	getline(iss, artist, ',');
	getline(iss, temp, ',');
	year = stoi(temp);
	getline(iss, type, ',');

}//end cons 3

/**
 * @brief Sets the name of the artwork.
 *
 * This method assigns the provided `name` argument to the `name` attribute of the `ArtWork` object.
 *
 * @param name A `string` representing the new name of the artwork.
 */
void ArtWork::setName(string) {
	this->name = name;
}//end setName

/**
 * @brief Sets the artist of the artwork.
 *
 * This method assigns the provided `artist` argument to the `artist` attribute of the `ArtWork` object.
 *
 * @param artist A `string` representing the new artist of the artwork.
 */
void ArtWork::setArtist(string) {
	this->artist = artist;
}//end setArtist

/**
 * @brief Sets the year of the artwork.
 *
 * This method assigns the provided `year` argument to the `year` attribute of the `ArtWork` object.
 *
 * @param year An `int` representing the new year of the artwork.
 */
void ArtWork::setYear(int) {
	this->year = year;
}//end setYear

/**
 * @brief Sets the type of the artwork (Painting, structure, etc).
 *
 * This method assigns the provided `type` argument to the `type` attribute of the `ArtWork` object.
 *
 * @param type A `string` representing the new type of the artwork.
 */
void ArtWork::setType(string) {
	this->type = type;
}//end setType

/**
 * @brief Retrieves the name of the artwork.
 *
 * This method returns the current value of the `name` attribute of the `ArtWork` object.
 *
 * @return A `string` representing the name of the artwork.
 */
string ArtWork::getName() {
	return name;
}//end getName

/**
 * @brief Retrieves the artist of the artwork.
 *
 * This method returns the current value of the `artist` attribute of the `ArtWork` object.
 *
 * @return A `string` representing the artist of the artwork.
 */
string ArtWork::getArtist() {
	return artist;
}//end getArtist

/**
 * @brief Retrieves the year of the artwork.
 *
 * This method returns the current value of the `year` attribute of the `ArtWork` object.
 *
 * @return An `int` representing the year of the artwork.
 */
int ArtWork::getYear() {
	return year;
}//end getYear

/**
 * @brief Retrieves the type of the artwork.
 *
 * This method returns the current value of the `type` attribute of the `ArtWork` object.
 *
 * @return A `string` representing the type of the artwork.
 */
string ArtWork::getType() {
	return type;
}//end getType

/**
 * @brief Displays all attributes of the artwork.
 *
 * This method prints the details of the `ArtWork` object in a formatted manner. It outputs the `name`, `artist`,
 * `year`, and `type` of the artwork, each separated by "||||" and aligned within specified width columns.
 *
 * The output format is as follows:
 * - Name: Left-aligned in a 30-character wide column.
 * - Artist: Left-aligned in a 30-character wide column.
 * - Year: Left-aligned in a 35-character wide column.
 * - Type: Left-aligned in a 35-character wide column.
 *
 * @note This method uses `cout` for output and `setw` for column width formatting.
 */
void ArtWork::displayAll() {
	cout << left << setw(30) << name << " |||| " << setw(30) << artist << " |||| " << setw(35)
		<< year << " |||| " << setw(35) << type << endl;

}//end displayAll
