//
// Created by giacomo on 28/06/23.
//

#include "SubjectTimer.h"

SubjectTimer::SubjectTimer() {
    this->currentDateTime = wxDateTime::Now();
}

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
    this->currentDateTime = wxDateTime::Now();
    if(this->isTimerRunning) {
        if(changingTimeSpan.IsEqualTo(wxTimeSpan(0))) {
            this->isTimerRunning = false;
            this->changingTimeSpan = originalTimeSpan;
        } else {
            changingTimeSpan -= wxTimeSpan(0,0,0, T_INTERVAL);
        }
    }
    this->notifyObservers();
}

unsigned short SubjectTimer::getHour() const {
    return this->currentDateTime.GetHour();
}

unsigned short SubjectTimer::getMinute() const {
    return this->currentDateTime.GetMinute();
}

unsigned short SubjectTimer::getSecond() const {
    return this->currentDateTime.GetSecond();
}

unsigned short SubjectTimer::getDay() const {
    return this->currentDateTime.GetDay();
}

unsigned short SubjectTimer::getMonth() const {
    return this->currentDateTime.GetMonth();
}

int SubjectTimer::getYear() const {
    return this->currentDateTime.GetYear();
}

wxString SubjectTimer::getDayName() const {
    wxDateTime::WeekDay weekDay = this->currentDateTime.GetWeekDay();
    wxString dayName = wxDateTime::GetWeekDayName(weekDay);
    return dayName;
}

wxString SubjectTimer::getFormattedChangingTimeSpan() const {
    return this->changingTimeSpan.Format();
}

void SubjectTimer::flipTimerRunningStatus() {
    this->isTimerRunning = !this->isTimerRunning;
}

bool SubjectTimer::getTimerRunningStatus() const {
    return this->isTimerRunning;
}
