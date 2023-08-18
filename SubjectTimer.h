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
    SubjectTimer();
    // TODO aggiungi distruttori qui e agli observer
    // Subject
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;

    // wxTimer
    void Notify() override;

    unsigned short getHour() const;
    unsigned short getMinute() const;
    unsigned short getSecond() const;
    unsigned short getDay() const;
    wxString getDayName() const;
    unsigned short getMonth() const;
    int getYear() const;

private:
    std::vector<Observer*> observers;
    wxDateTime currentDateTime;
    // TODO aggiungi un wxTimeSpan per usarlo per il timer + crea classe TimerDisplay come observer.
    //  Il timer dovrebbe aggornare il TimeSpan dentro Notify prima di notificare gli observer
};


#endif //LAB_PROGRAMMAZIONE_2023_SUBJECTTIMER_H
