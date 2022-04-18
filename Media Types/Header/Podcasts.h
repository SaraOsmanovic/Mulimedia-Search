#ifndef MULTIMEDIA_SEARCH_PODCASTS_H
#define MULTIMEDIA_SEARCH_PODCASTS_H
#include "Podcast.h"
#include <vector>
#include <unordered_map>
#include <fstream>

class Podcasts {
    vector<Podcast*> podcasts_list;
    unordered_map<string, vector<Podcast*>> genres;
    unordered_map<int, vector<Podcast*>> ratings;
    vector<string> genre_list;

    void createGenres();
    void createRatings();
public:
    Podcasts();
    ~Podcasts();
    unordered_map<string, vector<Podcast*>>& getGenres();
    unordered_map<int, vector<Podcast*>>& getRatings();
    vector<string>& getGenreList();

};


#endif //MULTIMEDIA_SEARCH_PODCASTS_H
