#ifndef CHARACTERCASSIDYGRINGO_H
#define CHARACTERCASSIDYGRINGO_H

#include "characterbase.h"

class CharacterCassidyGringo : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        BartCassidy,
        ElGringo,
        ViejoSikes
    };

    CharacterCassidyGringo(QObject* parent, Type); 
    virtual void setPlayer(Player* player);
    virtual int maxLifePoints() const;
    virtual void playCard(PlayingCard* card);

public slots:
    void onHit(int lifePoints, Player* causedBy);
    void onHit(int lifePoints);
private:
    Type m_type;
};

#endif // CHARACTERCASSIDYGRINGO_H
