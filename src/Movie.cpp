#include "Movie.h"

Movie::Movie() {
    vote_average = 0;
    vote_count = 0;
    release_date = 0;
}

Movie::Movie(string &line) {
    vote_average = 0;
    vote_count = 0;
    release_date = 0;
    string temps[16];
    istringstream str(line);
    for (int i = 0; i < 16; ++i) {
        string temp;
        getline(str, temp, '\t');
        if (temp != "N/A") {
            temps[i] = temp;
        }
    }
    title = temps[0];
    tagline = temps[1];
    overview = temps[2];
    try {
        if (!temps[3].empty() && temps[3] != "N/A") {
            release_date = stoi(temps[3]);
        }
    } catch (invalid_argument& e) {
        release_date = 0;
    }

    original_language = temps[4];
    for (int i = 0; i < 4; ++i) {
        genres[i] = temps[i + 5];
    }
    for (int i = 0; i < 4; ++i) {
        production_companies[i] = temps[i + 9];
    }
    production_country = temps[13];
    try {
        if (!temps[14].empty() && temps[14] != "N/A") {
            vote_average = stod(temps[14]);
        }

    } catch (invalid_argument& e) {
        vote_average = 0;
    }
    try {
        if (!temps[15].empty() && temps[15] != "N/A") {
            vote_count = stoi(temps[15]);
        }
    } catch (invalid_argument& e) {
        vote_count = 0;
    }
}

Movie::~Movie() {
    title = "";
    tagline = "";
    overview = "";
    release_date = 0;
    original_language = "";
    for (int i = 0; i < 4; ++i) {
        genres[i] = "";
    }
    for (int i = 0; i < 4; ++i) {
        production_companies[i] = "";
    }
    production_country = "";
    vote_average = 0;
    vote_count = 0;
}

Movie &Movie::operator=(const Movie &rhs) {
    this->title = rhs.title;
    this->tagline = rhs.tagline;
    this->overview = rhs.overview;
    this->original_language = rhs.original_language;
    this->production_country = rhs.production_country;
    this->vote_average = rhs.vote_average;
    this->vote_count = rhs.vote_count;
    this->release_date = rhs.release_date;
    for (int i = 0; i < 4; ++i) {
        this->genres[i] = rhs.genres[i];
        this->production_companies[i] = rhs.production_companies[i];
    }
    return *this;
}

bool Movie::operator>(const Movie &rhs) {
    if (this->title > rhs.title) {
        return true;
    }
    return false;
}

bool Movie::operator<(const Movie &rhs) {
    if (this->title < rhs.title) {
        return true;
    }
    return false;
}

bool Movie::operator==(const Movie &rhs) {
    if (this->title == rhs.title) {
        return true;
    }
    return false;
}

string& Movie::getTitle() {
    return title;
}

string &Movie::getTagline() {
    return tagline;
}

string &Movie::getOverview() {
    return overview;
}

string &Movie::getOriginalLanguage() {
    return original_language;
}

string* Movie::getGenres() {
    return &genres[0];
}

string *Movie::getProductionCompanies() {
    return &production_companies[0];
}

double &Movie::getVoteAverage(){
    return vote_average;
}

int &Movie::getReleaseDate() {
    return release_date;
}

int &Movie::getVoteCount() {
    return vote_count;
}

bool Movie::hasGenre(string &genre) {
    for (int i = 0; i < genres->size(); ++i) {
        if (genres[i] == genre) {
            return true;
        }
    }
    return false;
}
