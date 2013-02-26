#-------------------------------------------------
#
# Project created by QtCreator 2013-02-18T17:01:17
#
#-------------------------------------------------

QT       += core gui \
         += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Memory_Qt_GUI
TEMPLATE = app


SOURCES += main.cpp \
    src/mainwindow.cpp \
    src/memory_widget.cpp \
    src/memory_card.cpp \
    ../Memory_Engine/src/card.cpp \
    ../Memory_Engine/src/memory.cpp \
    ../Memory_Engine/src/first_card_state.cpp \
    ../Memory_Engine/src/second_card_state.cpp \
    ../Memory_Engine/src/end_turn_state.cpp \
    ../Memory_Engine/src/game_over_state.cpp \
    ../Memory_Engine/src/player.cpp \
    ../Memory_Engine/src/memory_state.cpp \
    src/player_wizzard.cpp \
    src/card_set_wizzard.cpp \
    src/main_menu.cpp \
    src/qplayer.cpp \
    src/memorygraphicswidget.cpp \
    src/qt_state.cpp \
    src/qt_state_first.cpp \
    src/qt_state_second.cpp \
    src/qt_state_end.cpp \
    src/qt_state_game_over.cpp

HEADERS  += mainwindow.h \
    include/mainwindow.h \
    include/memory_widget.h \
    include/memory_card.h \
    include/memory.h \
    include/player_wizzard.h \
    include/card_set_wizzard.h \
    include/main_menu.h \
    include/qplayer.h \
    include/memorygraphicswidget.h \
    include/qt_state.h \
    include/qt_state_first.h \
    include/qt_state_second.h \
    include/qt_state_end.h \
    include/qt_state_game_over.h

FORMS    += forms/mainwindow.ui \
    forms/memory_widget.ui \
    forms/player_wizzard.ui \
    forms/card_set_wizzard.ui \
    forms/main_menu.ui

INCLUDEPATH += ../Memory_Engine/

OTHER_FILES +=
