#include "textfinder.h"
#include "ui_textfinder.h"
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QTextDocument>
#include <QTextCursor>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();



    ui->textEdit->setPlainText(line);
    QTextCursor cursor =ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);


}
void TextFinder::on_findButton_clicked()
{
    QString SearchString=ui->lineEdit->text();
    QTextCursor cursor = ui->textEdit->document()->find(SearchString, ui->textEdit->textCursor(), QTextDocument::FindWholeWords);
//    ui->textEdit->find(SearchString,QTextDocument::FindWholeWords);
    QTextCharFormat format;
    format.setForeground(Qt::red);

    while (!cursor.isNull() && !cursor.atEnd()) {
            cursor.mergeCharFormat(format);
            cursor = ui->textEdit->document()->find(SearchString, cursor, QTextDocument::FindWholeWords);


}
}

