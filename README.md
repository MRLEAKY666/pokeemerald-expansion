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


# About `pokeemerald-expansion`

![Gif that shows debugging functionality that is unique to pokeemerald-expansion such as rerolling Trainer ID, Cheat Start, PC from Debug Menu, Debug PC Fill, Pokémon Sprite Visualizer, Debug Warp to Map, and Battle Debug Menu](https://github.com/user-attachments/assets/cf9dfbee-4c6b-4bca-8e0a-07f116ef891c) ![Gif that shows overworld functionality that is unique to pokeemerald-expansion such as indoor running, BW2 style map popups, overworld followers, DNA Splicers, Gen 1 style fishing, OW Item descriptions, Quick Run from Battle, Use Last Ball, Wild Double Battles, and Catch from EXP](https://github.com/user-attachments/assets/383af243-0904-4d41-bced-721492fbc48e) ![Gif that shows off a number of modern Pokémon battle mechanics happening in the pokeemerald-expansion engine: 2 vs 1 battles, modern Pokémon, items, moves, abilities, fully customizable opponents and partners, Trainer Slides, and generational gimmicks](https://github.com/user-attachments/assets/50c576bc-415e-4d66-a38f-ad712f3316be)

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->

**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.** 

# [Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those features can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.

```
Based off RHH's pokeemerald-expansion 1.13.1 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches. 

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide to forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [ROM Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!
