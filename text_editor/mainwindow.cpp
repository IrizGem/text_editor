#include "mainwindow.h"
#include <fstream>

#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_fileName = QString();
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
    if (m_fileName != "")
        readText(m_fileName);
}

void MainWindow::readText(const QString fileName)
{
    std::ifstream fileStream(fileName.toStdString());
    std::string text = "";
    std::string line;
    while (std::getline(fileStream, line)) {
        text += line + '\n';
    }
    fileStream.close();
    editor->document()->setPlainText(QString::fromStdString(text));
}

void MainWindow::save()
{
    writeText(m_fileName);
}

void MainWindow::writeText(const QString fileName)
{
    std::string text = editor->toPlainText().toStdString();
    std::ofstream fileStream(fileName.toStdString());
    std::string line;
    fileStream << text;
    fileStream.close();
    }
