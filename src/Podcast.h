#ifndef MULTIMEDIA_SEARCH_PODCAST_H
#define MULTIMEDIA_SEARCH_PODCAST_H
#include <string>
#include <sstream>

using namespace std;

class Podcast {
    string title, description, genre;
    double rating;
    int rating_volume;

public:
    Podcast(string& line);
    ~Podcast();

    bool operator==(const Podcast& rhs);

    string& getTitle();
    string& getDescription();
    string& getGenre();
    double& getRating();
    int& getRatingVolume();
};


#endif //MULTIMEDIA_SEARCH_PODCAST_H
