# blipblopsequencer
A program for used on a Arduino Uno to create a simple sequencer that can record and repeat a sequence played bt the user.
We have used [PlatformIO](https://platformio.org/) to be able to build and upload our program to our Arduinos.

We have a CAD that can be viewed here: 
![cad_of_arduino](./assets/cad.png)

### video_demo
[![Video Demo](https://markdown-videos-api.jorgenkh.no/url?url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DAp5ufkV2e5Q)](https://www.youtube.com/watch?v=Ap5ufkV2e5Q)

## set_up
To clone and run program follow these set up steps: 

1. Install PlatformIO - Download the PlatformIO IDE extension in you IDE. 
2. Clone and open project. You should now be able to use PlatformIO to build the program and upload it to your arduino. 

## keybinds && functionality
The Sequencer is set up to use one of the buttons in combination with the other. 

### button_layout
![button_layout](./assets/button_layout.jpg)

### single_presses

- Shift key (short-press) = Plays or Stops the current sequence. 
- Button 1-7 = Plays a note corresponding to that button.
- Pot1 = Controls the tempo of the sequence. 
- Pot2 = Controls the note lengths of the sequence. 

### button_combinations

- Shift + 1 = Enters the recoding mode, where the user can press buttons 1-7 to add a note to the sequence and move on to the next step in the sequence.
- Shift + 7 = Enters scale mode (Not an actual scale but rather a preset of notes).
- Shift + 2 = Clears the current sequence. 
- Shift + 2 (WHILE IN REC-MODE) = Adds a silent step to the sequence. 
- Button 1-7 (WHILE IN SCALE-MODE) = Sets the scale to the scale corresponding to the button pressed.


## team_gbg_members

- John Forslund - https://github.com/JohnForslundGebka
- Melker Petterson - https://github.com/cyberhelmer
- Sebastian Zazzi - https://github.com/zazzzi
- Stefan Jonaović - https://github.com/steffe1