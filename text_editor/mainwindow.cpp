#include "mainwindow.h"

#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_fileName = new QString;
    editor = new QPlainTextEdit;
    setCentralWidget(editor);
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
{
    createActions();
    m_fileMenu = menuBar()->addMenu("File");
    m_fileMenu->addAction(m_openAct);
    m_fileMenu->addAction(m_saveAct);
}

void MainWindow::createActions()
{
    m_openAct = new QAction("Open", this);
    m_openAct->setShortcuts(QKeySequence::Open);
    m_openAct->setStatusTip("Open from file");
    connect(m_openAct, &QAction::triggered, this, &MainWindow::open);

    m_saveAct = new QAction("Save", this);
    m_saveAct->setShortcuts(QKeySequence::Save);
    m_saveAct->setStatusTip("Save to file");
    connect(m_saveAct, &QAction::triggered, this, &MainWindow::save);
}

void MainWindow::open()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Open File", ".", "Text Files (*.txt *.md *.csv)");
    readText(m_fileName);
}

void MainWindow::readText(const QString fileName)
{

}

void MainWindow::save()
{
    writeText(m_fileName);
}

void MainWindow::writeText(const QString fileName)
{

}
