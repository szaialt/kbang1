This version includes the expansuions Team Fortress and Directors Cuts. For Team Fortress, see
http://tf2bangexpansion.blogspot.com/

For Directors Cuts see
http://bangdirectorscuts.blogspot.com/
and
http://bangcardgame.blogspot.com/2011/08/directors-cut-expansion.html

Compilation needs Qt5, Qt4 is not good for it.

You can choose the option Our rules. So you get those:
* Dynamit cann't be throwen out.
* Life-saving beer even with two players.
* Suzy Lafayette can use only one weapon during a turn.
* Suzy Lafayette can't switch her table cards but others yes.

Double dynamite can be separately set. 

Some characters are missing from technical reasons. 

To use ability of Jesse Jones, you need to clik to a free place on table of the target player. Another characters with target player need click to any card of their target.

You can modify character list by modifying characterlist.cpp. To modify the deck, you need modify cardfactory,cpp. If you would change a card, you need replace the card with a new card with the same name on the right place.

Some characters, like CHARACTER_BUCKSHOT_ROBERTS, can ruin the game by not using their ability correctly. 
* CHARACTER_BUCKSHOT_ROBERTS can cancel two cards by a Cat Balou, but he can elect only cards he sees.
* CHARACTER_DROSERA_ALBA can draw two cards by a Panic, but she can elect only cards she sees.
If they can't see a card, and they would target them, they will cause
a segmentation fault.

If you would support me, you can contribute to my student loan:

Name: Diákhitel Központ Zrt.

IBAN HU4810032000-01800126-00000000
SWIFT CODE: HUSTHUHB
Message: 16266058

Your contribution needs to be 1000 Ft (HUF) or more, that's minimum 4 Euros or US $-s.

Have a good time!

Anna Szekér
