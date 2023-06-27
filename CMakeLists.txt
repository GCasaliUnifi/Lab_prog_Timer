cmake_minimum_required(VERSION 3.20)
project(Lab_Programmazione_2023)

set(CMAKE_CXX_STANDARD 20)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(Lab_Programmazione_2023 main.cpp Window.cpp Window.h Observer.h Subject.h ClockDisplay.cpp ClockDisplay.h DateDisplay.cpp DateDisplay.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})