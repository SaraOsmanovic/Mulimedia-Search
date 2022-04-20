#ifndef MULTIMEDIA_SEARCH_MOVIES_H
#define MULTIMEDIA_SEARCH_MOVIES_H
#include "Movie.h"
#include <fstream>
#include <unordered_map>


class Movies {
    vector<Movie*> movie_list;
    int size;
    unordered_map<string, vector<Movie*>> genres;
    unordered_map<int, vector<Movie*>> ratings;
    unordered_map<int, vector<Movie*>> release_dates;
    vector<string> genre_list;

    void insertMovie(string& line);
    void createGenres();
    void createRatings();
    void createReleaseDates();

public:
    Movies();
    ~Movies();
    Movies& operator=(const Movies& rhs);

    unordered_map<string, vector<Movie*>>& getGenres();
    unordered_map<int, vector<Movie*>>& getRatings();
    unordered_map<int, vector<Movie*>>& getReleaseDates();
    vector<string>& getGenreList();
};


#endif //MULTIMEDIA_SEARCH_MOVIES_H
