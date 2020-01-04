#include "characterlist.h"

#include "characterbase.h"
#include "characterblackjack.h"
#include "charactercalamityjanet.h"
#include "charactercassidygringo.h"
#include "characterjessejones.h"
#include "characterjourdonnais.h"
#include "characterkitcarlson.h"
#include "characterluckyduke.h"
#include "characterpedroramirez.h"
#include "characterpropertychange.h"
#include "charactersidketchum.h"
#include "charactersuzylafayette.h"
#include "charactervulturesam.h"
#include "charactercowboy.h"

#include "characterdemoman.h" 
#include "characterengineer.h" 
#include "characterheavy.h" 
#include "charactermedic.h" 
#include "characterscout.h" 
#include "charactersniper.h" 
#include "charactersoldier.h" 

#include "charactercoronelmortimer.h" 
#include "characterdjango.h" 
#include "characteremma.h" 
#include "characterjohnford.h" 
#include "characterloco.h" 
//#include "characterpatgarrett.h"
#include "charactersartana.h"
#include "charactervienna.h"
#include "characterwyattearp.h"

#include "characterernestsaliven.h"
#include "characterernestsaliven2.h"
#include "charactercrazybear.h"
#include "characterwhitewolf.h"
#include "charactercharlesboggen.h"
#include "characterjonathhexx.h"
#include "charactercardkeeper.h"
#include "charactermatthewhell.h"
#include "characterabilitythief.h"
#include "characterdanquake.h"
#include "charactersamueldiehard.h"
#include "charactertomyleeghost.h"
#include "characterantonycarma.h"

#include "charactergordonchristensen.h"
#include "characterjoeljanis.h"
#include "charactercaptwcaroll.h"
#include "characterauntieangelici.h"
#include "charactergvblack.h"
#include "characterbushidobill.h"

#include "util.h"
#include "gameinfo.h"

QList<CharacterType> CharacterList::sm_characterTypes;

CharacterList::CharacterList(Game* parent, int size):
        QList<CharacterBase*>()
{
    if (sm_characterTypes.size() == 0)
        initCharacterTypes(parent);
    Q_ASSERT(sm_characterTypes.size() != 0);
    shuffleList(sm_characterTypes);
    for (int i = 0; i < size; ++i) {
        append(createCharacter(parent, sm_characterTypes[i % sm_characterTypes.size()]));
    }
}

CharacterBase* CharacterList::createCharacter(QObject* parent, CharacterType type)
{
    switch(type) {
    case CHARACTER_BART_CASSIDY:
        return new CharacterCassidyGringo(parent, CharacterCassidyGringo::BartCassidy);
    case CHARACTER_BLACK_JACK:
        return new CharacterBlackJack(parent);
    case CHARACTER_CALAMITY_JANET:
        return new CharacterCalamityJanet(parent);
    case CHARACTER_EL_GRINGO:
        return new CharacterCassidyGringo(parent, CharacterCassidyGringo::ElGringo);
    case CHARACTER_JESSE_JONES:
        return new CharacterJesseJones(parent);
    case CHARACTER_JOURDONNAIS:
        return new CharacterJourdonnais(parent);
    case CHARACTER_KIT_CARLSON:
        return new CharacterKitCarlson(parent, CharacterKitCarlson::KitCarlson);
    case CHARACTER_LUCKY_DUKE:
        return new CharacterLuckyDuke(parent);
    case CHARACTER_PAUL_REGRET:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::PaulRegret);
    case CHARACTER_PEDRO_RAMIREZ:
        return new CharacterPedroRamirez(parent);
    case CHARACTER_ROSE_DOOLAN:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::RoseDoolan);
    case CHARACTER_SID_KETCHUM:
        return new CharacterSidKetchum(parent);
    case CHARACTER_SLAB_THE_KILLER:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::SlabTheKiller);
    case CHARACTER_SUZY_LAFAYETTE:
        return new CharacterSuzyLafayette(parent);
    case CHARACTER_VULTURE_SAM:
        return new CharacterVultureSam(parent);
    case CHARACTER_WILLY_THE_KID:
        return new CharacterPropertyChange(parent, CharacterPropertyChange::WillyTheKid);
    case CHARACTER_COWBOY:
        return new CharacterCowboy(parent);
        //Team Fortress:
    case CHARACTER_DEMOMAN: 
        return new CharacterDemoman(parent);
    case CHARACTER_ENGINEER: 
        return new CharacterEngineer(parent);
    case CHARACTER_HEAVY: 
        return new CharacterHeavy(parent);
    case CHARACTER_MEDIC: 
        return new CharacterMedic(parent);
//     case CHARACTER_PYRO:
//         return new CharacterPyro(parent);
    //CHARACTER_PYRO ruins the game with his ability, please don't add him.
    case CHARACTER_SCOUT: 
        return new CharacterScout(parent);
    case CHARACTER_SNIPER: 
        return new CharacterSniper(parent);
    case CHARACTER_SOLDIER: 
        return new CharacterSoldier(parent, CharacterSoldier::Soldier);
    case CHARACTER_CORONEL_MORTIMER: 
        return new CharacterCoronelMortimer(parent);
    case CHARACTER_DJANGO: 
        return new CharacterDjango(parent); 
    case CHARACTER_EMMA: 
        return new CharacterEmma(parent);
    case CHARACTER_JOHN_FORD: 
        return new CharacterJohnFord(parent);
    case CHARACTER_LLANERO_SOLITARIO: 
        return new CharacterSoldier(parent, CharacterSoldier::LlaneroSolitario);
    case CHARACTER_LOCO: 
        return new CharacterLoco(parent);
    case CHARACTER_REV_JONATHAN_RUDD:
        return new CharacterKitCarlson(parent, CharacterKitCarlson::RevJonathanRudd);
    case CHARACTER_ROOSTER_COGBURN: 
        return new CharacterPropertyChange(parent, CharacterPropertyChange::RoosterCogburn);
    case CHARACTER_SARTANA: 
        return new CharacterSartana(parent);
    case CHARACTER_VIEJO_SIKES:
        return new CharacterCassidyGringo(parent, CharacterCassidyGringo::ViejoSikes);
    case CHARACTER_VIENNA: 
        return new CharacterVienna(parent);
    case CHARACTER_WYATT_EARP: 
        return new CharacterWyattEarp(parent, CharacterWyattEarp::WyattEarp);
    case CHARACTER_ERNEST_SALIVEN: 
        return new CharacterErnestSaliven(parent);
    case CHARACTER_ERNEST_SALIVEN2: 
        return new CharacterErnestSaliven2(parent);
    case CHARACTER_LADY_BURBOUN: 
        return new CharacterAbilityThief(parent, CharacterAbilityThief::LadyBourbon);
    case CHARACTER_SERGEANT_O_REILLY: 
        return new CharacterSoldier(parent, CharacterSoldier::SergeantOReilly);
    case CHARACTER_RON_ROBBER: 
        return new CharacterWyattEarp(parent, CharacterWyattEarp::RonRobber);
    case CHARACTER_CRAZY_BEAR: 
        return new CharacterCrazyBear(parent);
    case CHARACTER_TOMY_LEE_GHOST: 
        return new CharacterTomyLeeGhost(parent);
    case CHARACTER_WHITE_WOLF: 
        return new CharacterWhiteWolf(parent);
    case CHARACTER_CHARLES_BOGGEN: 
        return new CharacterCharlesBoggen(parent);
    case CHARACTER_JONATH_HEXX: 
        return new CharacterJonathHexx(parent);
    case CHARACTER_ANTONY_CARMA: 
        return new CharacterAntonyCarma(parent);
    case CHARACTER_JIM_SCARECROW: 
        return new CharacterAbilityThief(parent, CharacterAbilityThief::JimScarecrow);
    case CHARACTER_BILLY_LONGLIFE:
        return new CharacterCardKeeper(parent, CharacterCardKeeper::BillyLonglife);
    case CHARACTER_MATTHEW_HELL: 
        return new CharacterMatthewHell(parent);
    case CHARACTER_DAN_QUAKE: 
        return new CharacterDanQuake(parent);
    case CHARACTER_SAMUEL_DIEHARD: 
        return new CharacterSamuelDiehard(parent);
    case CHARACTER_JOEL_JANIS: 
        return new CharacterJoelJanis(parent);
    case CHARACTER_GORDON_CHRISTENSEN: 
        return new CharacterGordonChristensen(parent);
    case CHARACTER_CAPT_W_CAROLL: 
        return new CharacterCaptWCaroll(parent);
    case CHARACTER_AUNTIE_ANGELICI: 
        return new CharacterAuntieAngelici(parent);
    case CHARACTER_G_V_BLACK: 
        return new CharacterGVBlack(parent);
    case CHARACTER_BUSHIDO_BILL: 
        return new CharacterBushidoBill(parent);
     case CHARACTER_UNKNOWN:
         NOT_REACHED();
     
    }
    return new CharacterBase(parent, CHARACTER_UNKNOWN);
}

void CharacterList::initCharacterTypes(Game* game)
{
    Q_ASSERT(sm_characterTypes.size() == 0);
    sm_characterTypes.append(CHARACTER_BART_CASSIDY);
    sm_characterTypes.append(CHARACTER_BLACK_JACK);
    sm_characterTypes.append(CHARACTER_CALAMITY_JANET);
    sm_characterTypes.append(CHARACTER_EL_GRINGO);
    sm_characterTypes.append(CHARACTER_JESSE_JONES);
    sm_characterTypes.append(CHARACTER_JOURDONNAIS);
    sm_characterTypes.append(CHARACTER_KIT_CARLSON);
    sm_characterTypes.append(CHARACTER_LUCKY_DUKE);
    sm_characterTypes.append(CHARACTER_PAUL_REGRET);
    sm_characterTypes.append(CHARACTER_PEDRO_RAMIREZ);
    sm_characterTypes.append(CHARACTER_ROSE_DOOLAN);
    sm_characterTypes.append(CHARACTER_SID_KETCHUM);
    sm_characterTypes.append(CHARACTER_SLAB_THE_KILLER);
    sm_characterTypes.append(CHARACTER_SUZY_LAFAYETTE);
    sm_characterTypes.append(CHARACTER_VULTURE_SAM);
    sm_characterTypes.append(CHARACTER_WILLY_THE_KID);
        
    //sm_characterTypes.append(CHARACTER_COWBOY);
    
    if (game->gameInfo().teamFortressCharactersFlag()){
        qDebug() << "teamFortressCharactersFlag.";
        sm_characterTypes.append(CHARACTER_DEMOMAN);
        sm_characterTypes.append(CHARACTER_ENGINEER);
        sm_characterTypes.append(CHARACTER_HEAVY);
        sm_characterTypes.append(CHARACTER_MEDIC);
        sm_characterTypes.append(CHARACTER_SCOUT);
        sm_characterTypes.append(CHARACTER_SNIPER);
        sm_characterTypes.append(CHARACTER_SOLDIER);
    }
    else {
        qDebug() << "No teamFortressCharactersFlag.";
    }
    if (game->gameInfo().directorsCutsCharactersFlag()){
        qDebug() << "directorsCutsCharactersFlag.";
        
        sm_characterTypes.append(CHARACTER_CORONEL_MORTIMER);
        sm_characterTypes.append(CHARACTER_EMMA);
        sm_characterTypes.append(CHARACTER_JOHN_FORD);
        sm_characterTypes.append(CHARACTER_LLANERO_SOLITARIO);
        sm_characterTypes.append(CHARACTER_LOCO);
        sm_characterTypes.append(CHARACTER_REV_JONATHAN_RUDD);
        sm_characterTypes.append(CHARACTER_ROOSTER_COGBURN);
        sm_characterTypes.append(CHARACTER_SARTANA);
        sm_characterTypes.append(CHARACTER_VIEJO_SIKES);
        sm_characterTypes.append(CHARACTER_VIENNA);
        sm_characterTypes.append(CHARACTER_WYATT_EARP);

        //sm_characterTypes.append(CHARACTER_DJANGO);

    }
    else {
        qDebug() << "No directorsCutsCharactersFlag.";
    }
    
    if (game->gameInfo().martinCityCharactersFlag()){
        qDebug() << "martinCityCharactersFlag.";
        
        sm_characterTypes.append(CHARACTER_ERNEST_SALIVEN);
        sm_characterTypes.append(CHARACTER_SERGEANT_O_REILLY);
        sm_characterTypes.append(CHARACTER_RON_ROBBER);
        sm_characterTypes.append(CHARACTER_CRAZY_BEAR);
        sm_characterTypes.append(CHARACTER_WHITE_WOLF);
        sm_characterTypes.append(CHARACTER_CHARLES_BOGGEN);
        sm_characterTypes.append(CHARACTER_BILLY_LONGLIFE);
        sm_characterTypes.append(CHARACTER_DAN_QUAKE);
        sm_characterTypes.append(CHARACTER_SAMUEL_DIEHARD);
        sm_characterTypes.append(CHARACTER_ERNEST_SALIVEN2);
        sm_characterTypes.append(CHARACTER_MATTHEW_HELL);
        sm_characterTypes.append(CHARACTER_JIM_SCARECROW);
        sm_characterTypes.append(CHARACTER_LADY_BURBOUN); 
        sm_characterTypes.append(CHARACTER_TOMY_LEE_GHOST);
        sm_characterTypes.append(CHARACTER_ANTONY_CARMA);
        sm_characterTypes.append(CHARACTER_JONATH_HEXX);
        
    }
    else {
        qDebug() << "No martinCityCharactersFlag.";
    }

    if (game->gameInfo().cuspOfCarabelliCharactersFlag()){
        qDebug() << "cuspOfCarabelliCharactersFlag.";
        sm_characterTypes.append(CHARACTER_JOEL_JANIS);
        sm_characterTypes.append(CHARACTER_GORDON_CHRISTENSEN);
        sm_characterTypes.append(CHARACTER_AUNTIE_ANGELICI);
        sm_characterTypes.append(CHARACTER_G_V_BLACK);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL); 
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL); 
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
    }
    else {
        qDebug() << "No cuspOfCarabelliCharactersFlag.";
    }
    
    if (game->gameInfo().cuspOfCarabelliCharactersFlag()){
        qDebug() << "robberRoostCharactersFlag.";
    }
    else {
        qDebug() << "No robberRoostCharactersFlag.";
    }

}
