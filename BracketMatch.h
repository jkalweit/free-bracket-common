#ifndef BRACKETMATCH_H
#define BRACKETMATCH_H

#include <QObject>
#include "Team.h"

class BracketMatch : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Team *team1 MEMBER m_team1 WRITE setTeam1 NOTIFY team1Changed)
    Q_PROPERTY(Team *team2 MEMBER m_team2 WRITE setTeam2 NOTIFY team2Changed)
    Q_PROPERTY(quint8 matchNumber MEMBER m_matchNumber NOTIFY matchNumberChanged)
public:
    explicit BracketMatch(quint8 matchNumber = 0, QObject *parent = 0);

    void setTeam1(Team *team);
    void setTeam2(Team *team);

private:
    Team* m_team1;
    Team* m_team2;
    quint8 m_matchNumber;
signals:
    void team1Changed(Team*);
    void team2Changed(Team*);
    void matchNumberChanged(quint8);

public slots:

};

#endif // BRACKETMATCH_H
