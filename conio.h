/* conio.h for POWER C           */
/* This is to provide the        */
/* clearscr() function from      */
/* Borland C. Note that POWER C  */
/* also has no system() function,*/
/* so system("cls") and system   */
/* ("clear") are not working     */
/* Jan Klingel, 01/2026          */

clearscr(void) {
  putchar(147);
}
