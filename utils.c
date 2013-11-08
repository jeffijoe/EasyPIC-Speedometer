/*
utils.c
Author: Jeff Hansen
*/

/*
* Nullifies all characters in the buffer
*/
void nuke(char* buf) {
  int i = 0;
  for(i = 0; i < sizeof(buf); i++) {
    buf[i] = 0;
  }
}

/*
* Writes to the buffer the result of the speed calculation.
* Buffer must have room for 4 characters, including null-term.
* Returns a pointer to the passed buffer.
*/
char* speed(char* buf, int voltage, int* kph) {
  double valueInKm;
  int rounded;
  // Buffers
  char converted[7];
  
  // Nuke buffer
  nuke(buf);
  
  // Round up the result in KM/T
  valueInKm = voltage / 5.3;

  rounded = (int)valueInKm;
  
  // Convert it to a string
  IntToStr(rounded, converted);
  Ltrim(converted);

  // Copies the trimmed value to the trimmed buffer.
  strcat(buf, converted);
  *kph = rounded;
  return buf;
}

/*
* Takes the km value (~100 to ~2000) and writes it to the buffer with
*/
char* total(char* buf, int* totalKm, int kph) {
  int traveledNow;
  int value;
  int index;
  char iosBuf[7];
  char* lastDigit;
  
  // This is called every second, so we must have traveled kph / 60 to simulate that 1 sec = 1 minute
  traveledNow = ((kph * 10) / 60);
  
  // Dereference the totalKm and add travel time to it
  value = (*totalKm += traveledNow);

  IntToStr(value, iosBuf);
  Ltrim(iosBuf);
  
  index = strlen(iosBuf) -1;
  lastDigit = iosBuf[index];
  iosBuf[index] = ',';
  iosBuf[index+1] = lastDigit;
  iosBuf[index+2] = 0;
  strcpy(buf, iosBuf);
  return buf;
}