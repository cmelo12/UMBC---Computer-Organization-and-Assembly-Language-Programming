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

#pragma once
#include <string>

using namespace std;

class ArtWork {
private:
	/**
	 * @brief The name of the artwork.
	 */
	string name;

	/**
	* @brief The name of the artist who created the artwork.
	*/ 
	string artist;
	
	/**
	 * @brief The year the artwork was created.
	 */
	int year;

	/**
	 * @brief The type or genre of the artwork (e.g., painting, sculpture).
	 */
	string type;

public:
	/**
	* @brief Default constructor.
	*
	* Initializes an empty ArtWork object with default values.
	*/
	ArtWork();

	/**
	 * @brief Parameterized constructor.
	 *
	 * Initializes an ArtWork object with the given name, artist, year, and type.
	 *
	 * @param name The name of the artwork.
	 * @param artist The artist who created the artwork.
	 * @param year The year the artwork was created.
	 * @param type The type or genre of the artwork.
	 */
	ArtWork(string name, string artist, int year, string type);

	/**
	 * @brief Constructor that initializes the ArtWork object from a string.
	 *
	 * @param line A string containing the artwork details (name, artist, year, type).
	 */
	ArtWork(string line);

	/**
	 * @brief Sets the name of the artwork.
	 *
	 * @param name The new name of the artwork.
	 */
	void setName(string);

	/**
	 * @brief Sets the artist of the artwork.
	 *
	 * @param artist The new artist of the artwork.
	 */
	void setArtist(string);

	/**
	 * @brief Sets the year the artwork was created.
	 *
	 * @param year The year the artwork was created.
	 */
	void setYear(int);

	/**
	 * @brief Sets the type of the artwork, such as a 
	 * sculpure, painting, etc.
	 *
	 * @param type The new type of the artwork.
	 */
	void setType(string);

	/**
	 * @brief Gets the name of the artwork.
	 *
	 * @return The name of the artwork.
	 */
	string getName();

	/**
	 * @brief Gets the artist of the artwork.
	 *
	 * @return The artist of the artwork.
	 */
	string getArtist();

	/**
	 * @brief Gets the year the artwork was created.
	 *
	 * @return The year of creation.
	 */
	int getYear();

	/**
	 * @brief Gets the type of the artwork, such as a 
	 * sculpure, painting, etc..
	 *
	 * @return The type of the artwork.
	 */
	string getType();

	/**
	 * @brief Displays all the details of the artwork (name, artist, year, type).
	 */
	void displayAll();

};//end class