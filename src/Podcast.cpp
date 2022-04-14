#include "Podcast.h"

Podcast::Podcast(string &line) {
    string temps[5];
    stringstream str(line);
    for (int i = 0; i < 5; ++i) {
        getline(str, temps[i], '\t');
    }

    title = temps[0];
    description = temps[1];
    genre = temps[2];
    try {
        rating = stod(temps[3]);
    } catch (invalid_argument) {
        rating = 0;
    }
    try {
        rating_volume = stoi(temps[4]);
    } catch (invalid_argument) {
        rating_volume = 0;
    }

}

Podcast::~Podcast() {
    title = "";
    description = "";
    genre = "";
    rating = 0;
    rating_volume = 0;
}

bool Podcast::operator==(const Podcast &rhs) {
    if (rhs.title == this->title && this->rating_volume == rhs.rating_volume && this->rating == rhs.rating && this->genre == rhs.genre) {
        return true;
    }
    return false;
}

string& Podcast::getTitle() {
    return this->title;
}
string& Podcast::getDescription() {
    return this->description;
}
string& Podcast::getGenre() {
    return this->genre;
}
double& Podcast::getRating() {
    return this->rating;
}
int& Podcast::getRatingVolume() {
    return this->rating_volume;
}