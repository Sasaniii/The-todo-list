#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QDebug>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    // need to call this to init all widgets used in the
    // mainWindow.ui design file.
    ui->setupUi(this);


    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    // Call our method
    updateStatus();

}

MainWindow::~MainWindow()
{
    // Clean up the pointer
    delete ui;
}

/* Slot function for adding task */
void MainWindow::addTask()
{
    bool ok;

    // Static blocking function that display dialog to get task name.
    /* Signature:
     * QString QInputDialog::getText(QWidget *parent, const QString &title, const QString &label,
     *                               QLineEdit::EchoMode mode = QLineEdit::Normal,
     *                               const QString &text = QString(),
     *                               bool *ok = 0, ...)
     */
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        // We can do this because task is a QWidget
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);

    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;

    for (auto t : mTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;

    ui->statusLabel->setText(
                QString("Status: %1 todo / %2 completed")
                        .arg(todoCount)
                        .arg(completedCount));
}

void MainWindow::on_aboutusbutton_clicked()      // allocated space for a new timer
                                                // while also giving a parent class of                                                    // this, the MainWindow class
{                                                  // call the show method on the object
timerpointer=new timer(this);
 timerpointer->show();
}
