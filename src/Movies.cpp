#include "Movies.h"

Movies::Movies() {
    size = 0;
    ifstream mov("../data/movies_p3.txt");
    string line;
    while(mov.is_open()){
        getline(mov, line);
        while(mov.good()){
            getline(mov, line);
            insertMovie(line);
        }
        mov.close();
    }
    createGenres();
    createRatings();
    createReleaseDates();
}

Movies::~Movies() {
    for (int i = size - 1; i >= 0; --i) {
        delete movie_list.at(i);
        movie_list.pop_back();
    }
}

Movies &Movies::operator=(const Movies &rhs) {
    for (int i = 0; i < size; ++i) {
        this->movie_list.at(i) = rhs.movie_list.at(i);
    }
    return *this;
}

void Movies::insertMovie(string& line) {
    Movie *movie = new Movie(line);
    movie_list.push_back(movie);
    size++;
}

void Movies::createGenres() {
    vector<string> gens;
    ifstream gen("../data/movie_genres.txt");
    while (gen.is_open()) {
        while (gen.good()) {
            string temp;
            getline(gen, temp);
            gens.push_back(temp);
        }
        gen.close();
    }
    for (int i = 0; i < gens.size(); ++i) {
        genres.insert(pair<string, vector<Movie*>>(gens.at(i), vector<Movie*>()));
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < gens.size(); ++j) {
            if (movie_list.at(i)->hasGenre(gens.at(j))) {
                genres.at(gens.at(j)).push_back(movie_list.at(i));
            }
        }
    }
}

void Movies::createRatings() {
    for (int i = 0; i < 5; ++i) {
        ratings.insert(pair<int, vector<Movie*>>(i, vector<Movie*>()));
    }
    for (int i = 0; i < size; ++i) {
        if (movie_list.at(i)->getVoteAverage() >= 4) {
            ratings.at(4).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getVoteAverage() >= 3) {
            ratings.at(3).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getVoteAverage() >= 2) {
            ratings.at(2).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getVoteAverage() >= 1) {
            ratings.at(1).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getVoteAverage() >= 0) {
            ratings.at(0).push_back(movie_list.at(i));
        }
    }
}

void Movies::createReleaseDates() {
    for (int i = 1900; i < 2022; i += 25) {
        release_dates.insert(pair<int, vector<Movie*>>(i, vector<Movie*>()));
    }
    for (int i = 0; i < size; ++i) {
        if (movie_list.at(i)->getReleaseDate() >= 2000) {
            release_dates.at(2000).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getReleaseDate() >= 1975) {
            release_dates.at(1975).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getReleaseDate() >= 7950) {
            release_dates.at(1950).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getReleaseDate() >= 1725) {
            release_dates.at(1925).push_back(movie_list.at(i));
        }
        if (movie_list.at(i)->getReleaseDate() >= 1900) {
            release_dates.at(1900).push_back(movie_list.at(i));
        }
    }
}

unordered_map<string, vector<Movie *>> &Movies::getGenres() {
    return genres;
}

unordered_map<int, vector<Movie *>> &Movies::getRatings() {
    return ratings;
}

unordered_map<int, vector<Movie *>> &Movies::getReleaseDates() {
    return release_dates;
}
