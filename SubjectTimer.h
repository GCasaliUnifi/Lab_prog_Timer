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

#define T_INTERVAL 1000 // milliseconds between timer ticks

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

    wxString getFormattedChangingTimeSpan() const;

    void flipTimerRunningStatus();
    bool getTimerRunningStatus() const;
private:
    std::vector<Observer*> observers;

    wxDateTime currentDateTime;
    wxTimeSpan originalTimeSpan = wxTimeSpan(0, 15, 0);
    wxTimeSpan changingTimeSpan = wxTimeSpan(0, 0, 10);

    /* This below is not used to keep track of the wxTimer witch this class is derived from but to know whether
     * the observer should be updating its value or not (has the user pressed Play? -> Update, else don't!).
    */
    bool isTimerRunning = true;
    bool isTimerPaused = false;
};


#endif //LAB_PROGRAMMAZIONE_2023_SUBJECTTIMER_H
