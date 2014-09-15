#ifndef BRACKETROUND_H
#define BRACKETROUND_H

#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include "BracketMatch.h"

class BracketRound : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 level MEMBER m_level NOTIFY levelChanged)
    Q_PROPERTY(QQmlListProperty<BracketMatch> matches READ matches NOTIFY matchesChanged)
public:
    explicit BracketRound(quint8 level = 0, QObject *parent = 0);
    QQmlListProperty<BracketMatch> matches();
    quint8 numMatches();

    void setTeam(quint8 number, Team* team);

private:
    quint8 m_level;
    QList<BracketMatch *> m_matches;

signals:
    void matchesChanged(QQmlListProperty<BracketMatch>);
    void levelChanged(quint8);

public slots:

};

#endif // BRACKETROUND_H
