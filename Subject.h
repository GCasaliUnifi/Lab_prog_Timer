//
// Created by giacomo on 27/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_SUBJECT_H
#define LAB_PROGRAMMAZIONE_2023_SUBJECT_H

#include "Observer.h"

class Subject {
protected:
    virtual ~Subject() = default;
public:
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() const = 0;
};

#endif //LAB_PROGRAMMAZIONE_2023_SUBJECT_H
