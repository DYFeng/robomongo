#pragma once

#include <QWidget>
#include <QPlainTextEdit>

#include "robomongo/core/events/MongoEvents.h"
#include "robomongo/core/settings/ConnectionSettings.h"

namespace Robomongo
{
    class MainWindow;

    /**
     * Log panel
     */
    class LogWidget : public QWidget
    {
        Q_OBJECT

    public:
        /*
        ** Constructs log widget panel for main window
        */
        LogWidget(MainWindow *mainWindow);

    public slots:
        void addMessage(const QString &message);
        void handle(SomethingHappened *event);
        void handle(ConnectingEvent *event);
        void handle(OpeningShellEvent *event);

    private:
        /*
        ** Main window this widget belongs to
        */
        MainWindow *_mainWindow;

        /*
        ** Log text box
        */
        QPlainTextEdit *_logTextEdit;

        EventBus *_bus;
    };

}
