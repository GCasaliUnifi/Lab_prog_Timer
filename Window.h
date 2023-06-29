//
// Created by giacomo on 26/06/23.
//

#ifndef LAB_PROGRAMMAZIONE_2023_WINDOW_H
#define LAB_PROGRAMMAZIONE_2023_WINDOW_H

#include<wx/frame.h>
#include <wx/sizer.h>


#include "SubjectTimer.h"
#include "ClockDisplay.h"
#include "DateDisplay.h"

class Window : public wxFrame {
public:
    explicit Window(const wxString& title);
private:
    SubjectTimer* dateTimeData;
};


#endif //LAB_PROGRAMMAZIONE_2023_WINDOW_H
