//
// Created by Sara on 4/14/2022.
//

#include "Book.h"

Book::Book(string& line) {
    string temps[13];
    int i = 0;
    stringstream book(line);
    for (int j = 0; j < 13; ++j) {
        getline(book, temps[i], '\t');
        i++;
    }

    title = temps[0];
    for (int j = 0; j < 3; ++j) {
        authors[j] = temps[1 + j];
    }
    for (int j = 0; j < 2; ++j) {
        genres[j] = temps[4 + j];
    }
    thumbnail = temps[6];
    description = temps[7];
    try {
        published_year = stoi(temps[8]);
    } catch (invalid_argument) {
        published_year = 0;
    }
    try {
        average_rating = stod(temps[9]);
    } catch (invalid_argument) {
        average_rating = 0;
    }
    try {
        num_pages = stoi(temps[10]);
    } catch (invalid_argument) {
        num_pages = 0;
    }
    try {
        ratings_count = stoi(temps[11]);
    } catch (invalid_argument) {
        ratings_count = 0;
    }
    isbn13 = temps[12];

}
Book::~Book(){
    title = "";
    for (int i = 0; i < 3; ++i) {
        authors[i] = "";
    }
    for (int i = 0; i < 2; ++i) {
        genres[i] = "";
    }
    thumbnail = "";
    description = "";
    published_year = 0;
    num_pages = 0;
    ratings_count = 0;
    isbn13 = "";
    average_rating = 0;
}

string& Book::getTitle() {
    return title;
}
string* Book::getAuthors() {
    return &authors[0];
}
string* Book::getGenres() {
    return &genres[0];
}
string& Book::getThumbnail() {
    return thumbnail;
}
string& Book::getDescription() {
    return description;
}
int Book::getPublishedYear() {
    return published_year;
}
int Book::getNumPages() {
    return num_pages;
}
int Book::getRatingsCount() {
    return ratings_count;
}
string& Book::getIsbn13() {
    return isbn13;
}
double Book::getAverageRating() {
    return average_rating;
}

bool Book::hasGenre(const string& target) {
    for (int i = 0; i < 2; ++i) {
        if (target == genres[i] || genres[i].find(target, 0) != string::npos) {
            return true;
        }
    }
    return false;
}

bool Book::hasAuthors(const string& target) {
    for (int i = 0; i < 3; ++i) {
        if (target == authors[i] || authors[i].find(target, 0) != string::npos) {
            return true;
        }
    }
    return false;
}
