#ifndef MULTIMEDIA_SEARCH_MEDIA_H
#define MULTIMEDIA_SEARCH_MEDIA_H

#include "Media Types/Header/Books.h"
#include "Media Types/Header/Podcasts.h"
#include "Media Types/Header/Movies.h"
#include <set>

using namespace std;
template<class T>
struct heap {
    vector<T*> h;
    int s = 0;
    heap(set<T*> data) {
        for (auto i = data.begin(); i != data.end(); ++i) {
            insertEl(*i);
        }
        while (s > 0) {
            popMin()->print();
        }
    }
    void insertEl(T* newEl) {
        h.push_back(newEl);
        s++;
        heapifyUp(s - 1);
    }
    T* popMin() {
        T* res = h.at(0);
        h.at(0) = h.at(s - 1);
        h.pop_back();
        s--;
        heapifyDown(0);
        return res;
    }
    void heapifyUp(int i) {
        if (i == 0) {
            return;
        }
        if (*h.at((i - 1) / 2) > *h.at(i)) {
            T* temp = h.at((i - 1) / 2);
            h.at((i - 1) / 2) = h.at(i);
            h.at(i) = temp;
            heapifyUp((i - 1) / 2);
        } else {
            return;
        }
    }
    void heapifyDown(int i){
        T* l;
        if (2 * i + 1 < s) {
            l = h.at(2 * i + 1);
        } else {
            return;
        }
        T* r;
        if (2 * i + 2 < s) {
            r = h.at(2 * i + 2);
        } else {
            r = h.at(i);
        }
        if (r == h.at(i)) {
            if (*h.at(i) > *h.at(i * 2 + 1)) {
                T* temp = h.at(i);
                h.at(i) = h.at(i * 2 + 1);
                h.at(i * 2 + 1) = temp;
                heapifyDown(i * 2 + 1);
            } else {
                return;
            }
        }
        if (*r > *l) {
            if (h.at(i) > l) {
                T* temp = h.at(i);
                h.at(i) = l;
                h.at(i * 2 + 1) = temp;
                heapifyDown(i * 2 + 1);
            }
        } else if (*l > *r) {
            T* temp = h.at(i);
            h.at(i) = r;
            h.at(i * 2 + 2) = temp;
            heapifyDown(i * 2 + 2);
        }
    }
    T* at(int i) {
        return h.at(i);
    }
    int size() {
        return s;
    }
};

class Media {
    void books(int g, int r, int y, string& order);
    void movies(int g, int r, int y, string& order);
    void podcasts(int g, int r, string& order);

    template<typename T>
    void mergeSort(set<T*> data);

public:
    Media(int m, int g, int r, int y, string& order);
};

#endif //MULTIMEDIA_SEARCH_MEDIA_H
