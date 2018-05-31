void SPSDrop(int itemsLeft) {
// Movement/Maths/Strategy groups can edit this so that it drops SPS items in appropriate places
if (itemsLeft == 3)
  // First SPS item...drop immediately. 
  game.dropSPSItem();
else if (itemsLeft == 2) {
  // Second SPS item. Use MoveTo function to get there.
  float pos[3];
  // initialise pos[3];
  moveTo(pos);
  if (hasReachedPosition(pos)) {
    game.dropSPSItem();
  }
} else if (itemsLeft == 1) {
  // Last item...move to required position and drop/
  float pos[3];
  // initialise pos[3];
  moveTo(pos);
  if (hasReachedPosition(pos)) {
    game.dropSPSItem();
  }
}
}
