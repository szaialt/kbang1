#ifndef CHARACTERBUCKSHOTROBERTS_H
#define CHARACTERBUCKSHOTROBERTS_H

#include "characterbase.h"

class CharacterBuckshotRoberts : public CharacterBase
{
Q_OBJECT
public:
    enum Type {
        BuckshotRoberts,
        DroseraAlba
    };
    CharacterBuckshotRoberts(QObject *parent, Type type);
    virtual int maxLifePoints() const;
    virtual void useAbility(QList<PlayingCard*> cards);

};

#endif // CHARACTERBUCKSHOTROBERTS_H
