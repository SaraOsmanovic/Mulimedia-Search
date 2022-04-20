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

Media::Media(int m, int g, int r, int y, string& order, int sort) {
    this->sort = sort;
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
    ofstream outfile("../OutFiles/Book_Results_HeapSort.txt");

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
    string firstP, secondP, thirdP;

    if (order == "gry") {
        second = gen * rat;
        second = second / first;

        third = gen / first;
        third = third / second;
        firstP = "genre";
        secondP = "rating";
        thirdP = "release year";
    } else if (order == "gyr") {
        second = gen * pyr;
        second = second / first;

        third = gen / first;
        third = third / second;
        firstP = "genre";
        secondP = "release year";
        thirdP = "rating";
    } else if (order == "rgy") {
        second = gen * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
        firstP = "rating";
        secondP = "genre";
        thirdP = "release year";
    } else if (order == "ryg") {
        second = pyr * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
        firstP = "rating";
        secondP = "release year";
        thirdP = "genre";
    } else if (order == "ygr") {
        second = pyr * gen;
        second = second / first;

        third = pyr / first;
        third = third / second;
        firstP = "release year";
        secondP = "genre";
        thirdP = "rating";
    } else if (order == "yrg") {
        second = pyr * rat;
        second = second / first;

        third = pyr / first;
        third = third / second;
        firstP = "release year";
        secondP = "rating";
        thirdP = "genre";
    }

    if (sort == 0) {
        outfile << "The books that have your choice of " << firstP << ", " << secondP << ", and " << thirdP << ": " << endl << endl;
        if (first.size() == 0) {
            outfile << "None found" << endl;
        } else {
            heap<Book> f(first, outfile);
        }
        outfile << "The books that have your choice of " << firstP << " and " << secondP << ": " << endl << endl;
        if (second.size() == 0) {
            outfile << "None found" << endl;
        } else {
            heap<Book> s(second, outfile);
        }
        outfile << "The books that have your choice of " << firstP << ": " << endl << endl;
        if (third.size() == 0) {
            outfile << "None found" << endl;
        } else {
            heap<Book> t(third, outfile);
        }
    } else {
        outfile << "The books that have your choice of " << firstP << ", " << secondP << ", and " << thirdP << ": " << endl << endl;
        if (first.size() == 0) {
            outfile << "None found" << endl;
        } else {
            MergeSort<Book> f(first, outfile);
        }
        outfile << "The books that have your choice of " << firstP << " and " << secondP << ": " << endl << endl;
        if (second.size() == 0) {
            outfile << "None found" << endl;
        } else {
            MergeSort<Book> s(second, outfile);
        }
        outfile << "The books that have your choice of " << firstP << ": " << endl << endl;
        if (third.size() == 0) {
            outfile << "None found" << endl;
        } else {
            MergeSort<Book> t(third, outfile);
        }
    }
    outfile.close();
    delete books_list;
}

void Media::movies(int g, int r, int y, string &order) {
    Movies *movies_list = new Movies();
    set<Movie*> gen;
    set<Movie*> rat;
    set<Movie*> pyr;
    ofstream outfile("../OutFiles/Movie_Results_HeapSort.txt");

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
    string firstP, secondP, thirdP;

    if (order == "gry") {
        second = gen * rat;
        second = second / first;

        third = gen / first;
        third = third / second;
        firstP = "genre";
        secondP = "rating";
        thirdP = "release year";
    } else if (order == "gyr") {
        second = gen * pyr;
        second = second / first;

        third = gen / first;
        third = third / second;
        firstP = "genre";
        secondP = "release year";
        thirdP = "rating";
    } else if (order == "rgy") {
        second = gen * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
        firstP = "rating";
        secondP = "genre";
        thirdP = "release year";
    } else if (order == "ryg") {
        second = pyr * rat;
        second = second / first;

        third = rat / first;
        third = third / second;
        firstP = "rating";
        secondP = "release year";
        thirdP = "genre";
    } else if (order == "ygr") {
        second = pyr * gen;
        second = second / first;

        third = pyr / first;
        third = third / second;
        firstP = "release year";
        secondP = "genre";
        thirdP = "rating";
    } else if (order == "yrg") {
        second = pyr * rat;
        second = second / first;

        third = pyr / first;
        third = third / second;
        firstP = "release year";
        secondP = "rating";
        thirdP = "genre";
    }
    outfile << "The movies that have your choice of " << firstP << ", " << secondP << ", and " << thirdP << ": " << endl << endl;
    heap<Movie> f(first, outfile);
    outfile << "The movies that have your choice of " << firstP << " and " << secondP << ": " << endl << endl;
    heap<Movie> s(second, outfile);
    outfile << "The movies that have your choice of " << firstP << ": " << endl << endl;
    heap<Movie> t(third, outfile);
    outfile.close();
    delete movies_list;
}

void Media::podcasts(int g, int r, string &order) {
    Podcasts *podcasts_list = new Podcasts();
    set<Podcast*> gen;
    set<Podcast*> rat;
    ofstream outfile("../OutFiles/Podcast_Results_HeapSort.txt");

    string firstP, secondP;

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
        firstP = "genre";
        secondP = "rating";
    } else if (order == "rg") {
        second = rat / first;
        firstP = "rating";
        secondP = "genre";
    }

    outfile << "The podcasts that have your choice of " << firstP << " and " << secondP << ": " << endl << endl;
    heap<Podcast> f(first, outfile);
    outfile << "The podcasts that have your choice of " << firstP << ": " << endl << endl;
    heap<Podcast> s(second, outfile);
    outfile.close();
    delete podcasts_list;
}

