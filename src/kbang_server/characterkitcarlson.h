#ifndef CHARACTERKITCARLSON_H
#define CHARACTERKITCARLSON_H

#include "characterbase.h"
#include "reactionhandler.h"

class CharacterKitCarlson : public CharacterBase, public ReactionHandler
{
Q_OBJECT
public:
    enum Type {
        KitCarlson,
        RevJonathanRudd
    };
    CharacterKitCarlson(QObject *parent, Type type);
    virtual void useAbility();
    virtual void draw(bool specialDraw);

    virtual void respondCard(PlayingCard* targetCard);
    virtual ReactionType reactionType() const { return REACTION_KITCARLSON; }
    virtual Player* causedBy() const { return 0; }
private:
    Type m_type;
};

#endif // CHARACTERKITCARLSON_H
