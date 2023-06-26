//
// Created by giacomo on 26/06/23.
//

#include "Window.h"

Window::Window(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    auto finalSizer = new wxBoxSizer(wxVERTICAL);

    this->SetSizer(finalSizer);
    this->SetAutoLayout(true);
    this->Layout();
    this->Centre();

}
