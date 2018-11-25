#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a GUI object
    GUI gui;

    // Displays it
    gui.show();

    return app.exec();
}
