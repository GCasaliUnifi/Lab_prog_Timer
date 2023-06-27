//
// Created by giacomo on 26/06/23.
//

#include "Window.h"

Window::Window(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)) {
    auto finalSizer = new wxBoxSizer(wxVERTICAL);
    auto dateDisplaySizer = new wxBoxSizer(wxHORIZONTAL);
    auto clockDisplaySizer = new wxBoxSizer(wxHORIZONTAL);

    this->SetSizer(finalSizer);
    this->SetAutoLayout(true);
    this->Layout();
    finalSizer->SetSizeHints(this);
    this->Centre();

}
