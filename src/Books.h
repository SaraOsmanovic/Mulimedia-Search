#ifndef MULTIMEDIA_SEARCH_BOOKS_H
#define MULTIMEDIA_SEARCH_BOOKS_H
#include "Book.h"
#include <unordered_map>
#include <fstream>
#include <iostream>

class Books {
    vector<Book*> books;
    unordered_map<string, vector<Book*>> genres;
    unordered_map<int, vector<Book*>> release;
    unordered_map<int, vector<Book*>> rating;

public:
    Books();
    ~Books();

    void printTitles();
    void createGenres();
    void createReleases();
    void createRatings();
};


#endif //MULTIMEDIA_SEARCH_BOOKS_H
