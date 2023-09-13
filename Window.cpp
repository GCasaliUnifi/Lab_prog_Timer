//
// Created by giacomo on 26/06/23.
//

#include "Window.h"

Window::Window(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)) {

    this->dateTimeData = new SubjectTimer();
    auto *timerDisplay = new TimerDisplay(dateTimeData, this);
    auto *clockDisplay = new ClockDisplay(dateTimeData, this);
    auto *dateDisplay = new DateDisplay(dateTimeData, this);

    auto *menuBar = new wxMenuBar;
    auto *moreMenu = new wxMenu;
    auto *aboutMenu = new wxMenu;

    moreMenu->Append(wxID_EXIT, wxT("&Exit"));
    aboutMenu->Append(wxID_ABOUT, wxT("&About"));

    menuBar->Append(moreMenu, wxT("&More"));
    menuBar->Append(aboutMenu, wxT("&About"));
    this->SetMenuBar(menuBar);

    auto finalSizer = new wxBoxSizer(wxVERTICAL);
    auto dateDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    auto clockDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    auto timerDisplaySizer = new wxBoxSizer(wxHORIZONTAL);

    this->playButton = new wxButton(this, wxID_ANY, wxT("▶"));

    // ------------------------------- Connect events ---------------------------
    Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Window::OnAboutInfo));
    Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Window::OnButtonClick), NULL, this);

    // --------------------------------- Sizers ---------------------------------
    dateDisplaySizer->Add(dateDisplay, 1, wxALL, 5);
    clockDisplaySizer->Add(clockDisplay, 1, wxALL, 5);
    timerDisplaySizer->Add(timerDisplay, 1, wxALL, 5);

    finalSizer->Add(dateDisplaySizer, 1, wxEXPAND, 5);
    finalSizer->Add(clockDisplaySizer, 1, wxEXPAND, 5);
    finalSizer->Add(timerDisplaySizer, 1, wxEXPAND, 5);
    finalSizer->Add(playButton, 1, wxEXPAND, 5);

    this->SetSizer(finalSizer);
    this->SetAutoLayout(true);
    this->Layout();
    finalSizer->SetSizeHints(this);
    this->Centre();
    this->dateTimeData->Start(T_INTERVAL);
}

void Window::OnAboutInfo(wxCommandEvent &ev) {
    auto *dialog = new wxMessageDialog(nullptr, wxT("Developed by Giacomo Casali\n\nmail:giacomo.casali@stud.unifi.it"),
                                       wxT("Info"), wxOK);
    dialog->ShowModal();
    dialog->Destroy();
}

void Window::OnButtonClick(wxCommandEvent &ev) {
    this->dateTimeData->flipTimerRunningStatus();
}