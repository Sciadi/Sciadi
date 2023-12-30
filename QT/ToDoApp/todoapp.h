#ifndef TODOAPP_H
#define TODOAPP_H

#pragma once

#include <QtWidgets/QWidget>
#include "./ui_todoapp.h"
#include <QDate>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class ToDoApp;
}
QT_END_NAMESPACE

class ToDoApp : public QWidget
{
    Q_OBJECT

public:
    ToDoApp(QWidget *parent = nullptr);
    ~ToDoApp();

private:
    Ui::ToDoApp *ui;

public:
    void initStyleSheet ();
    void createNewTask(QString taskName, QString date);

public slots:
    void SlotAddNewTask();
    void SlotDeleteTask();
};
#endif // TODOAPP_H
