//
// Created by giacomo on 20/06/23.
//
#include <wx/wx.h>
#include "Window.h"

class MyTimer : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyTimer);

bool MyTimer::OnInit() {
    Window * appWindow = new Window(wxT("Timer"));
    appWindow->Show(true);
    return true;
}