#include "Media.h"

template<class T, class CMP = less<T>, class ALLOC = allocator<T>>
set<T, CMP, ALLOC> operator*(set<T, CMP, ALLOC>& lhs, set<T, CMP, ALLOC>& rhs) {
    auto i = lhs.begin();
    auto j = rhs.begin();
    set<T, CMP, ALLOC> intersection;

    while (i != lhs.end() && j != rhs.end()) {
        if (i != lhs.end()) {
            if (rhs.count(*i) != 0) {
                intersection.insert(*i);
            }
        }
        if (j != rhs.end()) {
            if (lhs.count(*j) != 0) {
                intersection.insert(*j);

            }
        }
        i++;
        j++;
    }
    return intersection;
}

template<class T, class CMP = less<T>, class ALLOC = allocator<T>>
set<T, CMP, ALLOC> operator/(set<T, CMP, ALLOC>& lhs, set<T, CMP, ALLOC>& rhs) {
    auto i = lhs.begin();
    set<T, CMP, ALLOC> difference;

    while (i != lhs.end()) {
        if (rhs.count(*i) == 0) {
            difference.insert(*i);
        }
        i++;
    }
    return difference;
}

template<class T, class CMP = std::less<T>, class ALLOC = std::allocator<T>>
set<T, CMP, ALLOC> operator+(set<T, CMP, ALLOC>& lhs, set<T, CMP, ALLOC>& rhs) {
    set<T, CMP, ALLOC> u;
    auto i = lhs.begin();
    auto j = rhs.begin();
    while (i != lhs.end() && j != rhs.end()) {
        if (i != lhs.end()) {
            u.insert(*i);
        }
        if (j != rhs.end()) {
            u.insert(*j);
        }
        i++;
        j++;
    }
    return u;
}

Media::Media(int m, int g, int r, int y, string& order) {
    switch (m) {
        case 3:
            movies(g, r, y, order);
            break;
        case 1:
            books(g, r, y, order);
            break;
        case 2:
            podcasts(g, r, order);
            break;
    }
}

void Media::books(int g, int r, int y, string& order) {
    Books *books_list = new Books();
    set<Book*> gen;
    set<Book*> rat;
    set<Book*> pyr;

    string genre = books_list->getGenresList().at(g);
    for (int i = 0; i < books_list->getGenres().at(genre).size(); ++i) {
       gen.insert(books_list->getGenres().at(genre).at(i));
    }
    for (int i = 0; i < books_list->getRating().at(r).size(); ++i) {
        rat.insert(books_list->getRating().at(r).at(i));
    }
    for (int i = 0; i < books_list->getRelease().at(y).size(); ++i) {
        pyr.insert(books_list->getRelease().at(y).at(i));
    }

    set<Book*> first = (gen * rat);
    first = first * pyr;
    set<Book*> second;
    set<Book*> third;

    if (order == "gry") {
        second = gen * rat;
        second = second / first;

        third = gen / first;
        third = third / second;
    } else if (order == "gyr") {
        second = gen * pyr;
        second = second / first;

        third = gen / first;
        third = third / second;
    } else if (order == "rgy") {
        second = gen * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
    } else if (order == "ryg") {
        second = pyr * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
    } else if (order == "ygr") {
        second = pyr * gen;
        second = second / first;

        third = pyr / first;
        third = third / second;
    } else if (order == "yrg") {
        second = pyr * rat;
        second = second / first;

        third = pyr / first;
        third = third / second;
    }

    heap<Book> f(first);
    heap<Book> s(second);
    heap<Book> t(third);
}

void Media::movies(int g, int r, int y, string &order) {
    Movies *movies_list = new Movies();
    set<Movie*> gen;
    set<Movie*> rat;
    set<Movie*> pyr;

    string genre = movies_list->getGenreList().at(g);
    for (int i = 0; i < movies_list->getGenres().at(genre).size(); ++i) {
        gen.insert(movies_list->getGenres().at(genre).at(i));
    }
    for (int i = 0; i < movies_list->getRatings().at(r).size(); ++i) {
        rat.insert(movies_list->getRatings().at(r).at(i));
    }
    for (int i = 0; i < movies_list->getReleaseDates().at(y).size(); ++i) {
        pyr.insert(movies_list->getReleaseDates().at(y).at(i));
    }

    set<Movie*> first = (gen * rat);
    first = first * pyr;
    set<Movie*> second;
    set<Movie*> third;

    if (order == "gry") {
        second = gen * rat;
        second = second / first;

        third = gen / first;
        third = third / second;
    } else if (order == "gyr") {
        second = gen * pyr;
        second = second / first;

        third = gen / first;
        third = third / second;
    } else if (order == "rgy") {
        second = gen * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
    } else if (order == "ryg") {
        second = pyr * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
    } else if (order == "ygr") {
        second = pyr * gen;
        second = second / first;

        third = pyr / first;
        third = third / second;
    } else if (order == "yrg") {
        second = pyr * rat;
        second = second / first;

        third = pyr / first;
        third = third / second;
    }

    heap<Movie> f(first);
    heap<Movie> s(second);
    heap<Movie> t(third);
}

void Media::podcasts(int g, int r, string &order) {
    Podcasts *podcasts_list = new Podcasts();
    set<Podcast*> gen;
    set<Podcast*> rat;

    string genre = podcasts_list->getGenreList().at(g);
    for (int i = 0; i < podcasts_list->getGenres().at(genre).size(); ++i) {
        gen.insert(podcasts_list->getGenres().at(genre).at(i));
    }
    for (int i = 0; i < podcasts_list->getRatings().at(r).size(); ++i) {
        rat.insert(podcasts_list->getRatings().at(r).at(i));
    }

    set<Podcast*> first = gen * rat;
    set<Podcast*> second;

    if (order == "gr") {
        second = gen / first;
    } else if (order == "rg") {
        second = rat / first;
    }

    heap<Podcast> f(first);
    heap<Podcast> s(second);
}

