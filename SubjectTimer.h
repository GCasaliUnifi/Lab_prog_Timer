//
// Created by giacomo on 28/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_SUBJECTTIMER_H
#define LAB_PROGRAMMAZIONE_2023_SUBJECTTIMER_H

#include <wx/timer.h>
#include <wx/datetime.h>

#include <vector>
#include <algorithm> // per std::find

#include "Observer.h"
#include "Subject.h"

class SubjectTimer : public Subject, public wxTimer {
public:
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;
    void Notify() override;
private:
    std::vector<Observer*> observers;
    wxDateTime currentDateTime;
};


#endif //LAB_PROGRAMMAZIONE_2023_SUBJECTTIMER_H
