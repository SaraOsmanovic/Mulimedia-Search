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

public:
    Podcasts();
    ~Podcasts();

    void createGenres();
    void createRatings();
};


#endif //MULTIMEDIA_SEARCH_PODCASTS_H
