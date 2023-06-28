//
// Created by giacomo on 20/06/23.
//
#include <wx/wx.h>
#include "Window.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Window * appWindow = new Window(wxT("Timer"));
    appWindow->Show(true);
    return true;
}