//
// Created by Sara on 4/14/2022.
//

#include "Books.h"

Books::Books() {
    ifstream b("../data/books_p3.txt");
    while (b.is_open()) {
        string temp;
        getline(b, temp);
        while (b.good()) {
            getline(b, temp);
            books.push_back(new Book(temp));
        }
        b.close();
    }
    createGenres();
    createReleases();
    createRatings();
}

Books::~Books() {
    for (int i = books.size() - 1; i > 0; --i) {
        delete books.at(i);
        books.pop_back();
    }
}

void Books::createGenres() {
    ifstream gens("../data/books_genres.txt");
    while (gens.is_open()) {
        while (gens.good()) {
            string temp;
            getline(gens, temp);
            genres.emplace(temp, vector<Book*>());
        }
        gens.close();
    }
    for (auto j = genres.begin(); j != genres.end() ; ++j) {
        for (int i = 0; i < books.size(); ++i) {
            if (books.at(i)->hasGenre(j->first)) {
                j->second.push_back(books.at(i));
            }
        }
    }
}

void Books::createReleases() {
    for (int i = 1850; i < 2020; i += 25) {
        release.emplace(i, vector<Book*>());
    }
    for (int i = 0; i < books.size(); ++i) {
        if (books.at(i)->getPublishedYear() >= 1850) {
            release.at(1850).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 1875) {
            release.at(1875).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 1900) {
            release.at(1900).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 1925) {
            release.at(1925).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 1950) {
            release.at(1950).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 1975) {
            release.at(1975).push_back(books.at(i));
        }
        if (books.at(i)->getPublishedYear() >= 2000) {
            release.at(2000).push_back(books.at(i));
        }
    }
}

void Books::createRatings() {
    for (int i = 0; i < 5; ++i) {
        rating.emplace(i, vector<Book*>());
    }
    for (int i = 0; i < books.size(); ++i) {
        if (books.at(i)->getAverageRating() >= 1) {
            rating.at(1).push_back(books.at(i));
        }
        if (books.at(i)->getAverageRating() >= 2) {
            rating.at(2).push_back(books.at(i));
        }
        if (books.at(i)->getAverageRating() >= 3) {
            rating.at(3).push_back(books.at(i));
        }
        if (books.at(i)->getAverageRating() >= 4) {
            rating.at(4).push_back(books.at(i));
        }
    }
}

