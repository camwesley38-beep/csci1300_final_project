# CSCI 1300 Final Project

## Project Theme
This game is a fictional risk managment game where the players hopes to live confortable and never work again after completing a series of thefts.However random civilians and officers will interact with the player if he devolps risk.The player needs to steal enough money while keeping his suspicion low before time runs out.

## Goal
Collect enough money without being arrested before your times up

## How to Compile and Run
g++ -std=c++17 -Wall -Werror -Wpedantic Player.cpp Character.cpp Authority.cpp Item.cpp Game.cpp main.cpp -o checkpoint3
## How to Play
The player chooses options for a menu.The player can view status, travel,take risky jobs, talk to authority , buy items , view inventory, view map and talk to civilians.Each move can affect money,risk,experence,authority pressure or the current day

## Classes
- Player: stores the users money, risk ,experience , day and location
- Character: Stores characters name , rumour spreading and suspicion 
-Authority: A type of character that raises suspicion significantly faster and can trigger events that arrest, or investigate the character
-Game: controls the game loop , the players choices and menu

## Extra Credit
Extra credit will be multiple endings, random events, and a simple map system.

Extra Credit Feature: Map Recommendation Algorithm

The game includes a map recommendation algorithm. The player can choose option 10 to get a recommended next location. The algorithm checks the location risk levels, the player's current risk, current money, and current location. It then recommends a location that balances safety and progress toward the money goal.

## Checkpoint 3 Progress

For Checkpoint 3, the game has a working menu, player stats, travel system, map display, character interactions, item shop, inventory system, and item perks. The game reads location data from `locations.txt` and item data from `items.txt`, then uses that file data in the running program. The player can travel, buy items, view inventory, talk to civilians, talk to authority, take risky jobs, and make choices that affect money, risk, authority pressure, and the ending.

## File Input

The game uses file input from:
- `locations.txt`: loads the locations shown in the travel menu and map.
- `items.txt`: loads shop items, prices, and item perk types.

## Character system

The game includes four meaningful civilian characters: Store clerk, Family Member, Paranoid Civilian, and Old Friend.Each character has 
unique dialogue that affect the game. 

## Item and Inventory System

The game includes at least five items: FakeID, OldPhone, Crowbar, GasCan, and Backpack. Items are loaded from `items.txt` and can be bought from the shop. After purchase, items are stored in the player's inventory and affect gameplay through perks.


##  Tradeoff system
The game uses heavily into its risk reward system riskyjob is how you make money but grows suspicion and pressure witch can lead to a gameover.

The game was balanced so risky jobs are more dangerous.Risky jobs now raise both player risk and authority pressure.Talking to authority gives the player differnent choices, such as cooperating, paying for legal help, or leaving quietly. Each option has a different cost or consequence
## Endings

The game has multiple ending based on money, risk and time.

## Current Features

- Working game loop and main menu
- Player stats: money, risk, experience, day, and location
- Location travel system
- Map display
- Civilian character interactions
- Authority interaction
- Item shop
- Inventory system
- Item perks that affect risk, money, or authority pressure
- Basic win/loss ending system
- Four meaningful civilian characters
- Character interactions that affect risk, pressure or experience
- Locations now have different risk levels.
- The OldPhone item lets the player preview location risk before traveling.
- Traveling can increase risk depending on the location chosen.