struct perstyp{
  char namn[10];
  struct perstyp *right;
  struct perstyp *down;
};

typedef struct perstyp person;

person *laesin(void);       // För inläsning av datastruktur
void tabort(person *start); // För borttagning från heapen

