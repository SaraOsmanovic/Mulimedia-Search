#ifndef MULTIMEDIA_SEARCH_BOOK_H
#define MULTIMEDIA_SEARCH_BOOK_H
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Book {
    string title, authors[3], genres[2], thumbnail,	description, isbn13;
    int published_year,	num_pages, ratings_count;
    double average_rating;

public:
    Book(string& line);
    ~Book();

    string& getTitle();
    string* getAuthors();
    string* getGenres();
    string& getThumbnail();
    string& getDescription();
    int getPublishedYear();
    int getNumPages();
    int getRatingsCount();
    string& getIsbn13();
    double getAverageRating();
    bool hasGenre(const string& target);
    bool hasAuthors(const string& target);
};


#endif //MULTIMEDIA_SEARCH_BOOK_H
