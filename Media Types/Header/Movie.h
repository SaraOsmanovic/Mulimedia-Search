#ifndef MULTIMEDIA_SEARCH_MOVIE_H
#define MULTIMEDIA_SEARCH_MOVIE_H
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Movie {
    string title, tagline,	overview, original_language, production_country, genres[4],	production_companies[4];
    double vote_average;
    int release_date, vote_count;

public:
    Movie();
    Movie(string& line);
    ~Movie();

    Movie& operator=(const Movie& rhs);
    bool operator>(const Movie& rhs);
    bool operator<(const Movie& rhs);
    bool operator==(const Movie& rhs);

    bool hasGenre(string& genre);

    string& getTitle();
    string& getTagline();
    string& getOverview();
    string& getOriginalLanguage();
    string* getGenres();
    string* getProductionCompanies();
    double& getVoteAverage();
    int& getReleaseDate();
    int& getVoteCount();

    void print();
};


#endif //MULTIMEDIA_SEARCH_MOVIE_H
