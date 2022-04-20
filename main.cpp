#include <iostream>
#include <map>
#include <string>
#include "Media.h"

using namespace std;

int main() {
    int medium;
    int g, r, pd, first, second, third;
    map<int, string> order;

    cout << "Would you like a book, podcast, or movie?" << endl;
    cout << "1. Book" << endl << "2. Podcast" << endl << "3. Movie" << endl;
    cin >> medium;
    cout << "Assign priorities among genre, rating, and publication date: (type number 1-3 for priority rating)" << endl;
    cout << "Genre: ";
    cin >> first;
    order.emplace(first, "g");
    cout << "Rating: ";
    cin >> second;
    order.emplace(second, "r");
    cout << "Publication date: ";
    cin >> third;
    order.emplace(third, "y");
    string o;
    for (auto i = order.begin(); i != order.end() ; ++i) {
        o += i->second;
    }

    cout << "Select genre:" << endl;
    if (medium == 1) {
        ifstream gen("../Data/books_genres.txt");
        while (gen.is_open()) {
            int i = 1;
            while (gen.good()) {
                string temp;
                getline(gen, temp);
                if (!temp.empty()) {
                    cout << i << ". " << temp << endl;
                    i++;
                }
            }
            gen.close();
        }
    } else if (medium == 2) {
        ifstream gen("../Data/podcasts_genres.txt");
        while (gen.is_open()) {
            int i = 1;
            while (gen.good()) {
                string temp;
                getline(gen, temp);
                if (!temp.empty()) {
                    cout << i << ". " << temp << endl;
                    i++;
                }
            }
            gen.close();
        }
    } else if (medium == 3) {
        ifstream gen("../Data/movie_genres.txt");
        while (gen.is_open()) {
            int i = 1;
            while (gen.good()) {
                string temp;
                getline(gen, temp);
                if (!temp.empty()) {
                    cout << i << ". " << temp << endl;
                    i++;
                }
            }
            gen.close();
        }
    }
    cin >> g;

    cout << "Select rating range:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " and up" << endl;
    }
    cin >> r;

    cout << "Select publication date:" << endl;
    int j = 1900;
    for (int i = 0; i < 5; ++i) {
        cout << j << " and later" << endl;
        j += 25;
    }
    cin >> pd;
    int sort = 0;
    cout << endl << "Choose your sorting algorithm: " << endl;
    cout << 0 << ". Heap sort" << endl;
    cout << 1 << ". Merge sort" << endl;

    Media(medium, g, r, pd, o, sort);


    return 0;
}