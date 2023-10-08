#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void open();
    void save();

private:
    QPlainTextEdit *editor;
    QMenu *m_fileMenu;
    QAction *m_openAct;
    QAction *m_saveAct;
    QString m_fileName;

private:
    void createMenus();
    void createActions();
    void readText(const QString fileName);
    void writeText(const QString fileName);
};
#endif // MAINWINDOW_H
