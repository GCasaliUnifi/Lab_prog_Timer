//
// Created by giacomo on 26/06/23.
//

#include "Window.h"

Window::Window(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)) {

    this->dateTimeData = new SubjectTimer();
    auto *dateDisplay = new DateDisplay(dateTimeData, this);
    auto *clockDisplay = new ClockDisplay(dateTimeData, this);

    auto finalSizer = new wxBoxSizer(wxVERTICAL);
    auto dateDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    auto clockDisplaySizer = new wxBoxSizer(wxHORIZONTAL);

    dateDisplaySizer->Add(dateDisplay, 1, wxALL, 5);
    clockDisplaySizer->Add(clockDisplay, 1, wxALL, 5);

    finalSizer->Add(dateDisplaySizer, 1, wxEXPAND, 5);
    this->SetSizer(finalSizer);
    this->SetAutoLayout(true);
    this->Layout();
    finalSizer->SetSizeHints(this);
    this->Centre();
    this->dateTimeData->Start(2000);
}
