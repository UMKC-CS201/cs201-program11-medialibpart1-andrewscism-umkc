#ifndef MEDIALIB_H
#define MEDIALIB_H

#include <iostream>
#include <vector>

class Media
{
private:
    char type;
    std::string title;
    std::string keyName;
    int rating;
    std::string genre;
    int length;
    int yearReleased;

public:
    // Default constructor
    Media();

    // Parameterized constructor
    Media(char t, const std::string &ttl, const std::string &key, int rtg, const std::string &gen, int len, int yr);

    // Copy constructor
    Media(const Media &other);

    // Destructor
    ~Media();

    // Getter methods
    char getType() const;
    std::string getTitle() const;
    std::string getKeyName() const;
    int getRating() const;
    std::string getGenre() const;
    int getLength() const;
    int getYearReleased() const;

    // Setter methods
    void setType(char t);
    void setTitle(const std::string &ttl);
    void setKeyName(const std::string &key);
    void setRating(int rtg);
    void setGenre(const std::string &gen);
    void setLength(int len);
    void setYearReleased(int yr);
};

// Function declarations
void readMediaList(std::istream &i, std::ostream &outErr, std::vector<Media> &m);
void printAllMedia(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m);
void printMovieList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m);
void printBookList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m);
void printSongList(std::istream &in, std::ostream &out, std::ostream &outErr, const std::vector<Media> &m);
void addNewMedia(std::istream &inCommands, std::ostream &out, std::ostream &outErr, std::vector<Media> &m);
void printTotals(std::ostream &out);

#endif /* MEDIALIB_H */
