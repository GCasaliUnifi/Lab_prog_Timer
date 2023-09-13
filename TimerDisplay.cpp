//
// Created by giacomo on 18/08/23.
//

#include "TimerDisplay.h"

TimerDisplay::TimerDisplay(SubjectTimer *dateTimeData, wxWindow *parent, wxWindowID id, const wxPoint &pos,
                           const wxSize &size, long style, const wxString &name)
                           : wxWindow(parent, id, pos, size, style, name) {
    this->dateTimeData = dateTimeData;
    this->dateTimeData->addObserver(this);

    auto *timerSizer = new wxBoxSizer(wxVERTICAL);
    auto *firstSizer = new wxBoxSizer(wxHORIZONTAL);

    timerDisplayTMP = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    firstSizer->Add(timerDisplayTMP, 1, wxALL, 5);
    timerSizer->Add(firstSizer, 1, wxEXPAND, 5);
    this->SetSizer(timerSizer);
}

void TimerDisplay::update() {
    this->timerDisplayTMP->SetValue(dateTimeData->getFormattedChangingTimeSpan());
    Refresh();
    Update();
}
