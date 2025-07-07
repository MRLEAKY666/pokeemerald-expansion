# Pokémon Emerald Game Corner Expansion

Hello! This is a tweaked version of Chris Piche's Game Corner Expansion feature branch made by me, AGSMGMaster64.
Currently, this adds a new config file that uses some flags by default but can be configured to other flags if necessary.
Some new music and changes to the Mauville Corner have been made as well, so keep that in mind if you plan to merge this into your
existing project. Credits to AsparagusEduardo for the basis of this merge here, I just mainly tweaked things around to help
out any developers who may want to use this as well.

Updated to pokeemerald-expansion v1.12.0

To pull from this branch here, just simply use these commands here:
```
git remote add AGSMG https://github.com/agsmgmaster64/worldlinkdeluxe-ame/
git pull AGSMG gacha-expansion
```


Below is the rest of the original description from Chris Piche himself:

More specifically, this adds 4 pinball mini-games, Flappy Bird, Block Stacker, Snake, Blackjack, Voltorb Flip, Plinko, Mauville Derby, and Gacha Machines into the Game Corner.

Big thank you to huderlem (Pokemon Pinball to Emerald), and Pokeabbie (Voltorb Flip from Emerald Rogue). All I really did for these was some graphics, music, and code to work with coins. They deserve the real credits here.
Also thank you to Viperio, who made an initial Snake for Pokemon Emerald that I based my code on.

...
# About `pokeemerald-expansion`
# Outfits System

## What is this?

This is a feature branch that implements _Outfits System_ into Pokémon Emerald, which also adds:
*  SDH's [commit](<https://github.com/ShinyDragonHunter/pokeemerald/commit/05f8f2688b22454e9d2400db1621375f1e4ccb3c>) for simplifying the player states system and thus making this system easier to implement. (Required)
* An item called _`OUTFIT BOX`_ for storing and changing the player's current outfit.
* A menu for changing outfits that is called in the OUTFIT BOX item. (Can also be configured to be called somewhere else if wanted)
* Several scripting macros for unlocking an outfit, checking the state of an outfit and buffers an outfit's name/description.

This is _not_ a faithful port of Gen 6's Outfits System. So, if you want it to behave similarly to Gen 6's system, you're likely gonna have to go on your own there. However, questions regarding the Outfits System is welcomed.

Note that this feature branch is still missing some of the features that's necessary, such as the ability to purchase outfits. So, stay tune for more until then!

## Known Bugs

<!-- TODO: Too busy to fix, so I'll put it here -->
### - Trainer Card shows Player's trainer pic for Link (Cable) Players

## Credits

- Slawter666, for their original costumes system that inspires me for doing this. 
- SDH for his commit that simplify the player states system and thus helps makes the process of creating this much easier.
- RavePossum for helping me with my silly mistakes that causes bugs and bringing ideas.
