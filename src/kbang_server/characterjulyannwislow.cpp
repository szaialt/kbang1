#include "characterjulyannwislow.h"
#include "gametable.h"
#include "playingcard.h"

CharacterJulyAnnWislow::CharacterJulyAnnWislow(QObject* parent):
        CharacterBase(parent, CHARACTER_JULY_ANN_WINSLOW)
{
}

void CharacterJulyAnnWislow::draw(bool)
{
    int handSize = mp_player->handSize();
    int draw = 4 - handSize;
    if (draw < 0) draw = 0;
    gameTable().playerDrawFromDeck(mp_player, draw, 0);
}
