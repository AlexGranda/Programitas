// calcular frecuencias de caracteres ASCII

#include <stdio.h>
#include <stdlib.h>

main (int argc, char *argv[]) {
  unsigned char c;
  int i, n = 1;
  int freq [256] = {0};
  FILE *fp;

  if (argc != 2) {printf ("USO: ./ascii <fname>\n"); exit (1);}

  fp = fopen (argv[1], "r");
  while ((c = fgetc (fp)) != (unsigned char)EOF) {
    freq [c]++;
    n++;
  }
  fclose (fp);

  for (i=0; i<32; i++)
    printf ("%3d   %d\n", i, freq [i]);
  for (i=32; i<128; i++)
    printf ("%3d %c %d\n", i, (unsigned char)i, freq [i]);
  for (i=128; i<256; i++)
    printf ("%3d   %d\n", i, freq[i]);

  exit (0);
}