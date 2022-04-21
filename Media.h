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
    heap(set<T*> data, ofstream& outfile) {
        for (auto i = data.begin(); i != data.end(); ++i) {
            insertEl(*i);
        }
        while (s > 0) {
            popMin()->print(outfile);
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
            r = nullptr;
        }
        if (r == nullptr) {
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
            if (*h.at(i) > *l) {
                T* temp = h.at(i);
                h.at(i) = l;
                h.at(i * 2 + 1) = temp;
                heapifyDown(i * 2 + 1);
            }
        } else if (*l > *r) {
            if (*h.at(i) > *r) {
                T* temp = h.at(i);
                h.at(i) = r;
                h.at(i * 2 + 2) = temp;
                heapifyDown(i * 2 + 2);
            }
        }
    }
    T* at(int i) {
        return h.at(i);
    }
    int size() {
        return s;
    }
};
// merge sort code
template <class T>
struct MergeSort{
    vector<T*> m;
    MergeSort(set<T*>& data, ofstream& outfile){
        for (auto i = data.begin(); i != data.end(); ++i) {
            m.push_back(*i);
        }
        int test = m.size() - 1;
        mergeSort(m, 0, test);
        for (int i = 0; i < m.size(); ++i) {
            m.at(i)->print(outfile);
        }
    }
    MergeSort(){

    }
    // data to be sorted
    void mergeSort(vector<T *> &data, int l, int r);
    void merge(vector<T *> &data, int l, int mid, int r);
};


// this code was taken from Professor Kapoor's Module 6 slides
// this is to sort the data in alphabetical order
template<class T>
void MergeSort<T>::mergeSort(vector<T *> &data, int l, int r) {
    if(l < r){
        int mid = l + (r - l) / 2;
        // call recursion on the list
        mergeSort(data, l, mid);
        mergeSort(data, mid + 1, r);
        // once the data has been sorted, it needs to be merged
        merge(data, l, mid, r);
    }
}

template<class T>
void MergeSort<T>::merge(vector<T *> &data, int l, int mid, int r) {
    // get starting points
    int n1 = mid - l + 1;
    int n2 = r - mid;
    // create the two sub arrays for merging
    vector<T*> X, Y;

    for(int i = 0; i < n1; i++){
        X.push_back(data.at(l + i));
    }
    for(int j = 0; j < n2; j++){
        Y.push_back(data.at(mid + 1 + j));
    }
    // merge arrays X and Y
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(*X.at(i) < *Y.at(j)){
            data.at(k) = X.at(i);
            i++;
        }
        else{
            data.at(k) = Y.at(j);
            j++;
        }
        k++;
    }

    while(i < n1){
        data.at(k) = X.at(i);
        i++;
        k++;
    }
    while(j < n2){
        data.at(k) = Y.at(j);
        j++;
        k++;
    }
}


class Media {
    void books(int g, int r, int y, string& order);
    void movies(int g, int r, int y, string& order);
    void podcasts(int g, int r, string& order);
    int sort;

public:
    Media(int m, int g, int r, int y, string& order, int sort);
};

#endif //MULTIMEDIA_SEARCH_MEDIA_H
