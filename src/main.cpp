#include "Movies.h"
#include "Podcasts.h"
#include "Books.h"
#include <iostream>

using namespace std;

int main() {
    Movies *movies = new Movies();
    Podcasts *podcasts = new Podcasts();
    Books *books = new Books();
    cout << endl;

    delete movies;
    delete podcasts;
    delete books;
    return 0;
}
