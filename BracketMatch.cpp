#include "BracketMatch.h"

BracketMatch::BracketMatch(quint8 matchNumber, QObject *parent) :
    QObject(parent), m_matchNumber(matchNumber), m_team1(nullptr), m_team2(nullptr)
{
}

void BracketMatch::setTeam1(Team *team) {
    m_team1 = team;
    team1Changed(m_team1);
}

void BracketMatch::setTeam2(Team *team) {
    m_team2 = team;
    team1Changed(m_team2);
}
