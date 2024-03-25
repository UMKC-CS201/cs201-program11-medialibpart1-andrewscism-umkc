#include "MediaLib.h"
#include <iostream>
#include <sstream>
#include <vector>

// Define a static class array to hold totals
class MediaTotals
{
public:
    static int totalCount;
    static int totalLength;

    // Update totals
    static void updateTotals(const Media &media)
    {
        totalCount++;
        totalLength += media.getLength();
    }

    // Print totals
    static void printTotals(std::ostream &out)
    {
        out << "Total Count: " << totalCount << std::endl;
        out << "Total Length: " << totalLength << " minutes" << std::endl;
    }
};

// Initialize static members
int MediaTotals::totalCount = 0;
int MediaTotals::totalLength = 0;

// Function to read data from an input stream, parse it, and load objects into a vector<Media>
void readMediaList(std::istream &i, std::ostream &outErr, std::vector<Media> &m)
{
    std::string line;
    while (std::getline(i, line))
    {
        std::istringstream iss(line);
        char type;
        std::string title, keyName, genre;
        int rating, length, yearReleased;

        if (!(iss >> type >> title >> keyName >> rating >> genre >> length >> yearReleased))
        {
            outErr << "Error reading line: " << line << std::endl;
            continue; // Skip current line if reading fails
        }

        m.emplace_back(type, title, keyName, rating, genre, length, yearReleased);
        MediaTotals::updateTotals(m.back()); // Update totals
    }
}

// Function to print information about all media items
void printAllMedia(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m)
{
    for (const auto &media : m)
    {
        out << "Type: " << media.getType() << std::endl;
        out << "Title: " << media.getTitle() << std::endl;
        out << "Key Name: " << media.getKeyName() << std::endl;
        out << "Rating: " << media.getRating() << std::endl;
        out << "Genre: " << media.getGenre() << std::endl;
        out << "Length: " << media.getLength() << " minutes" << std::endl;
        out << "Year Released: " << media.getYearReleased() << std::endl;
        out << std::endl;
    }
}

// Function to print information about movie items
void printMovieList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m)
{
    for (const auto &media : m)
    {
        if (media.getType() == 'M')
        {
            out << "Type: " << media.getType() << std::endl;
            out << "Title: " << media.getTitle() << std::endl;
            out << "Key Name: " << media.getKeyName() << std::endl;
            out << "Rating: " << media.getRating() << std::endl;
            out << "Genre: " << media.getGenre() << std::endl;
            out << "Length: " << media.getLength() << " minutes" << std::endl;
            out << "Year Released: " << media.getYearReleased() << std::endl;
            out << std::endl;
        }
    }
}

// Function to print information about book items
void printBookList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m)
{
    for (const auto &media : m)
    {
        if (media.getType() == 'B')
        {
            out << "Type: " << media.getType() << std::endl;
            out << "Title: " << media.getTitle() << std::endl;
            out << "Key Name: " << media.getKeyName() << std::endl;
            out << "Rating: " << media.getRating() << std::endl;
            out << "Genre: " << media.getGenre() << std::endl;
            out << "Length: " << media.getLength() << " minutes" << std::endl;
            out << "Year Released: " << media.getYearReleased() << std::endl;
            out << std::endl;
        }
    }
}

// Function to print information about song items
void printSongList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m)
{
    for (const auto &media : m)
    {
        if (media.getType() == 'S')
        {
            out << "Type: " << media.getType() << std::endl;
            out << "Title: " << media.getTitle() << std::endl;
            out << "Key Name: " << media.getKeyName() << std::endl;
            out << "Rating: " << media.getRating() << std::endl;
            out << "Genre: " << media.getGenre() << std::endl;
            out << "Length: " << media.getLength() << " minutes" << std::endl;
            out << "Year Released: " << media.getYearReleased() << std::endl;
            out << std::endl;
        }
    }
}

// Function to print totals
void printTotals(std::ostream &out)
{
    MediaTotals::printTotals(out);
}

// Function to add a new media item
void addNewMedia(std::istream &inCommands, std::ostream &out, std::ostream &outErr, std::vector<Media> &m)
{
    char type;
    std::string title, keyName, genre;
    int rating, length, yearReleased;

    out << "Enter type (M for Movie, B for Book, S for Song): ";
    inCommands >> type;

    out << "Enter title: ";
    inCommands.ignore(); // Ignore any leftover newline characters
    std::getline(inCommands, title);

    out << "Enter key name: ";
    std::getline(inCommands, keyName);

    out << "Enter rating: ";
    inCommands >> rating;

    out << "Enter genre: ";
    inCommands.ignore(); // Ignore any leftover newline characters
    std::getline(inCommands, genre);

    out << "Enter length (in minutes): ";
    inCommands >> length;

    out << "Enter year released: ";
    inCommands >> yearReleased;

    // Create a new Media object with the provided information and add it to the vector
    m.emplace_back(type, title, keyName, rating, genre, length, yearReleased);

    out << "New media item added successfully!" << std::endl;
}
