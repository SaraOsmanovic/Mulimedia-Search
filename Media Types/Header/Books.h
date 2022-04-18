#ifndef MULTIMEDIA_SEARCH_BOOKS_H
#define MULTIMEDIA_SEARCH_BOOKS_H
#include "../Header/Book.h"
#include <unordered_map>
#include <fstream>

class Books {
    vector<Book*> books;
    unordered_map<string, vector<Book*>> genres;
    unordered_map<int, vector<Book*>> release;
    unordered_map<int, vector<Book*>> rating;
    vector<string> genres_list;

    void createGenres();
    void createReleases();
    void createRatings();

public:
    Books();
    ~Books();


    unordered_map<string, vector<Book*>>& getGenres();
    unordered_map<int, vector<Book*>>& getRelease();
    unordered_map<int, vector<Book*>>& getRating();
    vector<string>& getGenresList();
};


#endif //MULTIMEDIA_SEARCH_BOOKS_H
