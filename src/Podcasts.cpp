//
// Created by Sara on 4/12/2022.
//

#include "Podcasts.h"

Podcasts::Podcasts() {
    ifstream pod("../data/podcasts_p3.txt");

    string temp;
    getline(pod, temp);

    while (pod.is_open()) {
        while (pod.good()) {
            getline(pod, temp);
            podcasts_list.push_back(new Podcast(temp));
        }
        pod.close();
    }

    createGenres();
    createRatings();
}

Podcasts::~Podcasts() {
    for (int i = podcasts_list.size() - 1; i >= 0; --i) {
        delete podcasts_list.at(i);
        podcasts_list.pop_back();
    }
}

void Podcasts::createGenres() {
    for (int i = 0; i < podcasts_list.size(); ++i) {
        if (genres.count(podcasts_list.at(i)->getGenre()) == 0) {
            genres.insert(pair<string, vector<Podcast*>>(podcasts_list.at(i)->getGenre(), vector<Podcast*>()));
        }
        genres.at(podcasts_list.at(i)->getGenre()).push_back(podcasts_list.at(i));
    }
}

void Podcasts::createRatings() {
    for (int i = 0; i < 5; ++i) {
        ratings.insert(pair<int, vector<Podcast*>>(i, vector<Podcast*>()));
    }
    for (int i = 0; i < podcasts_list.size(); ++i) {
        if (podcasts_list.at(i)->getRating() >= 4) {
            ratings.at(4).push_back(podcasts_list.at(i));
        }
        if (podcasts_list.at(i)->getRating() >= 3) {
            ratings.at(3).push_back(podcasts_list.at(i));
        }
        if (podcasts_list.at(i)->getRating() >= 2) {
            ratings.at(2).push_back(podcasts_list.at(i));
        }
        if (podcasts_list.at(i)->getRating() >= 1) {
            ratings.at(1).push_back(podcasts_list.at(i));
        }
        if (podcasts_list.at(i)->getRating() >= 0) {
            ratings.at(0).push_back(podcasts_list.at(i));
        }
    }
}
