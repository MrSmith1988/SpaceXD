float distanceToStub(float place[3], float dest[3]){
  float vecBetween[3];
  mathVecSubtract(vecBetween, dest, place, 3);
  mathVecMagnitude(vecBetween, 3);
  return vecBetween
}
