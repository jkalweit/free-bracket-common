#include "Bracket.h"

#include <QtQml>
#include "Team.h"

//Bracket::Bracket(const Bracket &copy) :
//    Bracket(copy.parent())
//{
//}

Bracket::Bracket(QObject *parent) :
    QObject(parent), m_currId(0)
{
}

QQmlListProperty<Team> Bracket::teams() {
    return QQmlListProperty<Team>(this, m_teams);
}

int Bracket::numTeams() {
    return m_teams.size();
}

Team* Bracket::addTeam(QString name) {
    Team *team = new Team(m_currId++, name, this);
    addTeam(team);
    return team;
}

void Bracket::addTeam(Team *team) {
    m_teams.append(team);
    fireTeamsChanged();
}


Team* Bracket::getTeamById(quint8 id) {
    foreach(Team *team, m_teams) {
        if(team->id() == id) {
            return team;
        }
    }
    return 0;
}

Team* Bracket::getTeamAt(quint8 index) {
    return m_teams[index];
}

void Bracket::deleteTeam(quint8 id) {
    Team *team;
    for(int i = 0; i < m_teams.size(); i++) {
        team = m_teams[i];
        if(team->id() == id) {
            m_teams.removeAt(i);
            fireTeamsChanged();
            return;
        }
    }
}

void Bracket::fireTeamsChanged() {
    numTeamsChanged(numTeams());
    teamsChanged(teams());
}

void Bracket::fireRoundsChanged() {
    numRoundsChanged(numRounds());
    roundsChanged(rounds());
}

QQmlListProperty<BracketRound> Bracket::rounds() {
    return QQmlListProperty<BracketRound>(this, m_rounds);
}

int Bracket::numRounds() {
    return m_rounds.size();
}


void Bracket::startTournament() {

    quint8 level = 1;
    int maxTeams = 0;
    BracketRound *round;

    do {
        maxTeams = exp2(level);
        round = new BracketRound(level++, this);
        m_rounds.append(round);
    } while(maxTeams < numTeams());

    for(int i = 0; i < numTeams(); i++) {
        round->setTeam(i, m_teams[i]);
    }

    fireRoundsChanged();
}
