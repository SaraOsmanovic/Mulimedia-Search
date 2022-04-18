#ifndef MULTIMEDIA_SEARCH_MEDIA_H
#define MULTIMEDIA_SEARCH_MEDIA_H

#include "Media Types/Header/Books.h"
#include "Media Types/Header/Podcasts.h"
#include "Media Types/Header/Movies.h"
#include "AVLTree.h"
#include <set>

using namespace std;

class Media {
    void books(int g, int r, int y, string& order);
    void movies(int g, int r, int y, string& order);
    void podcasts(int g, int r, string& order);

public:
    Media(int m, int g, int r, int y, string& order);
};




#endif //MULTIMEDIA_SEARCH_MEDIA_H
