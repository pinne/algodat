struct perstyp{
  char namn[10];
  struct perstyp *right;
  struct perstyp *down;
};

typedef struct perstyp person;

person *laesin(void);       // F�r inl�sning av datastruktur
void tabort(person *start); // F�r borttagning fr�n heapen

