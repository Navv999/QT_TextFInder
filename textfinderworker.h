#ifndef TEXTFINDERWORKER_H
#define TEXTFINDERWORKER_H

#include <QObject>
#include <QString>
#include <QTextDocument>
#include <QTextCursor>

class TextFinderWorker:public QObject
{
    QObject
public:
        explicit TextFinderWorker(QObject *parent = nullptr);


public slots:
    void findtext(const QString& searchText,QTextDocument* document);
signals:
    void textFound(const QTextCursor& cursor);

};
#endif // TEXTFINDERWORKER_H
