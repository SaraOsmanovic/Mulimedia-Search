#ifndef MULTIMEDIA_SEARCH_PODCAST_H
#define MULTIMEDIA_SEARCH_PODCAST_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Podcast {
    string title, description, genre;
    double rating;
    int rating_volume;

public:
    Podcast(string& line);
    ~Podcast();

    bool operator==(const Podcast& rhs);
    bool operator>(const Podcast& rhs);
    bool operator<(const Podcast& rhs);

    string& getTitle();
    string& getDescription();
    string& getGenre();
    double& getRating();
    int& getRatingVolume();

    void print();
};


#endif //MULTIMEDIA_SEARCH_PODCAST_H
