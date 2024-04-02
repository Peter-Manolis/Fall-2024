unsigned int face_buttons = 0;
unsigned int right_stick = 0;
unsigned int left_stick = 0;
unsigned int triggers = 0;
/*
  In this project, you are prohibited from using ANY complex statement.
  This means you are restricted to assignment, bitwise, logical and
  arithmatic operators
 */

/*
  Read a message and SET the bits of the `face_buttons`, `right_stick`,
      `left_stick`, and `triggers` variables based on the contents of the
      message.  The specifics of the bit mapping are up to you, but the
      two least significant bits MUST be used to uniquely identify which
      variable is being modified i.e. with the message:
          0000 .... 0001 1010
      We would SET the second and third bits of the variable corresponding 
      with 0b10
 */
int set_bits(unsigned int msg) {
  unsigned int first = 0;
  unsigned int second = 1;
  unsigned int third = 2;
  unsigned int fourth = 3;
  face_buttons = face_buttons | (((msg & fourth) == first) * msg);

  right_stick = right_stick | (((msg & fourth) == second) * msg);
  
  left_stick = left_stick | (((msg & fourth) == third) * msg);

  triggers = triggers | (((msg & fourth) == fourth) * msg);

  return 1;
}
/*
  Read a message and CLEAR the bits of the `face_buttons`, `right_stick`,
      `left_stick`, and `triggers` variables based on the contents of the
      message.  The specifics of the bit mapping are up to you, but the
      two least significant bits MUST be used to uniquely identify which
      variable is being modified - i.e. with the message:
          0000 .... 0001 1010
      We would CLEAR the second and third bits of the variable corresponding 
      with 0b10
 */
int clear_bits(unsigned int msg) {
  unsigned int first = 0;
  unsigned int second = 1;
  unsigned int third = 2;
  unsigned int fourth = 3;

  face_buttons = ~face_buttons & ~(((msg & fourth) == first) * msg);

  right_stick = ~right_stick & ~(((msg & fourth) == second) * msg);

  left_stick = ~left_stick & ~(((msg & fourth) == third) * msg);

  triggers = ~triggers & ~(((msg & fourth) == fourth) * msg);

  return 1;
}

/*
  for the get_<value> functions, return just the value of the requested
  field.  I.e. `get_t` would extract the 0 or 1 of the `face_buttons`
  integer corresponding to 't' and return it.
 */
int get_x(void) {
  unsigned int mask;
  unsigned int three = 4;
  mask = face_buttons & three;
  return (((mask >> 2 )<<31)>>31);
}
int get_o(void) {
  unsigned int mask;
  unsigned int four = 8;
  mask = face_buttons & four;
  return (((mask >> 3 )<<31)>>31);
}
int get_s(void) {
  unsigned int mask;
  unsigned int five = 16;
  mask = face_buttons & five;
  return (((mask >> 4 )<<31)>>31);
}
int get_t(void) {
  unsigned int mask;
  unsigned int six = 32;
  mask = face_buttons & six;
  return (((mask >> 5 )<<31)>>31);
}
int get_up(void) {
  unsigned int mask;
  unsigned int seven = 64;
  mask = face_buttons & seven;
  return (((mask >> 6 )<<31)>>31);
}
int get_left(void) {
  unsigned int mask;
  unsigned int eight = 128;
  mask = face_buttons & eight;
  return (((mask >> 7 )<<31)>>31);
}
int get_down(void) {
  unsigned int mask;
  unsigned int nine = 256;
  mask = face_buttons & nine;   
  return (((mask >> 8 )<<31)>>31);
}
int get_right(void) {
  unsigned int mask;
  unsigned int ten = 512;
  mask = face_buttons & ten;
  return (((mask >> 9 )<<31)>>31);
}
int get_r1(void) {
  unsigned int mask;
  unsigned int eleven = 1024;
  mask = face_buttons & eleven;
  return (((mask >> 10)<<31)>>31);
}
int get_r2(void) {
  return ((triggers >> 2) <<17) >>17; 
}
int get_l1(void) {
  unsigned int mask;
  unsigned int twelve = 2048;
  mask = face_buttons & twelve;
  return (((mask >> 11)<<31)>>31);
}
int get_l2(void) {
  return triggers >> 16;
}
int get_rx(void) {
  return ((right_stick >> 2) <<17) >>17;
}
int get_ry(void) {
  return right_stick >> 16;
}
int get_lx(void) {
  return ((left_stick >> 2) <<17) >>17;
}
int get_ly(void) {
  return left_stick >> 16;
}
int get_start(void) {
  unsigned int mask;
  unsigned int thirteen = 4096;
  mask = face_buttons & thirteen;
  return (((mask >> 12)<<31)>>31);
}

int get_option(void) {
  unsigned int mask;
  unsigned int fourteen = 8192;
  mask = face_buttons & fourteen;
  return (((mask >> 13)<<31)>>31);
}
