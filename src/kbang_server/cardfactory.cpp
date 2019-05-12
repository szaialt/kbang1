#include "cardfactory.h"
#include "cards.h"
#include "gameenums.h"
#include "gameenums.cpp"

#include <QSet>
#include <cstdlib>

struct CardFactory::CardFactoryImp
{

    void generateCards(Game* game, QMap<int, PlayingCard*>& res)
    {
        QList<PlayingCard*> list;
        //CheckDeckResultHandler cards should have unique m_PredrawCheck -s
        
        //////////
       // BANG //
      //////////
        for (int i = 2; i <= 14; ++i) {
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_DIAMONDS, i));
        }
        for (int i = 2; i <= 9; ++i) {
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_CLUBS, i));
        }
        for (int i = 12; i <= 14; ++i) {
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_HEARTS, i));
        }
        list.append(new CardBang(game, id(), CardBang::Bang, SUIT_SPADES, 14));


        ////////////
       // MISSED //
      ////////////
        for (int i = 2; i <= 8; ++i) {
            list.append(new CardMissed(game, id(), CardMissed::Missed, SUIT_SPADES, i));
        }
        for (int i = 10; i <= 14; ++i) {
            list.append(new CardMissed(game, id(), CardMissed::Missed, SUIT_CLUBS, i));
        }

        ///////////////////
       // BEER + SALOON //
      ///////////////////
        for (int i = 6; i <= 11; ++i) {
            list.append(new CardBeer(game, id(), CardBeer::Beer, SUIT_HEARTS, i));
        }
        list.append(new CardBeer(game, id(), CardBeer::Saloon, SUIT_HEARTS, 5));

        ////////////
       // HORSES //
      ////////////
        list.append(new CardHorse(game, id(), CardHorse::Appaloosa, SUIT_SPADES, 14));
        list.append(new CardHorse(game, id(), CardHorse::Mustang,   SUIT_HEARTS, 8));
        list.append(new CardHorse(game, id(), CardHorse::Mustang,   SUIT_HEARTS, 9));
        
        /////////////
       // WEAPONS //
      /////////////
        list.append(new WeaponCard(game, id(), WeaponCard::Volcanic, SUIT_SPADES, 10));
        list.append(new WeaponCard(game, id(), WeaponCard::Volcanic, SUIT_CLUBS,  10));
        list.append(new WeaponCard(game, id(), WeaponCard::Schofield, SUIT_CLUBS,  11));
        list.append(new WeaponCard(game, id(), WeaponCard::Schofield, SUIT_CLUBS,  12));
        list.append(new WeaponCard(game, id(), WeaponCard::Schofield, SUIT_SPADES, 13));
        list.append(new WeaponCard(game, id(), WeaponCard::Remington, SUIT_CLUBS,  13));
        list.append(new WeaponCard(game, id(), WeaponCard::Carabine, SUIT_CLUBS,  14));
        list.append(new WeaponCard(game, id(), WeaponCard::Winchester, SUIT_SPADES, 8));

        ////////////////
       // DRAW CARDS //
      ////////////////
        list.append(new CardDrawCards(game, id(), CardDrawCards::Diligenza,  SUIT_SPADES,  9));
        list.append(new CardDrawCards(game, id(), CardDrawCards::Diligenza,  SUIT_SPADES,  9));
        list.append(new CardDrawCards(game, id(), CardDrawCards::WellsFargo, SUIT_HEARTS,  3));

        ////////////////
       // MULTISHOOT //
      ////////////////
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Indians, SUIT_DIAMONDS,  13));
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Indians, SUIT_DIAMONDS,  14));
        list.append(new CardMultiShoot(game, id(), CardMultiShoot::Gatling, SUIT_HEARTS,    10));

        //////////
       // DUEL //
      //////////
        list.append(new CardDuel(game, id(), SUIT_CLUBS,    8 ));
        list.append(new CardDuel(game, id(), SUIT_SPADES,   11));
        list.append(new CardDuel(game, id(), SUIT_DIAMONDS, 12));


        list.append(new CardGeneralStore(game, id(), SUIT_SPADES, 12));
        list.append(new CardGeneralStore(game, id(), SUIT_CLUBS, 9));

        list.append(new CardJail(game, id(), CardJail::Jail, SUIT_SPADES, 10, 10));
        list.append(new CardJail(game, id(), CardJail::Jail, SUIT_SPADES, 11, 11));
        list.append(new CardJail(game, id(), CardJail::Jail, SUIT_HEARTS, 4, 12));

        list.append(new CardDynamite(game, id(), SUIT_HEARTS, 2, 20));

        list.append(new CardTaker(game, id(), CardTaker::Panic, SUIT_DIAMONDS, 8 ));
        list.append(new CardTaker(game, id(), CardTaker::Panic, SUIT_HEARTS,   11));
        list.append(new CardTaker(game, id(), CardTaker::Panic, SUIT_HEARTS,   12));
        list.append(new CardTaker(game, id(), CardTaker::Panic, SUIT_HEARTS,   14));

        list.append(new CardTaker(game, id(), CardTaker::CatBalou, SUIT_DIAMONDS, 9 ));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, SUIT_DIAMONDS, 10));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, SUIT_DIAMONDS, 11));
        list.append(new CardTaker(game, id(), CardTaker::CatBalou, SUIT_HEARTS,   13));

        list.append(new CardBarrel(game, id(), SUIT_SPADES, 12));
        list.append(new CardBarrel(game, id(), SUIT_SPADES, 13));
        
        
        if (game->gameInfo().dodgeCityFlag()) {
            list.append(new CardDynamite(game, id(), SUIT_CLUBS, 10, 21));
            
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_SPADES, 2));
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_SPADES, 8));
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_SPADES, 13));
            list.append(new CardBang(game, id(), CardBang::Bang, SUIT_CLUBS, 13));

            list.append(new CardMissed(game, id(), CardMissed::Missed, SUIT_DIAMONDS, 8));
            list.append(new CardMissed(game, id(), CardMissed::Missed,  SUIT_DIAMONDS, 11));
            list.append(new CardMissed(game, id(), CardMissed::Missed, SUIT_DIAMONDS, 12));

            list.append(new CardBeer(game, id(), CardBeer::Beer, SUIT_SPADES, 6));
            list.append(new CardBeer(game, id(), CardBeer::Beer, SUIT_HEARTS, 6));
                        
            list.append(new CardHorse(game, id(), CardHorse::Mustang,   SUIT_HEARTS, 5));
            list.append(new CardHorse(game, id(), CardHorse::Appaloosa, SUIT_SPADES, 14));

            list.append(new WeaponCard(game, id(), WeaponCard::Remington, SUIT_DIAMONDS,  6));
            list.append(new WeaponCard(game, id(), WeaponCard::Carabine, SUIT_SPADES,  5));

            list.append(new CardMultiShoot(game, id(), CardMultiShoot::Indians, SUIT_DIAMONDS,  5));
            
            list.append(new CardGeneralStore(game, id(), SUIT_SPADES, 14));
            
            list.append(new CardTaker(game, id(), CardTaker::Panic, SUIT_HEARTS,   12));
            
        }
        
        if (game->gameInfo().teamFortressFlag()){
             list.append(new CardTeamFortressBang(game, id(), CardBang::DirectHit, SUIT_CLUBS, 3));
             
             list.append(new CardExpansionBeer(game, id(), CardBeer::MadMilk, SUIT_HEARTS, 3));
             
             list.append(new CardExpansionBeer(game, id(), CardBeer::Sandvich, SUIT_HEARTS, 2));
             
             list.append(new CardDrawCards(game, id(), CardDrawCards::SupplyCrate,  SUIT_CLUBS,  4));
             
             list.append(new CardMultiShoot(game, id(), CardMultiShoot::ManVsMachine, SUIT_DIAMONDS,  14));
             
             list.append(new CardArson(game, id(), CardMultiShoot::Arson, SUIT_CLUBS,  2));
             
             list.append(new CardMissed(game, id(), CardMissed::DeadRinger, SUIT_SPADES, 4));
             
             list.append(new CardJarate(game, id(), SUIT_HEARTS, 14));
             
             list.append(new CardTeleport(game, id(), SUIT_HEARTS, 4, 4));
            
             list.append(new CardPersuasion(game, id(), SUIT_HEARTS, 13));
             
             list.append(new WeaponCard(game, id(), WeaponCard::Guitar, SUIT_SPADES,  14));
             
             list.append(new WeaponCard(game, id(), WeaponCard::HalfZatochi, SUIT_CLUBS,  13));
             
             list.append(new WeaponCard(game, id(), WeaponCard::Sandman, SUIT_SPADES,  13));
            
             list.append(new WeaponCard(game, id(), WeaponCard::MediGun, SUIT_CLUBS,  14));
           
             list.append(new CardBang(game, id(), CardBang::Bang, SUIT_DIAMONDS, 2));
             
             list.append(new CardBang(game, id(), CardBang::Bang, SUIT_DIAMONDS, 3));
             
             list.append(new CardBang(game, id(), CardBang::Bang, SUIT_DIAMONDS, 4));
             
             list.append(new CardBang(game, id(), CardBang::Bang, SUIT_DIAMONDS, 13));
             
             list.append(new CardMissed(game, id(), CardMissed::Missed,  SUIT_DIAMONDS, 2));
             
             list.append(new CardMissed(game, id(), CardMissed::Missed, SUIT_DIAMONDS, 3));
             
             
        }
        if (game->gameInfo().directorsCutsFlag()){
            list.append(new CardDrawCards(game, id(), CardDrawCards::AceUpYourSleeve, SUIT_CLUBS,  7));
        
            list.append(new CardDrawCards(game, id(), CardDrawCards::UnionPacific, SUIT_HEARTS,  6));
        
            list.append(new CardPeacePipe(game, id(), SUIT_DIAMONDS,  7));
        
            list.append(new WeaponCard(game, id(), WeaponCard::Shotgun, SUIT_CLUBS,  7));
        
            list.append(new CardJail(game, id(), CardJail::Sunglare, SUIT_SPADES, 4, 9));
        
            list.append(new CardHorse(game, id(), CardHorse::PackingMule, SUIT_SPADES, 7));
        
            list.append(new CardMemento(game, id(), SUIT_HEARTS, 5));

            list.append(new CardHiddenWeapon(game, id(), SUIT_SPADES, 5));
        
            list.append(new CardBang(game, id(), CardBang::Deflection, SUIT_HEARTS, 7));
           
        }
        
        
        if (game->gameInfo().martinCityFlag()){
            
            list.append(new CardBang(game, id(), CardBang::IndianBang, SUIT_DIAMONDS, 7));
            
            list.append(new CardBang(game, id(), CardBang::Undefensable, SUIT_CLUBS, 1));
            
            list.append(new CardExplosion(game, id(), SUIT_SPADES, 12));
            
            list.append(new CardExpansionBeer(game, id(), CardBeer::Elixir, SUIT_HEARTS, 7));
            
            list.append(new CardExpansionBeer(game, id(), CardBeer::FirstAidKit, SUIT_DIAMONDS, 3));
            
            list.append(new CardDirtyJob(game, id(), SUIT_CLUBS, 2));
            
            list.append(new CardCowboyPocket(game, id(), SUIT_CLUBS, 4));
            
            list.append(new CardBleedingInjury(game, id(), SUIT_DIAMONDS, 6));
            
            list.append(new CardFlameBottle(game, id(), SUIT_SPADES, 6));
            
            list.append(new CardMultiShoot(game, id(), CardMultiShoot::ManVsMachine, SUIT_CLUBS,  3));
            
            list.append(new CardThunder(game, id(), SUIT_DIAMONDS, 4));
            
            list.append(new CardStunning(game, id(), SUIT_DIAMONDS, 5));   
            
            list.append(new CardMissed(game, id(), CardMissed::Vest, SUIT_SPADES, 4));
            
            list.append(new CardThief(game, id(), SUIT_HEARTS, 6));
            
            list.append(new CardDrawCards(game, id(), CardDrawCards::Adrenaline,  SUIT_HEARTS,  12));
            
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            list.append(new CardBeer(game, id(), CardBeer::Medicines, SUIT_HEARTS, 11));
            
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5));  
            list.append(new CardStunning(game, id(), SUIT_HEARTS, 5)); 
            
            
            
            
            
            
            
        }
        foreach(PlayingCard* card, list) {
            res[card->id()] = card;
        }
    }


    int id()
    {
        int cardId;
        do {
            cardId = (int)qrand();
        } while(m_ids.contains(cardId));
        m_ids.insert(cardId);
        return cardId;
    }

    QSet<int>   m_ids;
};

CardFactory::CardFactory()
{
    mp_imp = new CardFactoryImp();
}

CardFactory::~CardFactory()
{
    delete mp_imp;
}

QMap<int, PlayingCard*> CardFactory::generateCards(Game* game)
{
    QMap<int, PlayingCard*> res;
    mp_imp->generateCards(game, res);
    return res;

}
