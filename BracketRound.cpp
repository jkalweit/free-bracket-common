#include <cmath>
#include "BracketRound.h"

BracketRound::BracketRound(quint8 level, QObject *parent) :
    QObject(parent), m_level(level)
{
    for(int i = 0; i < numMatches(); i++) {
        m_matches.append(new BracketMatch(i+1, this));
    }
}


QQmlListProperty<BracketMatch> BracketRound::matches() {
    return QQmlListProperty<BracketMatch>(this, m_matches);
}

quint8 BracketRound::numMatches() {
    //return m_matches.size(); // Should always be level^2
    return exp2(m_level - 1); // subtract 1 to effectively divide by 2 (2 teams per match)
}

void BracketRound::setTeam(quint8 number, Team* team) {
    int oddOffset = number % 2;
    number -= oddOffset;
    BracketMatch *match = m_matches[number / 2];

    if(!oddOffset)
        match->setTeam1(team);
    else
        match->setTeam2(team);
}
