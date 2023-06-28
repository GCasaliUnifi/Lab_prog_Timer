//
// Created by giacomo on 28/06/23.
//

#include "SubjectTimer.h"

void SubjectTimer::addObserver(Observer *o) {
    this->observers.push_back(o);
}

void SubjectTimer::removeObserver(Observer *o) {
    auto it = std::find(this->observers.begin(), this->observers.end(), o);
    if (it != this->observers.end()) {
        this->observers.erase(it);
    }
}

void SubjectTimer::notifyObservers() const {
    for (auto o : this->observers) {
        o->update();
    }
}

void SubjectTimer::Notify() {
    this->notifyObservers();
}
