#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include <QList>
#include <QObject>
#include "parser/parserstructs.h"
#include "game.h"

class CharacterBase;

class CharacterList : public QList<CharacterBase*>
{
public:
    CharacterList(Game* parent, int size);

private:
    CharacterBase* createCharacter(QObject* parent, CharacterType type);
    static void initCharacterTypes(Game* game);
    static QList<CharacterType> sm_characterTypes;


};

#endif // CHARACTERLIST_H
