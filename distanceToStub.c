int distanceToStub(float place[3], float dest[3]){
  int distance;
  distance = sqrt((place[0] - dest[0])*(place[0] - dest[0]) + (place[1] - dest[1])*(place[1] - dest[1]) + (place[2] - dest[2])*(place[2] - dest[2]) )
  return distance;
}
