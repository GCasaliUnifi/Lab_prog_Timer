//
// Created by giacomo on 27/06/23.
//

#include "ClockDisplay.h"

ClockDisplay::ClockDisplay(SubjectTimer *dateTimeData, wxWindow *parent, wxWindowID id, const wxPoint &pos,
                           const wxSize &size, long style, const wxString &name)
                           : wxWindow(parent, id, pos, size, style, name) {


    this->dateTimeData = dateTimeData;
    this->dateTimeData->addObserver(this);

    auto *clockSizer = new wxBoxSizer(wxVERTICAL);
    auto *firstSizer = new wxBoxSizer(wxHORIZONTAL);

    clockDisplayTMP = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    firstSizer->Add(clockDisplayTMP, 1, wxALL, 5);
    clockSizer->Add(firstSizer, 1, wxEXPAND, 5);
    this->SetSizer(clockSizer);
}

void ClockDisplay::update() {
    this->hour = dateTimeData->getHour();
    this->minute = dateTimeData->getMinute();
    this->second = dateTimeData->getSecond();

    this->clockDisplayTMP->SetValue(wxString::Format(wxT("%d:%d:%d"), this->hour, this->minute, this->second));
    std::cout << "ClockDisplay::update() = " << this->hour << ":" << this->minute << ":" << this->second << std::endl;
}
