//
// Created by giacomo on 27/06/23.
//

#include "DateDisplay.h"


DateDisplay::DateDisplay(SubjectTimer *dateTimeData, wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size,
                         long style, const wxString &name)
                         : wxWindow(parent, id, pos, size, style, name){

    this->dateTimeData = dateTimeData;
    this->dateTimeData->addObserver(this);

    auto *dateSizer = new wxBoxSizer(wxVERTICAL);
    auto *firstSizer = new wxBoxSizer(wxHORIZONTAL);

    dateDisplayTMP = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    firstSizer->Add(dateDisplayTMP, 1, wxALL, 5);
    dateSizer->Add(firstSizer, 1, wxEXPAND, 5);
    this->SetSizer(dateSizer);
}

void DateDisplay::update() {
    this->day = dateTimeData->getDay();
    this->nameOfDay = dateTimeData->getDayName();
    this->month = dateTimeData->getMonth();
    this->year = dateTimeData->getYear();

    this->dateDisplayTMP->SetValue(wxString::Format(wxT("%s %d/%d/%d"), this->nameOfDay.c_str(), this->day, this->month, this->year));
}
