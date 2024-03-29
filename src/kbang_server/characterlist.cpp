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
#include "characterpyro.h"
#include "characterscout.h" 
#include "charactersniper.h" 
#include "charactersoldier.h" 

#include "charactercoronelmortimer.h" 
#include "characterdjango.h" 
#include "characteremma.h" 
#include "characterhowardhawks.h"
#include "characterjohnford.h" 
#include "characterloco.h" 
#include "characterpatgarret.h"
#include "charactersartana.h"
#include "charactertucoelfeo.h"
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
#include "characterdanquake.h"
#include "charactersamueldiehard.h"
#include "charactertomyleeghost.h"
#include "characterantonycarma.h"

#include "charactergordonchristensen.h"
#include "characterjoeljanis.h"
#include "charactercaptwcaroll.h"
#include "characterauntieangelici.h"
#include "characteredwardangle.h"
#include "charactergvblack.h"
#include "characterbushidobill.h"
#include "charactercheckingblack.h"
#include "characterelfantasma.h"

#include "charactercrazywolf.h"
#include "characterturdferguson.h"
#include "characterlilsureshot.h"
#include "charactercheckingroyal.h"
#include "characterporterrockwall.h"
#include "characterqueenanne.h"
#include "characterjosebasset.h"
#include "charactermaggiemae.h"
#include "characterleladevere.h"
#include "characterjuliebulette.h"

#include "charactercaptbarret.h"
#include "characterdaltongang.h"
#include "characterdynamitedick.h"
#include "characterjaremybaile.h"
#include "characterjuanmiranda.h"
#include "characterjudgedread.h"
#include "characterjulyannwislow.h"

#include "characterbuckshotroberts.h"
#include "characterchosingthomas.h"
#include "characterfastfranz.h"
#include "characterfelipedelgado.h"
#include "charactergreenkatejanet.h"
#include "characterhurtingbob.h"
#include "characterjackbrown.h"
#include "characterjohnnyclem.h"
#include "characterlindavivenda.h"
#include "characteroscarrodriguez.h"
#include "characterpepitaduelita.h"
#include "characterridinghorse.h"
#include "characterridinghorse.h"
#include "characterstonewalljackson.h"
#include "charactertonyarmed.h"
#include "characterwilliamlongley.h"

#include "characteralfonsoduelo.h"
#include "characterambidexterbo.h"
#include "characterbartbarber.h"
#include "characterbigfatjoe.h"
#include "characterburtlongcatcher.h"
#include "charactercolinbarrel.h"
#include "charactercrazyhorse.h"
#include "characterhankthebank.h"
#include "characterjamesstoneheart.h"
#include "characterjenniferbigheart.h"
#include "characterjeremiahamish.h"
#include "characterlinusyale.h"
#include "characterjimmysquint.h"
#include "charactermykemyope.h"
#include "characterninaninelives.h"
#include "characternellychosechair.h"
#include "characteroneeyedjack.h"
#include "characterphilthinwire.h"
#include "characterprestonpresbyope.h"
#include "characterrichardgatling.h"
#include "characterscalpingbull.h"
#include "charactertedrevenge.h"
#include "charactertimcroupier.h"
#include "charactertobiasthemole.h"
#include "charactertomgunseller.h"

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
     case CHARACTER_PYRO:
         return new CharacterPyro(parent);
    case CHARACTER_SCOUT: 
        return new CharacterScout(parent);
    case CHARACTER_SNIPER: 
        return new CharacterSniper(parent);
    case CHARACTER_SOLDIER: 
        return new CharacterSoldier(parent, CharacterSoldier::Soldier);
    case CHARACTER_SPY: 
        return new CharacterNellyChoseChair(parent, CharacterNellyChoseChair::Spy);
    case CHARACTER_CORONEL_MORTIMER: 
        return new CharacterCoronelMortimer(parent);
    case CHARACTER_DJANGO: 
        return new CharacterDjango(parent); 
    case CHARACTER_EMMA: 
        return new CharacterEmma(parent);
    case CHARACTER_HOWARD_HAWKS: 
        return new CharacterHowardHawks(parent);
    case CHARACTER_JOHN_FORD: 
        return new CharacterJohnFord(parent);
    case CHARACTER_LLANERO_SOLITARIO: 
        return new CharacterSoldier(parent, CharacterSoldier::LlaneroSolitario);
    case CHARACTER_LOCO: 
        return new CharacterLoco(parent);
    case CHARACTER_PAT_GARRETT: 
        return new CharacterPatGarrett(parent);
    case CHARACTER_REV_JONATHAN_RUDD:
        return new CharacterKitCarlson(parent, CharacterKitCarlson::RevJonathanRudd);
    case CHARACTER_ROOSTER_COGBURN: 
        return new CharacterPropertyChange(parent, CharacterPropertyChange::RoosterCogburn);
    case CHARACTER_SARTANA: 
        return new CharacterSartana(parent);
    case CHARACTER_TUCO_EL_FEO: 
        return new CharacterTucoElFeo(parent); 
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
    case CHARACTER_SERGEANT_O_REILLY: 
        return new CharacterSoldier(parent, CharacterSoldier::SergeantOReilly);
    case CHARACTER_RON_ROBBER: 
        return new CharacterWyattEarp(parent, CharacterWyattEarp::RonRobber);
    case CHARACTER_CRAZY_BEAR: 
        return new CharacterCrazyBear(parent);
    case CHARACTER_TOMY_LEE_GHOST: 
        return new CharacterTomyLeeGhost(parent);
    case CHARACTER_WHITE_WOLF: 
        return new CharacterWhiteWolf(parent, CharacterWhiteWolf::WhiteWolf);
    case CHARACTER_CHARLES_BOGGEN: 
        return new CharacterCharlesBoggen(parent);
    case CHARACTER_JONATH_HEXX: 
        return new CharacterJonathHexx(parent);
    case CHARACTER_ANTONY_CARMA: 
        return new CharacterAntonyCarma(parent);
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
    case CHARACTER_EDWARD_ANGLE: 
        return new CharacterEdwardAngle(parent);
    case CHARACTER_G_V_BLACK: 
        return new CharacterGVBlack(parent);
    case CHARACTER_BUSHIDO_BILL: 
        return new CharacterBushidoBill(parent);
    case CHARACTER_WILLIAM_HARMAN: 
        return new CharacterCheckingBlack(parent, CharacterCheckingBlack::WilliamHarman);
    case CHARACTER_CLOCKWORK: 
        return new CharacterCheckingBlack(parent, CharacterCheckingBlack::Clockwork);
    case CHARACTER_EL_FANTASMA: 
        return new CharacterElFantasma(parent);
    case CHARACTER_CRAZY_WOLF: 
        return new CharacterCrazyWolf(parent);
    case CHARACTER_TURD_FERGUSON: 
        return new CharacterTurdFerguson(parent);
    case CHARACTER_LIL_SURE_SHOT: 
        return new CharacterLilSureshot(parent);
    case CHARACTER_FLINT_DIXON: 
        return new CharacterWhiteWolf(parent, CharacterWhiteWolf::FlintDixon);
    case CHARACTER_JOB_MUSHGROVE: 
        return new CharacterCheckingRoyal(parent);
    case CHARACTER_PORTER_ROCKWALL: 
        return new CharacterPorterRockwall(parent);    
    case CHARACTER_QUEEN_ANNE: 
        return new CharacterQueenAnne(parent);
    case CHARACTER_JOSEY_BASSET: 
        return new CharacterJoseBasset(parent);
    case CHARACTER_MAGGIE_MAE: 
        return new CharacterMaggieMae(parent);
    case CHARACTER_LELA_DEVERE: 
        return new CharacterLelaDevere(parent);
    case CHARACTER_JULIE_BULETTE: 
        return new CharacterJulieBulette(parent);
    case CHARACTER_CAPT_BARRETT:
        return new CharacterCaptBarret(parent);
    case CHARACTER_DALTON_GANG:
        return new CharacterDaltonGang(parent);
    case CHARACTER_DYNAMITE_DICK:
        return new CharacterDynamiteDick(parent);
    case CHARACTER_JAREMY_BAILE:
        return new CharacterJaremyBaile(parent);
    case CHARACTER_JUAN_MIRANDA:
        return new CharacterJuanMiranda(parent);
    case CHARACTER_JUGDE_DREAD:
        return new CharacterJudgeDread(parent);
    case CHARACTER_JULY_ANN_WINSLOW:
        return new CharacterJulyAnnWislow(parent);
    case CHARACTER_BUCKSHOT_ROBERTS:
        return new CharacterBuckshotRoberts(parent, CharacterBuckshotRoberts::BuckshotRoberts);
    case CHARACTER_DROSERA_ALBA:
        return new CharacterBuckshotRoberts(parent, CharacterBuckshotRoberts::DroseraAlba);
    case CHARACTER_CHOSING_THOMAS: 
        return new CharacterChosingThomas(parent);
    case CHARACTER_FAST_FRANZ: 
        return new CharacterFastFranz(parent);
     case CHARACTER_FELIPE_DELGADO: 
        return new CharacterFelipeDelgado(parent);   
    case CHARACTER_GREEN_KATE_JANET: 
        return new CharacterGreenKateJanet(parent);   
    case CHARACTER_HURTING_BOB: 
        return new CharacterHurtingBob(parent);   
    case CHARACTER_JACK_BROWN: 
        return new CharacterJackBrown(parent);   
    case CHARACTER_JOHNNY_CLEM: 
        return new CharacterJohnnyClem(parent); 
    case CHARACTER_LINDA_VIVENDA: 
        return new CharacterLindaVivenda(parent);
    case CHARACTER_OSCAR_RODRIGUEZ: 
        return new CharacterOscarRodriguez(parent); 
    case CHARACTER_PEPITA_DUELITA: 
        return new CharacterPepitaDuelita(parent); 
    case CHARACTER_RIDING_HORSE: 
        return new CharacterRidingHorse(parent); 
    case CHARACTER_SLOBODAN_THE_KILLER: 
        return new CharacterPropertyChange(parent, CharacterPropertyChange::SlobodanTheKiller);
    case CHARACTER_STONEWALL_JACKSON: 
        return new CharacterStonewallJackson(parent); 
    case CHARACTER_TONY_ARMED: 
        return new CharacterTonyArmed(parent); 
    case CHARACTER_WILLIAM_LONGLEY: 
        return new CharacterWilliamLongley(parent); 
    case CHARACTER_ALFONSO_DUELO: 
        return new CharacterAlfonsoDuelo(parent); 
    case CHARACTER_AMBIDEXTER_BO:
        return new CharacterAmbidexterBo(parent); 
    case CHARACTER_BART_BARBER: 
        return new CharacterBartBarber(parent); 
    case CHARACTER_BIG_FAT_JOE: 
        return new CharacterBigFatJoe(parent); 
    case CHARACTER_BURT_LONGCATCHER: 
        return new CharacterBurtLongcatcher(parent); 
    case CHARACTER_COLIN_BARREL: 
        return new CharacterColinBarrel(parent); 
    case CHARACTER_CRAZY_HORSE: 
        return new CharacterCrazyHorse(parent); 
    case CHARACTER_HANK_THE_BANK: 
        return new CharacterHankTheBank(parent); 
    case CHARACTER_JAMES_STONEHEART: 
        return new CharacterJamesStoneheart(parent); 
    case CHARACTER_JENNIFER_BIG_HEART: 
        return new CharacterJenniferBigHeart(parent); 
    case CHARACTER_JEREMIAH_AMISH: 
        return new CharacterJeremiahAmish(parent);
    case CHARACTER_JIMMY_SQUINT: 
        return new CharacterJimmySquint(parent);
    case CHARACTER_LINUS_YALE: 
        return new CharacterLinusYale(parent);
    case CHARACTER_MAX_PAINLESS:
        return new CharacterCardKeeper(parent, CharacterCardKeeper::MaxPainless);
    case CHARACTER_MYKE_MYOPE: 
        return new CharacterMykeMyope(parent);
    case CHARACTER_NINA_NINE_LIVES: 
        return new CharacterNinaNineLives(parent);
    case CHARACTER_NELLY_CHOSE_CHAIR: 
        return new CharacterNellyChoseChair(parent, CharacterNellyChoseChair::NellyChoseChair);
    case CHARACTER_ONE_EYED_JACK: 
        return new CharacterOneEyedJack(parent);
    case CHARACTER_PHIL_THINWIRE: 
        return new CharacterPhilThinwire(parent);
    case CHARACTER_PRESTON_PRESBYOPE: 
        return new CharacterPrestonPresbyope(parent);
    case CHARACTER_RICHARD_GATLING: 
        return new CharacterRichardGatling(parent);
    case CHARACTER_SCALPING_BULL: 
        return new CharacterScalpingBull(parent);
    case CHARACTER_TED_REVENGE: 
        return new CharacterTedRevenge(parent);
    case CHARACTER_TIM_CROUPIER: 
        return new CharacterTimCroupier(parent);
    case CHARACTER_TOBIAS_THE_MOLE: 
        return new CharacterTobiasTheMole(parent);
    case CHARACTER_TOM_GUN_SELLER: 
        return new CharacterTomGunSeller(parent);
     case CHARACTER_UNKNOWN:
     case CHARACTER_UNKNOWN5:
         NOT_REACHED();
     
    }
    return new CharacterBase(parent, CHARACTER_UNKNOWN);
}

void CharacterList::initCharacterTypes(Game* game)
{
    
    Q_ASSERT(sm_characterTypes.size() == 0);
    sm_characterTypes.append(CHARACTER_BART_CASSIDY);
    sm_characterTypes.append(CHARACTER_BLACK_JACK);
    sm_characterTypes.append(CHARACTER_CALAMITY_JANET);//!
    sm_characterTypes.append(CHARACTER_EL_GRINGO);
    sm_characterTypes.append(CHARACTER_JESSE_JONES);
    sm_characterTypes.append(CHARACTER_JOURDONNAIS); //!
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
        sm_characterTypes.append(CHARACTER_SPY);
        sm_characterTypes.append(CHARACTER_PYRO);
    }
    else {
        qDebug() << "No teamFortressCharactersFlag.";
    }
    if (game->gameInfo().directorsCutsCharactersFlag()){
        qDebug() << "directorsCutsCharactersFlag.";
        
        sm_characterTypes.append(CHARACTER_CORONEL_MORTIMER);
        sm_characterTypes.append(CHARACTER_DJANGO);
        sm_characterTypes.append(CHARACTER_EMMA); 
        sm_characterTypes.append(CHARACTER_HOWARD_HAWKS);
        sm_characterTypes.append(CHARACTER_JOHN_FORD);
        sm_characterTypes.append(CHARACTER_LLANERO_SOLITARIO);
        sm_characterTypes.append(CHARACTER_LOCO);
        sm_characterTypes.append(CHARACTER_PAT_GARRETT);
        sm_characterTypes.append(CHARACTER_REV_JONATHAN_RUDD);
        sm_characterTypes.append(CHARACTER_ROOSTER_COGBURN);
        sm_characterTypes.append(CHARACTER_SARTANA);
        sm_characterTypes.append(CHARACTER_TUCO_EL_FEO); 
        sm_characterTypes.append(CHARACTER_VIEJO_SIKES);
        sm_characterTypes.append(CHARACTER_VIENNA);
        sm_characterTypes.append(CHARACTER_WYATT_EARP); //// segfault
    }
    else {
        qDebug() << "No directorsCutsCharactersFlag.";
    }
    
    if (game->gameInfo().martinCityCharactersFlag()){
        qDebug() << "martinCityCharactersFlag.";
        
        sm_characterTypes.append(CHARACTER_ERNEST_SALIVEN); 
        sm_characterTypes.append(CHARACTER_SERGEANT_O_REILLY);
        sm_characterTypes.append(CHARACTER_RON_ROBBER); //// segfault
        sm_characterTypes.append(CHARACTER_CRAZY_BEAR); 
        sm_characterTypes.append(CHARACTER_WHITE_WOLF); 
        sm_characterTypes.append(CHARACTER_CHARLES_BOGGEN);
        sm_characterTypes.append(CHARACTER_BILLY_LONGLIFE);
        sm_characterTypes.append(CHARACTER_DAN_QUAKE);
        sm_characterTypes.append(CHARACTER_SAMUEL_DIEHARD);
        sm_characterTypes.append(CHARACTER_ERNEST_SALIVEN2);
        sm_characterTypes.append(CHARACTER_MATTHEW_HELL);
        sm_characterTypes.append(CHARACTER_TOMY_LEE_GHOST);
        sm_characterTypes.append(CHARACTER_ANTONY_CARMA);
        sm_characterTypes.append(CHARACTER_JONATH_HEXX); //!
        
    }
    else {
        qDebug() << "No martinCityCharactersFlag.";
    }

    if (game->gameInfo().cuspOfCarabelliCharactersFlag()){
        qDebug() << "cuspOfCarabelliCharactersFlag.";
        sm_characterTypes.append(CHARACTER_JOEL_JANIS); //! On the house
        sm_characterTypes.append(CHARACTER_GORDON_CHRISTENSEN);
        sm_characterTypes.append(CHARACTER_AUNTIE_ANGELICI);
        sm_characterTypes.append(CHARACTER_EDWARD_ANGLE);
        sm_characterTypes.append(CHARACTER_G_V_BLACK);
        sm_characterTypes.append(CHARACTER_BUSHIDO_BILL);
        sm_characterTypes.append(CHARACTER_CLOCKWORK);
        sm_characterTypes.append(CHARACTER_WILLIAM_HARMAN); 
        sm_characterTypes.append(CHARACTER_EL_FANTASMA); 
        
    }
    else {
        qDebug() << "No cuspOfCarabelliCharactersFlag.";
    }
    
    if (game->gameInfo().robberRoostCharactersFlag()){
        qDebug() << "robberRoostCharactersFlag.";
        sm_characterTypes.append(CHARACTER_CRAZY_WOLF); 
        sm_characterTypes.append(CHARACTER_TURD_FERGUSON);
        sm_characterTypes.append(CHARACTER_LIL_SURE_SHOT);
        sm_characterTypes.append(CHARACTER_FLINT_DIXON); 
        sm_characterTypes.append(CHARACTER_JOB_MUSHGROVE);
        sm_characterTypes.append(CHARACTER_PORTER_ROCKWALL); 
        sm_characterTypes.append(CHARACTER_QUEEN_ANNE); 
        sm_characterTypes.append(CHARACTER_JOSEY_BASSET); 
        sm_characterTypes.append(CHARACTER_MAGGIE_MAE); 
        sm_characterTypes.append(CHARACTER_LELA_DEVERE);
        sm_characterTypes.append(CHARACTER_JULIE_BULETTE);
        
    }
    else {
        qDebug() << "No robberRoostCharactersFlag.";
    }
    if (game->gameInfo().bootHillCharactersFlag()){
        qDebug() << "bootHillCharactersFlag.";
        sm_characterTypes.append(CHARACTER_CAPT_BARRETT); 
        sm_characterTypes.append(CHARACTER_DALTON_GANG); 
        sm_characterTypes.append(CHARACTER_DYNAMITE_DICK); 
        sm_characterTypes.append(CHARACTER_JAREMY_BAILE);
        sm_characterTypes.append(CHARACTER_JUGDE_DREAD);  
        sm_characterTypes.append(CHARACTER_JULY_ANN_WINSLOW);
        sm_characterTypes.append(CHARACTER_JUAN_MIRANDA);
        
    }
    else {
        qDebug() << "No bootHillCharactersFlag.";
    }
    if (game->gameInfo().twentyCharactersFlag()){
        qDebug() << "twentyCharactersFlag.";
        sm_characterTypes.append(CHARACTER_BUCKSHOT_ROBERTS);
        sm_characterTypes.append(CHARACTER_CHOSING_THOMAS);
        sm_characterTypes.append(CHARACTER_DROSERA_ALBA);
        sm_characterTypes.append(CHARACTER_FAST_FRANZ);
        sm_characterTypes.append(CHARACTER_FELIPE_DELGADO);
        sm_characterTypes.append(CHARACTER_GREEN_KATE_JANET);
        sm_characterTypes.append(CHARACTER_HURTING_BOB);
        sm_characterTypes.append(CHARACTER_JACK_BROWN); 
        sm_characterTypes.append(CHARACTER_JOHNNY_CLEM);
        if (!game->gameInfo().ourFlag()){
          sm_characterTypes.append(CHARACTER_LINDA_VIVENDA);
        } 
        sm_characterTypes.append(CHARACTER_OSCAR_RODRIGUEZ);
        sm_characterTypes.append(CHARACTER_PEPITA_DUELITA);
        sm_characterTypes.append(CHARACTER_RIDING_HORSE);
        sm_characterTypes.append(CHARACTER_SLOBODAN_THE_KILLER);
        sm_characterTypes.append(CHARACTER_STONEWALL_JACKSON);
        sm_characterTypes.append(CHARACTER_TONY_ARMED);
        sm_characterTypes.append(CHARACTER_WILLIAM_LONGLEY); 
    }
    else {
        qDebug() << "No twentyCharactersFlag.";
        
    }
    if (game->gameInfo().thirtythreeCharactersFlag()){
        qDebug() << "thirtythreeCharactersFlag.";
        sm_characterTypes.append(CHARACTER_ALFONSO_DUELO);
        sm_characterTypes.append(CHARACTER_AMBIDEXTER_BO);
        sm_characterTypes.append(CHARACTER_BART_BARBER);
        sm_characterTypes.append(CHARACTER_BIG_FAT_JOE);
        sm_characterTypes.append(CHARACTER_BURT_LONGCATCHER);
        sm_characterTypes.append(CHARACTER_COLIN_BARREL);
        sm_characterTypes.append(CHARACTER_CRAZY_HORSE); 
        sm_characterTypes.append(CHARACTER_HANK_THE_BANK); 
        sm_characterTypes.append(CHARACTER_JAMES_STONEHEART);
        sm_characterTypes.append(CHARACTER_JENNIFER_BIG_HEART); 
        sm_characterTypes.append(CHARACTER_JEREMIAH_AMISH);
        sm_characterTypes.append(CHARACTER_JIMMY_SQUINT);
        sm_characterTypes.append(CHARACTER_LINUS_YALE);
        sm_characterTypes.append(CHARACTER_MAX_PAINLESS);
        sm_characterTypes.append(CHARACTER_MYKE_MYOPE);
        sm_characterTypes.append(CHARACTER_NINA_NINE_LIVES);
        sm_characterTypes.append(CHARACTER_NELLY_CHOSE_CHAIR);
        sm_characterTypes.append(CHARACTER_ONE_EYED_JACK);
        sm_characterTypes.append(CHARACTER_PHIL_THINWIRE);
        sm_characterTypes.append(CHARACTER_PRESTON_PRESBYOPE);
        sm_characterTypes.append(CHARACTER_RICHARD_GATLING);
        sm_characterTypes.append(CHARACTER_SCALPING_BULL);
        sm_characterTypes.append(CHARACTER_TED_REVENGE);
        sm_characterTypes.append(CHARACTER_TIM_CROUPIER); 
        sm_characterTypes.append(CHARACTER_TOBIAS_THE_MOLE);
        sm_characterTypes.append(CHARACTER_TOM_GUN_SELLER); 
        

    }
    else {
        qDebug() << "No thirtythreeCharactersFlag.";
    }

}
